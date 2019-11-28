#pragma once
#include "./sdmmc-regs.hpp"
#include "../sdcard/sdcard.hpp"
#include <type_traits>
#include <optional>

namespace ucpp::stm32::sdmmc
{
namespace  {
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
    sdmmc_dev::ICR |= ICR::CMDRENDC.shift(1) | ICR::CTIMEOUTC.shift(1) | ICR::CMDSENTC.shift(1);
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
    return  sdmmc_dev::STA.CMDSENT == 1;
}

template <typename sdmmc_dev>
inline constexpr bool cmd_got_response()
{
    return  sdmmc_dev::STA.CMDREND == 1;
}

template <typename sdmmc_dev>
inline constexpr bool cmd_timeout()
{
    return  sdmmc_dev::STA.CTIMEOUT == 1;
}

}

template <typename sdmmc_dev>
struct sdmmc_ctrlr
{
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
                    return response<CMD,sdmmc_dev>();
            }
            else
            {
                if (cmd_got_response<sdmmc_dev>())
                {
                    return response<CMD,sdmmc_dev>();
                }
                if (cmd_timeout<sdmmc_dev>())
                {
                    return std::optional<typename CMD::response_type> { std::nullopt };
                }
            }
        }
    }

};
}
