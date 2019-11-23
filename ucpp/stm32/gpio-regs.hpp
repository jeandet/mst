
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
        static constexpr bitfield_t<MODER_t, 30> MODER15 = {};
        static constexpr bitfield_t<MODER_t, 28> MODER14 = {};
        static constexpr bitfield_t<MODER_t, 26> MODER13 = {};
        static constexpr bitfield_t<MODER_t, 24> MODER12 = {};
        static constexpr bitfield_t<MODER_t, 22> MODER11 = {};
        static constexpr bitfield_t<MODER_t, 20> MODER10 = {};
        static constexpr bitfield_t<MODER_t, 18> MODER9 = {};
        static constexpr bitfield_t<MODER_t, 16> MODER8 = {};
        static constexpr bitfield_t<MODER_t, 14> MODER7 = {};
        static constexpr bitfield_t<MODER_t, 12> MODER6 = {};
        static constexpr bitfield_t<MODER_t, 10> MODER5 = {};
        static constexpr bitfield_t<MODER_t, 8> MODER4 = {};
        static constexpr bitfield_t<MODER_t, 6> MODER3 = {};
        static constexpr bitfield_t<MODER_t, 4> MODER2 = {};
        static constexpr bitfield_t<MODER_t, 2> MODER1 = {};
        static constexpr bitfield_t<MODER_t, 0> MODER0 = {};
    } MODER = {};
    static constexpr struct OTYPER_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<OTYPER_t, 15, 15> OT15 = {};
        static constexpr bitfield_t<OTYPER_t, 14, 14> OT14 = {};
        static constexpr bitfield_t<OTYPER_t, 13, 13> OT13 = {};
        static constexpr bitfield_t<OTYPER_t, 12, 12> OT12 = {};
        static constexpr bitfield_t<OTYPER_t, 11, 11> OT11 = {};
        static constexpr bitfield_t<OTYPER_t, 10, 10> OT10 = {};
        static constexpr bitfield_t<OTYPER_t, 9, 9> OT9 = {};
        static constexpr bitfield_t<OTYPER_t, 8, 8> OT8 = {};
        static constexpr bitfield_t<OTYPER_t, 7, 7> OT7 = {};
        static constexpr bitfield_t<OTYPER_t, 6, 6> OT6 = {};
        static constexpr bitfield_t<OTYPER_t, 5, 5> OT5 = {};
        static constexpr bitfield_t<OTYPER_t, 4, 4> OT4 = {};
        static constexpr bitfield_t<OTYPER_t, 3, 3> OT3 = {};
        static constexpr bitfield_t<OTYPER_t, 2, 2> OT2 = {};
        static constexpr bitfield_t<OTYPER_t, 1, 1> OT1 = {};
        static constexpr bitfield_t<OTYPER_t, 0, 0> OT0 = {};
    } OTYPER = {};
    static constexpr struct GPIOB_OSPEEDR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 30> OSPEEDR15 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 28> OSPEEDR14 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 26> OSPEEDR13 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 24> OSPEEDR12 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 22> OSPEEDR11 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 20> OSPEEDR10 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 18> OSPEEDR9 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 16> OSPEEDR8 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 14> OSPEEDR7 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 12> OSPEEDR6 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 10> OSPEEDR5 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 8> OSPEEDR4 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 6> OSPEEDR3 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 4> OSPEEDR2 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 2> OSPEEDR1 = {};
        static constexpr bitfield_t<GPIOB_OSPEEDR_t, 0> OSPEEDR0 = {};
    } GPIOB_OSPEEDR = {};
    static constexpr struct PUPDR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<PUPDR_t, 30> PUPDR15 = {};
        static constexpr bitfield_t<PUPDR_t, 28> PUPDR14 = {};
        static constexpr bitfield_t<PUPDR_t, 26> PUPDR13 = {};
        static constexpr bitfield_t<PUPDR_t, 24> PUPDR12 = {};
        static constexpr bitfield_t<PUPDR_t, 22> PUPDR11 = {};
        static constexpr bitfield_t<PUPDR_t, 20> PUPDR10 = {};
        static constexpr bitfield_t<PUPDR_t, 18> PUPDR9 = {};
        static constexpr bitfield_t<PUPDR_t, 16> PUPDR8 = {};
        static constexpr bitfield_t<PUPDR_t, 14> PUPDR7 = {};
        static constexpr bitfield_t<PUPDR_t, 12> PUPDR6 = {};
        static constexpr bitfield_t<PUPDR_t, 10> PUPDR5 = {};
        static constexpr bitfield_t<PUPDR_t, 8> PUPDR4 = {};
        static constexpr bitfield_t<PUPDR_t, 6> PUPDR3 = {};
        static constexpr bitfield_t<PUPDR_t, 4> PUPDR2 = {};
        static constexpr bitfield_t<PUPDR_t, 2> PUPDR1 = {};
        static constexpr bitfield_t<PUPDR_t, 0> PUPDR0 = {};
    } PUPDR = {};
    static constexpr struct IDR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<IDR_t, 15, 15> IDR15 = {};
        static constexpr bitfield_t<IDR_t, 14, 14> IDR14 = {};
        static constexpr bitfield_t<IDR_t, 13, 13> IDR13 = {};
        static constexpr bitfield_t<IDR_t, 12, 12> IDR12 = {};
        static constexpr bitfield_t<IDR_t, 11, 11> IDR11 = {};
        static constexpr bitfield_t<IDR_t, 10, 10> IDR10 = {};
        static constexpr bitfield_t<IDR_t, 9, 9> IDR9 = {};
        static constexpr bitfield_t<IDR_t, 8, 8> IDR8 = {};
        static constexpr bitfield_t<IDR_t, 7, 7> IDR7 = {};
        static constexpr bitfield_t<IDR_t, 6, 6> IDR6 = {};
        static constexpr bitfield_t<IDR_t, 5, 5> IDR5 = {};
        static constexpr bitfield_t<IDR_t, 4, 4> IDR4 = {};
        static constexpr bitfield_t<IDR_t, 3, 3> IDR3 = {};
        static constexpr bitfield_t<IDR_t, 2, 2> IDR2 = {};
        static constexpr bitfield_t<IDR_t, 1, 1> IDR1 = {};
        static constexpr bitfield_t<IDR_t, 0, 0> IDR0 = {};
    } IDR = {};
    static constexpr struct ODR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<ODR_t, 15, 15> ODR15 = {};
        static constexpr bitfield_t<ODR_t, 14, 14> ODR14 = {};
        static constexpr bitfield_t<ODR_t, 13, 13> ODR13 = {};
        static constexpr bitfield_t<ODR_t, 12, 12> ODR12 = {};
        static constexpr bitfield_t<ODR_t, 11, 11> ODR11 = {};
        static constexpr bitfield_t<ODR_t, 10, 10> ODR10 = {};
        static constexpr bitfield_t<ODR_t, 9, 9> ODR9 = {};
        static constexpr bitfield_t<ODR_t, 8, 8> ODR8 = {};
        static constexpr bitfield_t<ODR_t, 7, 7> ODR7 = {};
        static constexpr bitfield_t<ODR_t, 6, 6> ODR6 = {};
        static constexpr bitfield_t<ODR_t, 5, 5> ODR5 = {};
        static constexpr bitfield_t<ODR_t, 4, 4> ODR4 = {};
        static constexpr bitfield_t<ODR_t, 3, 3> ODR3 = {};
        static constexpr bitfield_t<ODR_t, 2, 2> ODR2 = {};
        static constexpr bitfield_t<ODR_t, 1, 1> ODR1 = {};
        static constexpr bitfield_t<ODR_t, 0, 0> ODR0 = {};
    } ODR = {};
    static constexpr struct BSRR_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<BSRR_t, 31, 31> BR15 = {};
        static constexpr bitfield_t<BSRR_t, 30, 30> BR14 = {};
        static constexpr bitfield_t<BSRR_t, 29, 29> BR13 = {};
        static constexpr bitfield_t<BSRR_t, 28, 28> BR12 = {};
        static constexpr bitfield_t<BSRR_t, 27, 27> BR11 = {};
        static constexpr bitfield_t<BSRR_t, 26, 26> BR10 = {};
        static constexpr bitfield_t<BSRR_t, 25, 25> BR9 = {};
        static constexpr bitfield_t<BSRR_t, 24, 24> BR8 = {};
        static constexpr bitfield_t<BSRR_t, 23, 23> BR7 = {};
        static constexpr bitfield_t<BSRR_t, 22, 22> BR6 = {};
        static constexpr bitfield_t<BSRR_t, 21, 21> BR5 = {};
        static constexpr bitfield_t<BSRR_t, 20, 20> BR4 = {};
        static constexpr bitfield_t<BSRR_t, 19, 19> BR3 = {};
        static constexpr bitfield_t<BSRR_t, 18, 18> BR2 = {};
        static constexpr bitfield_t<BSRR_t, 17, 17> BR1 = {};
        static constexpr bitfield_t<BSRR_t, 16, 16> BR0 = {};
        static constexpr bitfield_t<BSRR_t, 15, 15> BS15 = {};
        static constexpr bitfield_t<BSRR_t, 14, 14> BS14 = {};
        static constexpr bitfield_t<BSRR_t, 13, 13> BS13 = {};
        static constexpr bitfield_t<BSRR_t, 12, 12> BS12 = {};
        static constexpr bitfield_t<BSRR_t, 11, 11> BS11 = {};
        static constexpr bitfield_t<BSRR_t, 10, 10> BS10 = {};
        static constexpr bitfield_t<BSRR_t, 9, 9> BS9 = {};
        static constexpr bitfield_t<BSRR_t, 8, 8> BS8 = {};
        static constexpr bitfield_t<BSRR_t, 7, 7> BS7 = {};
        static constexpr bitfield_t<BSRR_t, 6, 6> BS6 = {};
        static constexpr bitfield_t<BSRR_t, 5, 5> BS5 = {};
        static constexpr bitfield_t<BSRR_t, 4, 4> BS4 = {};
        static constexpr bitfield_t<BSRR_t, 3, 3> BS3 = {};
        static constexpr bitfield_t<BSRR_t, 2, 2> BS2 = {};
        static constexpr bitfield_t<BSRR_t, 1, 1> BS1 = {};
        static constexpr bitfield_t<BSRR_t, 0, 0> BS0 = {};
    } BSRR = {};
    static constexpr struct LCKR_t : reg_t<uint32_t, base_address + 28>
    {
        static constexpr bitfield_t<LCKR_t, 16, 16> LCKK = {};
        static constexpr bitfield_t<LCKR_t, 15, 15> LCK15 = {};
        static constexpr bitfield_t<LCKR_t, 14, 14> LCK14 = {};
        static constexpr bitfield_t<LCKR_t, 13, 13> LCK13 = {};
        static constexpr bitfield_t<LCKR_t, 12, 12> LCK12 = {};
        static constexpr bitfield_t<LCKR_t, 11, 11> LCK11 = {};
        static constexpr bitfield_t<LCKR_t, 10, 10> LCK10 = {};
        static constexpr bitfield_t<LCKR_t, 9, 9> LCK9 = {};
        static constexpr bitfield_t<LCKR_t, 8, 8> LCK8 = {};
        static constexpr bitfield_t<LCKR_t, 7, 7> LCK7 = {};
        static constexpr bitfield_t<LCKR_t, 6, 6> LCK6 = {};
        static constexpr bitfield_t<LCKR_t, 5, 5> LCK5 = {};
        static constexpr bitfield_t<LCKR_t, 4, 4> LCK4 = {};
        static constexpr bitfield_t<LCKR_t, 3, 3> LCK3 = {};
        static constexpr bitfield_t<LCKR_t, 2, 2> LCK2 = {};
        static constexpr bitfield_t<LCKR_t, 1, 1> LCK1 = {};
        static constexpr bitfield_t<LCKR_t, 0, 0> LCK0 = {};
    } LCKR = {};
    static constexpr struct AFRL_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<AFRL_t, 28> AFRL7 = {};
        static constexpr bitfield_t<AFRL_t, 24> AFRL6 = {};
        static constexpr bitfield_t<AFRL_t, 20> AFRL5 = {};
        static constexpr bitfield_t<AFRL_t, 16> AFRL4 = {};
        static constexpr bitfield_t<AFRL_t, 12> AFRL3 = {};
        static constexpr bitfield_t<AFRL_t, 8> AFRL2 = {};
        static constexpr bitfield_t<AFRL_t, 4> AFRL1 = {};
        static constexpr bitfield_t<AFRL_t, 0> AFRL0 = {};
    } AFRL = {};
    static constexpr struct AFRH_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<AFRH_t, 28> AFRH15 = {};
        static constexpr bitfield_t<AFRH_t, 24> AFRH14 = {};
        static constexpr bitfield_t<AFRH_t, 20> AFRH13 = {};
        static constexpr bitfield_t<AFRH_t, 16> AFRH12 = {};
        static constexpr bitfield_t<AFRH_t, 12> AFRH11 = {};
        static constexpr bitfield_t<AFRH_t, 8> AFRH10 = {};
        static constexpr bitfield_t<AFRH_t, 4> AFRH9 = {};
        static constexpr bitfield_t<AFRH_t, 0> AFRH8 = {};
    } AFRH = {};
    static constexpr struct BRR_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<BRR_t, 0, 0> BR0 = {};
        static constexpr bitfield_t<BRR_t, 1, 1> BR1 = {};
        static constexpr bitfield_t<BRR_t, 2, 2> BR2 = {};
        static constexpr bitfield_t<BRR_t, 3, 3> BR3 = {};
        static constexpr bitfield_t<BRR_t, 4, 4> BR4 = {};
        static constexpr bitfield_t<BRR_t, 5, 5> BR5 = {};
        static constexpr bitfield_t<BRR_t, 6, 6> BR6 = {};
        static constexpr bitfield_t<BRR_t, 7, 7> BR7 = {};
        static constexpr bitfield_t<BRR_t, 8, 8> BR8 = {};
        static constexpr bitfield_t<BRR_t, 9, 9> BR9 = {};
        static constexpr bitfield_t<BRR_t, 10, 10> BR10 = {};
        static constexpr bitfield_t<BRR_t, 11, 11> BR11 = {};
        static constexpr bitfield_t<BRR_t, 12, 12> BR12 = {};
        static constexpr bitfield_t<BRR_t, 13, 13> BR13 = {};
        static constexpr bitfield_t<BRR_t, 14, 14> BR14 = {};
        static constexpr bitfield_t<BRR_t, 15, 15> BR15 = {};
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
