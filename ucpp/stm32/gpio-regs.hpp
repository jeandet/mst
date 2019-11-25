
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::gpio
{
template <uint32_t base_address, int peripheral_index>
struct gpio_t
{
    using tag = ucpp::tags::gpio_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct MODER_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<MODER_t, 30, 31> MODER15 = {};
        static constexpr bitfield_t<MODER_t, 28, 29> MODER14 = {};
        static constexpr bitfield_t<MODER_t, 26, 27> MODER13 = {};
        static constexpr bitfield_t<MODER_t, 24, 25> MODER12 = {};
        static constexpr bitfield_t<MODER_t, 22, 23> MODER11 = {};
        static constexpr bitfield_t<MODER_t, 20, 21> MODER10 = {};
        static constexpr bitfield_t<MODER_t, 18, 19> MODER9 = {};
        static constexpr bitfield_t<MODER_t, 16, 17> MODER8 = {};
        static constexpr bitfield_t<MODER_t, 14, 15> MODER7 = {};
        static constexpr bitfield_t<MODER_t, 12, 13> MODER6 = {};
        static constexpr bitfield_t<MODER_t, 10, 11> MODER5 = {};
        static constexpr bitfield_t<MODER_t, 8, 9> MODER4 = {};
        static constexpr bitfield_t<MODER_t, 6, 7> MODER3 = {};
        static constexpr bitfield_t<MODER_t, 4, 5> MODER2 = {};
        static constexpr bitfield_t<MODER_t, 2, 3> MODER1 = {};
        static constexpr bitfield_t<MODER_t, 0, 1> MODER0 = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
    } MODER = {};
    static constexpr struct OTYPER_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<OTYPER_t, 15> OT15 = {};
        static constexpr bitfield_t<OTYPER_t, 14> OT14 = {};
        static constexpr bitfield_t<OTYPER_t, 13> OT13 = {};
        static constexpr bitfield_t<OTYPER_t, 12> OT12 = {};
        static constexpr bitfield_t<OTYPER_t, 11> OT11 = {};
        static constexpr bitfield_t<OTYPER_t, 10> OT10 = {};
        static constexpr bitfield_t<OTYPER_t, 9> OT9 = {};
        static constexpr bitfield_t<OTYPER_t, 8> OT8 = {};
        static constexpr bitfield_t<OTYPER_t, 7> OT7 = {};
        static constexpr bitfield_t<OTYPER_t, 6> OT6 = {};
        static constexpr bitfield_t<OTYPER_t, 5> OT5 = {};
        static constexpr bitfield_t<OTYPER_t, 4> OT4 = {};
        static constexpr bitfield_t<OTYPER_t, 3> OT3 = {};
        static constexpr bitfield_t<OTYPER_t, 2> OT2 = {};
        static constexpr bitfield_t<OTYPER_t, 1> OT1 = {};
        static constexpr bitfield_t<OTYPER_t, 0> OT0 = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
    } OTYPER = {};
    static constexpr struct GPIOB_OSPEEDR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 30, 31> OSPEEDR15 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 28, 29> OSPEEDR14 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 26, 27> OSPEEDR13 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 24, 25> OSPEEDR12 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 22, 23> OSPEEDR11 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 20, 21> OSPEEDR10 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 18, 19> OSPEEDR9 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 16, 17> OSPEEDR8 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 14, 15> OSPEEDR7 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 12, 13> OSPEEDR6 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 10, 11> OSPEEDR5 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 8, 9> OSPEEDR4 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 6, 7> OSPEEDR3 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 4, 5> OSPEEDR2 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 2, 3> OSPEEDR1 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 0, 1> OSPEEDR0 = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
    } GPIOB_OSPEEDR = {};
    static constexpr struct PUPDR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<PUPDR_t, 30, 31> PUPDR15 = {};
        static constexpr bitfield_t<PUPDR_t, 28, 29> PUPDR14 = {};
        static constexpr bitfield_t<PUPDR_t, 26, 27> PUPDR13 = {};
        static constexpr bitfield_t<PUPDR_t, 24, 25> PUPDR12 = {};
        static constexpr bitfield_t<PUPDR_t, 22, 23> PUPDR11 = {};
        static constexpr bitfield_t<PUPDR_t, 20, 21> PUPDR10 = {};
        static constexpr bitfield_t<PUPDR_t, 18, 19> PUPDR9 = {};
        static constexpr bitfield_t<PUPDR_t, 16, 17> PUPDR8 = {};
        static constexpr bitfield_t<PUPDR_t, 14, 15> PUPDR7 = {};
        static constexpr bitfield_t<PUPDR_t, 12, 13> PUPDR6 = {};
        static constexpr bitfield_t<PUPDR_t, 10, 11> PUPDR5 = {};
        static constexpr bitfield_t<PUPDR_t, 8, 9> PUPDR4 = {};
        static constexpr bitfield_t<PUPDR_t, 6, 7> PUPDR3 = {};
        static constexpr bitfield_t<PUPDR_t, 4, 5> PUPDR2 = {};
        static constexpr bitfield_t<PUPDR_t, 2, 3> PUPDR1 = {};
        static constexpr bitfield_t<PUPDR_t, 0, 1> PUPDR0 = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
    } PUPDR = {};
    static constexpr struct IDR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<IDR_t, 15> IDR15 = {};
        static constexpr bitfield_t<IDR_t, 14> IDR14 = {};
        static constexpr bitfield_t<IDR_t, 13> IDR13 = {};
        static constexpr bitfield_t<IDR_t, 12> IDR12 = {};
        static constexpr bitfield_t<IDR_t, 11> IDR11 = {};
        static constexpr bitfield_t<IDR_t, 10> IDR10 = {};
        static constexpr bitfield_t<IDR_t, 9> IDR9 = {};
        static constexpr bitfield_t<IDR_t, 8> IDR8 = {};
        static constexpr bitfield_t<IDR_t, 7> IDR7 = {};
        static constexpr bitfield_t<IDR_t, 6> IDR6 = {};
        static constexpr bitfield_t<IDR_t, 5> IDR5 = {};
        static constexpr bitfield_t<IDR_t, 4> IDR4 = {};
        static constexpr bitfield_t<IDR_t, 3> IDR3 = {};
        static constexpr bitfield_t<IDR_t, 2> IDR2 = {};
        static constexpr bitfield_t<IDR_t, 1> IDR1 = {};
        static constexpr bitfield_t<IDR_t, 0> IDR0 = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
    } IDR = {};
    static constexpr struct ODR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<ODR_t, 15> ODR15 = {};
        static constexpr bitfield_t<ODR_t, 14> ODR14 = {};
        static constexpr bitfield_t<ODR_t, 13> ODR13 = {};
        static constexpr bitfield_t<ODR_t, 12> ODR12 = {};
        static constexpr bitfield_t<ODR_t, 11> ODR11 = {};
        static constexpr bitfield_t<ODR_t, 10> ODR10 = {};
        static constexpr bitfield_t<ODR_t, 9> ODR9 = {};
        static constexpr bitfield_t<ODR_t, 8> ODR8 = {};
        static constexpr bitfield_t<ODR_t, 7> ODR7 = {};
        static constexpr bitfield_t<ODR_t, 6> ODR6 = {};
        static constexpr bitfield_t<ODR_t, 5> ODR5 = {};
        static constexpr bitfield_t<ODR_t, 4> ODR4 = {};
        static constexpr bitfield_t<ODR_t, 3> ODR3 = {};
        static constexpr bitfield_t<ODR_t, 2> ODR2 = {};
        static constexpr bitfield_t<ODR_t, 1> ODR1 = {};
        static constexpr bitfield_t<ODR_t, 0> ODR0 = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
    } ODR = {};
    static constexpr struct BSRR_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<BSRR_t, 31> BR15 = {};
        static constexpr bitfield_t<BSRR_t, 30> BR14 = {};
        static constexpr bitfield_t<BSRR_t, 29> BR13 = {};
        static constexpr bitfield_t<BSRR_t, 28> BR12 = {};
        static constexpr bitfield_t<BSRR_t, 27> BR11 = {};
        static constexpr bitfield_t<BSRR_t, 26> BR10 = {};
        static constexpr bitfield_t<BSRR_t, 25> BR9 = {};
        static constexpr bitfield_t<BSRR_t, 24> BR8 = {};
        static constexpr bitfield_t<BSRR_t, 23> BR7 = {};
        static constexpr bitfield_t<BSRR_t, 22> BR6 = {};
        static constexpr bitfield_t<BSRR_t, 21> BR5 = {};
        static constexpr bitfield_t<BSRR_t, 20> BR4 = {};
        static constexpr bitfield_t<BSRR_t, 19> BR3 = {};
        static constexpr bitfield_t<BSRR_t, 18> BR2 = {};
        static constexpr bitfield_t<BSRR_t, 17> BR1 = {};
        static constexpr bitfield_t<BSRR_t, 16> BR0 = {};
        static constexpr bitfield_t<BSRR_t, 15> BS15 = {};
        static constexpr bitfield_t<BSRR_t, 14> BS14 = {};
        static constexpr bitfield_t<BSRR_t, 13> BS13 = {};
        static constexpr bitfield_t<BSRR_t, 12> BS12 = {};
        static constexpr bitfield_t<BSRR_t, 11> BS11 = {};
        static constexpr bitfield_t<BSRR_t, 10> BS10 = {};
        static constexpr bitfield_t<BSRR_t, 9> BS9 = {};
        static constexpr bitfield_t<BSRR_t, 8> BS8 = {};
        static constexpr bitfield_t<BSRR_t, 7> BS7 = {};
        static constexpr bitfield_t<BSRR_t, 6> BS6 = {};
        static constexpr bitfield_t<BSRR_t, 5> BS5 = {};
        static constexpr bitfield_t<BSRR_t, 4> BS4 = {};
        static constexpr bitfield_t<BSRR_t, 3> BS3 = {};
        static constexpr bitfield_t<BSRR_t, 2> BS2 = {};
        static constexpr bitfield_t<BSRR_t, 1> BS1 = {};
        static constexpr bitfield_t<BSRR_t, 0> BS0 = {};
        using reg_t<uint32_t, base_address + 24>::operator=;
    } BSRR = {};
    static constexpr struct LCKR_t : reg_t<uint32_t, base_address + 28>
    {
        static constexpr bitfield_t<LCKR_t, 16> LCKK = {};
        static constexpr bitfield_t<LCKR_t, 15> LCK15 = {};
        static constexpr bitfield_t<LCKR_t, 14> LCK14 = {};
        static constexpr bitfield_t<LCKR_t, 13> LCK13 = {};
        static constexpr bitfield_t<LCKR_t, 12> LCK12 = {};
        static constexpr bitfield_t<LCKR_t, 11> LCK11 = {};
        static constexpr bitfield_t<LCKR_t, 10> LCK10 = {};
        static constexpr bitfield_t<LCKR_t, 9> LCK9 = {};
        static constexpr bitfield_t<LCKR_t, 8> LCK8 = {};
        static constexpr bitfield_t<LCKR_t, 7> LCK7 = {};
        static constexpr bitfield_t<LCKR_t, 6> LCK6 = {};
        static constexpr bitfield_t<LCKR_t, 5> LCK5 = {};
        static constexpr bitfield_t<LCKR_t, 4> LCK4 = {};
        static constexpr bitfield_t<LCKR_t, 3> LCK3 = {};
        static constexpr bitfield_t<LCKR_t, 2> LCK2 = {};
        static constexpr bitfield_t<LCKR_t, 1> LCK1 = {};
        static constexpr bitfield_t<LCKR_t, 0> LCK0 = {};
        using reg_t<uint32_t, base_address + 28>::operator=;
    } LCKR = {};
    static constexpr struct AFRL_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<AFRL_t, 28, 31> AFRL7 = {};
        static constexpr bitfield_t<AFRL_t, 24, 27> AFRL6 = {};
        static constexpr bitfield_t<AFRL_t, 20, 23> AFRL5 = {};
        static constexpr bitfield_t<AFRL_t, 16, 19> AFRL4 = {};
        static constexpr bitfield_t<AFRL_t, 12, 15> AFRL3 = {};
        static constexpr bitfield_t<AFRL_t, 8, 11> AFRL2 = {};
        static constexpr bitfield_t<AFRL_t, 4, 7> AFRL1 = {};
        static constexpr bitfield_t<AFRL_t, 0, 3> AFRL0 = {};
        using reg_t<uint32_t, base_address + 32>::operator=;
    } AFRL = {};
    static constexpr struct AFRH_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<AFRH_t, 28, 31> AFRH15 = {};
        static constexpr bitfield_t<AFRH_t, 24, 27> AFRH14 = {};
        static constexpr bitfield_t<AFRH_t, 20, 23> AFRH13 = {};
        static constexpr bitfield_t<AFRH_t, 16, 19> AFRH12 = {};
        static constexpr bitfield_t<AFRH_t, 12, 15> AFRH11 = {};
        static constexpr bitfield_t<AFRH_t, 8, 11> AFRH10 = {};
        static constexpr bitfield_t<AFRH_t, 4, 7> AFRH9 = {};
        static constexpr bitfield_t<AFRH_t, 0, 3> AFRH8 = {};
        using reg_t<uint32_t, base_address + 36>::operator=;
    } AFRH = {};
    static constexpr struct BRR_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<BRR_t, 0> BR0 = {};
        static constexpr bitfield_t<BRR_t, 1> BR1 = {};
        static constexpr bitfield_t<BRR_t, 2> BR2 = {};
        static constexpr bitfield_t<BRR_t, 3> BR3 = {};
        static constexpr bitfield_t<BRR_t, 4> BR4 = {};
        static constexpr bitfield_t<BRR_t, 5> BR5 = {};
        static constexpr bitfield_t<BRR_t, 6> BR6 = {};
        static constexpr bitfield_t<BRR_t, 7> BR7 = {};
        static constexpr bitfield_t<BRR_t, 8> BR8 = {};
        static constexpr bitfield_t<BRR_t, 9> BR9 = {};
        static constexpr bitfield_t<BRR_t, 10> BR10 = {};
        static constexpr bitfield_t<BRR_t, 11> BR11 = {};
        static constexpr bitfield_t<BRR_t, 12> BR12 = {};
        static constexpr bitfield_t<BRR_t, 13> BR13 = {};
        static constexpr bitfield_t<BRR_t, 14> BR14 = {};
        static constexpr bitfield_t<BRR_t, 15> BR15 = {};
        using reg_t<uint32_t, base_address + 40>::operator=;
    } BRR = {};
};


struct gpio_c_t
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t GPIOB_OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
    volatile uint32_t BRR;
};

}
