#pragma once
#include <stdint.h>
#include "../register.hpp"
#include "./gpio.hpp"
#include "./rcc.hpp"
#include "./sdmmc-regs.hpp"

using namespace ucpp::registers;
namespace ucpp::stm32 {
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
    struct stm32f7_t{
        DeviceSignature deviceSignature;
        static constexpr gpio::Gpio<0x40020000,0> GPIOA={};
        static constexpr gpio::Gpio<0x40020400,1> GPIOB = {};
        static constexpr gpio::Gpio<0x40020800,2> GPIOC = {};
        static constexpr gpio::Gpio<0x40020C00,3> GPIOD = {};
        static constexpr gpio::Gpio<0x40021000,4> GPIOE = {};
        static constexpr gpio::Gpio<0x40021400,5> GPIOF = {};
        static constexpr gpio::Gpio<0x40021800,6> GPIOG = {};
        static constexpr gpio::Gpio<0x40021C00,7> GPIOH = {};
        static constexpr gpio::Gpio<0x40022000,8> GPIOI = {};
        static constexpr gpio::Gpio<0x40022400,9> GPIOJ = {};
        static constexpr gpio::Gpio<0x40022800,10> GPIOK = {};
        static constexpr rcc::RCC_t<0x40023800, 0> rcc = {};
        static constexpr sdmmc::sdmmc_t<0x40012C00, 0> sdmmc ={};
    }stm32f7;
}

