
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::scb
{
template <uint32_t base_address, int peripheral_index>
struct scb_t
{
    using tag = ucpp::tags::scb_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct CPUID_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<CPUID_t, 0, 3> Revision = {};
        static constexpr bitfield_t<CPUID_t, 4, 15> PartNo = {};
        static constexpr bitfield_t<CPUID_t, 16, 19> Constant = {};
        static constexpr bitfield_t<CPUID_t, 20, 23> Variant = {};
        static constexpr bitfield_t<CPUID_t, 24, 31> Implementer = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
        using reg_t<uint32_t, base_address + 0>::operator|=;
        using reg_t<uint32_t, base_address + 0>::operator&=;
    } CPUID = {};
    static constexpr struct ICSR_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<ICSR_t, 0, 8> VECTACTIVE = {};
        static constexpr bitfield_t<ICSR_t, 11> RETTOBASE = {};
        static constexpr bitfield_t<ICSR_t, 12, 18> VECTPENDING = {};
        static constexpr bitfield_t<ICSR_t, 22> ISRPENDING = {};
        static constexpr bitfield_t<ICSR_t, 25> PENDSTCLR = {};
        static constexpr bitfield_t<ICSR_t, 26> PENDSTSET = {};
        static constexpr bitfield_t<ICSR_t, 27> PENDSVCLR = {};
        static constexpr bitfield_t<ICSR_t, 28> PENDSVSET = {};
        static constexpr bitfield_t<ICSR_t, 31> NMIPENDSET = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
        using reg_t<uint32_t, base_address + 4>::operator|=;
        using reg_t<uint32_t, base_address + 4>::operator&=;
    } ICSR = {};
    static constexpr struct VTOR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<VTOR_t, 9, 29> TBLOFF = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
        using reg_t<uint32_t, base_address + 8>::operator|=;
        using reg_t<uint32_t, base_address + 8>::operator&=;
    } VTOR = {};
    static constexpr struct AIRCR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<AIRCR_t, 0> VECTRESET = {};
        static constexpr bitfield_t<AIRCR_t, 1> VECTCLRACTIVE = {};
        static constexpr bitfield_t<AIRCR_t, 2> SYSRESETREQ = {};
        static constexpr bitfield_t<AIRCR_t, 8, 10> PRIGROUP = {};
        static constexpr bitfield_t<AIRCR_t, 15> ENDIANESS = {};
        static constexpr bitfield_t<AIRCR_t, 16, 31> VECTKEYSTAT = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
        using reg_t<uint32_t, base_address + 12>::operator|=;
        using reg_t<uint32_t, base_address + 12>::operator&=;
    } AIRCR = {};
    static constexpr struct SCR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<SCR_t, 1> SLEEPONEXIT = {};
        static constexpr bitfield_t<SCR_t, 2> SLEEPDEEP = {};
        static constexpr bitfield_t<SCR_t, 4> SEVEONPEND = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
        using reg_t<uint32_t, base_address + 16>::operator|=;
        using reg_t<uint32_t, base_address + 16>::operator&=;
    } SCR = {};
    static constexpr struct CCR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<CCR_t, 0> NONBASETHRDENA = {};
        static constexpr bitfield_t<CCR_t, 1> USERSETMPEND = {};
        static constexpr bitfield_t<CCR_t, 3> UNALIGN__TRP = {};
        static constexpr bitfield_t<CCR_t, 4> DIV_0_TRP = {};
        static constexpr bitfield_t<CCR_t, 8> BFHFNMIGN = {};
        static constexpr bitfield_t<CCR_t, 9> STKALIGN = {};
        static constexpr bitfield_t<CCR_t, 16> DC = {};
        static constexpr bitfield_t<CCR_t, 17> IC = {};
        static constexpr bitfield_t<CCR_t, 18> BP = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
        using reg_t<uint32_t, base_address + 20>::operator|=;
        using reg_t<uint32_t, base_address + 20>::operator&=;
    } CCR = {};
    static constexpr struct SHPR1_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<SHPR1_t, 0, 7> PRI_4 = {};
        static constexpr bitfield_t<SHPR1_t, 8, 15> PRI_5 = {};
        static constexpr bitfield_t<SHPR1_t, 16, 23> PRI_6 = {};
        using reg_t<uint32_t, base_address + 24>::operator=;
        using reg_t<uint32_t, base_address + 24>::operator|=;
        using reg_t<uint32_t, base_address + 24>::operator&=;
    } SHPR1 = {};
    static constexpr struct SHPR2_t : reg_t<uint32_t, base_address + 28>
    {
        static constexpr bitfield_t<SHPR2_t, 24, 31> PRI_11 = {};
        using reg_t<uint32_t, base_address + 28>::operator=;
        using reg_t<uint32_t, base_address + 28>::operator|=;
        using reg_t<uint32_t, base_address + 28>::operator&=;
    } SHPR2 = {};
    static constexpr struct SHPR3_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<SHPR3_t, 16, 23> PRI_14 = {};
        static constexpr bitfield_t<SHPR3_t, 24, 31> PRI_15 = {};
        using reg_t<uint32_t, base_address + 32>::operator=;
        using reg_t<uint32_t, base_address + 32>::operator|=;
        using reg_t<uint32_t, base_address + 32>::operator&=;
    } SHPR3 = {};
    static constexpr struct SHCRS_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<SHCRS_t, 0> MEMFAULTACT = {};
        static constexpr bitfield_t<SHCRS_t, 1> BUSFAULTACT = {};
        static constexpr bitfield_t<SHCRS_t, 3> USGFAULTACT = {};
        static constexpr bitfield_t<SHCRS_t, 7> SVCALLACT = {};
        static constexpr bitfield_t<SHCRS_t, 8> MONITORACT = {};
        static constexpr bitfield_t<SHCRS_t, 10> PENDSVACT = {};
        static constexpr bitfield_t<SHCRS_t, 11> SYSTICKACT = {};
        static constexpr bitfield_t<SHCRS_t, 12> USGFAULTPENDED = {};
        static constexpr bitfield_t<SHCRS_t, 13> MEMFAULTPENDED = {};
        static constexpr bitfield_t<SHCRS_t, 14> BUSFAULTPENDED = {};
        static constexpr bitfield_t<SHCRS_t, 15> SVCALLPENDED = {};
        static constexpr bitfield_t<SHCRS_t, 16> MEMFAULTENA = {};
        static constexpr bitfield_t<SHCRS_t, 17> BUSFAULTENA = {};
        static constexpr bitfield_t<SHCRS_t, 18> USGFAULTENA = {};
        using reg_t<uint32_t, base_address + 36>::operator=;
        using reg_t<uint32_t, base_address + 36>::operator|=;
        using reg_t<uint32_t, base_address + 36>::operator&=;
    } SHCRS = {};
    static constexpr struct CFSR_UFSR_BFSR_MMFSR_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 0> IACCVIOL = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 1> DACCVIOL = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 3> MUNSTKERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 4> MSTKERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 5> MLSPERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 7> MMARVALID = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 8> IBUSERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 9> PRECISERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 10> IMPRECISERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 11> UNSTKERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 12> STKERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 13> LSPERR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 15> BFARVALID = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 16> UNDEFINSTR = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 17> INVSTATE = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 18> INVPC = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 19> NOCP = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 24> UNALIGNED = {};
        static constexpr bitfield_t<CFSR_UFSR_BFSR_MMFSR_t, 25> DIVBYZERO = {};
        using reg_t<uint32_t, base_address + 40>::operator=;
        using reg_t<uint32_t, base_address + 40>::operator|=;
        using reg_t<uint32_t, base_address + 40>::operator&=;
    } CFSR_UFSR_BFSR_MMFSR = {};
    static constexpr struct HFSR_t : reg_t<uint32_t, base_address + 44>
    {
        static constexpr bitfield_t<HFSR_t, 1> VECTTBL = {};
        static constexpr bitfield_t<HFSR_t, 30> FORCED = {};
        static constexpr bitfield_t<HFSR_t, 31> DEBUG_VT = {};
        using reg_t<uint32_t, base_address + 44>::operator=;
        using reg_t<uint32_t, base_address + 44>::operator|=;
        using reg_t<uint32_t, base_address + 44>::operator&=;
    } HFSR = {};
    static constexpr reg_t<uint32_t, base_address + 52> MMFAR = {};
    static constexpr reg_t<uint32_t, base_address + 56> BFAR = {};
};


struct scb_c_t
{
    volatile uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t VTOR;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint32_t SHPR1;
    volatile uint32_t SHPR2;
    volatile uint32_t SHPR3;
    volatile uint32_t SHCRS;
    volatile uint32_t CFSR_UFSR_BFSR_MMFSR;
    volatile uint32_t HFSR;
    volatile uint32_t __dummy48;
    volatile uint32_t MMFAR;
    volatile uint32_t BFAR;
};

}
