#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "renderer.h"

int main() {
    Renderer renderer{};
    CPU cpu{};
    GPU gpu{};
    MMU mmu{cpu, gpu};
    cpu.SetMMU(mmu);
    gpu.SetCPU(cpu);
    gpu.SetMMU(mmu);
    gpu.SetRenderer(renderer);
    mmu.Load("../roms/ttt.gb");
    while (true) {
        uint8_t op = mmu.ReadByte(cpu.GetNextPC());
        cpu.ExecuteInstruction(op);
        gpu.CheckLine();
    }
    return 0;
}