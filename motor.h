// #include "Arduino.h"
#ifndef MOTOR_H
#define MOTOR_H
class Motor{
  private:
    int pwmPin;
    int selPin;

  public:
    Motor();
    Motor(int pwmPin, int selPin);
    void CW(int pwm);
    void CCW(int pwm);
    void stop();
    void setupPin();
};
#endif