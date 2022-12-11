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

void Key::KeyDown(SDL_Event& event) {
    switch (event.key.keysym.scancode)
    {
    case SDL_SCANCODE_RIGHT:
        key_2 &= 0xE;
        break;
    case SDL_SCANCODE_LEFT:
        key_2 &= 0xD;
        break;
    case SDL_SCANCODE_UP:
        key_2 &= 0xB;
        break;
    case SDL_SCANCODE_DOWN:
        key_2 &= 0x7;
        break;
    case SDL_SCANCODE_Q:
        key_1 &= 0xE;
        break;
    case SDL_SCANCODE_W:
        key_1 &= 0xD;
        break;
    case SDL_SCANCODE_SPACE:
        key_1 &= 0xB;
        break;
    case SDL_SCANCODE_RETURN:
        key_1 &= 0x7;
        break;
    
    default:
        break;
    }
}

void Key::KeyUp(SDL_Event& event) {
    switch (event.key.keysym.scancode)
    {
    case SDL_SCANCODE_RIGHT:
        key_2 &= 0x1;
        break;
    case SDL_SCANCODE_LEFT:
        key_2 &= 0x2;
        break;
    case SDL_SCANCODE_UP:
        key_2 &= 0x4;
        break;
    case SDL_SCANCODE_DOWN:
        key_2 &= 0x8;
        break;
    case SDL_SCANCODE_Q:
        key_1 &= 0x1;
        break;
    case SDL_SCANCODE_W:
        key_1 &= 0x2;
        break;
    case SDL_SCANCODE_SPACE:
        key_1 &= 0x5;
        break;
    case SDL_SCANCODE_RETURN:
        key_1 &= 0x8;
        break;
    
    default:
        break;
    }
}