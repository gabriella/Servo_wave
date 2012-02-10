#include <Servo.h>

#include "ServoWave.h"

Servo servo1;
Servo servo2;
ServoWave servoWave;

void setup(){
  servoWave = ServoWave(5, 90, 200, 2);
  servo1.attach(1);
  servo2.attach(2);  
  servoWave.addServo(servo1);
  servoWave.addServo(servo2);
}

void loop(){
  servoWave.update(); 
  //servoWave.move();
}

