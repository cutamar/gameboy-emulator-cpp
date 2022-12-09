#include <algorithm>
#include "gpu.h"

GPU::GPU() : cur_line{0}, cur_scan{0}, line_mode{2}, mode_clocks{0}, y_scrl{0}, x_scrl{0}, raster{0}, ints{0}, lcd_on{0}, bg_on{0}, obj_on{0}, win_on{0}, obj_size{0}, bg_tilebase{0x0000}, bg_mapbase{0x1800}, win_tilebase{0x1800} {
    vram = std::vector<uint8_t>(8192, 0);
    oam = std::vector<uint8_t>(160, 0);
    palette_bg = std::vector<uint8_t>(4, 255);
    palette_obj0 = std::vector<uint8_t>(4, 255);
    palette_obj1 = std::vector<uint8_t>(4, 255);
    tilemap = std::vector<std::vector<std::vector<uint8_t>>>(512, std::vector<std::vector<uint8_t>>(8, std::vector<uint8_t>(8, 0)));
    reg = std::vector<uint8_t>(65536, 0);
    scanrow = std::vector<uint8_t>(160, 0);
}

void GPU::SetCPU(CPU& cpu) {
    this->cpu = &cpu;
}

void GPU::SetMMU(MMU& mmu) {
    this->mmu = &mmu;
}

void GPU::Reset() {
    vram = std::vector<uint8_t>(8192, 0);
    oam = std::vector<uint8_t>(160, 0);
    palette_bg = std::vector<uint8_t>(4, 255);
    palette_obj0 = std::vector<uint8_t>(4, 255);
    palette_obj1 = std::vector<uint8_t>(4, 255);
    tilemap = std::vector<std::vector<std::vector<uint8_t>>>(512, std::vector<std::vector<uint8_t>>(8, std::vector<uint8_t>(8, 0)));
    reg = std::vector<uint8_t>(65536, 0);
    // TODO: handle gui
    cur_line = 0;
    cur_scan = 0;
    line_mode = 2;
    mode_clocks = 0;
    y_scrl = 0;
    x_scrl = 0;
    raster = 0;
    ints = 0;
    lcd_on = 0;
    bg_on = 0;
    obj_on = 0;
    win_on = 0;
    obj_size = 0;
    scanrow = std::vector<uint8_t>(160, 0);
    obj_data = std::vector<GPUObjectData>(40, {-8, -16, 0, 0, 0, 0, 0, 0});
    for (int i = 0; i < 40; ++i) {
        obj_data[i].num = i;
    }
    bg_tilebase = 0x0000;
    bg_mapbase = 0x1800;
    win_tilebase = 0x1800;
}

void GPU::CheckLine() {
    mode_clocks += cpu->registers.m;
    switch (line_mode)
    {
    case 0:
        if (mode_clocks >= 51) {
            if (cur_line == 143) {
                line_mode = 1;
                // TODO handle gui
                mmu->interrupt_f |= 1;
            } else {
                line_mode = 2;
            }
            cur_line++;
            cur_scan += 640;
            mode_clocks = 0;
        }
        break;
    case 1:
        if (mode_clocks >= 114) {
            mode_clocks = 0;
            cur_line++;
            if (cur_line > 153) {
                cur_line = 0;
                cur_scan = 0;
                line_mode = 2;
            }
        }
        break;
    case 2:
        if (mode_clocks >= 20) {
            mode_clocks = 0;
            line_mode = 3;
        }
        break;
    case 3:
        if (mode_clocks >= 43) {
            mode_clocks = 0;
            line_mode = 0;
            if (lcd_on && bg_on) {
                auto line_base = cur_scan;
                auto map_base = bg_mapbase + ((((cur_line + y_scrl) & 255) >> 3) << 5);
                auto x = x_scrl & 7;
                auto y = (cur_line + y_scrl) & 7;
                auto t = (x_scrl >> 3) & 31;
                auto pixel = 0;
                auto w = 160;
                if (bg_tilebase) {
                    auto tile = vram[map_base+t];
                    if (tile < 128) tile = 256 + tile;
                    auto tile_row = tilemap[tile][y];
                    do {
                        scanrow[160 - x] = tile_row[x];
                        // TODO handle gui
                        x++;
                        if (x == 8) {
                            t = (t + 1) & 31;
                            x = 0;
                            tile = vram[map_base + t];
                            if (tile < 128) tile = 256 + tile;
                            tile_row = tilemap[tile][y];
                        }
                        line_base += 4;
                    } while (--w);
                } else {
                    auto tile_row = tilemap[vram[map_base+t]][y];
                    do {
                        scanrow[160-x] = tile_row[x];
                        // TODO handle gui
                        x++;
                        if (x==8) {
                            t = (t + 1) & 31;
                            x = 0;
                            tile_row = tilemap[vram[map_base+t]][y];
                        }
                        line_base += 4;
                    } while (--w);
                }
            } else if (lcd_on && obj_on) {
                auto cnt = 0;
                if (!obj_size) {
                    std::vector<uint8_t> tile_row;
                    GPUObjectData obj;
                    std::vector<uint8_t> pal;
                    auto pixel = 0;
                    auto x = 0;
                    auto line_base = cur_scan;
                    for (int i = 0; i < 40; ++i) {
                        obj = obj_data_sorted[i];
                        if (obj.y <= cur_line && (obj.y + 8) > cur_line) {
                            if (obj.yflip) {
                                tile_row = tilemap[obj.tile][7-(cur_line-obj.y)];
                            } else {
                                tile_row = tilemap[obj.tile][cur_line-obj.y];
                            }
                            if (obj.palette) pal = palette_obj1;
                            else pal = palette_obj0;

                            line_base = (cur_line * 160 + obj.x) * 4;
                            if (obj.xflip) {
                                for (x=0; x < 8; ++x) {
                                    if (obj.x + x >= 0 && obj.x + x < 160) {
                                        if (tile_row[7-x] && (obj.prio || scanrow[x])) {
                                            // TODO handle gui
                                        }
                                    }
                                    line_base += 4;
                                }
                            } else {
                                for (x=0; x < 8; ++x) {
                                    if (obj.x + x >= 0 && obj.x + x < 160) {
                                        if (tile_row[x] && (obj.prio || scanrow[x])) {
                                            // TODO handle gui
                                        }
                                    }
                                    line_base += 4;
                                }
                            }
                            cnt++;
                            if (cnt > 10) break;
                        }
                    }
                }
            }
        }
        break;
    }
}

void GPU::UpdateTile(uint16_t address, uint8_t data) {
    auto s_address = address;
    if (address & 1) {
        s_address--;
        address--;
    }
    auto tile = (address >> 4) & 511;
    auto y = (address >> 1) & 7;
    auto sx = 0;
    for (int x = 0; x < 8; ++x) {
        sx = 1 << (7 - x);
        tilemap[tile][y][x] = ((vram[s_address] & sx) ? 1 : 0) | ((vram[s_address + 1] & sx) ? 2 : 0);
    }
}

void GPU::UpdateOAM(uint16_t address, uint8_t data) {
    address -= 0xFE00;
    auto obj = address >> 2;
    if (obj < 40) {
        switch (address & 3) {
            case 0: 
                obj_data[obj].y = data - 16;
                break;
            case 1:
                obj_data[obj].x = data - 8;
                break;
            case 2:
                if (obj_size) obj_data[obj].tile = (data & 0xFE);
                else obj_data[obj].tile = data;
                break;
            case 3:
                obj_data[obj].palette = (data & 0x10) ? 1 : 0;
                obj_data[obj].xflip = (data & 0x20) ? 1 : 0;
                obj_data[obj].yflip = (data & 0x40) ? 1 : 0;
                obj_data[obj].prio = (data & 0x80) ? 1 : 0;
                break;
        }
    }
    obj_data_sorted = obj_data;
    std::sort(obj_data_sorted.begin(), obj_data_sorted.end(), [](GPUObjectData a, GPUObjectData b) {
        if (a.x > b.x) return -1;
        if (a.num > b.num) return -1;
        return 0;
    });
}

uint8_t GPU::ReadByte(uint16_t address) const {
    uint16_t g_address = address - 0xFF40;
    switch (g_address)
    {
    case 0:
        return (lcd_on ? 0x80 : 0) | 
        ((bg_tilebase == 0x0000) ? 0x10 : 0) |
        ((bg_mapbase == 0x1C00) ? 0x08 : 0) |
        (obj_size ? 0x04 : 0) |
        (obj_on ? 0x02 : 0) |
        (bg_on ? 0x01 : 0);
        break;
    case 1:
        return (cur_line == raster ? 4 : 0) | line_mode;
        break;
    case 2:
        return y_scrl;
        break;
    case 3:
        return x_scrl;
        break;
    case 4:
        return cur_line;
        break;
    case 5:
        return raster;
        break;
    default:
        return reg[g_address];
        break;
    }
}

void GPU::WriteByte(uint16_t address, uint8_t data) {
    uint16_t g_address = address - 0xFF40;
    reg[g_address] = data;
    switch (g_address)
    {
    case 0:
        lcd_on = (data & 0x80) ? 1 : 0;
        bg_tilebase = (data & 0x10) ? 0x0000 : 0x0800;
        bg_mapbase = (data & 0x08) ? 0x1C00 : 0x1800;
        obj_size = (data & 0x04) ? 1 : 0;
        obj_on = (data & 0x02) ? 1 : 0;
        bg_on = (data & 0x01) ? 1 : 0;
        break;
    case 2:
        y_scrl = data;
        break;
    case 3:
        x_scrl = data;
        break;
    case 5:
        raster = data;
    case 6:
        for (int i = 0; i < 160; ++i) {
            auto v = mmu->ReadByte((data << 8) + i);
            oam[i] = v;
            UpdateOAM(0xFE00 + i, v);
        }
        break;
    case 7:
        for (int i = 0; i < 4; ++i) {
            switch((data >> (i*2)) & 3) {
                case 0: palette_bg[i] = 255; break;
                case 1: palette_bg[i] = 192; break;
                case 2: palette_bg[i] = 96; break;
                case 3: palette_bg[i] = 0; break;
            }
        }
        break;
    case 8:
        for (int i = 0; i < 4; ++i) {
            switch((data >> (i*2)) & 3) {
                case 0: palette_obj0[i] = 255; break;
                case 1: palette_obj0[i] = 192; break;
                case 2: palette_obj0[i] = 96; break;
                case 3: palette_obj0[i] = 0; break;
            }
        }
        break;
    case 9:
        for (int i = 0; i < 4; ++i) {
            switch((data >> (i*2)) & 3) {
                case 0: palette_obj1[i] = 255; break;
                case 1: palette_obj1[i] = 192; break;
                case 2: palette_obj1[i] = 96; break;
                case 3: palette_obj1[i] = 0; break;
            }
        }
        break;
    }
}