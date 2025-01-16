#include "Encoder.h"

Encoder* encoderPtr;
void ISR_updatePulse() {
    encoderPtr->updatePulse(); // Akses fungsi anggota melalui pointer global
}

Encoder::Encoder(uint8_t pinA, uint8_t pinB, int PPR) {
    this->pinA = pinA;
    this->pinB = pinB;
    this->velocity = 0;
    this->prevTime = 0;
    this->PPR = PPR;
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pinA), ISR_updatePulse, RISING);
}

void Encoder::updatePulse() {
    bool A = digitalRead(pinA);
    bool B = digitalRead(pinB);
    if (A == B) {
        pulseCount++; // Arah putaran searah jarum jam
    } else {
        pulseCount--; // Arah putaran berlawanan jarum jam
    }
}

float Encoder::getVelocity() {
    unsigned long currTime = micros();
    float deltaT = (currTime - prevTime) / 1e6; // Waktu dalam detik
    this->prevTime = currTime; // Perbarui waktu sebelumnya
    // Hitung kecepatan dalam RPM
    velocity = (pulseCount * 60.0) / (PPR * deltaT);
    // Reset pulse count setelah pembacaan
    pulseCount = 0;
    return velocity;
}

void Encoder::reset() {
    velocity = 0;
}
