
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::spi
{
template <uint32_t base_address, int peripheral_index>
struct spi_t
{
    using tag = ucpp::tags::spi_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct CR1_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<CR1_t, 15> BIDIMODE = {};
        static constexpr bitfield_t<CR1_t, 14> BIDIOE = {};
        static constexpr bitfield_t<CR1_t, 13> CRCEN = {};
        static constexpr bitfield_t<CR1_t, 12> CRCNEXT = {};
        static constexpr bitfield_t<CR1_t, 11> CRCL = {};
        static constexpr bitfield_t<CR1_t, 10> RXONLY = {};
        static constexpr bitfield_t<CR1_t, 9> SSM = {};
        static constexpr bitfield_t<CR1_t, 8> SSI = {};
        static constexpr bitfield_t<CR1_t, 7> LSBFIRST = {};
        static constexpr bitfield_t<CR1_t, 6> SPE = {};
        static constexpr bitfield_t<CR1_t, 3, 5> BR = {};
        static constexpr bitfield_t<CR1_t, 2> MSTR = {};
        static constexpr bitfield_t<CR1_t, 1> CPOL = {};
        static constexpr bitfield_t<CR1_t, 0> CPHA = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
        using reg_t<uint32_t, base_address + 0>::operator|=;
        using reg_t<uint32_t, base_address + 0>::operator&=;
    } CR1 = {};
    static constexpr struct CR2_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<CR2_t, 0> RXDMAEN = {};
        static constexpr bitfield_t<CR2_t, 1> TXDMAEN = {};
        static constexpr bitfield_t<CR2_t, 2> SSOE = {};
        static constexpr bitfield_t<CR2_t, 3> NSSP = {};
        static constexpr bitfield_t<CR2_t, 4> FRF = {};
        static constexpr bitfield_t<CR2_t, 5> ERRIE = {};
        static constexpr bitfield_t<CR2_t, 6> RXNEIE = {};
        static constexpr bitfield_t<CR2_t, 7> TXEIE = {};
        static constexpr bitfield_t<CR2_t, 8, 11> DS = {};
        static constexpr bitfield_t<CR2_t, 12> FRXTH = {};
        static constexpr bitfield_t<CR2_t, 13> LDMA_RX = {};
        static constexpr bitfield_t<CR2_t, 14> LDMA_TX = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
        using reg_t<uint32_t, base_address + 4>::operator|=;
        using reg_t<uint32_t, base_address + 4>::operator&=;
    } CR2 = {};
    static constexpr struct SR_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<SR_t, 8> FRE = {};
        static constexpr bitfield_t<SR_t, 7> BSY = {};
        static constexpr bitfield_t<SR_t, 6> OVR = {};
        static constexpr bitfield_t<SR_t, 5> MODF = {};
        static constexpr bitfield_t<SR_t, 4> CRCERR = {};
        static constexpr bitfield_t<SR_t, 3> UDR = {};
        static constexpr bitfield_t<SR_t, 2> CHSIDE = {};
        static constexpr bitfield_t<SR_t, 1> TXE = {};
        static constexpr bitfield_t<SR_t, 0> RXNE = {};
        static constexpr bitfield_t<SR_t, 9, 10> FRLVL = {};
        static constexpr bitfield_t<SR_t, 11, 12> FTLVL = {};
        using reg_t<uint32_t, base_address + 8>::operator=;
        using reg_t<uint32_t, base_address + 8>::operator|=;
        using reg_t<uint32_t, base_address + 8>::operator&=;
    } SR = {};
    static constexpr struct DR_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<DR_t, 0, 15> DR = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
        using reg_t<uint32_t, base_address + 12>::operator|=;
        using reg_t<uint32_t, base_address + 12>::operator&=;
    } DR = {};
    static constexpr struct CRCPR_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<CRCPR_t, 0, 15> CRCPOLY = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
        using reg_t<uint32_t, base_address + 16>::operator|=;
        using reg_t<uint32_t, base_address + 16>::operator&=;
    } CRCPR = {};
    static constexpr struct RXCRCR_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<RXCRCR_t, 0, 15> RxCRC = {};
        using reg_t<uint32_t, base_address + 20>::operator=;
        using reg_t<uint32_t, base_address + 20>::operator|=;
        using reg_t<uint32_t, base_address + 20>::operator&=;
    } RXCRCR = {};
    static constexpr struct TXCRCR_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<TXCRCR_t, 0, 15> TxCRC = {};
        using reg_t<uint32_t, base_address + 24>::operator=;
        using reg_t<uint32_t, base_address + 24>::operator|=;
        using reg_t<uint32_t, base_address + 24>::operator&=;
    } TXCRCR = {};
    static constexpr struct I2SCFGR_t : reg_t<uint32_t, base_address + 28>
    {
        static constexpr bitfield_t<I2SCFGR_t, 11> I2SMOD = {};
        static constexpr bitfield_t<I2SCFGR_t, 10> I2SE = {};
        static constexpr bitfield_t<I2SCFGR_t, 8, 9> I2SCFG = {};
        static constexpr bitfield_t<I2SCFGR_t, 7> PCMSYNC = {};
        static constexpr bitfield_t<I2SCFGR_t, 4, 5> I2SSTD = {};
        static constexpr bitfield_t<I2SCFGR_t, 3> CKPOL = {};
        static constexpr bitfield_t<I2SCFGR_t, 1, 2> DATLEN = {};
        static constexpr bitfield_t<I2SCFGR_t, 0> CHLEN = {};
        static constexpr bitfield_t<I2SCFGR_t, 12> ASTRTEN = {};
        using reg_t<uint32_t, base_address + 28>::operator=;
        using reg_t<uint32_t, base_address + 28>::operator|=;
        using reg_t<uint32_t, base_address + 28>::operator&=;
    } I2SCFGR = {};
    static constexpr struct I2SPR_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<I2SPR_t, 9> MCKOE = {};
        static constexpr bitfield_t<I2SPR_t, 8> ODD = {};
        static constexpr bitfield_t<I2SPR_t, 0, 7> I2SDIV = {};
        using reg_t<uint32_t, base_address + 32>::operator=;
        using reg_t<uint32_t, base_address + 32>::operator|=;
        using reg_t<uint32_t, base_address + 32>::operator&=;
    } I2SPR = {};
};


struct spi_c_t
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;
};

}
