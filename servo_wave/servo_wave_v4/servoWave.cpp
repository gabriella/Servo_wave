#include "ServoWave.h"


//constructor with four argiuments about the wave
ServoWave::ServoWave() {


}

ServoWave::ServoWave(int _numServos, int _amplitude, long _period, int _wavelength){
  numServos = _numServos;
  amplitude = _amplitude;
  period = _period;
  wavelength = _wavelength;

  servoPositions = new int[numServos];
  
    //initializr the servo array
  servos = new Servo[numServos];

  int currentServo = 0;

  //initialize servoPosition array
  for(int i=0;i<numServos;i++){//wtf
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
  }
//  for(int i=0;i<numServos;i++)
//  {
//   servos[i]= 
//  }

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


void ServoWave::addServo(Servo servo){
  servos[currentServo]=servo;
  currentServo++; 
}

void ServoWave::addServo(Servo servo, int startingPosition){
  servos[currentServo]=servo;
  servoPositions[currentServo] = startingPosition;
  currentServo++; 
}

void ServoWave::update(){
  for(int i=0;i<numServos;i++)
  {
   servos[i].write(servoPositions[i]); 
  }
  
//loop through all of them, calculate the positions


//what greg showed me: a pointer to an int is really a pointer to the 0th position in an array. so int* myarray
//because it allots a value to something that is the first in a bunch, you dont know how many
//so it is used here cause i dont know how many servos and servopositions i will have

  //calc position of each
  //servo based on its prev position
  //add amp/period/wavelength

  //update the servo to that position

  //update the servoPosition array so that it corresponds with where it is at
}

void ServoWave::move(){
  // for all the servos from 0 to numServos
      // lookup a position i.e. servoPositions[i]
      // and write that to the corresponding servo, i.e. servos[i].write(...)
      
  
  /*servos[i].write(servoPositions[currentServo]);
  currentServo++;
  if(currentServo>numServos-1)
  {
   currentServo=0; 
  }*/
}

//do I have to adjust then do i have to pass down the values? 

ServoWave
float ServoWave:: getSpeed(){
  return period;
  //again so wrong?
}

