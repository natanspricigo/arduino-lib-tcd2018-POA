#ifndef MeuServo_h
#define MeuServo_h
#include "Arduino.h"
#include <Servo.h>

class MeuServo{
  public:
    MeuServo(Servo s1, Servo s2);
    void transportar();
    void cumprimentar();
    void setDelay(int _d);
    void return0(Servo s);
  private:
    Servo servo1;
    Servo servo2;
    int _delay;
    void runServo(Servo s, int de, int ate);
};

#endif
