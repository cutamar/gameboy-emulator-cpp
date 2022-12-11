#include "key.h"

Key::Key() : key_1{0x0F}, key_2{0x0F}, colid_x{0} {}

void Key::Reset() {
    key_1 = 0x0F;
    key_2 = 0x0F;
    colid_x = 0;
}

uint8_t Key::ReadByte() {
    switch(colid_x) {
        case 0x00:
            return 0x00;
            break;
        case 0x10:
            return key_1;
            break;
        case 0x20:
            return key_2;
            break;
        default:
            return 0x00; 
    }
}

void Key::WriteByte(uint8_t data) {
    colid_x = data & 0x30;
}

void Key::KeyDown() {
    switch (0x00)
    {
    case 39:
        key_2 &= 0xE;
        break;
    case 37:
        key_2 &= 0xD;
        break;
    case 38:
        key_2 &= 0xB;
        break;
    case 40:
        key_2 &= 0x7;
        break;
    case 90:
        key_1 &= 0xE;
        break;
    case 88:
        key_1 &= 0xD;
        break;
    case 32:
        key_1 &= 0xB;
        break;
    case 13:
        key_1 &= 0x7;
        break;
    
    default:
        break;
    }
}

void Key::KeyUp() {
    switch (0x00)
    {
    case 39:
        key_2 &= 0x1;
        break;
    case 37:
        key_2 &= 0x2;
        break;
    case 38:
        key_2 &= 0x4;
        break;
    case 40:
        key_2 &= 0x8;
        break;
    case 90:
        key_1 &= 0x1;
        break;
    case 88:
        key_1 &= 0x2;
        break;
    case 32:
        key_1 &= 0x4;
        break;
    case 13:
        key_1 &= 0x8;
        break;
    
    default:
        break;
    }
}