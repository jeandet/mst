#pragma once
#include <stdint.h>
#include "../register.hpp"
#include "./gpio.hpp"
#include "./rcc.hpp"

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
        gpio::Gpio<0x40020000,1> GPIOA;
        gpio::Gpio<0x40020400,2> GPIOB;
        gpio::Gpio<0x40020800,3> GPIOC;
        gpio::Gpio<0x40020C00,4> GPIOD;
        gpio::Gpio<0x40021000,5> GPIOE;
        gpio::Gpio<0x40021400,6> GPIOF;
        gpio::Gpio<0x40021800,7> GPIOG;
        gpio::Gpio<0x40021C00,8> GPIOH;
        gpio::Gpio<0x40022000,9> GPIOI;
        gpio::Gpio<0x40022400,10> GPIOJ;
        gpio::Gpio<0x40022800,11> GPIOK;
        rcc::RCC_t<0x40023800, 0> rcc;
    }stm32f7;
}

