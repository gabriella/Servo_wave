#include <Servo.h>

#include "ServoWave.h"

//Servo servo1;
//Servo servo2;
//Servo servos[15];

ServoWave servoWave;

long counter = 0;
//int period  = 250 milliseconds;//how long until the wave repeats 
int numServos = 15;//this has to be 15



void setup(){
  Serial.begin(9600);
  servoWave = ServoWave(numServos, 90, 20, 2, 90);
  //   int _numServos, int _amplitude, long _period, int _wavelength
  
 //numservos = number of servos in the unit
 //amplitude = 
 //period
 //wavelength = number of servos each wave length will be
 for(int i=0;i<numServos;i++){
  servoWave.servos[i].attach(i+2);
  
  
  //no - i have to add servsowave...? 
  
 // servo2.attach();  
  servoWave.addServo(servoWave.servos[i]);
  //servoWave.addServo(servo[i]);
}
}

void loop(){
for(int i=0;i<15;i++){
servoWave.update(); 
 // servoWave.servoPositons;
 
  servoWave.move();
  //when to add the object when to add ther servo
  
}
 // for(int i=0

//if(counter%1000==0)
//{
// servoWave.period =100; 
// Serial.print("1000");
// 
// //get the period to change
// 
// 
//}
//counter++;


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
