#include <Servo.h>

#include "ServoWave.h"
#include <Metro.h>

//Servo servo1;
//Servo servo2;
//Servo servos[15];


ServoWave servoWave;

long counter = 0;
//int period  = 250 milliseconds;//how long until the wave repeats 
int numServos = 15;//this has to be 15



void setup(){
  Serial.begin(9600);
  servoWave = ServoWave(numServos, 90, 1000, 2, 45);
  //   int _numServos, int _amplitude, long _period, int _wavelength
//Metro metro =Metro(servoWave.period);
 for(int i=0;i<numServos;i++){
  servoWave.servos[i].attach(i+2);
  
  servoWave.addServo(servoWave.servos[i]);
  //servoWave.addServo(servo[i]);
}
}

void loop(){
for(int i=0;i<15;i++){
servoWave.update(); 
 // servoWave.servoPositons;
// if(metro.check()==1){
  servoWave.move();
// }
  //when to add the object when to add ther servo
//  long time=millis();
 // Serial.println(counter);
//  if (counter%100==0){
//  servoWave.period=servoWave.period*2;
//  Serial.print("period=   ");
//    Serial.println(servoWave.period);
//  }
  counter++;

  
  
}
}

//this isn't wavelke
//i'm not using wavelength
//how do i make a dynamic array
//camaera stuff

//talk to some people 
//cam using IR, or servo, or whatever fits purposes
//perhaps over USB? 

//dynamic number of servos
//will this just be moving together
//how to have sin in arduino
//how to model this - 
//servo or servos
