#ifndef CLOCK_H
#define CLOCK_H

#include <cstdint>

class Clock {
    public:
        Clock();
        // m clock and t clock
        uint16_t m, t;
};

#endif