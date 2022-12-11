#ifndef KEY_H
#define KEY_H

#include <cstdint>
#include "SDL.h"


class Key {
    public:
        Key();
        void Reset();
        uint8_t ReadByte();
        void WriteByte(uint8_t data);
        void KeyDown(SDL_Event& event);
        void KeyUp(SDL_Event& event);
    private:
        uint8_t key_1;
        uint8_t key_2;
        uint8_t colid_x;
};

#endif