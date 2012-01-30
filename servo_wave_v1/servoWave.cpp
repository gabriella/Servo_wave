#include "ServoWave.h"
#include "WProgram.h"

//constructor with four argiuments about the wave
ServoWave::ServoWave(int _numServos, int _amplitude, long _period, int _wavelength){
 numServos = _numServos;
amplitude = _amplitude;
period = _period;
wavelength = _wavelength;

//set current servo to 0


int currentServo = 0;

//initialize servoPosition array
for(int i=0;i<numServos;i++){//wtf
int  servoPositions[i];
}
//initializr the servo array
}


//SO MANY QUESTIONS: when void, when to return something; how to set something and initialize something


//Classname::Functionname

//set currentServo to 0
/*
void ServoWave::setServo(int _currentServo){
  currentServo = _currentServo;
  currentServo = 0;//this is totally wrong
}
void ServoWave::servoPos(){ 
}
void ServoWave::servoArray(){
}*/
//initialize the servoPosition array
//initialize the servo array
 
}

ServoWave::addServo(Servo servo){
 servos[currentServo]=servo;
currentServo++; 
}

ServoWave::update(){
  

  //calc position of each
  //servo based on its prev position
  //add amp/period/wavelength
  
  //update the servo to that position
  
  //update the servoPosition array so that it corresponds with where it is at
}
float ServoWave:: getSpeed(){
  return period;
  //again so wrong?
}
