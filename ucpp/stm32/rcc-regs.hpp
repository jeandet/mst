
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
    struct CR_t : reg_t<uint32_t, base_address + 0>
    {
        bitfield_t<CR_t, 27, 27> PLLI2SRDY;
        bitfield_t<CR_t, 26, 26> PLLI2SON;
        bitfield_t<CR_t, 25, 25> PLLRDY;
        bitfield_t<CR_t, 24, 24> PLLON;
        bitfield_t<CR_t, 19, 19> CSSON;
        bitfield_t<CR_t, 18, 18> HSEBYP;
        bitfield_t<CR_t, 17, 17> HSERDY;
        bitfield_t<CR_t, 16, 16> HSEON;
        bitfield_t<CR_t, 8> HSICAL;
        bitfield_t<CR_t, 3> HSITRIM;
        bitfield_t<CR_t, 1, 1> HSIRDY;
        bitfield_t<CR_t, 0, 0> HSION;
    } CR;
    struct PLLCFGR_t : reg_t<uint32_t, base_address + 4>
    {
        bitfield_t<PLLCFGR_t, 27, 27> PLLQ3;
        bitfield_t<PLLCFGR_t, 26, 26> PLLQ2;
        bitfield_t<PLLCFGR_t, 25, 25> PLLQ1;
        bitfield_t<PLLCFGR_t, 24, 24> PLLQ0;
        bitfield_t<PLLCFGR_t, 22, 22> PLLSRC;
        bitfield_t<PLLCFGR_t, 17, 17> PLLP1;
        bitfield_t<PLLCFGR_t, 16, 16> PLLP0;
        bitfield_t<PLLCFGR_t, 14, 14> PLLN8;
        bitfield_t<PLLCFGR_t, 13, 13> PLLN7;
        bitfield_t<PLLCFGR_t, 12, 12> PLLN6;
        bitfield_t<PLLCFGR_t, 11, 11> PLLN5;
        bitfield_t<PLLCFGR_t, 10, 10> PLLN4;
        bitfield_t<PLLCFGR_t, 9, 9> PLLN3;
        bitfield_t<PLLCFGR_t, 8, 8> PLLN2;
        bitfield_t<PLLCFGR_t, 7, 7> PLLN1;
        bitfield_t<PLLCFGR_t, 6, 6> PLLN0;
        bitfield_t<PLLCFGR_t, 5, 5> PLLM5;
        bitfield_t<PLLCFGR_t, 4, 4> PLLM4;
        bitfield_t<PLLCFGR_t, 3, 3> PLLM3;
        bitfield_t<PLLCFGR_t, 2, 2> PLLM2;
        bitfield_t<PLLCFGR_t, 1, 1> PLLM1;
        bitfield_t<PLLCFGR_t, 0, 0> PLLM0;
    } PLLCFGR;
    struct CFGR_t : reg_t<uint32_t, base_address + 8>
    {
        bitfield_t<CFGR_t, 30> MCO2;
        bitfield_t<CFGR_t, 27> MCO2PRE;
        bitfield_t<CFGR_t, 24> MCO1PRE;
        bitfield_t<CFGR_t, 23, 23> I2SSRC;
        bitfield_t<CFGR_t, 21> MCO1;
        bitfield_t<CFGR_t, 16> RTCPRE;
        bitfield_t<CFGR_t, 13> PPRE2;
        bitfield_t<CFGR_t, 10> PPRE1;
        bitfield_t<CFGR_t, 4> HPRE;
        bitfield_t<CFGR_t, 3, 3> SWS1;
        bitfield_t<CFGR_t, 2, 2> SWS0;
        bitfield_t<CFGR_t, 1, 1> SW1;
        bitfield_t<CFGR_t, 0, 0> SW0;
    } CFGR;
    struct CIR_t : reg_t<uint32_t, base_address + 12>
    {
        bitfield_t<CIR_t, 23, 23> CSSC;
        bitfield_t<CIR_t, 22, 22> PLLSAIRDYC;
        bitfield_t<CIR_t, 21, 21> PLLI2SRDYC;
        bitfield_t<CIR_t, 20, 20> PLLRDYC;
        bitfield_t<CIR_t, 19, 19> HSERDYC;
        bitfield_t<CIR_t, 18, 18> HSIRDYC;
        bitfield_t<CIR_t, 17, 17> LSERDYC;
        bitfield_t<CIR_t, 16, 16> LSIRDYC;
        bitfield_t<CIR_t, 14, 14> PLLSAIRDYIE;
        bitfield_t<CIR_t, 13, 13> PLLI2SRDYIE;
        bitfield_t<CIR_t, 12, 12> PLLRDYIE;
        bitfield_t<CIR_t, 11, 11> HSERDYIE;
        bitfield_t<CIR_t, 10, 10> HSIRDYIE;
        bitfield_t<CIR_t, 9, 9> LSERDYIE;
        bitfield_t<CIR_t, 8, 8> LSIRDYIE;
        bitfield_t<CIR_t, 7, 7> CSSF;
        bitfield_t<CIR_t, 6, 6> PLLSAIRDYF;
        bitfield_t<CIR_t, 5, 5> PLLI2SRDYF;
        bitfield_t<CIR_t, 4, 4> PLLRDYF;
        bitfield_t<CIR_t, 3, 3> HSERDYF;
        bitfield_t<CIR_t, 2, 2> HSIRDYF;
        bitfield_t<CIR_t, 1, 1> LSERDYF;
        bitfield_t<CIR_t, 0, 0> LSIRDYF;
    } CIR;
    struct AHB1RSTR_t : reg_t<uint32_t, base_address + 16>
    {
        bitfield_t<AHB1RSTR_t, 29, 29> OTGHSRST;
        bitfield_t<AHB1RSTR_t, 25, 25> ETHMACRST;
        bitfield_t<AHB1RSTR_t, 23, 23> DMA2DRST;
        bitfield_t<AHB1RSTR_t, 22, 22> DMA2RST;
        bitfield_t<AHB1RSTR_t, 21, 21> DMA1RST;
        bitfield_t<AHB1RSTR_t, 12, 12> CRCRST;
        bitfield_t<AHB1RSTR_t, 10, 10> GPIOKRST;
        bitfield_t<AHB1RSTR_t, 9, 9> GPIOJRST;
        bitfield_t<AHB1RSTR_t, 8, 8> GPIOIRST;
        bitfield_t<AHB1RSTR_t, 7, 7> GPIOHRST;
        bitfield_t<AHB1RSTR_t, 6, 6> GPIOGRST;
        bitfield_t<AHB1RSTR_t, 5, 5> GPIOFRST;
        bitfield_t<AHB1RSTR_t, 4, 4> GPIOERST;
        bitfield_t<AHB1RSTR_t, 3, 3> GPIODRST;
        bitfield_t<AHB1RSTR_t, 2, 2> GPIOCRST;
        bitfield_t<AHB1RSTR_t, 1, 1> GPIOBRST;
        bitfield_t<AHB1RSTR_t, 0, 0> GPIOARST;
    } AHB1RSTR;
    struct AHB2RSTR_t : reg_t<uint32_t, base_address + 20>
    {
        bitfield_t<AHB2RSTR_t, 7, 7> OTGFSRST;
        bitfield_t<AHB2RSTR_t, 6, 6> RNGRST;
        bitfield_t<AHB2RSTR_t, 5, 5> HSAHRST;
        bitfield_t<AHB2RSTR_t, 4, 4> CRYPRST;
        bitfield_t<AHB2RSTR_t, 0, 0> DCMIRST;
    } AHB2RSTR;
    struct AHB3RSTR_t : reg_t<uint32_t, base_address + 24>
    {
        bitfield_t<AHB3RSTR_t, 0, 0> FMCRST;
        bitfield_t<AHB3RSTR_t, 1, 1> QSPIRST;
    } AHB3RSTR;
    struct APB1RSTR_t : reg_t<uint32_t, base_address + 32>
    {
        bitfield_t<APB1RSTR_t, 0, 0> TIM2RST;
        bitfield_t<APB1RSTR_t, 1, 1> TIM3RST;
        bitfield_t<APB1RSTR_t, 2, 2> TIM4RST;
        bitfield_t<APB1RSTR_t, 3, 3> TIM5RST;
        bitfield_t<APB1RSTR_t, 4, 4> TIM6RST;
        bitfield_t<APB1RSTR_t, 5, 5> TIM7RST;
        bitfield_t<APB1RSTR_t, 6, 6> TIM12RST;
        bitfield_t<APB1RSTR_t, 7, 7> TIM13RST;
        bitfield_t<APB1RSTR_t, 8, 8> TIM14RST;
        bitfield_t<APB1RSTR_t, 11, 11> WWDGRST;
        bitfield_t<APB1RSTR_t, 14, 14> SPI2RST;
        bitfield_t<APB1RSTR_t, 15, 15> SPI3RST;
        bitfield_t<APB1RSTR_t, 17, 17> UART2RST;
        bitfield_t<APB1RSTR_t, 18, 18> UART3RST;
        bitfield_t<APB1RSTR_t, 19, 19> UART4RST;
        bitfield_t<APB1RSTR_t, 20, 20> UART5RST;
        bitfield_t<APB1RSTR_t, 21, 21> I2C1RST;
        bitfield_t<APB1RSTR_t, 22, 22> I2C2RST;
        bitfield_t<APB1RSTR_t, 23, 23> I2C3RST;
        bitfield_t<APB1RSTR_t, 25, 25> CAN1RST;
        bitfield_t<APB1RSTR_t, 26, 26> CAN2RST;
        bitfield_t<APB1RSTR_t, 28, 28> PWRRST;
        bitfield_t<APB1RSTR_t, 29, 29> DACRST;
        bitfield_t<APB1RSTR_t, 30, 30> UART7RST;
        bitfield_t<APB1RSTR_t, 31, 31> UART8RST;
        bitfield_t<APB1RSTR_t, 16, 16> SPDIFRXRST;
        bitfield_t<APB1RSTR_t, 27, 27> CECRST;
        bitfield_t<APB1RSTR_t, 9, 9> LPTIM1RST;
        bitfield_t<APB1RSTR_t, 24, 24> I2C4RST;
    } APB1RSTR;
    struct APB2RSTR_t : reg_t<uint32_t, base_address + 36>
    {
        bitfield_t<APB2RSTR_t, 0, 0> TIM1RST;
        bitfield_t<APB2RSTR_t, 1, 1> TIM8RST;
        bitfield_t<APB2RSTR_t, 4, 4> USART1RST;
        bitfield_t<APB2RSTR_t, 5, 5> USART6RST;
        bitfield_t<APB2RSTR_t, 8, 8> ADCRST;
        bitfield_t<APB2RSTR_t, 12, 12> SPI1RST;
        bitfield_t<APB2RSTR_t, 13, 13> SPI4RST;
        bitfield_t<APB2RSTR_t, 14, 14> SYSCFGRST;
        bitfield_t<APB2RSTR_t, 16, 16> TIM9RST;
        bitfield_t<APB2RSTR_t, 17, 17> TIM10RST;
        bitfield_t<APB2RSTR_t, 18, 18> TIM11RST;
        bitfield_t<APB2RSTR_t, 20, 20> SPI5RST;
        bitfield_t<APB2RSTR_t, 21, 21> SPI6RST;
        bitfield_t<APB2RSTR_t, 22, 22> SAI1RST;
        bitfield_t<APB2RSTR_t, 26, 26> LTDCRST;
        bitfield_t<APB2RSTR_t, 23, 23> SAI2RST;
        bitfield_t<APB2RSTR_t, 11, 11> SDMMC1RST;
    } APB2RSTR;
    struct AHB1ENR_t : reg_t<uint32_t, base_address + 48>
    {
        bitfield_t<AHB1ENR_t, 30, 30> OTGHSULPIEN;
        bitfield_t<AHB1ENR_t, 29, 29> OTGHSEN;
        bitfield_t<AHB1ENR_t, 28, 28> ETHMACPTPEN;
        bitfield_t<AHB1ENR_t, 27, 27> ETHMACRXEN;
        bitfield_t<AHB1ENR_t, 26, 26> ETHMACTXEN;
        bitfield_t<AHB1ENR_t, 25, 25> ETHMACEN;
        bitfield_t<AHB1ENR_t, 23, 23> DMA2DEN;
        bitfield_t<AHB1ENR_t, 22, 22> DMA2EN;
        bitfield_t<AHB1ENR_t, 21, 21> DMA1EN;
        bitfield_t<AHB1ENR_t, 20, 20> CCMDATARAMEN;
        bitfield_t<AHB1ENR_t, 18, 18> BKPSRAMEN;
        bitfield_t<AHB1ENR_t, 12, 12> CRCEN;
        bitfield_t<AHB1ENR_t, 10, 10> GPIOKEN;
        bitfield_t<AHB1ENR_t, 9, 9> GPIOJEN;
        bitfield_t<AHB1ENR_t, 8, 8> GPIOIEN;
        bitfield_t<AHB1ENR_t, 7, 7> GPIOHEN;
        bitfield_t<AHB1ENR_t, 6, 6> GPIOGEN;
        bitfield_t<AHB1ENR_t, 5, 5> GPIOFEN;
        bitfield_t<AHB1ENR_t, 4, 4> GPIOEEN;
        bitfield_t<AHB1ENR_t, 3, 3> GPIODEN;
        bitfield_t<AHB1ENR_t, 2, 2> GPIOCEN;
        bitfield_t<AHB1ENR_t, 1, 1> GPIOBEN;
        bitfield_t<AHB1ENR_t, 0, 0> GPIOAEN;
    } AHB1ENR;
    struct AHB2ENR_t : reg_t<uint32_t, base_address + 52>
    {
        bitfield_t<AHB2ENR_t, 7, 7> OTGFSEN;
        bitfield_t<AHB2ENR_t, 6, 6> RNGEN;
        bitfield_t<AHB2ENR_t, 5, 5> HASHEN;
        bitfield_t<AHB2ENR_t, 4, 4> CRYPEN;
        bitfield_t<AHB2ENR_t, 0, 0> DCMIEN;
    } AHB2ENR;
    struct AHB3ENR_t : reg_t<uint32_t, base_address + 56>
    {
        bitfield_t<AHB3ENR_t, 0, 0> FMCEN;
        bitfield_t<AHB3ENR_t, 1, 1> QSPIEN;
    } AHB3ENR;
    struct APB1ENR_t : reg_t<uint32_t, base_address + 64>
    {
        bitfield_t<APB1ENR_t, 0, 0> TIM2EN;
        bitfield_t<APB1ENR_t, 1, 1> TIM3EN;
        bitfield_t<APB1ENR_t, 2, 2> TIM4EN;
        bitfield_t<APB1ENR_t, 3, 3> TIM5EN;
        bitfield_t<APB1ENR_t, 4, 4> TIM6EN;
        bitfield_t<APB1ENR_t, 5, 5> TIM7EN;
        bitfield_t<APB1ENR_t, 6, 6> TIM12EN;
        bitfield_t<APB1ENR_t, 7, 7> TIM13EN;
        bitfield_t<APB1ENR_t, 8, 8> TIM14EN;
        bitfield_t<APB1ENR_t, 11, 11> WWDGEN;
        bitfield_t<APB1ENR_t, 14, 14> SPI2EN;
        bitfield_t<APB1ENR_t, 15, 15> SPI3EN;
        bitfield_t<APB1ENR_t, 17, 17> USART2EN;
        bitfield_t<APB1ENR_t, 18, 18> USART3EN;
        bitfield_t<APB1ENR_t, 19, 19> UART4EN;
        bitfield_t<APB1ENR_t, 20, 20> UART5EN;
        bitfield_t<APB1ENR_t, 21, 21> I2C1EN;
        bitfield_t<APB1ENR_t, 22, 22> I2C2EN;
        bitfield_t<APB1ENR_t, 23, 23> I2C3EN;
        bitfield_t<APB1ENR_t, 25, 25> CAN1EN;
        bitfield_t<APB1ENR_t, 26, 26> CAN2EN;
        bitfield_t<APB1ENR_t, 28, 28> PWREN;
        bitfield_t<APB1ENR_t, 29, 29> DACEN;
        bitfield_t<APB1ENR_t, 30, 30> UART7ENR;
        bitfield_t<APB1ENR_t, 31, 31> UART8ENR;
        bitfield_t<APB1ENR_t, 16, 16> SPDIFRXEN;
        bitfield_t<APB1ENR_t, 27, 27> CECEN;
        bitfield_t<APB1ENR_t, 9, 9> LPTMI1EN;
        bitfield_t<APB1ENR_t, 24, 24> I2C4EN;
    } APB1ENR;
    struct APB2ENR_t : reg_t<uint32_t, base_address + 68>
    {
        bitfield_t<APB2ENR_t, 0, 0> TIM1EN;
        bitfield_t<APB2ENR_t, 1, 1> TIM8EN;
        bitfield_t<APB2ENR_t, 4, 4> USART1EN;
        bitfield_t<APB2ENR_t, 5, 5> USART6EN;
        bitfield_t<APB2ENR_t, 8, 8> ADC1EN;
        bitfield_t<APB2ENR_t, 9, 9> ADC2EN;
        bitfield_t<APB2ENR_t, 10, 10> ADC3EN;
        bitfield_t<APB2ENR_t, 12, 12> SPI1EN;
        bitfield_t<APB2ENR_t, 13, 13> SPI4ENR;
        bitfield_t<APB2ENR_t, 14, 14> SYSCFGEN;
        bitfield_t<APB2ENR_t, 16, 16> TIM9EN;
        bitfield_t<APB2ENR_t, 17, 17> TIM10EN;
        bitfield_t<APB2ENR_t, 18, 18> TIM11EN;
        bitfield_t<APB2ENR_t, 20, 20> SPI5ENR;
        bitfield_t<APB2ENR_t, 21, 21> SPI6ENR;
        bitfield_t<APB2ENR_t, 22, 22> SAI1EN;
        bitfield_t<APB2ENR_t, 26, 26> LTDCEN;
        bitfield_t<APB2ENR_t, 23, 23> SAI2EN;
        bitfield_t<APB2ENR_t, 11, 11> SDMMC1EN;
    } APB2ENR;
    struct AHB1LPENR_t : reg_t<uint32_t, base_address + 80>
    {
        bitfield_t<AHB1LPENR_t, 0, 0> GPIOALPEN;
        bitfield_t<AHB1LPENR_t, 1, 1> GPIOBLPEN;
        bitfield_t<AHB1LPENR_t, 2, 2> GPIOCLPEN;
        bitfield_t<AHB1LPENR_t, 3, 3> GPIODLPEN;
        bitfield_t<AHB1LPENR_t, 4, 4> GPIOELPEN;
        bitfield_t<AHB1LPENR_t, 5, 5> GPIOFLPEN;
        bitfield_t<AHB1LPENR_t, 6, 6> GPIOGLPEN;
        bitfield_t<AHB1LPENR_t, 7, 7> GPIOHLPEN;
        bitfield_t<AHB1LPENR_t, 8, 8> GPIOILPEN;
        bitfield_t<AHB1LPENR_t, 9, 9> GPIOJLPEN;
        bitfield_t<AHB1LPENR_t, 10, 10> GPIOKLPEN;
        bitfield_t<AHB1LPENR_t, 12, 12> CRCLPEN;
        bitfield_t<AHB1LPENR_t, 15, 15> FLITFLPEN;
        bitfield_t<AHB1LPENR_t, 16, 16> SRAM1LPEN;
        bitfield_t<AHB1LPENR_t, 17, 17> SRAM2LPEN;
        bitfield_t<AHB1LPENR_t, 18, 18> BKPSRAMLPEN;
        bitfield_t<AHB1LPENR_t, 19, 19> SRAM3LPEN;
        bitfield_t<AHB1LPENR_t, 21, 21> DMA1LPEN;
        bitfield_t<AHB1LPENR_t, 22, 22> DMA2LPEN;
        bitfield_t<AHB1LPENR_t, 23, 23> DMA2DLPEN;
        bitfield_t<AHB1LPENR_t, 25, 25> ETHMACLPEN;
        bitfield_t<AHB1LPENR_t, 26, 26> ETHMACTXLPEN;
        bitfield_t<AHB1LPENR_t, 27, 27> ETHMACRXLPEN;
        bitfield_t<AHB1LPENR_t, 28, 28> ETHMACPTPLPEN;
        bitfield_t<AHB1LPENR_t, 29, 29> OTGHSLPEN;
        bitfield_t<AHB1LPENR_t, 30, 30> OTGHSULPILPEN;
    } AHB1LPENR;
    struct AHB2LPENR_t : reg_t<uint32_t, base_address + 84>
    {
        bitfield_t<AHB2LPENR_t, 7, 7> OTGFSLPEN;
        bitfield_t<AHB2LPENR_t, 6, 6> RNGLPEN;
        bitfield_t<AHB2LPENR_t, 5, 5> HASHLPEN;
        bitfield_t<AHB2LPENR_t, 4, 4> CRYPLPEN;
        bitfield_t<AHB2LPENR_t, 0, 0> DCMILPEN;
    } AHB2LPENR;
    struct AHB3LPENR_t : reg_t<uint32_t, base_address + 88>
    {
        bitfield_t<AHB3LPENR_t, 0, 0> FMCLPEN;
        bitfield_t<AHB3LPENR_t, 1, 1> QSPILPEN;
    } AHB3LPENR;
    struct APB1LPENR_t : reg_t<uint32_t, base_address + 96>
    {
        bitfield_t<APB1LPENR_t, 0, 0> TIM2LPEN;
        bitfield_t<APB1LPENR_t, 1, 1> TIM3LPEN;
        bitfield_t<APB1LPENR_t, 2, 2> TIM4LPEN;
        bitfield_t<APB1LPENR_t, 3, 3> TIM5LPEN;
        bitfield_t<APB1LPENR_t, 4, 4> TIM6LPEN;
        bitfield_t<APB1LPENR_t, 5, 5> TIM7LPEN;
        bitfield_t<APB1LPENR_t, 6, 6> TIM12LPEN;
        bitfield_t<APB1LPENR_t, 7, 7> TIM13LPEN;
        bitfield_t<APB1LPENR_t, 8, 8> TIM14LPEN;
        bitfield_t<APB1LPENR_t, 11, 11> WWDGLPEN;
        bitfield_t<APB1LPENR_t, 14, 14> SPI2LPEN;
        bitfield_t<APB1LPENR_t, 15, 15> SPI3LPEN;
        bitfield_t<APB1LPENR_t, 17, 17> USART2LPEN;
        bitfield_t<APB1LPENR_t, 18, 18> USART3LPEN;
        bitfield_t<APB1LPENR_t, 19, 19> UART4LPEN;
        bitfield_t<APB1LPENR_t, 20, 20> UART5LPEN;
        bitfield_t<APB1LPENR_t, 21, 21> I2C1LPEN;
        bitfield_t<APB1LPENR_t, 22, 22> I2C2LPEN;
        bitfield_t<APB1LPENR_t, 23, 23> I2C3LPEN;
        bitfield_t<APB1LPENR_t, 25, 25> CAN1LPEN;
        bitfield_t<APB1LPENR_t, 26, 26> CAN2LPEN;
        bitfield_t<APB1LPENR_t, 28, 28> PWRLPEN;
        bitfield_t<APB1LPENR_t, 29, 29> DACLPEN;
        bitfield_t<APB1LPENR_t, 30, 30> UART7LPEN;
        bitfield_t<APB1LPENR_t, 31, 31> UART8LPEN;
        bitfield_t<APB1LPENR_t, 16, 16> SPDIFRXLPEN;
        bitfield_t<APB1LPENR_t, 27, 27> CECLPEN;
        bitfield_t<APB1LPENR_t, 9, 9> LPTIM1LPEN;
        bitfield_t<APB1LPENR_t, 24, 24> I2C4LPEN;
    } APB1LPENR;
    struct APB2LPENR_t : reg_t<uint32_t, base_address + 100>
    {
        bitfield_t<APB2LPENR_t, 0, 0> TIM1LPEN;
        bitfield_t<APB2LPENR_t, 1, 1> TIM8LPEN;
        bitfield_t<APB2LPENR_t, 4, 4> USART1LPEN;
        bitfield_t<APB2LPENR_t, 5, 5> USART6LPEN;
        bitfield_t<APB2LPENR_t, 8, 8> ADC1LPEN;
        bitfield_t<APB2LPENR_t, 9, 9> ADC2LPEN;
        bitfield_t<APB2LPENR_t, 10, 10> ADC3LPEN;
        bitfield_t<APB2LPENR_t, 12, 12> SPI1LPEN;
        bitfield_t<APB2LPENR_t, 13, 13> SPI4LPEN;
        bitfield_t<APB2LPENR_t, 14, 14> SYSCFGLPEN;
        bitfield_t<APB2LPENR_t, 16, 16> TIM9LPEN;
        bitfield_t<APB2LPENR_t, 17, 17> TIM10LPEN;
        bitfield_t<APB2LPENR_t, 18, 18> TIM11LPEN;
        bitfield_t<APB2LPENR_t, 20, 20> SPI5LPEN;
        bitfield_t<APB2LPENR_t, 21, 21> SPI6LPEN;
        bitfield_t<APB2LPENR_t, 22, 22> SAI1LPEN;
        bitfield_t<APB2LPENR_t, 26, 26> LTDCLPEN;
        bitfield_t<APB2LPENR_t, 23, 23> SAI2LPEN;
        bitfield_t<APB2LPENR_t, 11, 11> SDMMC1LPEN;
    } APB2LPENR;
    struct BDCR_t : reg_t<uint32_t, base_address + 112>
    {
        bitfield_t<BDCR_t, 16, 16> BDRST;
        bitfield_t<BDCR_t, 15, 15> RTCEN;
        bitfield_t<BDCR_t, 9, 9> RTCSEL1;
        bitfield_t<BDCR_t, 8, 8> RTCSEL0;
        bitfield_t<BDCR_t, 2, 2> LSEBYP;
        bitfield_t<BDCR_t, 1, 1> LSERDY;
        bitfield_t<BDCR_t, 0, 0> LSEON;
    } BDCR;
    struct CSR_t : reg_t<uint32_t, base_address + 116>
    {
        bitfield_t<CSR_t, 31, 31> LPWRRSTF;
        bitfield_t<CSR_t, 30, 30> WWDGRSTF;
        bitfield_t<CSR_t, 29, 29> WDGRSTF;
        bitfield_t<CSR_t, 28, 28> SFTRSTF;
        bitfield_t<CSR_t, 27, 27> PORRSTF;
        bitfield_t<CSR_t, 26, 26> PADRSTF;
        bitfield_t<CSR_t, 25, 25> BORRSTF;
        bitfield_t<CSR_t, 24, 24> RMVF;
        bitfield_t<CSR_t, 1, 1> LSIRDY;
        bitfield_t<CSR_t, 0, 0> LSION;
    } CSR;
    struct SSCGR_t : reg_t<uint32_t, base_address + 128>
    {
        bitfield_t<SSCGR_t, 31, 31> SSCGEN;
        bitfield_t<SSCGR_t, 30, 30> SPREADSEL;
        bitfield_t<SSCGR_t, 13> INCSTEP;
        bitfield_t<SSCGR_t, 0> MODPER;
    } SSCGR;
    struct PLLI2SCFGR_t : reg_t<uint32_t, base_address + 132>
    {
        bitfield_t<PLLI2SCFGR_t, 28> PLLI2SR;
        bitfield_t<PLLI2SCFGR_t, 24> PLLI2SQ;
        bitfield_t<PLLI2SCFGR_t, 6> PLLI2SN;
    } PLLI2SCFGR;
    struct PLLSAICFGR_t : reg_t<uint32_t, base_address + 136>
    {
        bitfield_t<PLLSAICFGR_t, 6> PLLSAIN;
        bitfield_t<PLLSAICFGR_t, 16> PLLSAIP;
        bitfield_t<PLLSAICFGR_t, 24> PLLSAIQ;
        bitfield_t<PLLSAICFGR_t, 28> PLLSAIR;
    } PLLSAICFGR;
    struct DKCFGR1_t : reg_t<uint32_t, base_address + 140>
    {
        bitfield_t<DKCFGR1_t, 0> PLLI2SDIV;
        bitfield_t<DKCFGR1_t, 8> PLLSAIDIVQ;
        bitfield_t<DKCFGR1_t, 16> PLLSAIDIVR;
        bitfield_t<DKCFGR1_t, 20> SAI1SEL;
        bitfield_t<DKCFGR1_t, 22> SAI2SEL;
        bitfield_t<DKCFGR1_t, 24, 24> TIMPRE;
    } DKCFGR1;
    struct DKCFGR2_t : reg_t<uint32_t, base_address + 144>
    {
        bitfield_t<DKCFGR2_t, 0> USART1SEL;
        bitfield_t<DKCFGR2_t, 2> USART2SEL;
        bitfield_t<DKCFGR2_t, 4> USART3SEL;
        bitfield_t<DKCFGR2_t, 6> UART4SEL;
        bitfield_t<DKCFGR2_t, 8> UART5SEL;
        bitfield_t<DKCFGR2_t, 10> USART6SEL;
        bitfield_t<DKCFGR2_t, 12> UART7SEL;
        bitfield_t<DKCFGR2_t, 14> UART8SEL;
        bitfield_t<DKCFGR2_t, 16> I2C1SEL;
        bitfield_t<DKCFGR2_t, 18> I2C2SEL;
        bitfield_t<DKCFGR2_t, 20> I2C3SEL;
        bitfield_t<DKCFGR2_t, 22> I2C4SEL;
        bitfield_t<DKCFGR2_t, 24> LPTIM1SEL;
        bitfield_t<DKCFGR2_t, 26, 26> CECSEL;
        bitfield_t<DKCFGR2_t, 27, 27> CK48MSEL;
        bitfield_t<DKCFGR2_t, 28, 28> SDMMCSEL;
    } DKCFGR2;
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
