#ifndef REGISTERS_H
#define REGISTERS_H

#include <cstdint>

class Registers {
    public:
        Registers();
        // 8-bit registers
        uint8_t a, b, c, d, e, h, l, f;
        // 16-bit registers
        // program counter, stack pointer, m clock and t clock
        uint16_t pc, sp, m, t, ime;
};

#endif