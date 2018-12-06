#include "Arduino.h"
#include "Meuservo.h"
#include <Servo.h>

MeuServo::MeuServo(Servo s1, Servo s2) {
  servo1 = s1;
  servo2 = s2;
  _delay=10;
}

void MeuServo::return0(Servo s){
  s.write(0);
  delay(500);
}

void MeuServo::transportar() {
  return0(servo1);
  return0(servo2);
  runServo(servo1, 0, 0);
  runServo(servo1, 0, 180);
  runServo(servo2, 0, 180);
  runServo(servo2, 180, 0);

  runServo(servo1, 180, 0);
  runServo(servo2, 0, 180);
  runServo(servo2, 180, 0);
}

void MeuServo::cumprimentar() {
  return0(servo1);
  return0(servo2);
  runServo(servo1, 0, 90);
  int oldDl = _delay;
  setDelay(1);
  runServo(servo2, 0, 180);
  runServo(servo2, 180, 0);
  
  runServo(servo2, 0, 180);
  runServo(servo2, 180, 0);
  
  runServo(servo2, 0, 180);
  runServo(servo2, 180, 0);
  setDelay(oldDl);
}

void MeuServo::setDelay(int _d) {
  _delay = _d;
}

void MeuServo::runServo(Servo s, int de, int ate) {
  int pos = 0;
  if (de < ate) {
    for (pos = de; pos < ate; pos++) {
      s.write(pos);
      delay(_delay);
    }
    delay(1000);
  } else {
    for (pos = de; pos >= ate; pos--) {
      s.write(pos);
      delay(_delay);
    }
    delay(1000);
  }
}
