#include "motor.h"
#ifndef RB_H
#define RB_H

class RangkaBawah{
  private:
    Motor motorFR;
    Motor motorFL;
    Motor motorBR;
    Motor motorBL;

    // Motor enc1a;
    // Motor enc1a;
    // Motor enc2a;
    // Motor enc2b;
    // Motor enc3a;
    // Motor enc3b;
    // Motor enc4a;
    // Motor enc4b;
  public:
    RangkaBawah(
      Motor motorFR,
      Motor motorFL,
      Motor motorBR,
      Motor motorBL
    );

    // Encoder(
    //   Motor enc1a,
    //   Motor enc2a,
    //   Motor enc2b,
    //   Motor enc3a,
    //   Motor enc3b,
    //   Motor enc4a,
    //   Motor enc4b
    // );

    void moveRobot(float v_w1, float v_w2, float v_w3, float v_w4);
    void moveRobotOmega();
    void setupPin();
    void maju();
    void mundur();
    void kanan();
    void kiri();
    void stop();
};
#endif