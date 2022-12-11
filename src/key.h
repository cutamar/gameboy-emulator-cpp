#ifndef KEY_H
#define KEY_H

#include <cstdint>

class Key {
    public:
        Key();
        void Reset();
        uint8_t ReadByte();
        void WriteByte(uint8_t data);
        void KeyDown();
        void KeyUp();
    private:
        uint8_t key_1;
        uint8_t key_2;
        uint8_t colid_x;
};

#endif