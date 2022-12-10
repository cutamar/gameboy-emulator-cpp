#include "timer.h"

Timer::Timer(CPU& cpu, MMU& mmu) : div{0}, tma{0}, tima{0}, tac{0}, main_clock{0}, sub_clock{0}, div_clock{0} {
    this->cpu = &cpu;
    this->mmu = &mmu;
}

void Timer::Reset() {
    div = 0;
    tma = 0;
    tima = 0;
    tac = 0;
    main_clock = 0;
    sub_clock = 0;
    div_clock = 0;
}

void Timer::Step() {
    tima++;
    main_clock = 0;
    if (tima > 255) {
        tima = tma;
        mmu->interrupt_f |= 4;
    }
}

void Timer::Inc() {
    uint16_t old_clock = main_clock;
    sub_clock += cpu->registers.m;
    if (sub_clock > 3) {
        main_clock++;
        sub_clock -= 4;
        div_clock++;
        if (div_clock == 16) {
            div_clock = 0;
            div++;
            div &= 255;
        }
    }

    if (tac & 4) {
        switch (tac & 3)
        {
        case 0:
            if (main_clock >= 64) Step();
            break;
        case 1:
            if (main_clock >= 1) Step();
            break;
        case 2:
            if (main_clock >= 4) Step();
            break;
        case 3:
            if (main_clock >= 16) Step();
            break;
        default:
            break;
        }
    }
}

uint8_t Timer::ReadByte(uint16_t address) {
    switch (address)
    {
    case 0xFF04:
        return div;
        break;
    case 0xFF05:
        return tima;
        break;
    case 0xFF06:
        return tma;
        break;
    case 0xFF07:
        return tac;
        break;
    
    default:
        break;
    }
    return 0;
}

void Timer::WriteByte(uint16_t address, uint8_t data) {
    switch (address)
    {
    case 0xFF04:
        div = 0;
        break;
    case 0xFF05:
        tima = data;
        break;
    case 0xFF06:
        tma = data;
        break;
    case 0xFF07:
        tac = data & 7;
        break;
    
    default:
        break;
    }
}