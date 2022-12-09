#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"

int main() {
    CPU cpu{};
    GPU gpu{};
    MMU mmu{cpu, gpu};
    cpu.SetMMU(mmu);
    gpu.SetCPU(cpu);
    gpu.SetMMU(mmu);
    while (true) {
        uint8_t op = mmu.ReadByte(cpu.GetNextPC());
        cpu.ExecuteInstruction(op);
        gpu.CheckLine();
    }
    return 0;
}