
#pragma once
#include "../peripherals_tags.hpp"
#include "../register.hpp"
#include <stdint.h>


using namespace ucpp::registers;
namespace ucpp::stm32::sdmmc
{
template <uint32_t base_address, int index>
struct sdmmc_t
{
    using tag = ucpp::tags::sdmmc_tag<index>;
    struct POWER_t : reg_t<uint32_t, base_address + 0>
    {
        bitfield_t<POWER_t, 0> PWRCTRL;
    } POWER;
    struct CLKCR_t : reg_t<uint32_t, base_address + 4>
    {
        bitfield_t<CLKCR_t, 14, 14> HWFC_EN;
        bitfield_t<CLKCR_t, 13, 13> NEGEDGE;
        bitfield_t<CLKCR_t, 11> WIDBUS;
        bitfield_t<CLKCR_t, 10, 10> BYPASS;
        bitfield_t<CLKCR_t, 9, 9> PWRSAV;
        bitfield_t<CLKCR_t, 8, 8> CLKEN;
        bitfield_t<CLKCR_t, 0> CLKDIV;
    } CLKCR;
    struct ARG_t : reg_t<uint32_t, base_address + 8>
    {
        bitfield_t<ARG_t, 0> CMDARG;
    } ARG;
    struct CMD_t : reg_t<uint32_t, base_address + 12>
    {
        bitfield_t<CMD_t, 14, 14> CE_ATACMD;
        bitfield_t<CMD_t, 13, 13> nIEN;
        bitfield_t<CMD_t, 12, 12> ENCMDcompl;
        bitfield_t<CMD_t, 11, 11> SDIOSuspend;
        bitfield_t<CMD_t, 10, 10> CPSMEN;
        bitfield_t<CMD_t, 9, 9> WAITPEND;
        bitfield_t<CMD_t, 8, 8> WAITINT;
        bitfield_t<CMD_t, 6> WAITRESP;
        bitfield_t<CMD_t, 0> CMDINDEX;
    } CMD;
    struct RESPCMD_t : reg_t<uint32_t, base_address + 16>
    {
        bitfield_t<RESPCMD_t, 0> RESPCMD;
    } RESPCMD;
    struct RESP1_t : reg_t<uint32_t, base_address + 20>
    {
        bitfield_t<RESP1_t, 0> CARDSTATUS1;
    } RESP1;
    struct RESP2_t : reg_t<uint32_t, base_address + 24>
    {
        bitfield_t<RESP2_t, 0> CARDSTATUS2;
    } RESP2;
    struct RESP3_t : reg_t<uint32_t, base_address + 28>
    {
        bitfield_t<RESP3_t, 0> CARDSTATUS3;
    } RESP3;
    struct RESP4_t : reg_t<uint32_t, base_address + 32>
    {
        bitfield_t<RESP4_t, 0> CARDSTATUS4;
    } RESP4;
    struct DTIMER_t : reg_t<uint32_t, base_address + 36>
    {
        bitfield_t<DTIMER_t, 0> DATATIME;
    } DTIMER;
    struct DLEN_t : reg_t<uint32_t, base_address + 40>
    {
        bitfield_t<DLEN_t, 0> DATALENGTH;
    } DLEN;
    struct DCTRL_t : reg_t<uint32_t, base_address + 44>
    {
        bitfield_t<DCTRL_t, 11, 11> SDIOEN;
        bitfield_t<DCTRL_t, 10, 10> RWMOD;
        bitfield_t<DCTRL_t, 9, 9> RWSTOP;
        bitfield_t<DCTRL_t, 8, 8> RWSTART;
        bitfield_t<DCTRL_t, 4> DBLOCKSIZE;
        bitfield_t<DCTRL_t, 3, 3> DMAEN;
        bitfield_t<DCTRL_t, 2, 2> DTMODE;
        bitfield_t<DCTRL_t, 1, 1> DTDIR;
        bitfield_t<DCTRL_t, 0, 0> DTEN;
    } DCTRL;
    struct DCOUNT_t : reg_t<uint32_t, base_address + 48>
    {
        bitfield_t<DCOUNT_t, 0> DATACOUNT;
    } DCOUNT;
    struct STA_t : reg_t<uint32_t, base_address + 52>
    {
        bitfield_t<STA_t, 23, 23> CEATAEND;
        bitfield_t<STA_t, 22, 22> SDIOIT;
        bitfield_t<STA_t, 21, 21> RXDAVL;
        bitfield_t<STA_t, 20, 20> TXDAVL;
        bitfield_t<STA_t, 19, 19> RXFIFOE;
        bitfield_t<STA_t, 18, 18> TXFIFOE;
        bitfield_t<STA_t, 17, 17> RXFIFOF;
        bitfield_t<STA_t, 16, 16> TXFIFOF;
        bitfield_t<STA_t, 15, 15> RXFIFOHF;
        bitfield_t<STA_t, 14, 14> TXFIFOHE;
        bitfield_t<STA_t, 13, 13> RXACT;
        bitfield_t<STA_t, 12, 12> TXACT;
        bitfield_t<STA_t, 11, 11> CMDACT;
        bitfield_t<STA_t, 10, 10> DBCKEND;
        bitfield_t<STA_t, 9, 9> STBITERR;
        bitfield_t<STA_t, 8, 8> DATAEND;
        bitfield_t<STA_t, 7, 7> CMDSENT;
        bitfield_t<STA_t, 6, 6> CMDREND;
        bitfield_t<STA_t, 5, 5> RXOVERR;
        bitfield_t<STA_t, 4, 4> TXUNDERR;
        bitfield_t<STA_t, 3, 3> DTIMEOUT;
        bitfield_t<STA_t, 2, 2> CTIMEOUT;
        bitfield_t<STA_t, 1, 1> DCRCFAIL;
        bitfield_t<STA_t, 0, 0> CCRCFAIL;
    } STA;
    struct ICR_t : reg_t<uint32_t, base_address + 56>
    {
        bitfield_t<ICR_t, 23, 23> CEATAENDC;
        bitfield_t<ICR_t, 22, 22> SDIOITC;
        bitfield_t<ICR_t, 10, 10> DBCKENDC;
        bitfield_t<ICR_t, 9, 9> STBITERRC;
        bitfield_t<ICR_t, 8, 8> DATAENDC;
        bitfield_t<ICR_t, 7, 7> CMDSENTC;
        bitfield_t<ICR_t, 6, 6> CMDRENDC;
        bitfield_t<ICR_t, 5, 5> RXOVERRC;
        bitfield_t<ICR_t, 4, 4> TXUNDERRC;
        bitfield_t<ICR_t, 3, 3> DTIMEOUTC;
        bitfield_t<ICR_t, 2, 2> CTIMEOUTC;
        bitfield_t<ICR_t, 1, 1> DCRCFAILC;
        bitfield_t<ICR_t, 0, 0> CCRCFAILC;
    } ICR;
    struct MASK_t : reg_t<uint32_t, base_address + 60>
    {
        bitfield_t<MASK_t, 23, 23> CEATAENDIE;
        bitfield_t<MASK_t, 22, 22> SDIOITIE;
        bitfield_t<MASK_t, 21, 21> RXDAVLIE;
        bitfield_t<MASK_t, 20, 20> TXDAVLIE;
        bitfield_t<MASK_t, 19, 19> RXFIFOEIE;
        bitfield_t<MASK_t, 18, 18> TXFIFOEIE;
        bitfield_t<MASK_t, 17, 17> RXFIFOFIE;
        bitfield_t<MASK_t, 16, 16> TXFIFOFIE;
        bitfield_t<MASK_t, 15, 15> RXFIFOHFIE;
        bitfield_t<MASK_t, 14, 14> TXFIFOHEIE;
        bitfield_t<MASK_t, 13, 13> RXACTIE;
        bitfield_t<MASK_t, 12, 12> TXACTIE;
        bitfield_t<MASK_t, 11, 11> CMDACTIE;
        bitfield_t<MASK_t, 10, 10> DBCKENDIE;
        bitfield_t<MASK_t, 9, 9> STBITERRIE;
        bitfield_t<MASK_t, 8, 8> DATAENDIE;
        bitfield_t<MASK_t, 7, 7> CMDSENTIE;
        bitfield_t<MASK_t, 6, 6> CMDRENDIE;
        bitfield_t<MASK_t, 5, 5> RXOVERRIE;
        bitfield_t<MASK_t, 4, 4> TXUNDERRIE;
        bitfield_t<MASK_t, 3, 3> DTIMEOUTIE;
        bitfield_t<MASK_t, 2, 2> CTIMEOUTIE;
        bitfield_t<MASK_t, 1, 1> DCRCFAILIE;
        bitfield_t<MASK_t, 0, 0> CCRCFAILIE;
    } MASK;
    struct FIFOCNT_t : reg_t<uint32_t, base_address + 72>
    {
        bitfield_t<FIFOCNT_t, 0> FIFOCOUNT;
    } FIFOCNT;
    struct FIFO_t : reg_t<uint32_t, base_address + 128>
    {
        bitfield_t<FIFO_t, 0> FIFOData;
    } FIFO;
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
