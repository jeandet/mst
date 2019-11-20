#include "ucpp/strong_ops.hpp"
#include "ucpp/strong_types.hpp"
#include <Arduino.h>
#include <SPI.h>

using namespace ucpp::strong_types;
using offset_t = strong_type<uint32_t>;
using address_t = strong_type<uint32_t, ops::plus<int, ops::self_t>,
    ops::plus<offset_t, ops::self_t>, ops::minus<ops::self_t, offset_t>>;

constexpr uint8_t operator"" _u8(unsigned long long v)
{
    return static_cast<uint8_t>(v);
}


// CS = digit pin 4
auto select_sd = [](bool select) { digitalWrite(PIN4, !select); };

template <typename fields_t, typename value_t = uint8_t>
union response_t {
    static_assert(sizeof(fields_t) == sizeof(value_t),
        "Size mismatch between response fields and value type");
    value_t value;
    fields_t fields;
    uint8_t bytes[sizeof(fields)];
    response_t(value_t v) { value = v; }
    response_t() {}
    operator int() { return this->value; }
    response_t& operator=(value_t v)
    {
        value = v;
        return *this;
    }
};


struct R1_fields
{
    uint8_t zero : 1;
    uint8_t ParamError : 1;
    uint8_t AddressError : 1;
    uint8_t EraseSeqError : 1;
    uint8_t ComCRCError : 1;
    uint8_t IllegalCmd : 1;
    uint8_t EraseReset : 1;
    uint8_t InIdleState : 1;
};

struct OCR_fields
{
    uint32_t busy : 1;
    uint32_t capacity_status : 1;
    uint32_t reserved : 6;
    uint32_t v3_6_v3_5 : 1;
    uint32_t v3_5_v3_4 : 1;
    uint32_t v3_4_v3_3 : 1;
    uint32_t v3_3_v3_2 : 1;
    uint32_t v3_2_v3_1 : 1;
    uint32_t v3_1_v3_0 : 1;
    uint32_t v3_0_v2_9 : 1;
    uint32_t v2_9_v2_8 : 1;
    uint32_t v2_8_v2_7 : 1;
    uint32_t v2_7_v2_6 : 1;
    uint32_t v2_6_v2_5 : 1;
    uint32_t v2_5_v2_4 : 1;
    uint32_t v2_4_v2_3 : 1;
    uint32_t v2_3_v2_2 : 1;
    uint32_t v2_2_v2_1 : 1;
    uint32_t v2_1_v2_0 : 1;
    uint32_t v2_0_v1_9 : 1;
    uint32_t v1_9_v1_8 : 1;
    uint32_t v1_8_v1_7 : 1;
    uint32_t reserved2 : 5;
};

using R1 = response_t<R1_fields, uint8_t>;

using OCR = response_t<OCR_fields, uint32_t>;
struct R3
{
    R1 r1;
    OCR ocr;
};

struct R7
{
    uint8_t r1;
    uint32_t resp;
};


template <typename bus>
struct SDCard
{
    template <uint8_t CMD_number, typename resp_t>
    static inline resp_t cmd(uint32_t param = 0)
    {
        resp_t resp {};
        bus::select(true);
        bus::write(static_cast<uint8_t>(CMD_number | 0x40));
        bus::write(param);
        if constexpr (CMD_number == 0)
        {
            int i = 0;
            bus::write(0x95_u8);
            do
            {
                resp = bus::write(0xFF_u8);
            } while ((resp != 1_u8) && (i++ < 32));
        }
        else
        {
            bus::write(1_u8);
            delayMicroseconds(10);
            resp.r1 = bus::write(0xFF_u8); // R1
            for (auto i = 0u; i < sizeof(resp_t); i++)
            {
                resp.resp = (resp.resp << 8) | bus::write(0xFF_u8);
            }
        }
        bus::select(false);
        return resp;
    }
};

template <int CS_PIN = 4>
struct MySpi
{
    static inline void select(bool sel) { digitalWrite(PIN4, !sel); }
    static inline uint8_t write(uint8_t v) { return SPI.transfer(v); }
    static inline uint16_t write(uint16_t v) { return SPI.transfer16(v); }
    static inline uint32_t write(uint32_t v)
    {
        return (static_cast<uint32_t>(SPI.transfer16(static_cast<uint16_t>(v))) << 16)
            + SPI.transfer16(v >> 16);
    }
};


void setup()
{

    Serial.begin(115200);
    Serial.print("hello\n");
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV32);
    SPI.setBitOrder(MSBFIRST);
    pinMode(PIN4, OUTPUT);
    select_sd(false);
    for (int i = 0; i < 80; i++)
        SPI.transfer(0xFF);
}

void loop()
{
    using sd = SDCard<MySpi<4>>;
    Serial.print("hello\n\r");
    Serial.print(int(sd::cmd<0, uint8_t>()));
    R7 resp8 = sd::cmd<8, R7>(0x1AA);
    Serial.print("CMD8: got:");
    Serial.print(int(resp8.r1));
    Serial.print("\t");
    Serial.print(int(resp8.resp));
    Serial.print(int(resp8.resp >> 16));
    Serial.print("\n\r");
    while (true)
    {
    }
}
