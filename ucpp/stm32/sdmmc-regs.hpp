
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
        static constexpr bitfield_t<POWER_t, 0> PWRCTRL = {};
    } POWER = {};
    static constexpr struct CLKCR_t : reg_t<uint32_t, base_address + 4>
    {
        static constexpr bitfield_t<CLKCR_t, 14, 14> HWFC_EN = {};
        static constexpr bitfield_t<CLKCR_t, 13, 13> NEGEDGE = {};
        static constexpr bitfield_t<CLKCR_t, 11> WIDBUS = {};
        static constexpr bitfield_t<CLKCR_t, 10, 10> BYPASS = {};
        static constexpr bitfield_t<CLKCR_t, 9, 9> PWRSAV = {};
        static constexpr bitfield_t<CLKCR_t, 8, 8> CLKEN = {};
        static constexpr bitfield_t<CLKCR_t, 0> CLKDIV = {};
    } CLKCR = {};
    static constexpr struct ARG_t : reg_t<uint32_t, base_address + 8>
    {
        static constexpr bitfield_t<ARG_t, 0> CMDARG = {};
    } ARG = {};
    static constexpr struct CMD_t : reg_t<uint32_t, base_address + 12>
    {
        static constexpr bitfield_t<CMD_t, 14, 14> CE_ATACMD = {};
        static constexpr bitfield_t<CMD_t, 13, 13> nIEN = {};
        static constexpr bitfield_t<CMD_t, 12, 12> ENCMDcompl = {};
        static constexpr bitfield_t<CMD_t, 11, 11> SDIOSuspend = {};
        static constexpr bitfield_t<CMD_t, 10, 10> CPSMEN = {};
        static constexpr bitfield_t<CMD_t, 9, 9> WAITPEND = {};
        static constexpr bitfield_t<CMD_t, 8, 8> WAITINT = {};
        static constexpr bitfield_t<CMD_t, 6> WAITRESP = {};
        static constexpr bitfield_t<CMD_t, 0> CMDINDEX = {};
    } CMD = {};
    static constexpr struct RESPCMD_t : reg_t<uint32_t, base_address + 16>
    {
        static constexpr bitfield_t<RESPCMD_t, 0> RESPCMD = {};
    } RESPCMD = {};
    static constexpr struct RESP1_t : reg_t<uint32_t, base_address + 20>
    {
        static constexpr bitfield_t<RESP1_t, 0> CARDSTATUS1 = {};
    } RESP1 = {};
    static constexpr struct RESP2_t : reg_t<uint32_t, base_address + 24>
    {
        static constexpr bitfield_t<RESP2_t, 0> CARDSTATUS2 = {};
    } RESP2 = {};
    static constexpr struct RESP3_t : reg_t<uint32_t, base_address + 28>
    {
        static constexpr bitfield_t<RESP3_t, 0> CARDSTATUS3 = {};
    } RESP3 = {};
    static constexpr struct RESP4_t : reg_t<uint32_t, base_address + 32>
    {
        static constexpr bitfield_t<RESP4_t, 0> CARDSTATUS4 = {};
    } RESP4 = {};
    static constexpr struct DTIMER_t : reg_t<uint32_t, base_address + 36>
    {
        static constexpr bitfield_t<DTIMER_t, 0> DATATIME = {};
    } DTIMER = {};
    static constexpr struct DLEN_t : reg_t<uint32_t, base_address + 40>
    {
        static constexpr bitfield_t<DLEN_t, 0> DATALENGTH = {};
    } DLEN = {};
    static constexpr struct DCTRL_t : reg_t<uint32_t, base_address + 44>
    {
        static constexpr bitfield_t<DCTRL_t, 11, 11> SDIOEN = {};
        static constexpr bitfield_t<DCTRL_t, 10, 10> RWMOD = {};
        static constexpr bitfield_t<DCTRL_t, 9, 9> RWSTOP = {};
        static constexpr bitfield_t<DCTRL_t, 8, 8> RWSTART = {};
        static constexpr bitfield_t<DCTRL_t, 4> DBLOCKSIZE = {};
        static constexpr bitfield_t<DCTRL_t, 3, 3> DMAEN = {};
        static constexpr bitfield_t<DCTRL_t, 2, 2> DTMODE = {};
        static constexpr bitfield_t<DCTRL_t, 1, 1> DTDIR = {};
        static constexpr bitfield_t<DCTRL_t, 0, 0> DTEN = {};
    } DCTRL = {};
    static constexpr struct DCOUNT_t : reg_t<uint32_t, base_address + 48>
    {
        static constexpr bitfield_t<DCOUNT_t, 0> DATACOUNT = {};
    } DCOUNT = {};
    static constexpr struct STA_t : reg_t<uint32_t, base_address + 52>
    {
        static constexpr bitfield_t<STA_t, 23, 23> CEATAEND = {};
        static constexpr bitfield_t<STA_t, 22, 22> SDIOIT = {};
        static constexpr bitfield_t<STA_t, 21, 21> RXDAVL = {};
        static constexpr bitfield_t<STA_t, 20, 20> TXDAVL = {};
        static constexpr bitfield_t<STA_t, 19, 19> RXFIFOE = {};
        static constexpr bitfield_t<STA_t, 18, 18> TXFIFOE = {};
        static constexpr bitfield_t<STA_t, 17, 17> RXFIFOF = {};
        static constexpr bitfield_t<STA_t, 16, 16> TXFIFOF = {};
        static constexpr bitfield_t<STA_t, 15, 15> RXFIFOHF = {};
        static constexpr bitfield_t<STA_t, 14, 14> TXFIFOHE = {};
        static constexpr bitfield_t<STA_t, 13, 13> RXACT = {};
        static constexpr bitfield_t<STA_t, 12, 12> TXACT = {};
        static constexpr bitfield_t<STA_t, 11, 11> CMDACT = {};
        static constexpr bitfield_t<STA_t, 10, 10> DBCKEND = {};
        static constexpr bitfield_t<STA_t, 9, 9> STBITERR = {};
        static constexpr bitfield_t<STA_t, 8, 8> DATAEND = {};
        static constexpr bitfield_t<STA_t, 7, 7> CMDSENT = {};
        static constexpr bitfield_t<STA_t, 6, 6> CMDREND = {};
        static constexpr bitfield_t<STA_t, 5, 5> RXOVERR = {};
        static constexpr bitfield_t<STA_t, 4, 4> TXUNDERR = {};
        static constexpr bitfield_t<STA_t, 3, 3> DTIMEOUT = {};
        static constexpr bitfield_t<STA_t, 2, 2> CTIMEOUT = {};
        static constexpr bitfield_t<STA_t, 1, 1> DCRCFAIL = {};
        static constexpr bitfield_t<STA_t, 0, 0> CCRCFAIL = {};
    } STA = {};
    static constexpr struct ICR_t : reg_t<uint32_t, base_address + 56>
    {
        static constexpr bitfield_t<ICR_t, 23, 23> CEATAENDC = {};
        static constexpr bitfield_t<ICR_t, 22, 22> SDIOITC = {};
        static constexpr bitfield_t<ICR_t, 10, 10> DBCKENDC = {};
        static constexpr bitfield_t<ICR_t, 9, 9> STBITERRC = {};
        static constexpr bitfield_t<ICR_t, 8, 8> DATAENDC = {};
        static constexpr bitfield_t<ICR_t, 7, 7> CMDSENTC = {};
        static constexpr bitfield_t<ICR_t, 6, 6> CMDRENDC = {};
        static constexpr bitfield_t<ICR_t, 5, 5> RXOVERRC = {};
        static constexpr bitfield_t<ICR_t, 4, 4> TXUNDERRC = {};
        static constexpr bitfield_t<ICR_t, 3, 3> DTIMEOUTC = {};
        static constexpr bitfield_t<ICR_t, 2, 2> CTIMEOUTC = {};
        static constexpr bitfield_t<ICR_t, 1, 1> DCRCFAILC = {};
        static constexpr bitfield_t<ICR_t, 0, 0> CCRCFAILC = {};
    } ICR = {};
    static constexpr struct MASK_t : reg_t<uint32_t, base_address + 60>
    {
        static constexpr bitfield_t<MASK_t, 23, 23> CEATAENDIE = {};
        static constexpr bitfield_t<MASK_t, 22, 22> SDIOITIE = {};
        static constexpr bitfield_t<MASK_t, 21, 21> RXDAVLIE = {};
        static constexpr bitfield_t<MASK_t, 20, 20> TXDAVLIE = {};
        static constexpr bitfield_t<MASK_t, 19, 19> RXFIFOEIE = {};
        static constexpr bitfield_t<MASK_t, 18, 18> TXFIFOEIE = {};
        static constexpr bitfield_t<MASK_t, 17, 17> RXFIFOFIE = {};
        static constexpr bitfield_t<MASK_t, 16, 16> TXFIFOFIE = {};
        static constexpr bitfield_t<MASK_t, 15, 15> RXFIFOHFIE = {};
        static constexpr bitfield_t<MASK_t, 14, 14> TXFIFOHEIE = {};
        static constexpr bitfield_t<MASK_t, 13, 13> RXACTIE = {};
        static constexpr bitfield_t<MASK_t, 12, 12> TXACTIE = {};
        static constexpr bitfield_t<MASK_t, 11, 11> CMDACTIE = {};
        static constexpr bitfield_t<MASK_t, 10, 10> DBCKENDIE = {};
        static constexpr bitfield_t<MASK_t, 9, 9> STBITERRIE = {};
        static constexpr bitfield_t<MASK_t, 8, 8> DATAENDIE = {};
        static constexpr bitfield_t<MASK_t, 7, 7> CMDSENTIE = {};
        static constexpr bitfield_t<MASK_t, 6, 6> CMDRENDIE = {};
        static constexpr bitfield_t<MASK_t, 5, 5> RXOVERRIE = {};
        static constexpr bitfield_t<MASK_t, 4, 4> TXUNDERRIE = {};
        static constexpr bitfield_t<MASK_t, 3, 3> DTIMEOUTIE = {};
        static constexpr bitfield_t<MASK_t, 2, 2> CTIMEOUTIE = {};
        static constexpr bitfield_t<MASK_t, 1, 1> DCRCFAILIE = {};
        static constexpr bitfield_t<MASK_t, 0, 0> CCRCFAILIE = {};
    } MASK = {};
    static constexpr struct FIFOCNT_t : reg_t<uint32_t, base_address + 72>
    {
        static constexpr bitfield_t<FIFOCNT_t, 0> FIFOCOUNT = {};
    } FIFOCNT = {};
    static constexpr struct FIFO_t : reg_t<uint32_t, base_address + 128>
    {
        static constexpr bitfield_t<FIFO_t, 0> FIFOData = {};
    } FIFO = {};
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
