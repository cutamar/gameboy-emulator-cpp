#include "gtest/gtest.h"
#include "../src/cpu.h"
#include "../src/gpu.h"
#include "../src/mmu.h"

class GameboyEmulatorTest : public ::testing::Test {
    public:
        GameboyEmulatorTest() : cpu{}, gpu{}, mmu{cpu, gpu} {
            cpu.SetMMU(mmu);
            gpu.SetCPU(cpu);
        }
        void Step() {
            auto op = mmu.ReadByte(cpu.GetNextPC());
            cpu.ExecuteInstruction(op);
        }
        CPU cpu;
        GPU gpu;
        MMU mmu;
};

TEST_F(GameboyEmulatorTest, Step0) {
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 0);
    ASSERT_EQ(cpu.registers.pc, 0);
    ASSERT_EQ(cpu.registers.sp, 0);
}

TEST_F(GameboyEmulatorTest, Step1) {
    Step();
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 3);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step2) {
    for (int i = 0; i < 2; ++i) {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 4);
    ASSERT_EQ(cpu.registers.sp, 65534);
}