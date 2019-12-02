
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::flash
{
template <uint32_t base_address, int peripheral_index>
struct flash_t
{
    using tag = ucpp::tags::flash_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct ACR_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<ACR_t, 0, 3> LATENCY = {};
        static constexpr bitfield_t<ACR_t, 8> PRFTEN = {};
        static constexpr bitfield_t<ACR_t, 9> ARTEN = {};
        static constexpr bitfield_t<ACR_t, 11> ARTRST = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
        using reg_t<uint32_t, base_address + 0>::operator|=;
        using reg_t<uint32_t, base_address + 0>::operator&=;
    } ACR = {};
    static constexpr reg_t<uint32_t, base_address + 4> KEYR = {};
    static constexpr reg_t<uint32_t, base_address + 8> OPTKEYR = {};
    static constexpr struct SR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<SR_t, 0> EOP = {};
        static constexpr bitfield_t<SR_t, 1> OPERR = {};
        static constexpr bitfield_t<SR_t, 4> WRPERR = {};
        static constexpr bitfield_t<SR_t, 5> PGAERR = {};
        static constexpr bitfield_t<SR_t, 6> PGPERR = {};
        static constexpr bitfield_t<SR_t, 7> ERSERR = {};
        static constexpr bitfield_t<SR_t, 16> BSY = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
        using reg_t<uint32_t, base_address + 12>::operator|=;
        using reg_t<uint32_t, base_address + 12>::operator&=;
    } SR = {};
    static constexpr struct CR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<CR_t, 0> PG = {};
        static constexpr bitfield_t<CR_t, 1> SER = {};
        static constexpr bitfield_t<CR_t, 2> MER = {};
        static constexpr bitfield_t<CR_t, 3, 6> SNB = {};
        static constexpr bitfield_t<CR_t, 8, 9> PSIZE = {};
        static constexpr bitfield_t<CR_t, 16> STRT = {};
        static constexpr bitfield_t<CR_t, 24> EOPIE = {};
        static constexpr bitfield_t<CR_t, 25> ERRIE = {};
        static constexpr bitfield_t<CR_t, 31> LOCK = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
        using reg_t<uint32_t, base_address + 16>::operator|=;
        using reg_t<uint32_t, base_address + 16>::operator&=;
    } CR = {};
    static constexpr struct OPTCR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<OPTCR_t, 0> OPTLOCK = {};
        static constexpr bitfield_t<OPTCR_t, 1> OPTSTRT = {};
        static constexpr bitfield_t<OPTCR_t, 2, 3> BOR_LEV = {};
        static constexpr bitfield_t<OPTCR_t, 4> WWDG_SW = {};
        static constexpr bitfield_t<OPTCR_t, 5> IWDG_SW = {};
        static constexpr bitfield_t<OPTCR_t, 6> nRST_STOP = {};
        static constexpr bitfield_t<OPTCR_t, 7> nRST_STDBY = {};
        static constexpr bitfield_t<OPTCR_t, 8, 15> RDP = {};
        static constexpr bitfield_t<OPTCR_t, 16, 23> nWRP = {};
        static constexpr bitfield_t<OPTCR_t, 30> IWDG_STDBY = {};
        static constexpr bitfield_t<OPTCR_t, 31> IWDG_STOP = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
        using reg_t<uint32_t, base_address + 20>::operator|=;
        using reg_t<uint32_t, base_address + 20>::operator&=;
    } OPTCR = {};
    static constexpr struct OPTCR1_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<OPTCR1_t, 0, 15> BOOT_ADD0 = {};
        static constexpr bitfield_t<OPTCR1_t, 16, 31> BOOT_ADD1 = {};
        using reg_t<uint32_t, base_address + 24>::operator=;
        using reg_t<uint32_t, base_address + 24>::operator|=;
        using reg_t<uint32_t, base_address + 24>::operator&=;
    } OPTCR1 = {};
};


struct flash_c_t
{
    volatile uint32_t ACR;
    volatile uint32_t KEYR;
    volatile uint32_t OPTKEYR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t OPTCR;
    volatile uint32_t OPTCR1;
};

}
