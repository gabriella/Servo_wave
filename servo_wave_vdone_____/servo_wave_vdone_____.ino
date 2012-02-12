#include <Servo.h>

#include "ServoWave.h"

Servo servo1;
Servo servo2;
ServoWave servoWave;
int counter;
//int period  = 250 milliseconds;//how long until the wave repeats 




void setup(){
  Serial.begin(9600);
  servoWave = ServoWave(15, 90, PI/3, 10);
  //   int _numServos, int _amplitude, long _period, int _wavelength
  
 //numservos = number of servos in the unit
 //amplitude = 
 //period
 //wavelength = number of servos each wave length will be
  servo1.attach(2);
  servo2.attach(3);  
  servoWave.addServo(servo1);
  servoWave.addServo(servo2);
}

void loop(){
//for(int i=0;i<15;i++){
  if (counter%1000==0){
  servoWave.update(); 
  }
 // servoWave.servoPositons;
  servoWave.move();
  //for(int i=0;i<servoWave.numServos;i++){
  // Serial.println("here");
  Serial.print("Amplitude: ");
  Serial.println(servoWave.amplitude);
//  Serial.print(", Sin(Period): ");
//  Serial.println(sin(servoWave.period));
//  Serial.print("sin times one eighty: ");
//  Serial.println(abs(sin(TWO_PI)*180));
 //why am i only getting ninety for this ugh
//  }
delay(15);
}


