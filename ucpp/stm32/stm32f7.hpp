#pragma once
#include "../register.hpp"
#include "./gpio.hpp"
#include "./rcc.hpp"
#include "./sdmmc.hpp"
#include "./spi.hpp"
#include <stdint.h>

using namespace ucpp::registers;
namespace ucpp::stm32
{
struct DeviceSignature
{
    reg_t<uint32_t, 0x1FF0F420> uuid0;
    reg_t<uint32_t, 0x1FF0F420 + 4> uuid1;
    reg_t<uint32_t, 0x1FF0F420 + 8> uuid2;
    reg_t<uint16_t, 0x1FF0F442> flash_size;
    struct package_t : reg_t<uint16_t, 0x1FF07BF0>
    {
        bitfield_t<reg_t<uint16_t, 0x1FF07BF0>, 8, 10> pkg;
    } package;
};

//    const DeviceSignature dev;
static constexpr struct stm32f7_t
{
    DeviceSignature deviceSignature;
    static constexpr struct apb1_t
    {
        using tag = ucpp::tags::apb_bus_tag;
        static constexpr int index = 1;
    } apb1 = {};
    static constexpr struct apb2_t
    {
        using tag = ucpp::tags::apb_bus_tag;
        static constexpr int index = 2;
    } apb2 = {};
    static constexpr gpio::Gpio<0x40020000, 0> GPIOA = {};
    static constexpr gpio::Gpio<0x40020400, 1> GPIOB = {};
    static constexpr gpio::Gpio<0x40020800, 2> GPIOC = {};
    static constexpr gpio::Gpio<0x40020C00, 3> GPIOD = {};
    static constexpr gpio::Gpio<0x40021000, 4> GPIOE = {};
    static constexpr gpio::Gpio<0x40021400, 5> GPIOF = {};
    static constexpr gpio::Gpio<0x40021800, 6> GPIOG = {};
    static constexpr gpio::Gpio<0x40021C00, 7> GPIOH = {};
    static constexpr gpio::Gpio<0x40022000, 8> GPIOI = {};
    static constexpr gpio::Gpio<0x40022400, 9> GPIOJ = {};
    static constexpr gpio::Gpio<0x40022800, 10> GPIOK = {};
    static constexpr rcc::RCC_t<0x40023800, 0> rcc = {};
    static constexpr sdmmc::sdmmc_t<0x40012C00, 0> sdmmc = {};
    static constexpr spi::spi_t<0x40013000, 0> SPI1 = {};
    static constexpr spi::spi_t<0x40003800, 1> SPI2 = {};
    static constexpr spi::spi_t<0x40003C00, 2> SPI3 = {};
    static constexpr spi::spi_t<0x40013400, 3> SPI4 = {};
    static constexpr spi::spi_t<0x40015000, 4> SPI5 = {};
    static constexpr spi::spi_t<0x40015400, 5> SPI6 = {};
} stm32f7 = {};
}
