#ifndef TEMP_REGISTERS_H
#define TEMP_REGISTERS_H

#include <cstdint>

class TempRegisters {
    public:
        TempRegisters();
        // 8-bit registers
        uint8_t a, b, c, d, e, h, l, f;
};

#endif