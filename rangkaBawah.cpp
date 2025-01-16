// #include "Arduino.h"
#include "rangkaBawah.h"


RangkaBawah::RangkaBawah(Motor motorFR, Motor motorFL, Motor motorBR, Motor motorBL){
  this->motorFR = motorFR;
  this->motorFL = motorFL;
  this->motorBR = motorBR;
  this->motorBL = motorBL;
}

// RangkaBawah::Encoder(Motor enc1a, Motor enc2a, Motor enc2b, Motor enc3a, Motor enc3b, Motor enc4a, Motor enc4b){

// }

void RangkaBawah::setupPin(){
  motorFR.setupPin();
  motorFL.setupPin();
  motorBR.setupPin();
  motorBL.setupPin();
}

void RangkaBawah::moveRobot(float v_w1, float v_w2, float v_w3, float v_w4){
  if (v_w1 > 0) {
     motorFR.CW(v_w1);
   }else if (v_w1 < 0) {
     motorFR.CCW(v_w1*-1);
   }else {
     motorFR.stop();
  }

  if (v_w2 > 0) {
     motorFL.CW(v_w2);
   }else if (v_w2 < 0) {
     motorFL.CCW(v_w2*-1);
   }else {
     motorFL.stop();
  }

  if (v_w3 > 0) {
     motorBL.CW(v_w3);
   }else if (v_w3 < 0) {
     motorBL.CCW(v_w3*-1);
   }else {
     motorBL.stop();
  }

  if (v_w4 > 0) {
     motorBR.CW(v_w4);
   }else if (v_w4 < 0) {
     motorBR.CCW(v_w4*-1);
   }else {
     motorBR.stop();
  }
}

void RangkaBawah::moveRobotOmega(){
}

void RangkaBawah::maju(){
  motorFR.CW(150);
  motorFL.CCW(150);
  motorBR.CW(150);
  motorBL.CCW(150);
}
void RangkaBawah::mundur(){
  motorFR.CCW(150);
  motorFL.CW(150);
  motorBR.CCW(150);
  motorBL.CW(150);
}
void RangkaBawah::kanan(){
  motorFR.CCW(150);
  motorFL.CCW(150);
  motorBR.CW(150);
  motorBL.CW(150);
}
void RangkaBawah::kiri(){
  motorFR.CW(150);
  motorFL.CW(150);
  motorBR.CCW(150);
  motorBL.CCW(150);
}

void RangkaBawah::stop(){
  motorFR.CW(0);
  motorFL.CW(0);
  motorBL.CCW(0);
  motorBR.CCW(0);
}
