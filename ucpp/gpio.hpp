#pragma once
#include <cstdint>

namespace ucpp::gpio
{
template<std::size_t port_number, std::size_t pin_number>
struct GPIO
{
    static inline constexpr std::size_t port = port_number;
    static inline constexpr std::size_t pin = pin_number;
};

static inline constexpr GPIO<0,0> GPIOA0 = {};
static inline constexpr GPIO<1,8> GPIOB8 = {};
static inline constexpr GPIO<8,11> GPIOI11 = {};
}
