#include <Servo.h>

#include "ServoWave.h"

Servo servo1;
Servo servo2;
ServoWave servoWave;

//int period  = 250 milliseconds;//how long until the wave repeats 




void setup(){
  servoWave = ServoWave(5, 90, 200, 2);
  //   int _numServos, int _amplitude, long _period, int _wavelength
  
 //numservos = number of servos in the unit
 //amplitude = 
 //period
 //wavelength = number of servos each wave length will be
  servo1.attach(1);
  servo2.attach(2);  
  servoWave.addServo(servo1);
  servoWave.addServo(servo2);
}

void loop(){
  servoWave.update(); 
  //servoWave.servoPositons;
  //servoWave.move();
}


