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
    while (true) {
        auto op = mmu.ReadByte(cpu.GetNextPC());
        cpu.ExecuteInstruction(op);
    }
    return 0;
}