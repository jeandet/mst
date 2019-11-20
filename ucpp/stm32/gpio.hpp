#pragma once
#include <stdint.h>
#include "../register.hpp"


using namespace ucpp::registers;
namespace ucpp::stm32::gpio {

template<uint32_t base_address>
struct Gpio
{
    bitfield_array_t<0,2,reg_t<uint32_t, base_address> ,16> mode;
    bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x4> ,16> output_type;
    bitfield_array_t<0,2,reg_t<uint32_t, base_address+0x8> ,16> speed;
    bitfield_array_t<0,2,reg_t<uint32_t, base_address+0xc> ,16> pupd;
    bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x10> ,16> id;
    bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x14> ,16> od;
    bitfield_array_t<16,1,reg_t<uint32_t, base_address+0x18> ,16> br;
    bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x18> ,16> bs;
    bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x1c> ,16> lck;
    bitfield_array_t<0,4,reg_t<uint32_t, base_address+0x20> ,8> afrl;
    bitfield_array_t<0,4,reg_t<uint32_t, base_address+0x24> ,8> afrh;
};

}
