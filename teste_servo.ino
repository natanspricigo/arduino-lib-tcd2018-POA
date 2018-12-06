#include <Servo.h>
#include "meuservo.h"

const int pinoServo1 = 5;
const int pinoServo2 = 6;

Servo s1;
Servo s2;

MeuServo meuservo(s1, s2);

void setup () {
  s1.attach(pinoServo1);
  s1.write(0);
  s2.attach(pinoServo2);
  s2.write(0);
}

void loop(){
  delay(2000);
  meuservo.transportar();
  meuservo.cumprimentar();
}
