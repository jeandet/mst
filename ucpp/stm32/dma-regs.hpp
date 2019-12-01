
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::dma
{
template <uint32_t base_address, int peripheral_index>
struct dma_t
{
    using tag = ucpp::tags::dma_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct LISR_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<LISR_t, 27> TCIF3 = {};
        static constexpr bitfield_t<LISR_t, 26> HTIF3 = {};
        static constexpr bitfield_t<LISR_t, 25> TEIF3 = {};
        static constexpr bitfield_t<LISR_t, 24> DMEIF3 = {};
        static constexpr bitfield_t<LISR_t, 22> FEIF3 = {};
        static constexpr bitfield_t<LISR_t, 21> TCIF2 = {};
        static constexpr bitfield_t<LISR_t, 20> HTIF2 = {};
        static constexpr bitfield_t<LISR_t, 19> TEIF2 = {};
        static constexpr bitfield_t<LISR_t, 18> DMEIF2 = {};
        static constexpr bitfield_t<LISR_t, 16> FEIF2 = {};
        static constexpr bitfield_t<LISR_t, 11> TCIF1 = {};
        static constexpr bitfield_t<LISR_t, 10> HTIF1 = {};
        static constexpr bitfield_t<LISR_t, 9> TEIF1 = {};
        static constexpr bitfield_t<LISR_t, 8> DMEIF1 = {};
        static constexpr bitfield_t<LISR_t, 6> FEIF1 = {};
        static constexpr bitfield_t<LISR_t, 5> TCIF0 = {};
        static constexpr bitfield_t<LISR_t, 4> HTIF0 = {};
        static constexpr bitfield_t<LISR_t, 3> TEIF0 = {};
        static constexpr bitfield_t<LISR_t, 2> DMEIF0 = {};
        static constexpr bitfield_t<LISR_t, 0> FEIF0 = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
        using reg_t<uint32_t, base_address + 0>::operator|=;
        using reg_t<uint32_t, base_address + 0>::operator&=;
    } LISR = {};
    static constexpr struct HISR_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<HISR_t, 27> TCIF7 = {};
        static constexpr bitfield_t<HISR_t, 26> HTIF7 = {};
        static constexpr bitfield_t<HISR_t, 25> TEIF7 = {};
        static constexpr bitfield_t<HISR_t, 24> DMEIF7 = {};
        static constexpr bitfield_t<HISR_t, 22> FEIF7 = {};
        static constexpr bitfield_t<HISR_t, 21> TCIF6 = {};
        static constexpr bitfield_t<HISR_t, 20> HTIF6 = {};
        static constexpr bitfield_t<HISR_t, 19> TEIF6 = {};
        static constexpr bitfield_t<HISR_t, 18> DMEIF6 = {};
        static constexpr bitfield_t<HISR_t, 16> FEIF6 = {};
        static constexpr bitfield_t<HISR_t, 11> TCIF5 = {};
        static constexpr bitfield_t<HISR_t, 10> HTIF5 = {};
        static constexpr bitfield_t<HISR_t, 9> TEIF5 = {};
        static constexpr bitfield_t<HISR_t, 8> DMEIF5 = {};
        static constexpr bitfield_t<HISR_t, 6> FEIF5 = {};
        static constexpr bitfield_t<HISR_t, 5> TCIF4 = {};
        static constexpr bitfield_t<HISR_t, 4> HTIF4 = {};
        static constexpr bitfield_t<HISR_t, 3> TEIF4 = {};
        static constexpr bitfield_t<HISR_t, 2> DMEIF4 = {};
        static constexpr bitfield_t<HISR_t, 0> FEIF4 = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
        using reg_t<uint32_t, base_address + 4>::operator|=;
        using reg_t<uint32_t, base_address + 4>::operator&=;
    } HISR = {};
    static constexpr struct LIFCR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<LIFCR_t, 27> CTCIF3 = {};
        static constexpr bitfield_t<LIFCR_t, 26> CHTIF3 = {};
        static constexpr bitfield_t<LIFCR_t, 25> CTEIF3 = {};
        static constexpr bitfield_t<LIFCR_t, 24> CDMEIF3 = {};
        static constexpr bitfield_t<LIFCR_t, 22> CFEIF3 = {};
        static constexpr bitfield_t<LIFCR_t, 21> CTCIF2 = {};
        static constexpr bitfield_t<LIFCR_t, 20> CHTIF2 = {};
        static constexpr bitfield_t<LIFCR_t, 19> CTEIF2 = {};
        static constexpr bitfield_t<LIFCR_t, 18> CDMEIF2 = {};
        static constexpr bitfield_t<LIFCR_t, 16> CFEIF2 = {};
        static constexpr bitfield_t<LIFCR_t, 11> CTCIF1 = {};
        static constexpr bitfield_t<LIFCR_t, 10> CHTIF1 = {};
        static constexpr bitfield_t<LIFCR_t, 9> CTEIF1 = {};
        static constexpr bitfield_t<LIFCR_t, 8> CDMEIF1 = {};
        static constexpr bitfield_t<LIFCR_t, 6> CFEIF1 = {};
        static constexpr bitfield_t<LIFCR_t, 5> CTCIF0 = {};
        static constexpr bitfield_t<LIFCR_t, 4> CHTIF0 = {};
        static constexpr bitfield_t<LIFCR_t, 3> CTEIF0 = {};
        static constexpr bitfield_t<LIFCR_t, 2> CDMEIF0 = {};
        static constexpr bitfield_t<LIFCR_t, 0> CFEIF0 = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
        using reg_t<uint32_t, base_address + 8>::operator|=;
        using reg_t<uint32_t, base_address + 8>::operator&=;
    } LIFCR = {};
    static constexpr struct HIFCR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<HIFCR_t, 27> CTCIF7 = {};
        static constexpr bitfield_t<HIFCR_t, 26> CHTIF7 = {};
        static constexpr bitfield_t<HIFCR_t, 25> CTEIF7 = {};
        static constexpr bitfield_t<HIFCR_t, 24> CDMEIF7 = {};
        static constexpr bitfield_t<HIFCR_t, 22> CFEIF7 = {};
        static constexpr bitfield_t<HIFCR_t, 21> CTCIF6 = {};
        static constexpr bitfield_t<HIFCR_t, 20> CHTIF6 = {};
        static constexpr bitfield_t<HIFCR_t, 19> CTEIF6 = {};
        static constexpr bitfield_t<HIFCR_t, 18> CDMEIF6 = {};
        static constexpr bitfield_t<HIFCR_t, 16> CFEIF6 = {};
        static constexpr bitfield_t<HIFCR_t, 11> CTCIF5 = {};
        static constexpr bitfield_t<HIFCR_t, 10> CHTIF5 = {};
        static constexpr bitfield_t<HIFCR_t, 9> CTEIF5 = {};
        static constexpr bitfield_t<HIFCR_t, 8> CDMEIF5 = {};
        static constexpr bitfield_t<HIFCR_t, 6> CFEIF5 = {};
        static constexpr bitfield_t<HIFCR_t, 5> CTCIF4 = {};
        static constexpr bitfield_t<HIFCR_t, 4> CHTIF4 = {};
        static constexpr bitfield_t<HIFCR_t, 3> CTEIF4 = {};
        static constexpr bitfield_t<HIFCR_t, 2> CDMEIF4 = {};
        static constexpr bitfield_t<HIFCR_t, 0> CFEIF4 = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
        using reg_t<uint32_t, base_address + 12>::operator|=;
        using reg_t<uint32_t, base_address + 12>::operator&=;
    } HIFCR = {};
    static constexpr struct S0CR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<S0CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S0CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S0CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S0CR_t, 19> CT = {};
        static constexpr bitfield_t<S0CR_t, 18> DBM = {};
        static constexpr bitfield_t<S0CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S0CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S0CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S0CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S0CR_t, 10> MINC = {};
        static constexpr bitfield_t<S0CR_t, 9> PINC = {};
        static constexpr bitfield_t<S0CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S0CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S0CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S0CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S0CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S0CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S0CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S0CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
        using reg_t<uint32_t, base_address + 16>::operator|=;
        using reg_t<uint32_t, base_address + 16>::operator&=;
    } S0CR = {};
    static constexpr struct S0NDTR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<S0NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
        using reg_t<uint32_t, base_address + 20>::operator|=;
        using reg_t<uint32_t, base_address + 20>::operator&=;
    } S0NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 24> S0PAR = {};
    static constexpr reg_t<uint32_t, base_address + 28> S0M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 32> S0M1AR = {};
    static constexpr struct S0FCR_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<S0FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S0FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S0FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S0FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 36>::operator=;
        using reg_t<uint32_t, base_address + 36>::operator|=;
        using reg_t<uint32_t, base_address + 36>::operator&=;
    } S0FCR = {};
    static constexpr struct S1CR_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<S1CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S1CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S1CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S1CR_t, 20> ACK = {};
        static constexpr bitfield_t<S1CR_t, 19> CT = {};
        static constexpr bitfield_t<S1CR_t, 18> DBM = {};
        static constexpr bitfield_t<S1CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S1CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S1CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S1CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S1CR_t, 10> MINC = {};
        static constexpr bitfield_t<S1CR_t, 9> PINC = {};
        static constexpr bitfield_t<S1CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S1CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S1CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S1CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S1CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S1CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S1CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S1CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 40>::operator=;
        using reg_t<uint32_t, base_address + 40>::operator|=;
        using reg_t<uint32_t, base_address + 40>::operator&=;
    } S1CR = {};
    static constexpr struct S1NDTR_t : reg_t<uint32_t, base_address + 44>
    {
        static constexpr bitfield_t<S1NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 44>::operator=;
        using reg_t<uint32_t, base_address + 44>::operator|=;
        using reg_t<uint32_t, base_address + 44>::operator&=;
    } S1NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 48> S1PAR = {};
    static constexpr reg_t<uint32_t, base_address + 52> S1M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 56> S1M1AR = {};
    static constexpr struct S1FCR_t : reg_t<uint32_t, base_address + 60>
    {
        static constexpr bitfield_t<S1FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S1FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S1FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S1FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 60>::operator=;
        using reg_t<uint32_t, base_address + 60>::operator|=;
        using reg_t<uint32_t, base_address + 60>::operator&=;
    } S1FCR = {};
    static constexpr struct S2CR_t : reg_t<uint32_t, base_address + 64>
    {
        static constexpr bitfield_t<S2CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S2CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S2CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S2CR_t, 20> ACK = {};
        static constexpr bitfield_t<S2CR_t, 19> CT = {};
        static constexpr bitfield_t<S2CR_t, 18> DBM = {};
        static constexpr bitfield_t<S2CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S2CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S2CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S2CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S2CR_t, 10> MINC = {};
        static constexpr bitfield_t<S2CR_t, 9> PINC = {};
        static constexpr bitfield_t<S2CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S2CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S2CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S2CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S2CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S2CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S2CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S2CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 64>::operator=;
        using reg_t<uint32_t, base_address + 64>::operator|=;
        using reg_t<uint32_t, base_address + 64>::operator&=;
    } S2CR = {};
    static constexpr struct S2NDTR_t : reg_t<uint32_t, base_address + 68>
    {
        static constexpr bitfield_t<S2NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 68>::operator=;
        using reg_t<uint32_t, base_address + 68>::operator|=;
        using reg_t<uint32_t, base_address + 68>::operator&=;
    } S2NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 72> S2PAR = {};
    static constexpr reg_t<uint32_t, base_address + 76> S2M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 80> S2M1AR = {};
    static constexpr struct S2FCR_t : reg_t<uint32_t, base_address + 84>
    {
        static constexpr bitfield_t<S2FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S2FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S2FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S2FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 84>::operator=;
        using reg_t<uint32_t, base_address + 84>::operator|=;
        using reg_t<uint32_t, base_address + 84>::operator&=;
    } S2FCR = {};
    static constexpr struct S3CR_t : reg_t<uint32_t, base_address + 88>
    {
        static constexpr bitfield_t<S3CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S3CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S3CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S3CR_t, 20> ACK = {};
        static constexpr bitfield_t<S3CR_t, 19> CT = {};
        static constexpr bitfield_t<S3CR_t, 18> DBM = {};
        static constexpr bitfield_t<S3CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S3CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S3CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S3CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S3CR_t, 10> MINC = {};
        static constexpr bitfield_t<S3CR_t, 9> PINC = {};
        static constexpr bitfield_t<S3CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S3CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S3CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S3CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S3CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S3CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S3CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S3CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 88>::operator=;
        using reg_t<uint32_t, base_address + 88>::operator|=;
        using reg_t<uint32_t, base_address + 88>::operator&=;
    } S3CR = {};
    static constexpr struct S3NDTR_t : reg_t<uint32_t, base_address + 92>
    {
        static constexpr bitfield_t<S3NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 92>::operator=;
        using reg_t<uint32_t, base_address + 92>::operator|=;
        using reg_t<uint32_t, base_address + 92>::operator&=;
    } S3NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 96> S3PAR = {};
    static constexpr reg_t<uint32_t, base_address + 100> S3M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 104> S3M1AR = {};
    static constexpr struct S3FCR_t : reg_t<uint32_t, base_address + 108>
    {
        static constexpr bitfield_t<S3FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S3FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S3FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S3FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 108>::operator=;
        using reg_t<uint32_t, base_address + 108>::operator|=;
        using reg_t<uint32_t, base_address + 108>::operator&=;
    } S3FCR = {};
    static constexpr struct S4CR_t : reg_t<uint32_t, base_address + 112>
    {
        static constexpr bitfield_t<S4CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S4CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S4CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S4CR_t, 20> ACK = {};
        static constexpr bitfield_t<S4CR_t, 19> CT = {};
        static constexpr bitfield_t<S4CR_t, 18> DBM = {};
        static constexpr bitfield_t<S4CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S4CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S4CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S4CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S4CR_t, 10> MINC = {};
        static constexpr bitfield_t<S4CR_t, 9> PINC = {};
        static constexpr bitfield_t<S4CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S4CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S4CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S4CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S4CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S4CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S4CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S4CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 112>::operator=;
        using reg_t<uint32_t, base_address + 112>::operator|=;
        using reg_t<uint32_t, base_address + 112>::operator&=;
    } S4CR = {};
    static constexpr struct S4NDTR_t : reg_t<uint32_t, base_address + 116>
    {
        static constexpr bitfield_t<S4NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 116>::operator=;
        using reg_t<uint32_t, base_address + 116>::operator|=;
        using reg_t<uint32_t, base_address + 116>::operator&=;
    } S4NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 120> S4PAR = {};
    static constexpr reg_t<uint32_t, base_address + 124> S4M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 128> S4M1AR = {};
    static constexpr struct S4FCR_t : reg_t<uint32_t, base_address + 132>
    {
        static constexpr bitfield_t<S4FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S4FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S4FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S4FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 132>::operator=;
        using reg_t<uint32_t, base_address + 132>::operator|=;
        using reg_t<uint32_t, base_address + 132>::operator&=;
    } S4FCR = {};
    static constexpr struct S5CR_t : reg_t<uint32_t, base_address + 136>
    {
        static constexpr bitfield_t<S5CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S5CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S5CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S5CR_t, 20> ACK = {};
        static constexpr bitfield_t<S5CR_t, 19> CT = {};
        static constexpr bitfield_t<S5CR_t, 18> DBM = {};
        static constexpr bitfield_t<S5CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S5CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S5CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S5CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S5CR_t, 10> MINC = {};
        static constexpr bitfield_t<S5CR_t, 9> PINC = {};
        static constexpr bitfield_t<S5CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S5CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S5CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S5CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S5CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S5CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S5CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S5CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 136>::operator=;
        using reg_t<uint32_t, base_address + 136>::operator|=;
        using reg_t<uint32_t, base_address + 136>::operator&=;
    } S5CR = {};
    static constexpr struct S5NDTR_t : reg_t<uint32_t, base_address + 140>
    {
        static constexpr bitfield_t<S5NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 140>::operator=;
        using reg_t<uint32_t, base_address + 140>::operator|=;
        using reg_t<uint32_t, base_address + 140>::operator&=;
    } S5NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 144> S5PAR = {};
    static constexpr reg_t<uint32_t, base_address + 148> S5M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 152> S5M1AR = {};
    static constexpr struct S5FCR_t : reg_t<uint32_t, base_address + 156>
    {
        static constexpr bitfield_t<S5FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S5FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S5FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S5FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 156>::operator=;
        using reg_t<uint32_t, base_address + 156>::operator|=;
        using reg_t<uint32_t, base_address + 156>::operator&=;
    } S5FCR = {};
    static constexpr struct S6CR_t : reg_t<uint32_t, base_address + 160>
    {
        static constexpr bitfield_t<S6CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S6CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S6CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S6CR_t, 20> ACK = {};
        static constexpr bitfield_t<S6CR_t, 19> CT = {};
        static constexpr bitfield_t<S6CR_t, 18> DBM = {};
        static constexpr bitfield_t<S6CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S6CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S6CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S6CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S6CR_t, 10> MINC = {};
        static constexpr bitfield_t<S6CR_t, 9> PINC = {};
        static constexpr bitfield_t<S6CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S6CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S6CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S6CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S6CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S6CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S6CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S6CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 160>::operator=;
        using reg_t<uint32_t, base_address + 160>::operator|=;
        using reg_t<uint32_t, base_address + 160>::operator&=;
    } S6CR = {};
    static constexpr struct S6NDTR_t : reg_t<uint32_t, base_address + 164>
    {
        static constexpr bitfield_t<S6NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 164>::operator=;
        using reg_t<uint32_t, base_address + 164>::operator|=;
        using reg_t<uint32_t, base_address + 164>::operator&=;
    } S6NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 168> S6PAR = {};
    static constexpr reg_t<uint32_t, base_address + 172> S6M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 176> S6M1AR = {};
    static constexpr struct S6FCR_t : reg_t<uint32_t, base_address + 180>
    {
        static constexpr bitfield_t<S6FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S6FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S6FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S6FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 180>::operator=;
        using reg_t<uint32_t, base_address + 180>::operator|=;
        using reg_t<uint32_t, base_address + 180>::operator&=;
    } S6FCR = {};
    static constexpr struct S7CR_t : reg_t<uint32_t, base_address + 184>
    {
        static constexpr bitfield_t<S7CR_t, 25, 27> CHSEL = {};
        static constexpr bitfield_t<S7CR_t, 23, 24> MBURST = {};
        static constexpr bitfield_t<S7CR_t, 21, 22> PBURST = {};
        static constexpr bitfield_t<S7CR_t, 20> ACK = {};
        static constexpr bitfield_t<S7CR_t, 19> CT = {};
        static constexpr bitfield_t<S7CR_t, 18> DBM = {};
        static constexpr bitfield_t<S7CR_t, 16, 17> PL = {};
        static constexpr bitfield_t<S7CR_t, 15> PINCOS = {};
        static constexpr bitfield_t<S7CR_t, 13, 14> MSIZE = {};
        static constexpr bitfield_t<S7CR_t, 11, 12> PSIZE = {};
        static constexpr bitfield_t<S7CR_t, 10> MINC = {};
        static constexpr bitfield_t<S7CR_t, 9> PINC = {};
        static constexpr bitfield_t<S7CR_t, 8> CIRC = {};
        static constexpr bitfield_t<S7CR_t, 6, 7> DIR = {};
        static constexpr bitfield_t<S7CR_t, 5> PFCTRL = {};
        static constexpr bitfield_t<S7CR_t, 4> TCIE = {};
        static constexpr bitfield_t<S7CR_t, 3> HTIE = {};
        static constexpr bitfield_t<S7CR_t, 2> TEIE = {};
        static constexpr bitfield_t<S7CR_t, 1> DMEIE = {};
        static constexpr bitfield_t<S7CR_t, 0> EN = {};
        using reg_t<uint32_t, base_address + 184>::operator=;
        using reg_t<uint32_t, base_address + 184>::operator|=;
        using reg_t<uint32_t, base_address + 184>::operator&=;
    } S7CR = {};
    static constexpr struct S7NDTR_t : reg_t<uint32_t, base_address + 188>
    {
        static constexpr bitfield_t<S7NDTR_t, 0, 15> NDT = {};
        using reg_t<uint32_t, base_address + 188>::operator=;
        using reg_t<uint32_t, base_address + 188>::operator|=;
        using reg_t<uint32_t, base_address + 188>::operator&=;
    } S7NDTR = {};
    static constexpr reg_t<uint32_t, base_address + 192> S7PAR = {};
    static constexpr reg_t<uint32_t, base_address + 196> S7M0AR = {};
    static constexpr reg_t<uint32_t, base_address + 200> S7M1AR = {};
    static constexpr struct S7FCR_t : reg_t<uint32_t, base_address + 204>
    {
        static constexpr bitfield_t<S7FCR_t, 7> FEIE = {};
        static constexpr bitfield_t<S7FCR_t, 3, 5> FS = {};
        static constexpr bitfield_t<S7FCR_t, 2> DMDIS = {};
        static constexpr bitfield_t<S7FCR_t, 0, 1> FTH = {};
        using reg_t<uint32_t, base_address + 204>::operator=;
        using reg_t<uint32_t, base_address + 204>::operator|=;
        using reg_t<uint32_t, base_address + 204>::operator&=;
    } S7FCR = {};
};


struct dma_c_t
{
    volatile uint32_t LISR;
    volatile uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;
    volatile uint32_t S0CR;
    volatile uint32_t S0NDTR;
    volatile uint32_t S0PAR;
    volatile uint32_t S0M0AR;
    volatile uint32_t S0M1AR;
    volatile uint32_t S0FCR;
    volatile uint32_t S1CR;
    volatile uint32_t S1NDTR;
    volatile uint32_t S1PAR;
    volatile uint32_t S1M0AR;
    volatile uint32_t S1M1AR;
    volatile uint32_t S1FCR;
    volatile uint32_t S2CR;
    volatile uint32_t S2NDTR;
    volatile uint32_t S2PAR;
    volatile uint32_t S2M0AR;
    volatile uint32_t S2M1AR;
    volatile uint32_t S2FCR;
    volatile uint32_t S3CR;
    volatile uint32_t S3NDTR;
    volatile uint32_t S3PAR;
    volatile uint32_t S3M0AR;
    volatile uint32_t S3M1AR;
    volatile uint32_t S3FCR;
    volatile uint32_t S4CR;
    volatile uint32_t S4NDTR;
    volatile uint32_t S4PAR;
    volatile uint32_t S4M0AR;
    volatile uint32_t S4M1AR;
    volatile uint32_t S4FCR;
    volatile uint32_t S5CR;
    volatile uint32_t S5NDTR;
    volatile uint32_t S5PAR;
    volatile uint32_t S5M0AR;
    volatile uint32_t S5M1AR;
    volatile uint32_t S5FCR;
    volatile uint32_t S6CR;
    volatile uint32_t S6NDTR;
    volatile uint32_t S6PAR;
    volatile uint32_t S6M0AR;
    volatile uint32_t S6M1AR;
    volatile uint32_t S6FCR;
    volatile uint32_t S7CR;
    volatile uint32_t S7NDTR;
    volatile uint32_t S7PAR;
    volatile uint32_t S7M0AR;
    volatile uint32_t S7M1AR;
    volatile uint32_t S7FCR;
};

}
