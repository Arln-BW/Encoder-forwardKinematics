#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder {
public:
    Encoder(uint8_t pinA, uint8_t pinB, int PPR);
    void updatePulse();
    float getVelocity();
    void reset();

private:
    uint8_t pinA, pinB; // pin encoder
    int PPR; // pulse per revolution
    volatile int pulseCount; // jumlah pulsa
    unsigned long prevTime; // waktu sebelumnya
    float velocity; // kecepatan motor
};

#endif
