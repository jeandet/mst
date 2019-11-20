#include <iostream>

template <typename T, const uint32_t address>
struct reg_t
{
    inline reg_t& operator=(const T& value) noexcept
    {
        *reinterpret_cast<T*>(address) = value;
        return *this;
    }
    constexpr operator T&() noexcept { return *reinterpret_cast<T*>(address); }
    constexpr operator const T&() const noexcept { return *reinterpret_cast<T*>(address); }
};

struct DeviceSignature
{
    reg_t<uint32_t, 0x1FF0F420> uuid0;
    reg_t<uint32_t, 0x1FF0F420 + 4> uuid1;
    reg_t<uint32_t, 0x1FF0F420 + 8> uuid2;
    reg_t<uint16_t, 0x1FF0F442> flash_size;
    reg_t<uint16_t, 0x1FF07BF0> package;
};

const DeviceSignature dev;
int f1(void) noexcept
{
    return int(dev.flash_size);
}

int f2(void) noexcept
{
    return *reinterpret_cast<uint16_t*>(0x1FF0F442);
}


void f3() noexcept
{
    auto v = dev.flash_size;
}

