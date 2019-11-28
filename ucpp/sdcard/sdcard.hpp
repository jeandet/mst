#pragma once
#include <cstdint>
#include <type_traits>
#include <optional>
#include "./commands.hpp"

namespace ucpp::sdcard {
template<typename bus>
struct Sdcard
{
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

        } // SD HC
        else
        {
            do
            {

                r = Sdcard::send_cmd<ACMD41>(0x40000000);
            } while (!(r->value & 0x80000000));
        }
        return true;
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
};

} // namespace ucpp::sdcard
