#pragma once
#include <cstdint>
#include <type_traits>
#include <optional>
#include "./commands.hpp"

namespace ucpp::sdcard {

namespace
{
template<typename sdcard>
inline bool set_block_size(uint32_t size)
{
    using namespace commands;
    if(sdcard::template send_cmd<CMD16>(size))
        return true;
    return false;
}
}

template<typename bus>
struct Sdcard
{
    uint16_t RCA=0;
    bool init()
    {
        using namespace commands;
        //setup_sd_io();
        Sdcard::send_cmd<CMD0>();
        for (volatile int i = 0; i < 1024; i++)
            ;
        auto r = Sdcard::send_cmd<CMD8>(0x1aa);
        if (!r) // SD SC
        {
            // r = sd_send_cmd<41>(0);
            return false;
        }
        else if (r->value != 0x1aa)
        {
            return false;
        } // SD HC
        else
        {
            do
            {
                //0x80100000U
                r = Sdcard::send_cmd<ACMD41>(0x40000000|0x80100000);
                volatile int v = r->value;
                v = r->value;
            } while (r->value>>31 == 0);
        }
        auto cid_r = Sdcard::send_cmd<CMD2>();
        volatile int CID[4];
        CID[0] = cid_r->value[0];
        CID[1] = cid_r->value[1];
        CID[2] = cid_r->value[2];
        CID[3] = cid_r->value[3];
        r = Sdcard::send_cmd<CMD3>();
        if(r)
        {
            bus::set_speed(10000000);
            RCA = r->value>>16;
            return true;//set_block_size<Sdcard>(1024);
        }
        return false;
    }

    template <typename CMD>
    inline static constexpr auto send_cmd(uint32_t argument = 0)
    {
        using namespace commands;
        if constexpr (is_application_specific_v<CMD>)
        {
            auto r = bus::template send_cmd<CMD55>(0);
            if (!r)
                return std::optional<typename CMD::response_type> { std::nullopt };
        }
        return bus::template send_cmd<CMD>(argument);
    }

    inline constexpr auto select()
    {
        using namespace commands;
        return send_cmd<CMD7>(RCA<<16);
    }

    inline constexpr auto read_block(uint32_t address, char* data)
    {
        using namespace commands;
        int timeout = 10;
        do{
            //auto resp  = send_cmd<CMD7>(RCA<<16);
            //if(resp)
            {
                auto  resp  = send_cmd<CMD17>(address);
                if(resp)
                    return bus::read_data(data, 512);
            }

        }while (timeout--);
        return false;
    }
};

} // namespace ucpp::sdcard
