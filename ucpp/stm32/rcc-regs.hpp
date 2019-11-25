
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::rcc
{
template <uint32_t base_address, int peripheral_index>
struct RCC_t
{
    using tag = ucpp::tags::no_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct CR_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<CR_t, 27> PLLI2SRDY = {};
        static constexpr bitfield_t<CR_t, 26> PLLI2SON = {};
        static constexpr bitfield_t<CR_t, 25> PLLRDY = {};
        static constexpr bitfield_t<CR_t, 24> PLLON = {};
        static constexpr bitfield_t<CR_t, 19> CSSON = {};
        static constexpr bitfield_t<CR_t, 18> HSEBYP = {};
        static constexpr bitfield_t<CR_t, 17> HSERDY = {};
        static constexpr bitfield_t<CR_t, 16> HSEON = {};
        static constexpr bitfield_t<CR_t, 8, 15> HSICAL = {};
        static constexpr bitfield_t<CR_t, 3, 7> HSITRIM = {};
        static constexpr bitfield_t<CR_t, 1> HSIRDY = {};
        static constexpr bitfield_t<CR_t, 0> HSION = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
    } CR = {};
    static constexpr struct PLLCFGR_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<PLLCFGR_t, 27> PLLQ3 = {};
        static constexpr bitfield_t<PLLCFGR_t, 26> PLLQ2 = {};
        static constexpr bitfield_t<PLLCFGR_t, 25> PLLQ1 = {};
        static constexpr bitfield_t<PLLCFGR_t, 24> PLLQ0 = {};
        static constexpr bitfield_t<PLLCFGR_t, 22> PLLSRC = {};
        static constexpr bitfield_t<PLLCFGR_t, 17> PLLP1 = {};
        static constexpr bitfield_t<PLLCFGR_t, 16> PLLP0 = {};
        static constexpr bitfield_t<PLLCFGR_t, 14> PLLN8 = {};
        static constexpr bitfield_t<PLLCFGR_t, 13> PLLN7 = {};
        static constexpr bitfield_t<PLLCFGR_t, 12> PLLN6 = {};
        static constexpr bitfield_t<PLLCFGR_t, 11> PLLN5 = {};
        static constexpr bitfield_t<PLLCFGR_t, 10> PLLN4 = {};
        static constexpr bitfield_t<PLLCFGR_t, 9> PLLN3 = {};
        static constexpr bitfield_t<PLLCFGR_t, 8> PLLN2 = {};
        static constexpr bitfield_t<PLLCFGR_t, 7> PLLN1 = {};
        static constexpr bitfield_t<PLLCFGR_t, 6> PLLN0 = {};
        static constexpr bitfield_t<PLLCFGR_t, 5> PLLM5 = {};
        static constexpr bitfield_t<PLLCFGR_t, 4> PLLM4 = {};
        static constexpr bitfield_t<PLLCFGR_t, 3> PLLM3 = {};
        static constexpr bitfield_t<PLLCFGR_t, 2> PLLM2 = {};
        static constexpr bitfield_t<PLLCFGR_t, 1> PLLM1 = {};
        static constexpr bitfield_t<PLLCFGR_t, 0> PLLM0 = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
    } PLLCFGR = {};
    static constexpr struct CFGR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<CFGR_t, 30, 31> MCO2 = {};
        static constexpr bitfield_t<CFGR_t, 27, 29> MCO2PRE = {};
        static constexpr bitfield_t<CFGR_t, 24, 26> MCO1PRE = {};
        static constexpr bitfield_t<CFGR_t, 23> I2SSRC = {};
        static constexpr bitfield_t<CFGR_t, 21, 22> MCO1 = {};
        static constexpr bitfield_t<CFGR_t, 16, 20> RTCPRE = {};
        static constexpr bitfield_t<CFGR_t, 13, 15> PPRE2 = {};
        static constexpr bitfield_t<CFGR_t, 10, 12> PPRE1 = {};
        static constexpr bitfield_t<CFGR_t, 4, 7> HPRE = {};
        static constexpr bitfield_t<CFGR_t, 3> SWS1 = {};
        static constexpr bitfield_t<CFGR_t, 2> SWS0 = {};
        static constexpr bitfield_t<CFGR_t, 1> SW1 = {};
        static constexpr bitfield_t<CFGR_t, 0> SW0 = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
    } CFGR = {};
    static constexpr struct CIR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<CIR_t, 23> CSSC = {};
        static constexpr bitfield_t<CIR_t, 22> PLLSAIRDYC = {};
        static constexpr bitfield_t<CIR_t, 21> PLLI2SRDYC = {};
        static constexpr bitfield_t<CIR_t, 20> PLLRDYC = {};
        static constexpr bitfield_t<CIR_t, 19> HSERDYC = {};
        static constexpr bitfield_t<CIR_t, 18> HSIRDYC = {};
        static constexpr bitfield_t<CIR_t, 17> LSERDYC = {};
        static constexpr bitfield_t<CIR_t, 16> LSIRDYC = {};
        static constexpr bitfield_t<CIR_t, 14> PLLSAIRDYIE = {};
        static constexpr bitfield_t<CIR_t, 13> PLLI2SRDYIE = {};
        static constexpr bitfield_t<CIR_t, 12> PLLRDYIE = {};
        static constexpr bitfield_t<CIR_t, 11> HSERDYIE = {};
        static constexpr bitfield_t<CIR_t, 10> HSIRDYIE = {};
        static constexpr bitfield_t<CIR_t, 9> LSERDYIE = {};
        static constexpr bitfield_t<CIR_t, 8> LSIRDYIE = {};
        static constexpr bitfield_t<CIR_t, 7> CSSF = {};
        static constexpr bitfield_t<CIR_t, 6> PLLSAIRDYF = {};
        static constexpr bitfield_t<CIR_t, 5> PLLI2SRDYF = {};
        static constexpr bitfield_t<CIR_t, 4> PLLRDYF = {};
        static constexpr bitfield_t<CIR_t, 3> HSERDYF = {};
        static constexpr bitfield_t<CIR_t, 2> HSIRDYF = {};
        static constexpr bitfield_t<CIR_t, 1> LSERDYF = {};
        static constexpr bitfield_t<CIR_t, 0> LSIRDYF = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
    } CIR = {};
    static constexpr struct AHB1RSTR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<AHB1RSTR_t, 29> OTGHSRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 25> ETHMACRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 23> DMA2DRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 22> DMA2RST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 21> DMA1RST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 12> CRCRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 10> GPIOKRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 9> GPIOJRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 8> GPIOIRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 7> GPIOHRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 6> GPIOGRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 5> GPIOFRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 4> GPIOERST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 3> GPIODRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 2> GPIOCRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 1> GPIOBRST = {};
        static constexpr bitfield_t<AHB1RSTR_t, 0> GPIOARST = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
    } AHB1RSTR = {};
    static constexpr struct AHB2RSTR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<AHB2RSTR_t, 7> OTGFSRST = {};
        static constexpr bitfield_t<AHB2RSTR_t, 6> RNGRST = {};
        static constexpr bitfield_t<AHB2RSTR_t, 5> HSAHRST = {};
        static constexpr bitfield_t<AHB2RSTR_t, 4> CRYPRST = {};
        static constexpr bitfield_t<AHB2RSTR_t, 0> DCMIRST = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
    } AHB2RSTR = {};
    static constexpr struct AHB3RSTR_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<AHB3RSTR_t, 0> FMCRST = {};
        static constexpr bitfield_t<AHB3RSTR_t, 1> QSPIRST = {};
        using reg_t<uint32_t, base_address + 24>::operator=;
    } AHB3RSTR = {};
    static constexpr struct APB1RSTR_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<APB1RSTR_t, 0> TIM2RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 1> TIM3RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 2> TIM4RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 3> TIM5RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 4> TIM6RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 5> TIM7RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 6> TIM12RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 7> TIM13RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 8> TIM14RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 11> WWDGRST = {};
        static constexpr bitfield_t<APB1RSTR_t, 14> SPI2RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 15> SPI3RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 17> UART2RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 18> UART3RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 19> UART4RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 20> UART5RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 21> I2C1RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 22> I2C2RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 23> I2C3RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 25> CAN1RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 26> CAN2RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 28> PWRRST = {};
        static constexpr bitfield_t<APB1RSTR_t, 29> DACRST = {};
        static constexpr bitfield_t<APB1RSTR_t, 30> UART7RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 31> UART8RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 16> SPDIFRXRST = {};
        static constexpr bitfield_t<APB1RSTR_t, 27> CECRST = {};
        static constexpr bitfield_t<APB1RSTR_t, 9> LPTIM1RST = {};
        static constexpr bitfield_t<APB1RSTR_t, 24> I2C4RST = {};
        using reg_t<uint32_t, base_address + 32>::operator=;
    } APB1RSTR = {};
    static constexpr struct APB2RSTR_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<APB2RSTR_t, 0> TIM1RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 1> TIM8RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 4> USART1RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 5> USART6RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 8> ADCRST = {};
        static constexpr bitfield_t<APB2RSTR_t, 12> SPI1RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 13> SPI4RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 14> SYSCFGRST = {};
        static constexpr bitfield_t<APB2RSTR_t, 16> TIM9RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 17> TIM10RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 18> TIM11RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 20> SPI5RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 21> SPI6RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 22> SAI1RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 26> LTDCRST = {};
        static constexpr bitfield_t<APB2RSTR_t, 23> SAI2RST = {};
        static constexpr bitfield_t<APB2RSTR_t, 11> SDMMC1RST = {};
        using reg_t<uint32_t, base_address + 36>::operator=;
    } APB2RSTR = {};
    static constexpr struct AHB1ENR_t : reg_t<uint32_t, base_address + 48>
    {
        static constexpr bitfield_t<AHB1ENR_t, 30> OTGHSULPIEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 29> OTGHSEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 28> ETHMACPTPEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 27> ETHMACRXEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 26> ETHMACTXEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 25> ETHMACEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 23> DMA2DEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 22> DMA2EN = {};
        static constexpr bitfield_t<AHB1ENR_t, 21> DMA1EN = {};
        static constexpr bitfield_t<AHB1ENR_t, 20> CCMDATARAMEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 18> BKPSRAMEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 12> CRCEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 10> GPIOKEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 9> GPIOJEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 8> GPIOIEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 7> GPIOHEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 6> GPIOGEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 5> GPIOFEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 4> GPIOEEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 3> GPIODEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 2> GPIOCEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 1> GPIOBEN = {};
        static constexpr bitfield_t<AHB1ENR_t, 0> GPIOAEN = {};
        using reg_t<uint32_t, base_address + 48>::operator=;
    } AHB1ENR = {};
    static constexpr struct AHB2ENR_t : reg_t<uint32_t, base_address + 52>
    {
        static constexpr bitfield_t<AHB2ENR_t, 7> OTGFSEN = {};
        static constexpr bitfield_t<AHB2ENR_t, 6> RNGEN = {};
        static constexpr bitfield_t<AHB2ENR_t, 5> HASHEN = {};
        static constexpr bitfield_t<AHB2ENR_t, 4> CRYPEN = {};
        static constexpr bitfield_t<AHB2ENR_t, 0> DCMIEN = {};
        using reg_t<uint32_t, base_address + 52>::operator=;
    } AHB2ENR = {};
    static constexpr struct AHB3ENR_t : reg_t<uint32_t, base_address + 56>
    {
        static constexpr bitfield_t<AHB3ENR_t, 0> FMCEN = {};
        static constexpr bitfield_t<AHB3ENR_t, 1> QSPIEN = {};
        using reg_t<uint32_t, base_address + 56>::operator=;
    } AHB3ENR = {};
    static constexpr struct APB1ENR_t : reg_t<uint32_t, base_address + 64>
    {
        static constexpr bitfield_t<APB1ENR_t, 0> TIM2EN = {};
        static constexpr bitfield_t<APB1ENR_t, 1> TIM3EN = {};
        static constexpr bitfield_t<APB1ENR_t, 2> TIM4EN = {};
        static constexpr bitfield_t<APB1ENR_t, 3> TIM5EN = {};
        static constexpr bitfield_t<APB1ENR_t, 4> TIM6EN = {};
        static constexpr bitfield_t<APB1ENR_t, 5> TIM7EN = {};
        static constexpr bitfield_t<APB1ENR_t, 6> TIM12EN = {};
        static constexpr bitfield_t<APB1ENR_t, 7> TIM13EN = {};
        static constexpr bitfield_t<APB1ENR_t, 8> TIM14EN = {};
        static constexpr bitfield_t<APB1ENR_t, 11> WWDGEN = {};
        static constexpr bitfield_t<APB1ENR_t, 14> SPI2EN = {};
        static constexpr bitfield_t<APB1ENR_t, 15> SPI3EN = {};
        static constexpr bitfield_t<APB1ENR_t, 17> USART2EN = {};
        static constexpr bitfield_t<APB1ENR_t, 18> USART3EN = {};
        static constexpr bitfield_t<APB1ENR_t, 19> UART4EN = {};
        static constexpr bitfield_t<APB1ENR_t, 20> UART5EN = {};
        static constexpr bitfield_t<APB1ENR_t, 21> I2C1EN = {};
        static constexpr bitfield_t<APB1ENR_t, 22> I2C2EN = {};
        static constexpr bitfield_t<APB1ENR_t, 23> I2C3EN = {};
        static constexpr bitfield_t<APB1ENR_t, 25> CAN1EN = {};
        static constexpr bitfield_t<APB1ENR_t, 26> CAN2EN = {};
        static constexpr bitfield_t<APB1ENR_t, 28> PWREN = {};
        static constexpr bitfield_t<APB1ENR_t, 29> DACEN = {};
        static constexpr bitfield_t<APB1ENR_t, 30> UART7ENR = {};
        static constexpr bitfield_t<APB1ENR_t, 31> UART8ENR = {};
        static constexpr bitfield_t<APB1ENR_t, 16> SPDIFRXEN = {};
        static constexpr bitfield_t<APB1ENR_t, 27> CECEN = {};
        static constexpr bitfield_t<APB1ENR_t, 9> LPTMI1EN = {};
        static constexpr bitfield_t<APB1ENR_t, 24> I2C4EN = {};
        using reg_t<uint32_t, base_address + 64>::operator=;
    } APB1ENR = {};
    static constexpr struct APB2ENR_t : reg_t<uint32_t, base_address + 68>
    {
        static constexpr bitfield_t<APB2ENR_t, 0> TIM1EN = {};
        static constexpr bitfield_t<APB2ENR_t, 1> TIM8EN = {};
        static constexpr bitfield_t<APB2ENR_t, 4> USART1EN = {};
        static constexpr bitfield_t<APB2ENR_t, 5> USART6EN = {};
        static constexpr bitfield_t<APB2ENR_t, 8> ADC1EN = {};
        static constexpr bitfield_t<APB2ENR_t, 9> ADC2EN = {};
        static constexpr bitfield_t<APB2ENR_t, 10> ADC3EN = {};
        static constexpr bitfield_t<APB2ENR_t, 12> SPI1EN = {};
        static constexpr bitfield_t<APB2ENR_t, 13> SPI4ENR = {};
        static constexpr bitfield_t<APB2ENR_t, 14> SYSCFGEN = {};
        static constexpr bitfield_t<APB2ENR_t, 16> TIM9EN = {};
        static constexpr bitfield_t<APB2ENR_t, 17> TIM10EN = {};
        static constexpr bitfield_t<APB2ENR_t, 18> TIM11EN = {};
        static constexpr bitfield_t<APB2ENR_t, 20> SPI5ENR = {};
        static constexpr bitfield_t<APB2ENR_t, 21> SPI6ENR = {};
        static constexpr bitfield_t<APB2ENR_t, 22> SAI1EN = {};
        static constexpr bitfield_t<APB2ENR_t, 26> LTDCEN = {};
        static constexpr bitfield_t<APB2ENR_t, 23> SAI2EN = {};
        static constexpr bitfield_t<APB2ENR_t, 11> SDMMC1EN = {};
        using reg_t<uint32_t, base_address + 68>::operator=;
    } APB2ENR = {};
    static constexpr struct AHB1LPENR_t : reg_t<uint32_t, base_address + 80>
    {
        static constexpr bitfield_t<AHB1LPENR_t, 0> GPIOALPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 1> GPIOBLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 2> GPIOCLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 3> GPIODLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 4> GPIOELPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 5> GPIOFLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 6> GPIOGLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 7> GPIOHLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 8> GPIOILPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 9> GPIOJLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 10> GPIOKLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 12> CRCLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 15> FLITFLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 16> SRAM1LPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 17> SRAM2LPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 18> BKPSRAMLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 19> SRAM3LPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 21> DMA1LPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 22> DMA2LPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 23> DMA2DLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 25> ETHMACLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 26> ETHMACTXLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 27> ETHMACRXLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 28> ETHMACPTPLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 29> OTGHSLPEN = {};
        static constexpr bitfield_t<AHB1LPENR_t, 30> OTGHSULPILPEN = {};
        using reg_t<uint32_t, base_address + 80>::operator=;
    } AHB1LPENR = {};
    static constexpr struct AHB2LPENR_t : reg_t<uint32_t, base_address + 84>
    {
        static constexpr bitfield_t<AHB2LPENR_t, 7> OTGFSLPEN = {};
        static constexpr bitfield_t<AHB2LPENR_t, 6> RNGLPEN = {};
        static constexpr bitfield_t<AHB2LPENR_t, 5> HASHLPEN = {};
        static constexpr bitfield_t<AHB2LPENR_t, 4> CRYPLPEN = {};
        static constexpr bitfield_t<AHB2LPENR_t, 0> DCMILPEN = {};
        using reg_t<uint32_t, base_address + 84>::operator=;
    } AHB2LPENR = {};
    static constexpr struct AHB3LPENR_t : reg_t<uint32_t, base_address + 88>
    {
        static constexpr bitfield_t<AHB3LPENR_t, 0> FMCLPEN = {};
        static constexpr bitfield_t<AHB3LPENR_t, 1> QSPILPEN = {};
        using reg_t<uint32_t, base_address + 88>::operator=;
    } AHB3LPENR = {};
    static constexpr struct APB1LPENR_t : reg_t<uint32_t, base_address + 96>
    {
        static constexpr bitfield_t<APB1LPENR_t, 0> TIM2LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 1> TIM3LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 2> TIM4LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 3> TIM5LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 4> TIM6LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 5> TIM7LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 6> TIM12LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 7> TIM13LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 8> TIM14LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 11> WWDGLPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 14> SPI2LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 15> SPI3LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 17> USART2LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 18> USART3LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 19> UART4LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 20> UART5LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 21> I2C1LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 22> I2C2LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 23> I2C3LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 25> CAN1LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 26> CAN2LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 28> PWRLPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 29> DACLPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 30> UART7LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 31> UART8LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 16> SPDIFRXLPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 27> CECLPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 9> LPTIM1LPEN = {};
        static constexpr bitfield_t<APB1LPENR_t, 24> I2C4LPEN = {};
        using reg_t<uint32_t, base_address + 96>::operator=;
    } APB1LPENR = {};
    static constexpr struct APB2LPENR_t : reg_t<uint32_t, base_address + 100>
    {
        static constexpr bitfield_t<APB2LPENR_t, 0> TIM1LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 1> TIM8LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 4> USART1LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 5> USART6LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 8> ADC1LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 9> ADC2LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 10> ADC3LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 12> SPI1LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 13> SPI4LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 14> SYSCFGLPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 16> TIM9LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 17> TIM10LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 18> TIM11LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 20> SPI5LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 21> SPI6LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 22> SAI1LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 26> LTDCLPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 23> SAI2LPEN = {};
        static constexpr bitfield_t<APB2LPENR_t, 11> SDMMC1LPEN = {};
        using reg_t<uint32_t, base_address + 100>::operator=;
    } APB2LPENR = {};
    static constexpr struct BDCR_t : reg_t<uint32_t, base_address + 112>
    {
        static constexpr bitfield_t<BDCR_t, 16> BDRST = {};
        static constexpr bitfield_t<BDCR_t, 15> RTCEN = {};
        static constexpr bitfield_t<BDCR_t, 9> RTCSEL1 = {};
        static constexpr bitfield_t<BDCR_t, 8> RTCSEL0 = {};
        static constexpr bitfield_t<BDCR_t, 2> LSEBYP = {};
        static constexpr bitfield_t<BDCR_t, 1> LSERDY = {};
        static constexpr bitfield_t<BDCR_t, 0> LSEON = {};
        using reg_t<uint32_t, base_address + 112>::operator=;
    } BDCR = {};
    static constexpr struct CSR_t : reg_t<uint32_t, base_address + 116>
    {
        static constexpr bitfield_t<CSR_t, 31> LPWRRSTF = {};
        static constexpr bitfield_t<CSR_t, 30> WWDGRSTF = {};
        static constexpr bitfield_t<CSR_t, 29> WDGRSTF = {};
        static constexpr bitfield_t<CSR_t, 28> SFTRSTF = {};
        static constexpr bitfield_t<CSR_t, 27> PORRSTF = {};
        static constexpr bitfield_t<CSR_t, 26> PADRSTF = {};
        static constexpr bitfield_t<CSR_t, 25> BORRSTF = {};
        static constexpr bitfield_t<CSR_t, 24> RMVF = {};
        static constexpr bitfield_t<CSR_t, 1> LSIRDY = {};
        static constexpr bitfield_t<CSR_t, 0> LSION = {};
        using reg_t<uint32_t, base_address + 116>::operator=;
    } CSR = {};
    static constexpr struct SSCGR_t : reg_t<uint32_t, base_address + 128>
    {
        static constexpr bitfield_t<SSCGR_t, 31> SSCGEN = {};
        static constexpr bitfield_t<SSCGR_t, 30> SPREADSEL = {};
        static constexpr bitfield_t<SSCGR_t, 13, 27> INCSTEP = {};
        static constexpr bitfield_t<SSCGR_t, 0, 12> MODPER = {};
        using reg_t<uint32_t, base_address + 128>::operator=;
    } SSCGR = {};
    static constexpr struct PLLI2SCFGR_t : reg_t<uint32_t, base_address + 132>
    {
        static constexpr bitfield_t<PLLI2SCFGR_t, 28, 30> PLLI2SR = {};
        static constexpr bitfield_t<PLLI2SCFGR_t, 24, 27> PLLI2SQ = {};
        static constexpr bitfield_t<PLLI2SCFGR_t, 6, 14> PLLI2SN = {};
        using reg_t<uint32_t, base_address + 132>::operator=;
    } PLLI2SCFGR = {};
    static constexpr struct PLLSAICFGR_t : reg_t<uint32_t, base_address + 136>
    {
        static constexpr bitfield_t<PLLSAICFGR_t, 6, 14> PLLSAIN = {};
        static constexpr bitfield_t<PLLSAICFGR_t, 16, 17> PLLSAIP = {};
        static constexpr bitfield_t<PLLSAICFGR_t, 24, 27> PLLSAIQ = {};
        static constexpr bitfield_t<PLLSAICFGR_t, 28, 30> PLLSAIR = {};
        using reg_t<uint32_t, base_address + 136>::operator=;
    } PLLSAICFGR = {};
    static constexpr struct DKCFGR1_t : reg_t<uint32_t, base_address + 140>
    {
        static constexpr bitfield_t<DKCFGR1_t, 0, 4> PLLI2SDIV = {};
        static constexpr bitfield_t<DKCFGR1_t, 8, 12> PLLSAIDIVQ = {};
        static constexpr bitfield_t<DKCFGR1_t, 16, 17> PLLSAIDIVR = {};
        static constexpr bitfield_t<DKCFGR1_t, 20, 21> SAI1SEL = {};
        static constexpr bitfield_t<DKCFGR1_t, 22, 23> SAI2SEL = {};
        static constexpr bitfield_t<DKCFGR1_t, 24> TIMPRE = {};
        using reg_t<uint32_t, base_address + 140>::operator=;
    } DKCFGR1 = {};
    static constexpr struct DKCFGR2_t : reg_t<uint32_t, base_address + 144>
    {
        static constexpr bitfield_t<DKCFGR2_t, 0, 1> USART1SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 2, 3> USART2SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 4, 5> USART3SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 6, 7> UART4SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 8, 9> UART5SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 10, 11> USART6SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 12, 13> UART7SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 14, 15> UART8SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 16, 17> I2C1SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 18, 19> I2C2SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 20, 21> I2C3SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 22, 23> I2C4SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 24, 25> LPTIM1SEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 26> CECSEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 27> CK48MSEL = {};
        static constexpr bitfield_t<DKCFGR2_t, 28> SDMMCSEL = {};
        using reg_t<uint32_t, base_address + 144>::operator=;
    } DKCFGR2 = {};
};


struct RCC_c_t
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t __dummy28;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t __dummy40;
    volatile uint32_t __dummy44;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t __dummy60;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t __dummy72;
    volatile uint32_t __dummy76;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t __dummy92;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t __dummy104;
    volatile uint32_t __dummy108;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t __dummy120;
    volatile uint32_t __dummy124;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DKCFGR1;
    volatile uint32_t DKCFGR2;
};

}
