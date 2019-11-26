
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include "rcc-regs.hpp"
#include <stdint.h>

namespace
{
using namespace ucpp::tags;
template <typename rcc_t, typename device_t>
auto& clk_enable_bit(const rcc_t& rcc, const device_t&,
    typename std::enable_if_t<is_gpio_v<device_t>>* = 0)
{
    if constexpr (device_t::index == 0)
        return rcc.AHB1ENR.GPIOAEN;
    if constexpr (device_t::index == 1)
        return rcc.AHB1ENR.GPIOBEN;
    if constexpr (device_t::index == 2)
        return rcc.AHB1ENR.GPIOCEN;
    if constexpr (device_t::index == 3)
        return rcc.AHB1ENR.GPIODEN;
    if constexpr (device_t::index == 4)
        return rcc.AHB1ENR.GPIOEEN;
    if constexpr (device_t::index == 5)
        return rcc.AHB1ENR.GPIOFEN;
    if constexpr (device_t::index == 6)
        return rcc.AHB1ENR.GPIOGEN;
    if constexpr (device_t::index == 7)
        return rcc.AHB1ENR.GPIOHEN;
    if constexpr (device_t::index == 8)
        return rcc.AHB1ENR.GPIOIEN;
    if constexpr (device_t::index == 9)
        return rcc.AHB1ENR.GPIOJEN;
    if constexpr (device_t::index == 10)
        return rcc.AHB1ENR.GPIOKEN;
}

template <typename rcc_t, typename device_t>
auto& clk_enable_bit(const rcc_t& rcc, const device_t&,
    typename std::enable_if_t<is_sdmmc_v<device_t>>* = 0)
{
    return rcc.APB2ENR.SDMMC1EN;
}

}

using namespace ucpp::registers;
namespace ucpp::stm32::rcc
{
template <typename rcc_type, typename device_t>
void enable_clock(const rcc_type& rccdev, const device_t& device, bool state = true)
{
    clk_enable_bit(rccdev, device) = state;
}
}
