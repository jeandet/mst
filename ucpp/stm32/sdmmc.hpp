#pragma once
#include "../sdcard/sdcard.hpp"
#include "./sdmmc-regs.hpp"
#include "./stm32f7.hpp"
#include <optional>
#include <type_traits>

namespace ucpp::stm32::sdmmc
{
namespace
{
    template <typename CMD, typename sdmmc_dev>
    inline constexpr auto response()
    {
        using namespace ucpp::sdcard::commands;
        if constexpr (is_no_response_v<CMD>)
        {
            return true;
        }
        else if constexpr (is_short_response_v<CMD>)
        {
            return std::optional<short_response> { short_response { uint32_t(sdmmc_dev::RESP1) } };
        }
        else if constexpr (is_long_response_v<CMD>)
        {
            return std::optional<long_response> { long_response {
                sdmmc_dev::RESP1, sdmmc_dev::RESP2, sdmmc_dev::RESP3, sdmmc_dev::RESP4 } };
        }
    }
    template <typename CMD>
    inline constexpr int WAITRESP_v()
    {
        using namespace ucpp::sdcard::commands;
        if constexpr (is_no_response_v<CMD>)
            return 0;
        if constexpr (is_short_response_v<CMD>)
            return 1;
        if constexpr (is_long_response_v<CMD>)
            return 3;
    }

    template <typename sdmmc_dev>
    inline constexpr void cmd_clear_icr_flags()
    {
        using namespace ucpp::sdcard::commands;
        using ICR = decltype(sdmmc_dev::ICR);
        sdmmc_dev::ICR |= sdmmc_dev::ICR.CCRCFAILC.shift(1) | sdmmc_dev::ICR.CTIMEOUTC.shift(1)
            | sdmmc_dev::ICR.CMDRENDC.shift(1) | sdmmc_dev::ICR.CMDSENTC.shift(1);
    }

    template <typename sdmmc_dev>
    inline constexpr void data_clear_icr_flags()
    {
        using namespace ucpp::sdcard::commands;
        using ICR = decltype(sdmmc_dev::ICR);
        sdmmc_dev::ICR |= sdmmc_dev::ICR.DCRCFAILC.shift(1) | sdmmc_dev::ICR.DTIMEOUTC.shift(1)
            | sdmmc_dev::ICR.TXUNDERRC.shift(1) | sdmmc_dev::ICR.RXOVERRC.shift(1)
            | sdmmc_dev::ICR.DATAENDC.shift(1) | sdmmc_dev::ICR.DBCKENDC.shift(1);
    }

    template <typename sdmmc_dev, typename CMD>
    inline constexpr void cmd_set_cmd_reg()
    {
        using namespace ucpp::sdcard::commands;
        using cmd_reg = decltype(sdmmc_dev::CMD);
        sdmmc_dev::CMD |= cmd_reg::CPSMEN.shift(1) | cmd_reg::CMDINDEX.shift(CMD::index)
            | cmd_reg::WAITRESP.shift(WAITRESP_v<CMD>());
    }

    template <typename sdmmc_dev>
    inline constexpr bool cmd_sent()
    {
        return sdmmc_dev::STA.CMDSENT == 1;
    }

    template <typename sdmmc_dev>
    inline constexpr bool cmd_got_response()
    {
        return sdmmc_dev::STA.CMDREND == 1;
    }

    template <typename sdmmc_dev>
    inline constexpr bool cmd_timeout()
    {
        return sdmmc_dev::STA.CTIMEOUT == 1;
    }

    template <typename sdmmc_dev>
    inline constexpr bool cmd_crc_fail()
    {
        return sdmmc_dev::STA.CCRCFAIL == 1;
    }

}

template <typename sdmmc_dev, typename dma_dev>
struct sdmmc_ctrlr
{
    inline static constexpr void set_speed(int speed)
    {
        for (volatile int i = 0; i < 1024 * 256; i++)
            ;
        if (speed == -1)
        {
            sdmmc_dev::CLKCR |= sdmmc_dev::CLKCR.CLKDIV.shift(0);
        }
        else
        {
            auto div = std::max((48 * 1000 * 1000) / (speed)-2, 0);
            sdmmc_dev::CLKCR |= sdmmc_dev::CLKCR.CLKDIV.shift(div);
        }
        for (volatile int i = 0; i < 1024 * 256; i++)
            ;
    }

    template <typename CMD>
    inline static constexpr auto send_cmd(uint32_t argument)
    {
        using namespace ucpp::sdcard::commands;
        cmd_clear_icr_flags<sdmmc_dev>();
        sdmmc_dev::ARG = argument;
        cmd_set_cmd_reg<sdmmc_dev, CMD>();
        while (1)
        {
            if constexpr (is_no_response_v<CMD>)
            {
                if (cmd_sent<sdmmc_dev>())
                    return response<CMD, sdmmc_dev>();
            }
            else
            {
                if (cmd_got_response<sdmmc_dev>())
                {
                    cmd_clear_icr_flags<sdmmc_dev>();
                    return response<CMD, sdmmc_dev>();
                }
                if (cmd_timeout<sdmmc_dev>())
                {
                    cmd_clear_icr_flags<sdmmc_dev>();
                    return std::optional<typename CMD::response_type> { std::nullopt };
                }
                if (cmd_crc_fail<sdmmc_dev>())
                {
                    cmd_clear_icr_flags<sdmmc_dev>();
                    if constexpr (has_crc_v<CMD>)
                        return std::optional<typename CMD::response_type> { std::nullopt };
                    else
                        return response<CMD, sdmmc_dev>();
                }
            }
        }
    }

    inline static constexpr auto read_block(ucpp::sdcard::block_address_t address, char* data)
    {
        using namespace ucpp::sdcard::commands;
        data_clear_icr_flags<sdmmc_dev>();
        sdmmc_dev::DCTRL |= sdmmc_dev::DCTRL.DTEN.shift(0);
        sdmmc_dev::DLEN = 512;
        dma_dev::setup(reinterpret_cast<uint32_t>(data), sdmmc_dev::FIFO.address);

        sdmmc_dev::DCTRL = sdmmc_dev::DCTRL.DBLOCKSIZE.shift(9) | sdmmc_dev::DCTRL.DMAEN.shift(1)
            | sdmmc_dev::DCTRL.DTDIR.shift(1) | sdmmc_dev::DCTRL.DTEN.shift(1);
        for (int timeout = 100; timeout > 0; timeout--)
        {
            auto resp = sdmmc_ctrlr::send_cmd<CMD17>(address.value());
            if (resp)
                break;
        }
        while (!sdmmc_dev::STA.DBCKEND & !sdmmc_dev::STA.DATAEND)
        {
            volatile int c = sdmmc_dev::FIFOCNT;
            volatile int sta = sdmmc_dev::STA;
            sta = sdmmc_dev::STA;
        }
        return true;
    }
};
}
