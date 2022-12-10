#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "timer.h"
#include "renderer.h"

int main() {
    Renderer renderer{};
    CPU cpu{};
    GPU gpu{};
    MMU mmu{cpu, gpu};
    Timer timer{cpu, mmu};
    cpu.SetMMU(mmu);
    gpu.SetCPU(cpu);
    gpu.SetMMU(mmu);
    gpu.SetRenderer(renderer);
    mmu.Load("../roms/ttt.gb");
    while (true) {
        if (cpu.halt) {
            cpu.registers.m = 1;
        } else {
            uint8_t op = mmu.ReadByte(cpu.GetNextPC());
            cpu.ExecuteInstruction(op);
        }
        if (cpu.registers.ime && mmu.interrupt_e && mmu.interrupt_f) {
            cpu.halt = 0;
            cpu.registers.ime = 0;
            uint8_t fired = mmu.interrupt_e & mmu.interrupt_f;
            if (fired & 1) {
                mmu.interrupt_f &= 0xFE;
                cpu.RST40();
            } else if (fired & 2) {
                mmu.interrupt_f &= 0xFD;
                cpu.RST48();
            } else if (fired & 4) {
                mmu.interrupt_f &= 0xFB;
                cpu.RST50();
            } else if (fired & 8) {
                mmu.interrupt_f &= 0xF7;
                cpu.RST58();
            } else if (fired & 16) {
                mmu.interrupt_f &= 0xEF;
                cpu.RST60();
            } else {
                cpu.registers.ime = 1;
            }
            cpu.UpdateClock();
        }
        gpu.CheckLine();
        timer.Inc();
    }
    return 0;
}