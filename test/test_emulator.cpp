#include "gtest/gtest.h"
#include "../src/cpu.h"
#include "../src/gpu.h"
#include "../src/mmu.h"
#include "../src/key.h"

class GameboyEmulatorTest : public ::testing::Test
{
public:
    GameboyEmulatorTest() : cpu{}, gpu{}, mmu{cpu, gpu}
    {
        cpu.SetMMU(mmu);
        gpu.SetCPU(cpu);
        gpu.SetMMU(mmu);
        mmu.Load("../roms/ttt.gb");
        mmu.SetKey(key);
    }
    void Step()
    {
        uint8_t op = mmu.ReadByte(cpu.GetNextPC());
        cpu.ExecuteInstruction(op);
        gpu.CheckLine();
    }
    CPU cpu;
    GPU gpu;
    MMU mmu;
    Key key;
};

TEST_F(GameboyEmulatorTest, Step0)
{
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
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step1)
{
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
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 3);
}

TEST_F(GameboyEmulatorTest, Step2)
{
    for (int i = 0; i < 2; ++i)
    {
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

TEST_F(GameboyEmulatorTest, Step3)
{
    for (int i = 0; i < 3; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 255);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 7);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step4)
{
    for (int i = 0; i < 4; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 254);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step5)
{
    for (int i = 0; i < 5; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 254);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step6)
{
    for (int i = 0; i < 6; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 254);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 7);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step7)
{
    for (int i = 0; i < 7; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 253);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step8)
{
    for (int i = 0; i < 8; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 253);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step9)
{
    for (int i = 0; i < 9; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 253);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 7);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step10)
{
    for (int i = 0; i < 10; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 252);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 2);
}

TEST_F(GameboyEmulatorTest, Step15)
{
    for (int i = 0; i < 15; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 251);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 7);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 14);
}

TEST_F(GameboyEmulatorTest, Step25)
{
    for (int i = 0; i < 25; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 247);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 37);
}

TEST_F(GameboyEmulatorTest, Step49)
{
    for (int i = 0; i < 49; ++i)
    {
        Step();
    }
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 49);
}

TEST_F(GameboyEmulatorTest, Step50)
{
    for (int i = 0; i < 50; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 239);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 1);
    ASSERT_EQ(gpu.cur_scan, 640);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step100)
{
    for (int i = 0; i < 100; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 159);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 222);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 2);
    ASSERT_EQ(gpu.cur_scan, 1280);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step1000)
{
    for (int i = 0; i < 1000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 158);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 178);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step10000)
{
    for (int i = 0; i < 10000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 146);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 250);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step20000)
{
    for (int i = 0; i < 20000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 133);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 245);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24000)
{
    for (int i = 0; i < 24000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 192);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 7);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24500)
{
    for (int i = 0; i < 24500; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 25);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24550)
{
    for (int i = 0; i < 24550; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 8);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 8);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24551)
{
    for (int i = 0; i < 24551; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 8);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 10);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24580)
{
    for (int i = 0; i < 24580; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 38);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 15);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24581)
{
    for (int i = 0; i < 24581; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 17);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 38);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 17);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24582)
{
    for (int i = 0; i < 24582; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 128);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 17);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 38);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 19);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24583)
{
    for (int i = 0; i < 24583; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 128);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 17);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 37);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 20);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24584)
{
    for (int i = 0; i < 24584; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 128);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 17);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 37);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 21);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24585)
{
    for (int i = 0; i < 24585; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 128);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 37);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 22);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24586)
{
    for (int i = 0; i < 24586; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 243);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 37);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 24);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24587)
{
    for (int i = 0; i < 24587; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 243);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 37);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 25);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24588)
{
    for (int i = 0; i < 24588; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 243);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 26);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24589)
{
    for (int i = 0; i < 24589; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 119);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 28);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24590)
{
    for (int i = 0; i < 24590; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 119);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 29);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24591)
{
    for (int i = 0; i < 24591; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 252);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 31);
    ASSERT_EQ(cpu.registers.sp, 65534);
    for (int i = 0; i < 65536; ++i)
    {
        ASSERT_EQ(gpu.reg[i], 0);
    }
}

TEST_F(GameboyEmulatorTest, Step24592)
{
    for (int i = 0; i < 24592; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 252);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 33);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.reg[7], 252);
}

TEST_F(GameboyEmulatorTest, Step24593)
{
    for (int i = 0; i < 24593; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 252);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 4);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 255);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 36);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 36);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24594)
{
    for (int i = 0; i < 24594; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 252);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 4);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 16);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 39);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24595)
{
    for (int i = 0; i < 24595; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 206);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 18);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 4);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 16);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 40);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step24600)
{
    for (int i = 0; i < 24600; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 206);
    ASSERT_EQ(cpu.registers.b, 4);
    ASSERT_EQ(cpu.registers.c, 156);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 4);
    ASSERT_EQ(cpu.registers.f, 16);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 16);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 155);
    ASSERT_EQ(cpu.registers.sp, 65530);
}

TEST_F(GameboyEmulatorTest, Step25000)
{
    for (int i = 0; i < 25000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 120);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 172);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 8);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 52);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 156);
    ASSERT_EQ(cpu.registers.sp, 65530);
}

TEST_F(GameboyEmulatorTest, Step26000)
{
    for (int i = 0; i < 26000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 2);
    ASSERT_EQ(cpu.registers.c, 0);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 20);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 148);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 156);
    ASSERT_EQ(cpu.registers.sp, 65530);
}

TEST_F(GameboyEmulatorTest, Step27000)
{
    for (int i = 0; i < 27000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 159);
    ASSERT_EQ(cpu.registers.b, 3);
    ASSERT_EQ(cpu.registers.c, 106);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 32);
    ASSERT_EQ(cpu.registers.f, 16);
    ASSERT_EQ(cpu.registers.h, 128);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 244);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 156);
    ASSERT_EQ(cpu.registers.sp, 65530);
}

TEST_F(GameboyEmulatorTest, Step28000)
{
    for (int i = 0; i < 28000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 231);
    ASSERT_EQ(cpu.registers.b, 4);
    ASSERT_EQ(cpu.registers.c, 180);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 44);
    ASSERT_EQ(cpu.registers.f, 16);
    ASSERT_EQ(cpu.registers.h, 129);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 84);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 156);
    ASSERT_EQ(cpu.registers.sp, 65530);
}

TEST_F(GameboyEmulatorTest, Step28500)
{
    for (int i = 0; i < 28500; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 15);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 53);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 50);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 129);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 132);
    ASSERT_EQ(cpu.registers.m, 5);
    ASSERT_EQ(cpu.registers.pc, 150);
    ASSERT_EQ(cpu.registers.sp, 65532);
}

TEST_F(GameboyEmulatorTest, Step28700)
{
    for (int i = 0; i < 28700; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 21);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 8);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 43);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 74);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28750)
{
    for (int i = 0; i < 28750; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 11);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 11);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 14);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28770)
{
    for (int i = 0; i < 28770; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 7);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 7);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 10);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28780)
{
    for (int i = 0; i < 28780; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 5);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 5);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 8);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28790)
{
    for (int i = 0; i < 28790; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 3);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 3);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 6);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28795)
{
    for (int i = 0; i < 28795; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 5);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28796)
{
    for (int i = 0; i < 28796; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 4);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 78);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28797)
{
    for (int i = 0; i < 28797; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 4);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 79);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28798)
{
    for (int i = 0; i < 28798; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 4);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 74);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28799)
{
    for (int i = 0; i < 28799; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 4);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 75);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28800)
{
    for (int i = 0; i < 28800; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 153);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 4);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 77);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28810)
{
    for (int i = 0; i < 28810; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 100);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 88);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28815)
{
    for (int i = 0; i < 28815; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 145);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 224);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 96);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28816)
{
    for (int i = 0; i < 28816; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 145);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 98);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28817)
{
    for (int i = 0; i < 28817; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 145);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.reg[0], 145);
    ASSERT_EQ(gpu.reg[2], 100);
    ASSERT_EQ(gpu.reg[7], 252);
}

TEST_F(GameboyEmulatorTest, Step28818)
{
    for (int i = 0; i < 28818; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 102);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28819)
{
    for (int i = 0; i < 28819; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 102);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28820)
{
    for (int i = 0; i < 28820; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 102);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28850)
{
    for (int i = 0; i < 28850; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 103);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28890)
{
    for (int i = 0; i < 28890; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 104);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step28900)
{
    for (int i = 0; i < 28900; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 104);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step29000)
{
    for (int i = 0; i < 29000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 106);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step30000)
{
    for (int i = 0; i < 30000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 129);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 100);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step50000)
{
    for (int i = 0; i < 50000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 127);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 8);
    ASSERT_EQ(cpu.registers.d, 99);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
}

TEST_F(GameboyEmulatorTest, Step100000)
{
    for (int i = 0; i < 100000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 43);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 96);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 4);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 43);
    ASSERT_EQ(gpu.cur_scan, 27520);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step200000)
{
    for (int i = 0; i < 200000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 30);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 90);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 10);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 30);
    ASSERT_EQ(gpu.cur_scan, 19200);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 30);
}

TEST_F(GameboyEmulatorTest, Step300000)
{
    for (int i = 0; i < 300000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 17);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 84);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 16);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 17);
    ASSERT_EQ(gpu.cur_scan, 10880);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 5);
}

TEST_F(GameboyEmulatorTest, Step350000)
{
    for (int i = 0; i < 350000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 87);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 8);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 87);
    ASSERT_EQ(gpu.cur_scan, 55680);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 16);
}

TEST_F(GameboyEmulatorTest, Step359155)
{
    for (int i = 0; i < 359155; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 3);
}

TEST_F(GameboyEmulatorTest, Step359156)
{
    for (int i = 0; i < 359156; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 5);
}

TEST_F(GameboyEmulatorTest, Step359158)
{
    for (int i = 0; i < 359158; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 9);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 107);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 8);
}

TEST_F(GameboyEmulatorTest, Step359160)
{
    for (int i = 0; i < 359160; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 9);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 14);
}

TEST_F(GameboyEmulatorTest, Step359170)
{
    for (int i = 0; i < 359170; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 7);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 36);
}

TEST_F(GameboyEmulatorTest, Step359180)
{
    for (int i = 0; i < 359180; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 5);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 58);
}

TEST_F(GameboyEmulatorTest, Step359185)
{
    for (int i = 0; i < 359185; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 4);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 69);
}

TEST_F(GameboyEmulatorTest, Step359186)
{
    for (int i = 0; i < 359186; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 4);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 71);
}

TEST_F(GameboyEmulatorTest, Step359187)
{
    for (int i = 0; i < 359187; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 4);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 106);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 73);
}

TEST_F(GameboyEmulatorTest, Step359188)
{
    for (int i = 0; i < 359188; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 3);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 107);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 74);
}

TEST_F(GameboyEmulatorTest, Step359189)
{
    for (int i = 0; i < 359189; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 3);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 77);
}

TEST_F(GameboyEmulatorTest, Step359190)
{
    for (int i = 0; i < 359190; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 3);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 80);
}

TEST_F(GameboyEmulatorTest, Step359195)
{
    for (int i = 0; i < 359195; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 91);
}

TEST_F(GameboyEmulatorTest, Step359196)
{
    for (int i = 0; i < 359196; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 93);
}

TEST_F(GameboyEmulatorTest, Step359197)
{
    for (int i = 0; i < 359197; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 106);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 95);
}

TEST_F(GameboyEmulatorTest, Step359198)
{
    for (int i = 0; i < 359198; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 107);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 96);
}

TEST_F(GameboyEmulatorTest, Step359199)
{
    for (int i = 0; i < 359199; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 99);
}

TEST_F(GameboyEmulatorTest, Step359200)
{
    for (int i = 0; i < 359200; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 1);
    ASSERT_EQ(cpu.registers.d, 81);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 19);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 102);
}

TEST_F(GameboyEmulatorTest, Step359600)
{
    for (int i = 0; i < 359600; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 153);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 80);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 64);
    ASSERT_EQ(cpu.registers.h, 20);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 5);
}

TEST_F(GameboyEmulatorTest, Step359650)
{
    for (int i = 0; i < 359650; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 80);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 20);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 1);
    ASSERT_EQ(gpu.cur_scan, 640);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step359700)
{
    for (int i = 0; i < 359700; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 80);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 20);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 2);
    ASSERT_EQ(gpu.cur_scan, 1280);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 19);
}

TEST_F(GameboyEmulatorTest, Step360000)
{
    for (int i = 0; i < 360000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 9);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 80);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 20);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 9);
    ASSERT_EQ(gpu.cur_scan, 5760);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 6);
}

TEST_F(GameboyEmulatorTest, Step400000)
{
    for (int i = 0; i < 400000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 3);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 78);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 22);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 4);
    ASSERT_EQ(gpu.cur_scan, 2560);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step500000)
{
    for (int i = 0; i < 500000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 144);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 5);
    ASSERT_EQ(cpu.registers.d, 72);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 28);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 144);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 85);
}

TEST_F(GameboyEmulatorTest, Step1000000)
{
    for (int i = 0; i < 1000000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 78);
    ASSERT_EQ(cpu.registers.b, 1);
    ASSERT_EQ(cpu.registers.c, 12);
    ASSERT_EQ(cpu.registers.d, 42);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 58);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 78);
    ASSERT_EQ(gpu.cur_scan, 49920);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 26);
}

TEST_F(GameboyEmulatorTest, Step2000000)
{
    for (int i = 0; i < 2000000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 100);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 15);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 117);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 100);
    ASSERT_EQ(gpu.cur_scan, 64000);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 8);
}

TEST_F(GameboyEmulatorTest, Step2100000)
{
    for (int i = 0; i < 2100000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 87);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 9);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 123);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 87);
    ASSERT_EQ(gpu.cur_scan, 55680);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 27);
}

TEST_F(GameboyEmulatorTest, Step2200000)
{
    for (int i = 0; i < 2200000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 74);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 3);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 129);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 74);
    ASSERT_EQ(gpu.cur_scan, 47360);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step2210000)
{
    for (int i = 0; i < 2210000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 149);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 2);
    ASSERT_EQ(cpu.registers.d, 2);
    ASSERT_EQ(cpu.registers.e, 2);
    ASSERT_EQ(cpu.registers.f, 64);
    ASSERT_EQ(cpu.registers.h, 130);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 149);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 82);
}

TEST_F(GameboyEmulatorTest, Step2220000)
{
    for (int i = 0; i < 2220000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 71);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 4);
    ASSERT_EQ(cpu.registers.d, 2);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 130);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 71);
    ASSERT_EQ(gpu.cur_scan, 45440);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step2230000)
{
    for (int i = 0; i < 2230000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 147);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 64);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 147);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 8);
}

TEST_F(GameboyEmulatorTest, Step2231000)
{
    for (int i = 0; i < 2231000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 16);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 16);
    ASSERT_EQ(gpu.cur_scan, 10240);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 16);
}

TEST_F(GameboyEmulatorTest, Step2232000)
{
    for (int i = 0; i < 2232000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 39);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 39);
    ASSERT_EQ(gpu.cur_scan, 24960);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 16);
}

TEST_F(GameboyEmulatorTest, Step2233000)
{
    for (int i = 0; i < 2233000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 62);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 62);
    ASSERT_EQ(gpu.cur_scan, 39680);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step2234000)
{
    for (int i = 0; i < 2234000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 85);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 100);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 85);
    ASSERT_EQ(gpu.cur_scan, 54400);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step2235000)
{
    for (int i = 0; i < 2235000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 108);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 102);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 108);
    ASSERT_EQ(gpu.cur_scan, 69120);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 11);
}

TEST_F(GameboyEmulatorTest, Step2236000)
{
    for (int i = 0; i < 2236000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 131);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 10);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 131);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 15);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 104);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 131);
    ASSERT_EQ(gpu.cur_scan, 83840);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 10);
}

TEST_F(GameboyEmulatorTest, Step2237000)
{
    for (int i = 0; i < 2237000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 50);
    ASSERT_EQ(cpu.registers.b, 255);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 214);
    ASSERT_EQ(cpu.registers.f, 112);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 50);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 230);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 150);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 107);
}

TEST_F(GameboyEmulatorTest, Step2237100)
{
    for (int i = 0; i < 2237100; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 19);
    ASSERT_EQ(cpu.registers.b, 5);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 73);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 246);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 52);
}

TEST_F(GameboyEmulatorTest, Step2237110)
{
    for (int i = 0; i < 2237110; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 19);
    ASSERT_EQ(cpu.registers.b, 2);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 75);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 244);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 70);
}

TEST_F(GameboyEmulatorTest, Step2237120)
{
    for (int i = 0; i < 2237120; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 176);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 77);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 252);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 87);
}

TEST_F(GameboyEmulatorTest, Step2237121)
{
    for (int i = 0; i < 2237121; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 176);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 77);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 254);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 89);
}

TEST_F(GameboyEmulatorTest, Step2237122)
{
    for (int i = 0; i < 2237122; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 176);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 77);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 256);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 92);
}

TEST_F(GameboyEmulatorTest, Step2237123)
{
    for (int i = 0; i < 2237123; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 1);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 176);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 1);
    ASSERT_EQ(cpu.registers.l, 77);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 257);
    ASSERT_EQ(cpu.registers.sp, 65534);
    ASSERT_EQ(gpu.cur_line, 152);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 93);
}

TEST_F(GameboyEmulatorTest, Step2237130)
{
    for (int i = 0; i < 2237130; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 216);
    ASSERT_EQ(cpu.registers.f, 176);
    ASSERT_EQ(cpu.registers.h, 1);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 77);
    ASSERT_EQ(cpu.registers.m, 4);
    ASSERT_EQ(cpu.registers.pc, 899);
    ASSERT_EQ(cpu.registers.sp, 65522);
    ASSERT_EQ(gpu.cur_line, 153);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step2237200)
{
    for (int i = 0; i < 2237200; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 5);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 255);
    ASSERT_EQ(cpu.registers.e, 207);
    ASSERT_EQ(cpu.registers.f, 192);
    ASSERT_EQ(cpu.registers.h, 5);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 172);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 6211);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 0);
    ASSERT_EQ(gpu.cur_scan, 0);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 21);
}

TEST_F(GameboyEmulatorTest, Step2238000)
{
    for (int i = 0; i < 2238000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 18);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 255);
    ASSERT_EQ(cpu.registers.e, 194);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 1000);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 18);
    ASSERT_EQ(gpu.cur_scan, 11520);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 21);
}

TEST_F(GameboyEmulatorTest, Step2240000)
{
    for (int i = 0; i < 2240000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 64);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 19);
    ASSERT_EQ(cpu.registers.d, 255);
    ASSERT_EQ(cpu.registers.e, 194);
    ASSERT_EQ(cpu.registers.f, 80);
    ASSERT_EQ(cpu.registers.h, 0);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 1004);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 64);
    ASSERT_EQ(gpu.cur_scan, 40960);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 18);
}

TEST_F(GameboyEmulatorTest, Step2250000)
{
    for (int i = 0; i < 2250000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 64);
    ASSERT_EQ(cpu.registers.b, 38);
    ASSERT_EQ(cpu.registers.c, 255);
    ASSERT_EQ(cpu.registers.d, 209);
    ASSERT_EQ(cpu.registers.e, 4);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 136);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 94);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 8910);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 93);
    ASSERT_EQ(gpu.cur_scan, 59520);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 26);
}

TEST_F(GameboyEmulatorTest, Step2260000)
{
    for (int i = 0; i < 2260000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 43);
    ASSERT_EQ(cpu.registers.c, 73);
    ASSERT_EQ(cpu.registers.d, 3);
    ASSERT_EQ(cpu.registers.e, 135);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 152);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 121);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 9115);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 88);
    ASSERT_EQ(gpu.cur_scan, 56320);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step2270000)
{
    for (int i = 0; i < 2270000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 2);
    ASSERT_EQ(cpu.registers.b, 45);
    ASSERT_EQ(cpu.registers.c, 146);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 62);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 154);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 194);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 9107);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 118);
    ASSERT_EQ(gpu.cur_scan, 75520);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 6);
}

TEST_F(GameboyEmulatorTest, Step2271000)
{
    for (int i = 0; i < 2271000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 45);
    ASSERT_EQ(cpu.registers.c, 200);
    ASSERT_EQ(cpu.registers.d, 1);
    ASSERT_EQ(cpu.registers.e, 8);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 154);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 249);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 9113);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 136);
    ASSERT_EQ(gpu.cur_scan, 87040);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 11);
}

TEST_F(GameboyEmulatorTest, Step2272000)
{
    for (int i = 0; i < 2272000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 28);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 180);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 76);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 9115);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 153);
    ASSERT_EQ(gpu.cur_scan, 92160);
    ASSERT_EQ(gpu.line_mode, 1);
    ASSERT_EQ(gpu.mode_clocks, 52);
}

TEST_F(GameboyEmulatorTest, Step2273000)
{
    for (int i = 0; i < 2273000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 85);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 123);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 133);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 9107);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 17);
    ASSERT_EQ(gpu.cur_scan, 10880);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 39);
}

TEST_F(GameboyEmulatorTest, Step2274000)
{
    for (int i = 0; i < 2274000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 3);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 140);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 68);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 188);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 9107);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 36);
    ASSERT_EQ(gpu.cur_scan, 23040);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 32);
}

TEST_F(GameboyEmulatorTest, Step2275000)
{
    for (int i = 0; i < 2275000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 0);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 196);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 12);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 244);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 9111);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 54);
    ASSERT_EQ(gpu.cur_scan, 34560);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 43);
}

TEST_F(GameboyEmulatorTest, Step2275100)
{
    for (int i = 0; i < 2275100; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 201);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 7);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 250);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 9113);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 56);
    ASSERT_EQ(gpu.cur_scan, 35840);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 29);
}

TEST_F(GameboyEmulatorTest, Step2275200)
{
    for (int i = 0; i < 2275200; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 207);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 1);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 155);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 255);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 9115);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 58);
    ASSERT_EQ(gpu.cur_scan, 37120);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step2275210)
{
    for (int i = 0; i < 2275210; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 208);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 9115);
    ASSERT_EQ(cpu.registers.sp, 65455);
    ASSERT_EQ(gpu.cur_line, 58);
    ASSERT_EQ(gpu.cur_scan, 37120);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 31);
}

TEST_F(GameboyEmulatorTest, Step2275220)
{
    for (int i = 0; i < 2275220; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 208);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 2);
    ASSERT_EQ(cpu.registers.pc, 943);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 59);
    ASSERT_EQ(gpu.cur_scan, 37760);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 5);
}

TEST_F(GameboyEmulatorTest, Step2275221)
{
    for (int i = 0; i < 2275221; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 32);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 208);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 4);
    ASSERT_EQ(cpu.registers.pc, 946);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 59);
    ASSERT_EQ(gpu.cur_scan, 37760);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 9);
}

TEST_F(GameboyEmulatorTest, Step2275222)
{
    for (int i = 0; i < 2275222; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 15);
    ASSERT_EQ(cpu.registers.b, 46);
    ASSERT_EQ(cpu.registers.c, 208);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 4);
    ASSERT_EQ(cpu.registers.pc, 949);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 59);
    ASSERT_EQ(gpu.cur_scan, 37760);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 13);
}

TEST_F(GameboyEmulatorTest, Step2275230)
{
    for (int i = 0; i < 2275230; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 15);
    ASSERT_EQ(cpu.registers.b, 0);
    ASSERT_EQ(cpu.registers.c, 208);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 128);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 4);
    ASSERT_EQ(cpu.registers.pc, 966);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 59);
    ASSERT_EQ(gpu.cur_scan, 37760);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 12);
}

TEST_F(GameboyEmulatorTest, Step2275300)
{
    for (int i = 0; i < 2275300; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 219);
    ASSERT_EQ(cpu.registers.b, 3);
    ASSERT_EQ(cpu.registers.c, 218);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 1010);
    ASSERT_EQ(cpu.registers.sp, 65453);
    ASSERT_EQ(gpu.cur_line, 60);
    ASSERT_EQ(gpu.cur_scan, 38400);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 19);
}

TEST_F(GameboyEmulatorTest, Step2276000)
{
    for (int i = 0; i < 2276000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 43);
    ASSERT_EQ(cpu.registers.b, 3);
    ASSERT_EQ(cpu.registers.c, 43);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 156);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 0);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 1010);
    ASSERT_EQ(cpu.registers.sp, 65453);
    ASSERT_EQ(gpu.cur_line, 69);
    ASSERT_EQ(gpu.cur_scan, 44160);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 0);
}

TEST_F(GameboyEmulatorTest, Step2280000)
{
    for (int i = 0; i < 2280000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 254);
    ASSERT_EQ(cpu.registers.b, 186);
    ASSERT_EQ(cpu.registers.c, 213);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 2);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 198);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 1008);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 123);
    ASSERT_EQ(gpu.cur_scan, 78720);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 7);
}

TEST_F(GameboyEmulatorTest, Step2300000)
{
    for (int i = 0; i < 2300000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 239);
    ASSERT_EQ(cpu.registers.b, 167);
    ASSERT_EQ(cpu.registers.c, 77);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 2);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 198);
    ASSERT_EQ(cpu.registers.m, 1);
    ASSERT_EQ(cpu.registers.pc, 1008);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 78);
    ASSERT_EQ(gpu.cur_scan, 49920);
    ASSERT_EQ(gpu.line_mode, 3);
    ASSERT_EQ(gpu.mode_clocks, 5);
}

TEST_F(GameboyEmulatorTest, Step3000000)
{
    for (int i = 0; i < 3000000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 246);
    ASSERT_EQ(cpu.registers.b, 80);
    ASSERT_EQ(cpu.registers.c, 182);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 2);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 198);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 1007);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 51);
    ASSERT_EQ(gpu.cur_scan, 32640);
    ASSERT_EQ(gpu.line_mode, 0);
    ASSERT_EQ(gpu.mode_clocks, 9);
}

TEST_F(GameboyEmulatorTest, Step6000000)
{
    for (int i = 0; i < 6000000; ++i)
    {
        Step();
    }
    ASSERT_EQ(cpu.registers.a, 51);
    ASSERT_EQ(cpu.registers.b, 51);
    ASSERT_EQ(cpu.registers.c, 34);
    ASSERT_EQ(cpu.registers.d, 0);
    ASSERT_EQ(cpu.registers.e, 0);
    ASSERT_EQ(cpu.registers.f, 0);
    ASSERT_EQ(cpu.registers.h, 2);
    ASSERT_EQ(cpu.registers.ime, 0);
    ASSERT_EQ(cpu.registers.l, 198);
    ASSERT_EQ(cpu.registers.m, 3);
    ASSERT_EQ(cpu.registers.pc, 1007);
    ASSERT_EQ(cpu.registers.sp, 65451);
    ASSERT_EQ(gpu.cur_line, 114);
    ASSERT_EQ(gpu.cur_scan, 72960);
    ASSERT_EQ(gpu.line_mode, 2);
    ASSERT_EQ(gpu.mode_clocks, 18);
}
