#ifndef TIMER_H
#define TIMER_H

#include <cstdint>
#include "cpu.h"
#include "mmu.h"

class Timer {
    public:
        Timer(CPU& cpu, MMU& mmu);
        uint16_t div, tma, tima, tac;
        uint16_t main_clock, sub_clock, div_clock;
        void Reset();
        void Step();
        void Inc();
        uint8_t ReadByte(uint16_t address);
        void WriteByte(uint16_t address, uint8_t data);
    private:
        CPU* cpu;
        MMU* mmu;
};

#endif