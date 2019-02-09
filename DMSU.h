/**
 *  @author:
 *  @date: 09-02-2019
 *  @version: 1.0
 */
#ifndef H_DMSU
#define H_DMSU

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

// Debug
#define DEBUG

#define VCC 5

#define M   0
#define CM  1
#define MM  2

class DMSU{
    public:
        DMSU(uint8_t pin);
        float read(uint8_t unit = CM);   // read distance in cm
    private:
        uint8_t _pin;
        // theta 0: 0.0025236
        // theta 1: 0.0259679
        // theta 2: 0.0070634
};

#endif
