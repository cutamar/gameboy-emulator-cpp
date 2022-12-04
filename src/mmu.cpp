#include <fstream>
#include "mmu.h"
#include "gpu.h"

MMU::MMU(const CPU& cpu, GPU& gpu) : cpu{cpu}, gpu{gpu}, in_bios{true}, cartridge_type{0}, interrupt_e{0}, interrupt_f{0}, rom_offs{0x4000}, ram_offs{0}, rom_bank{0}, ram_bank{0}, ram_on{0}, mode{0} {}

void MMU::Reset() {
    wram = std::vector<uint8_t>(8192, 0);
    eram = std::vector<uint8_t>(32768, 0);
    zram = std::vector<uint8_t>(127, 0);
    in_bios = true;
    interrupt_e = 0;
    interrupt_f = 0;
    cartridge_type = 0;
    rom_bank = 0;
    ram_bank = 0;
    ram_on = 0;
    mode = 0;
    rom_offs = 0x4000;
    ram_offs = 0;
}

int8_t MMU::ReadByte(int8_t address) {
    switch (address & 0xF000) {
        case 0x0000:
            if (in_bios && address < 0x0100) {
                return bios[address];
            }
            if (in_bios && cpu.GetCurrentPC() == 0x0100) {
                in_bios = false;
            }
            return rom[address];
        case 0x1000:
        case 0x2000:
        case 0x3000:
            return rom[address];
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
            return rom[address + (address & 0x3FFF)];
        case 0x8000:
        case 0x9000:
            return gpu.vram[address & 0x1FFF];
        case 0xA000:
        case 0xB000:
            return eram[ram_offs + (address & 0x1FFF)];
        case 0xC000:
        case 0xD000:
        case 0xE000:
            return wram[address & 0x1FFF];
        case 0xF000:
            switch (address & 0x0F00) {
                case 0x000:
                case 0x100:
                case 0x200:
                case 0x300:
                case 0x400:
                case 0x500:
                case 0x600:
                case 0x700:
                case 0x800:
                case 0x900:
                case 0xA00:
                case 0xB00:
                case 0xC00:
                case 0xD00:
                    return wram[address & 0x1FFF];
                case 0xE00:
                    if ((address & 0xFF) < 0xA0) {
                        return gpu.oam[address & 0xFF];
                    } else {
                        return 0;
                    }
                case 0xF00:
                    if (address == 0xFFFF) {
                        return interrupt_e;
                    } else if (address > 0xFF7F) {
                        return zram[address & 0x7F];
                    } else {
                        switch (address & 0xF0) {
                            case 0x00:
                                switch (address & 0xF) {
                                    case 0:
                                        // TODO return KEY.rb();    // JOYP
                                        return 0;
                                    case 4:
                                    case 5:
                                    case 6:
                                    case 7:
                                        // TODO TIMER.rb(addr);
                                        return 0;
                                    case 15:
                                        return interrupt_f;
                                    default:
                                        return 0;
                                }
                            case 0x10:
                            case 0x20:
                            case 0x30:
                                return 0;
                            case 0x40:
                            case 0x50:
                            case 0x60:
                            case 0x70:
                                return gpu.ReadByte(address);
                        }
                    }
            }
    }
    // should not get here
    return 0;
}

int16_t MMU::ReadWord(int8_t address) {
    return ReadByte(address) + (ReadByte(address+1) << 8);
}

void MMU::WriteByte(int8_t address, int8_t data) {
    switch (address & 0xF000) {
        case 0x0000:
        case 0x1000:
            if (cartridge_type == 1) {
                ram_on = ((data & 0xF) == 0xA) ? 1 : 0;
            }
            break;
        case 0x2000:
        case 0x3000:
            if (cartridge_type == 1) {
                rom_bank &= 0x60;
                data &= 0x1F;
                if (!data) data = 1;
                rom_bank |= data;
                rom_offs = rom_bank * 0x4000;
            }
            break;
        case 0x4000:
        case 0x5000:
            if (cartridge_type == 1 && mode) {
                ram_bank = data & 3;
                ram_offs = ram_bank * 0x2000;
            } else if (cartridge_type == 1) {
                rom_bank &= 0x1F;
                rom_bank |= ((data & 3)<<5);
                rom_offs = rom_bank * 0x4000;
            }
            break;
        case 0x6000:
        case 0x7000:
            if (cartridge_type == 1) {
                mode = data & 1;
            }
            break;
        case 0x8000:
        case 0x9000:
            gpu.vram[address & 0x1FFF] = data;
            gpu.UpdateTile(address & 0x1FFF, data);
            break;
        case 0xA000:
        case 0xB000:
            eram[ram_offs + (address & 0x1FFF)] = data;
            break;
        case 0xC000:
        case 0xD000:
        case 0xE000:
            wram[address & 0x1FFF] = data;
            break;
        case 0xF000:
            switch(address & 0x0F00) {
                case 0x000:
                case 0x100:
                case 0x200:
                case 0x300:
                case 0x400:
                case 0x500:
                case 0x600:
                case 0x700:
                case 0x800:
                case 0x900:
                case 0xA00:
                case 0xB00:
                case 0xC00:
                case 0xD00:
                    wram[address & 0x1FFF] = data;
                    break;
                case 0xE00:
                    if ((address & 0xFF) < 0xA0) gpu.oam[address & 0xFF] = data;
                    gpu.UpdateOAM(address, data);
                    break;
                case 0xF00:
                    if (address == 0xFFFF) {
                        interrupt_e = data;
                    } else if (address > 0xFF7F) {
                        zram[address & 0x7F] = data;
                    } else {
                        switch (address & 0xF0) {
                            case 0x00:
                                switch (address & 0xF) {
                                    case 0x0:
                                        // TODO KEY.wb(val);
                                        break;
                                    case 0x4:
                                    case 0x5:
                                    case 0x6:
                                    case 0x7:
                                        // TODO TIMER.wb(addr, val);
                                        break;
                                    case 15:
                                        interrupt_f = data;
                                        break;
                                }
                            case 0x10:
                            case 0x20:
                            case 0x30:
                                break;
                            case 0x40:
                            case 0x50:
                            case 0x60:
                            case 0x70:
                                gpu.WriteByte(address, data);
                                break;
                        }
                    }
                    break;
            }
    }
}

void MMU::WriteWord(int8_t address, int16_t data) {
    WriteByte(address, data & 255);
    WriteByte(address + 1, data >> 8);
}

void MMU::Load(std::string path) {
    std::ifstream stream(path, std::ios::in | std::ios::binary);
    rom = {std::istreambuf_iterator<char>(stream), {}};
    cartridge_type = rom[0x0147];
}