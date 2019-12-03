#pragma once
#include <stdint.h>
#include "../register.hpp"
#include "../peripherals_tags.hpp"
#include "./gpio-regs.hpp"
#include "../gpio.hpp"

using namespace ucpp::registers;
namespace ucpp::stm32::gpio {
enum class mode
{
    input = 0,
    output = 1,
    alternate_function = 2,
    analogue = 3
};
enum class speed{
    low = 0,
    medium = 1,
    high = 2,
    very_high = 3
};
enum class output_type{
    push_pull = 0,
    open_drain = 1
};
enum class alternate_function
{
    af0 = 0,
    af1 = 1,
    af2 = 2,
    af3 = 3,
    af4 = 4,
    af5 = 5,
    af6 = 6,
    af7 = 7,
    af8 = 8,
    af9 = 9,
    af10 = 10,
    af11 = 11,
    af12 = 12,
    af13 = 13,
    af14 = 14,
    af15 = 15
};

template<std::size_t index, typename gpio_t>
auto alternate_function_field(const gpio_t& gpio)
{
    if constexpr (index<8)
        return gpio.afrl.template get<index>();
    if constexpr (index>=8)
        return gpio.afrh.template get<index-8>();
}

template<std::size_t index, typename gpio_t>
auto mode_field(const gpio_t& gpio)
{
    return gpio.moder.template get<index>();
}

template<std::size_t index, typename gpio_t>
auto speed_field(const gpio_t& gpio)
{
    return gpio.speedr.template get<index>();
}

template<std::size_t index, typename gpio_t>
auto output_type_field(const gpio_t& gpio)
{
    return gpio.output_typer.template get<index>();
}

template<uint32_t base_address, int peripheral_index>
struct Gpio
{
    using tag = ucpp::tags::gpio_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr bitfield_array_t<0,2,reg_t<uint32_t, base_address> ,16, mode> moder ={};
    static constexpr bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x4> ,16, output_type>  output_typer={};
    static constexpr bitfield_array_t<0,2,reg_t<uint32_t, base_address+0x8> ,16, speed> speedr={};
    static constexpr bitfield_array_t<0,2,reg_t<uint32_t, base_address+0xc> ,16> pupd={};
    static constexpr bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x10> ,16> id = {};
    static constexpr bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x14> ,16> od={};
    static constexpr bitfield_array_t<16,1,reg_t<uint32_t, base_address+0x18> ,16> br={};
    static constexpr bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x18> ,16> bs={};
    static constexpr bitfield_array_t<0,1,reg_t<uint32_t, base_address+0x1c> ,16> lck={};
    static constexpr bitfield_array_t<0,4,reg_t<uint32_t, base_address+0x20> ,8, alternate_function> afrl={};
    static constexpr bitfield_array_t<0,4,reg_t<uint32_t, base_address+0x24> ,8, alternate_function> afrh={};
};

template <typename soc_t, typename gpio_t>
auto constexpr port_register(const soc_t& soc, const gpio_t& gpio)
{
    if constexpr (gpio_t::port == 0)
            return soc.GPIOA;
    if constexpr (gpio_t::port == 1)
            return soc.GPIOB;
    if constexpr (gpio_t::port == 2)
            return soc.GPIOC;
    if constexpr (gpio_t::port == 3)
            return soc.GPIOD;
    if constexpr (gpio_t::port == 4)
            return soc.GPIOE;
    if constexpr (gpio_t::port == 5)
            return soc.GPIOF;
    if constexpr (gpio_t::port == 6)
            return soc.GPIOG;
    if constexpr (gpio_t::port == 7)
            return soc.GPIOH;
    if constexpr (gpio_t::port == 8)
            return soc.GPIOI;
    if constexpr (gpio_t::port == 9)
            return soc.GPIOJ;
}

}


namespace ucpp::gpio {
    template <typename soc_t, typename gpio_t, typename direction_t>
    void constexpr set_direction(const soc_t& soc, const gpio_t& gpio, const direction_t direction)
    {
        using namespace ucpp::stm32::gpio;
        mode_field<gpio_t::pin>(port_register(soc, gpio)) = direction;
    }
}
