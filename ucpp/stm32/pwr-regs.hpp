
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::pwr
{
template <uint32_t base_address, int peripheral_index>
struct pwr_t
{
    using tag = ucpp::tags::pwr_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct CR1_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<CR1_t, 0> LPDS = {};
        static constexpr bitfield_t<CR1_t, 1> PDDS = {};
        static constexpr bitfield_t<CR1_t, 3> CSBF = {};
        static constexpr bitfield_t<CR1_t, 4> PVDE = {};
        static constexpr bitfield_t<CR1_t, 5, 7> PLS = {};
        static constexpr bitfield_t<CR1_t, 8> DBP = {};
        static constexpr bitfield_t<CR1_t, 9> FPDS = {};
        static constexpr bitfield_t<CR1_t, 10> LPUDS = {};
        static constexpr bitfield_t<CR1_t, 11> MRUDS = {};
        static constexpr bitfield_t<CR1_t, 13> ADCDC1 = {};
        static constexpr bitfield_t<CR1_t, 14, 15> VOS = {};
        static constexpr bitfield_t<CR1_t, 16> ODEN = {};
        static constexpr bitfield_t<CR1_t, 17> ODSWEN = {};
        static constexpr bitfield_t<CR1_t, 18, 19> UDEN = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
        using reg_t<uint32_t, base_address + 0>::operator|=;
        using reg_t<uint32_t, base_address + 0>::operator&=;
    } CR1 = {};
    static constexpr struct CSR1_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<CSR1_t, 0> WUIF = {};
        static constexpr bitfield_t<CSR1_t, 1> SBF = {};
        static constexpr bitfield_t<CSR1_t, 2> PVDO = {};
        static constexpr bitfield_t<CSR1_t, 3> BRR = {};
        static constexpr bitfield_t<CSR1_t, 9> BRE = {};
        static constexpr bitfield_t<CSR1_t, 14> VOSRDY = {};
        static constexpr bitfield_t<CSR1_t, 16> ODRDY = {};
        static constexpr bitfield_t<CSR1_t, 17> ODSWRDY = {};
        static constexpr bitfield_t<CSR1_t, 18, 19> UDRDY = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
        using reg_t<uint32_t, base_address + 4>::operator|=;
        using reg_t<uint32_t, base_address + 4>::operator&=;
    } CSR1 = {};
    static constexpr struct CR2_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<CR2_t, 0> CWUPF1 = {};
        static constexpr bitfield_t<CR2_t, 1> CWUPF2 = {};
        static constexpr bitfield_t<CR2_t, 2> CWUPF3 = {};
        static constexpr bitfield_t<CR2_t, 3> CWUPF4 = {};
        static constexpr bitfield_t<CR2_t, 4> CWUPF5 = {};
        static constexpr bitfield_t<CR2_t, 5> CWUPF6 = {};
        static constexpr bitfield_t<CR2_t, 8> WUPP1 = {};
        static constexpr bitfield_t<CR2_t, 9> WUPP2 = {};
        static constexpr bitfield_t<CR2_t, 10> WUPP3 = {};
        static constexpr bitfield_t<CR2_t, 11> WUPP4 = {};
        static constexpr bitfield_t<CR2_t, 12> WUPP5 = {};
        static constexpr bitfield_t<CR2_t, 13> WUPP6 = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
        using reg_t<uint32_t, base_address + 8>::operator|=;
        using reg_t<uint32_t, base_address + 8>::operator&=;
    } CR2 = {};
    static constexpr struct CSR2_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<CSR2_t, 0> WUPF1 = {};
        static constexpr bitfield_t<CSR2_t, 1> WUPF2 = {};
        static constexpr bitfield_t<CSR2_t, 2> WUPF3 = {};
        static constexpr bitfield_t<CSR2_t, 3> WUPF4 = {};
        static constexpr bitfield_t<CSR2_t, 4> WUPF5 = {};
        static constexpr bitfield_t<CSR2_t, 5> WUPF6 = {};
        static constexpr bitfield_t<CSR2_t, 8> EWUP1 = {};
        static constexpr bitfield_t<CSR2_t, 9> EWUP2 = {};
        static constexpr bitfield_t<CSR2_t, 10> EWUP3 = {};
        static constexpr bitfield_t<CSR2_t, 11> EWUP4 = {};
        static constexpr bitfield_t<CSR2_t, 12> EWUP5 = {};
        static constexpr bitfield_t<CSR2_t, 13> EWUP6 = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
        using reg_t<uint32_t, base_address + 12>::operator|=;
        using reg_t<uint32_t, base_address + 12>::operator&=;
    } CSR2 = {};
};


struct pwr_c_t
{
    volatile uint32_t CR1;
    volatile uint32_t CSR1;
    volatile uint32_t CR2;
    volatile uint32_t CSR2;
};

}
