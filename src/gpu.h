#ifndef GPU_H
#define GPU_H

#include <cstdint>
#include <vector>
#include "cpu.h"
#include "mmu.h"

struct GPUObjectData {
    int8_t x;
    int8_t y;
    int8_t tile;
    int8_t palette;
    int8_t xflip;
    int8_t yflip;
    int8_t prio;
    int8_t num;
};

class GPU {
    public:
        GPU();
        uint8_t ReadByte(uint8_t address) const;
        void WriteByte(uint8_t address, uint8_t data);
        void Reset();
        void UpdateTile(uint8_t address, uint8_t data);
        void UpdateOAM(uint8_t address, uint8_t data);
        void SetCPU(CPU& cpu);
        void SetMMU(MMU& mmu);
        std::vector<uint8_t> vram;
        std::vector<uint8_t> oam;
    private:
        void CheckLine();
        CPU* cpu;
        MMU* mmu;
        std::vector<uint8_t> reg;
        std::vector<std::vector<std::vector<uint8_t>>> tilemap;
        std::vector<GPUObjectData> obj_data;
        std::vector<GPUObjectData> obj_data_sorted;
        std::vector<uint8_t> palette_bg;
        std::vector<uint8_t> palette_obj0;
        std::vector<uint8_t> palette_obj1;
        std::vector<uint8_t> scanrow;
        uint8_t cur_line, cur_scan, line_mode, mode_clocks;
        uint8_t y_scrl, x_scrl, raster, ints;
        uint8_t lcd_on, bg_on, obj_on, win_on;
        uint8_t obj_size;
        uint16_t bg_tilebase, bg_mapbase, win_tilebase;
};

#endif