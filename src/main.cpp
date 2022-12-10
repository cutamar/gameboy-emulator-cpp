#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "renderer.h"

int main() {
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
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