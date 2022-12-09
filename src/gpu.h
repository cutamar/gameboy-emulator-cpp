#ifndef GPU_H
#define GPU_H

#include <cstdint>
#include <vector>
#include "cpu.h"
#include "mmu.h"

struct GPUObjectData {
    int8_t x;
    int8_t y;
    uint8_t tile;
    uint8_t palette;
    uint8_t xflip;
    uint8_t yflip;
    uint8_t prio;
    uint8_t num;
};

class GPU {
    public:
        GPU();
        uint8_t ReadByte(uint16_t address) const;
        void WriteByte(uint16_t address, uint8_t data);
        void Reset();
        void UpdateTile(uint16_t address, uint8_t data);
        void UpdateOAM(uint16_t address, uint8_t data);
        void CheckLine();
        void SetCPU(CPU& cpu);
        void SetMMU(MMU& mmu);
        std::vector<uint8_t> vram;
        std::vector<uint8_t> oam;
        std::vector<uint8_t> reg;
        uint32_t cur_line, cur_scan, line_mode, mode_clocks;
        std::vector<GPUObjectData> obj_data;
    private:
        CPU* cpu;
        MMU* mmu;
        std::vector<std::vector<std::vector<uint8_t>>> tilemap;
        std::vector<GPUObjectData> obj_data_sorted;
        std::vector<uint8_t> palette_bg;
        std::vector<uint8_t> palette_obj0;
        std::vector<uint8_t> palette_obj1;
        std::vector<uint8_t> scanrow;
        uint8_t y_scrl, x_scrl, raster, ints;
        uint8_t lcd_on, bg_on, obj_on, win_on;
        uint8_t obj_size;
        uint16_t bg_tilebase, bg_mapbase, win_tilebase;
};

#endif