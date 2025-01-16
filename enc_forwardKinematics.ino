#include <Arduino.h>
#include "Wire.h"
#include "Header.h"

#define pin1 2
#define pin2 3
#define pin3 19
#define pin4 18
#define perimeter 18.84
#define pulse 134

// -------------- Kinematika rangka bawah
Kinematic invKinematic; 
ForKinematic forKinematic;

// -------------- setup encoder
Encoder encoder1(enc1A,enc1B, 134), encoderx(encxA,encxB, 600), encodery(encyA,encyB, 600);
double encRad1 = 0;
double encRad2 = (3.14/180)*90;
double encRad3 = (3.14/180)*224.8;

float velocityX = forKinematic.encVelocityX(encRad1, encRad2, encRad3, encoder1.getVelocity(), encoderx.getVelocity(), encodery.getVelocity());
float velocityY = forKinematic.encVelocityY(encRad1, encRad2, encRad3, encoder1.getVelocity(), encoderx.getVelocity(), encodery.getVelocity());
float omegaEnc  = forKinematic.encOmega(encoder1.getVelocity(), encoderx.getVelocity(), encodery.getVelocity());

// -------------- object seriat transfer
SerialTransfer mega;

// -------------- data serial transfer
struct movement{
  bool up, down, right, left;
  int16_t lx, ly;
  int16_t rx, ry;
} robot;

// ------------- setup motor
int pwm1, pwm2, pwm3, pwm4;
int pwm1Omega, pwm2Omega, pwm3Omega, pwm4Omega;

float v_w1, v_w2, v_w3, v_w4;
float v_w1Omega, v_w2Omega, v_w3Omega, v_w4Omega;

// ------------ setup sudut motor
double rad1 = (3.14/180)*44.8;
double rad2 = (3.14/180)*135.2;
double rad3 = (3.14/180)*224.8;
double rad4 = (3.14/180)*315.2;

int x, y;
float alpha, v_x, v_y, v_xOmega, v_yOmega;

// ------------- setup pin motor
Motor motorFR(2, 3);
Motor motorFL(18, 19);
Motor motorBR(2, 3); // motor encoder 1
Motor motorBL(18, 19); // motor encoder 2

// Motor motorFR(5, 36);
// Motor motorFL(6, 34);
// Motor motorBR(9, 32); // motor encoder 1
// Motor motorBL(8, 30); // motor encoder 2

// ------------ untuk motor
RangkaBawah RB(motorFR, motorFL, motorBR, motorBL);

void setup() {
  Serial.begin(9600);
  RB.setupPin();
}

void loop() {
  float totalVelocity = sqrt((velocityX*velocityX)+(velocityY*velocityY));
  Serial.print(velocityX);
  Serial.print(" | ");
  Serial.print(velocityY);
  Serial.print(" | ");
  Serial.println(totalVelocity);
}