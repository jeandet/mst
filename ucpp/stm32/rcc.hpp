
#pragma once
#include <stdint.h>
#include "../register.hpp"
#include "rcc-regs.hpp"
#include "../peripherals_tags.hpp"


using namespace ucpp::registers;
namespace ucpp::stm32::rcc
{
    template<typename T, typename tag=typename T::tag>
    void enable_clock(const T& device, bool state = true);
}
    
