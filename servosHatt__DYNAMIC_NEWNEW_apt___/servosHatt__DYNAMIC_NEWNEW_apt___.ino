#include <Servo.h>

#include "ServoWave.h"
#include <Metro.h>

const int analogPin1 = A0 ;
const int analogPin2 =A1;
const int analogPin3 = A2;

ServoWave servoWave;

long counter = 0;
//int period  = 250 milliseconds;//how long until the wave repeats 
int numServos = 12;//this has to be 15



void setup(){
  Serial.begin(57600);



  servoWave = ServoWave(numServos, 135, 0.05, 10, 180.0, 5);
  //   int _numServos, int _amplitude, long _period, int _wavelength, int amp_max, int indexSpacing
  //Metro metro =Metro(servoWave.period);



  for(int i=0;i<numServos;i++){



    servoWave.servos[i].attach(i+2);

    servoWave.addServo(servoWave.servos[i]);
    //servoWave.addServo(servo[i]);
  }
}

void loop(){
 

  for(int i=0;i<12;i++){
    servoWave.update(); 
    servoWave.move();

//set some parameter here..


//servoWave.indexSpacing = 1;


 servoWave.ampMax  = map(analogRead(analogPin1), 0,1023, 0,270);
  servoWave.period  =  (map(analogRead(analogPin2),0,1023,7,90))/1000;//check these values...
Serial.print(" period: ");
Serial.println(servoWave.period);
  
  servoWave.indexSpacing  = map(analogRead(analogPin3),0,1023, 1,10);
  //Serial.println(servoWave.indexSpacing);
//  Serial.print(" indexSpacing: ");
//  Serial.println(servoWave.indexSpacing);
//  


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

