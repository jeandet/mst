#pragma once
#include <cstdint>

namespace ucpp::stm32::dma
{
template <typename dma_dev>
struct dma_ctrlr
{
    inline static constexpr void setup(uint32_t mem_address, uint32_t periph_address)
    {
        dma_dev::S3CR.EN = 0;
        dma_dev::S3CR.CHSEL = 4;
        dma_dev::S3CR.MSIZE = 2;
        dma_dev::S3CR.PSIZE = 2;
        dma_dev::S3PAR = periph_address;
        dma_dev::S3M0AR = mem_address;
        dma_dev::S3CR.MINC = 1;
        dma_dev::S3CR.PINC = 0;
        dma_dev::S3CR.PFCTRL = 1;
        dma_dev::S3CR.MBURST = 1;
        dma_dev::S3CR.PBURST = 1;
        dma_dev::S3CR.PL = 3;
        dma_dev::HIFCR = 0xFFFFFFFF;
        dma_dev::LIFCR = 0xFFFFFFFF;
        dma_dev::S3FCR = dma_dev::S3FCR.FTH.shift(3) | dma_dev::S3FCR.DMDIS.shift(1);
        dma_dev::S3CR.EN = 1;
    }
    inline static constexpr bool done()
    {
        //return dma_dev::DMA_LISR.;
    }
};
}
