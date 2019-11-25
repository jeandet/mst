
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::sdmmc
{
template <uint32_t base_address, int peripheral_index>
struct sdmmc_t
{
    using tag = ucpp::tags::sdmmc_tag;
    static constexpr int index = peripheral_index;
    static constexpr int address = base_address;
    static constexpr struct POWER_t : reg_t<uint32_t, base_address + 0>
    {
        static constexpr bitfield_t<POWER_t, 0, 1> PWRCTRL = {};
        using reg_t<uint32_t, base_address + 0>::operator=;
    } POWER = {};
    static constexpr struct CLKCR_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<CLKCR_t, 14> HWFC_EN = {};
        static constexpr bitfield_t<CLKCR_t, 13> NEGEDGE = {};
        static constexpr bitfield_t<CLKCR_t, 11, 12> WIDBUS = {};
        static constexpr bitfield_t<CLKCR_t, 10> BYPASS = {};
        static constexpr bitfield_t<CLKCR_t, 9> PWRSAV = {};
        static constexpr bitfield_t<CLKCR_t, 8> CLKEN = {};
        static constexpr bitfield_t<CLKCR_t, 0, 7> CLKDIV = {};
        using reg_t<uint32_t, base_address + 4>::operator=;
    } CLKCR = {};
    static constexpr reg_t<uint32_t, base_address + 8> ARG = {};
    static constexpr struct CMD_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<CMD_t, 14> CE_ATACMD = {};
        static constexpr bitfield_t<CMD_t, 13> nIEN = {};
        static constexpr bitfield_t<CMD_t, 12> ENCMDcompl = {};
        static constexpr bitfield_t<CMD_t, 11> SDIOSuspend = {};
        static constexpr bitfield_t<CMD_t, 10> CPSMEN = {};
        static constexpr bitfield_t<CMD_t, 9> WAITPEND = {};
        static constexpr bitfield_t<CMD_t, 8> WAITINT = {};
        static constexpr bitfield_t<CMD_t, 6, 7> WAITRESP = {};
        static constexpr bitfield_t<CMD_t, 0, 5> CMDINDEX = {};
        using reg_t<uint32_t, base_address + 12>::operator=;
    } CMD = {};
    static constexpr struct RESPCMD_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<RESPCMD_t, 0, 5> RESPCMD = {};
        using reg_t<uint32_t, base_address + 16>::operator=;
    } RESPCMD = {};
    static constexpr reg_t<uint32_t, base_address + 20> RESP1 = {};
    static constexpr reg_t<uint32_t, base_address + 24> RESP2 = {};
    static constexpr reg_t<uint32_t, base_address + 28> RESP3 = {};
    static constexpr reg_t<uint32_t, base_address + 32> RESP4 = {};
    static constexpr reg_t<uint32_t, base_address + 36> DTIMER = {};
    static constexpr struct DLEN_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<DLEN_t, 0, 24> DATALENGTH = {};
        using reg_t<uint32_t, base_address + 40>::operator=;
    } DLEN = {};
    static constexpr struct DCTRL_t : reg_t<uint32_t, base_address + 44>
    {
        static constexpr bitfield_t<DCTRL_t, 11> SDIOEN = {};
        static constexpr bitfield_t<DCTRL_t, 10> RWMOD = {};
        static constexpr bitfield_t<DCTRL_t, 9> RWSTOP = {};
        static constexpr bitfield_t<DCTRL_t, 8> RWSTART = {};
        static constexpr bitfield_t<DCTRL_t, 4, 7> DBLOCKSIZE = {};
        static constexpr bitfield_t<DCTRL_t, 3> DMAEN = {};
        static constexpr bitfield_t<DCTRL_t, 2> DTMODE = {};
        static constexpr bitfield_t<DCTRL_t, 1> DTDIR = {};
        static constexpr bitfield_t<DCTRL_t, 0> DTEN = {};
        using reg_t<uint32_t, base_address + 44>::operator=;
    } DCTRL = {};
    static constexpr struct DCOUNT_t : reg_t<uint32_t, base_address + 48>
    {
        static constexpr bitfield_t<DCOUNT_t, 0, 24> DATACOUNT = {};
        using reg_t<uint32_t, base_address + 48>::operator=;
    } DCOUNT = {};
    static constexpr struct STA_t : reg_t<uint32_t, base_address + 52>
    {
        static constexpr bitfield_t<STA_t, 23> CEATAEND = {};
        static constexpr bitfield_t<STA_t, 22> SDIOIT = {};
        static constexpr bitfield_t<STA_t, 21> RXDAVL = {};
        static constexpr bitfield_t<STA_t, 20> TXDAVL = {};
        static constexpr bitfield_t<STA_t, 19> RXFIFOE = {};
        static constexpr bitfield_t<STA_t, 18> TXFIFOE = {};
        static constexpr bitfield_t<STA_t, 17> RXFIFOF = {};
        static constexpr bitfield_t<STA_t, 16> TXFIFOF = {};
        static constexpr bitfield_t<STA_t, 15> RXFIFOHF = {};
        static constexpr bitfield_t<STA_t, 14> TXFIFOHE = {};
        static constexpr bitfield_t<STA_t, 13> RXACT = {};
        static constexpr bitfield_t<STA_t, 12> TXACT = {};
        static constexpr bitfield_t<STA_t, 11> CMDACT = {};
        static constexpr bitfield_t<STA_t, 10> DBCKEND = {};
        static constexpr bitfield_t<STA_t, 9> STBITERR = {};
        static constexpr bitfield_t<STA_t, 8> DATAEND = {};
        static constexpr bitfield_t<STA_t, 7> CMDSENT = {};
        static constexpr bitfield_t<STA_t, 6> CMDREND = {};
        static constexpr bitfield_t<STA_t, 5> RXOVERR = {};
        static constexpr bitfield_t<STA_t, 4> TXUNDERR = {};
        static constexpr bitfield_t<STA_t, 3> DTIMEOUT = {};
        static constexpr bitfield_t<STA_t, 2> CTIMEOUT = {};
        static constexpr bitfield_t<STA_t, 1> DCRCFAIL = {};
        static constexpr bitfield_t<STA_t, 0> CCRCFAIL = {};
        using reg_t<uint32_t, base_address + 52>::operator=;
    } STA = {};
    static constexpr struct ICR_t : reg_t<uint32_t, base_address + 56>
    {
        static constexpr bitfield_t<ICR_t, 23> CEATAENDC = {};
        static constexpr bitfield_t<ICR_t, 22> SDIOITC = {};
        static constexpr bitfield_t<ICR_t, 10> DBCKENDC = {};
        static constexpr bitfield_t<ICR_t, 9> STBITERRC = {};
        static constexpr bitfield_t<ICR_t, 8> DATAENDC = {};
        static constexpr bitfield_t<ICR_t, 7> CMDSENTC = {};
        static constexpr bitfield_t<ICR_t, 6> CMDRENDC = {};
        static constexpr bitfield_t<ICR_t, 5> RXOVERRC = {};
        static constexpr bitfield_t<ICR_t, 4> TXUNDERRC = {};
        static constexpr bitfield_t<ICR_t, 3> DTIMEOUTC = {};
        static constexpr bitfield_t<ICR_t, 2> CTIMEOUTC = {};
        static constexpr bitfield_t<ICR_t, 1> DCRCFAILC = {};
        static constexpr bitfield_t<ICR_t, 0> CCRCFAILC = {};
        using reg_t<uint32_t, base_address + 56>::operator=;
    } ICR = {};
    static constexpr struct MASK_t : reg_t<uint32_t, base_address + 60>
    {
        static constexpr bitfield_t<MASK_t, 23> CEATAENDIE = {};
        static constexpr bitfield_t<MASK_t, 22> SDIOITIE = {};
        static constexpr bitfield_t<MASK_t, 21> RXDAVLIE = {};
        static constexpr bitfield_t<MASK_t, 20> TXDAVLIE = {};
        static constexpr bitfield_t<MASK_t, 19> RXFIFOEIE = {};
        static constexpr bitfield_t<MASK_t, 18> TXFIFOEIE = {};
        static constexpr bitfield_t<MASK_t, 17> RXFIFOFIE = {};
        static constexpr bitfield_t<MASK_t, 16> TXFIFOFIE = {};
        static constexpr bitfield_t<MASK_t, 15> RXFIFOHFIE = {};
        static constexpr bitfield_t<MASK_t, 14> TXFIFOHEIE = {};
        static constexpr bitfield_t<MASK_t, 13> RXACTIE = {};
        static constexpr bitfield_t<MASK_t, 12> TXACTIE = {};
        static constexpr bitfield_t<MASK_t, 11> CMDACTIE = {};
        static constexpr bitfield_t<MASK_t, 10> DBCKENDIE = {};
        static constexpr bitfield_t<MASK_t, 9> STBITERRIE = {};
        static constexpr bitfield_t<MASK_t, 8> DATAENDIE = {};
        static constexpr bitfield_t<MASK_t, 7> CMDSENTIE = {};
        static constexpr bitfield_t<MASK_t, 6> CMDRENDIE = {};
        static constexpr bitfield_t<MASK_t, 5> RXOVERRIE = {};
        static constexpr bitfield_t<MASK_t, 4> TXUNDERRIE = {};
        static constexpr bitfield_t<MASK_t, 3> DTIMEOUTIE = {};
        static constexpr bitfield_t<MASK_t, 2> CTIMEOUTIE = {};
        static constexpr bitfield_t<MASK_t, 1> DCRCFAILIE = {};
        static constexpr bitfield_t<MASK_t, 0> CCRCFAILIE = {};
        using reg_t<uint32_t, base_address + 60>::operator=;
    } MASK = {};
    static constexpr struct FIFOCNT_t : reg_t<uint32_t, base_address + 72>
    {
        static constexpr bitfield_t<FIFOCNT_t, 0, 23> FIFOCOUNT = {};
        using reg_t<uint32_t, base_address + 72>::operator=;
    } FIFOCNT = {};
    static constexpr reg_t<uint32_t, base_address + 128> FIFO = {};
};


struct sdmmc_c_t
{
    volatile uint32_t POWER;
    volatile uint32_t CLKCR;
    volatile uint32_t ARG;
    volatile uint32_t CMD;
    volatile uint32_t RESPCMD;
    volatile uint32_t RESP1;
    volatile uint32_t RESP2;
    volatile uint32_t RESP3;
    volatile uint32_t RESP4;
    volatile uint32_t DTIMER;
    volatile uint32_t DLEN;
    volatile uint32_t DCTRL;
    volatile uint32_t DCOUNT;
    volatile uint32_t STA;
    volatile uint32_t ICR;
    volatile uint32_t MASK;
    volatile uint32_t __dummy64;
    volatile uint32_t __dummy68;
    volatile uint32_t FIFOCNT;
    volatile uint32_t __dummy76;
    volatile uint32_t __dummy80;
    volatile uint32_t __dummy84;
    volatile uint32_t __dummy88;
    volatile uint32_t __dummy92;
    volatile uint32_t __dummy96;
    volatile uint32_t __dummy100;
    volatile uint32_t __dummy104;
    volatile uint32_t __dummy108;
    volatile uint32_t __dummy112;
    volatile uint32_t __dummy116;
    volatile uint32_t __dummy120;
    volatile uint32_t __dummy124;
    volatile uint32_t FIFO;
};

}
