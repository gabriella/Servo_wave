#include "ServoWave.h"


//constructor with four argiuments about the wave
ServoWave::ServoWave() {

//try define
//preprocessor 
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}

ServoWave::ServoWave(int _numServos, int _amplitude, long _period, int _wavelength){
  numServos = _numServos;
  amplitude = _amplitude;
  period = _period;
  wavelength = _wavelength;

  //servoPositions = new int[numServos];
  
    //initializr the servo array
  //servos = new Servo[numServos];

  int currentServo = 0;

  //initialize servoPosition array
  for(int i=0;i<numServos;i++){//wtf
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
}
//  for(int i=0;i<numServos;i++)
//  {
//   servos[i]= 
//  }




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
//  for(int i=0;i<numServos;i++)
//  {
//   servos[i].write(servoPositions[i]); 
//  }
  for(int i=0;i<numServos;i++){
  //  servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 


long freq=100;//this is a constant that sin is changing
//return a foloat based on numservos sin(period) is 
//long time = millis();
//period = period + time;
period = freq*period;
calcAmp(period);
  




//for(int i = numservos-1; i > 0; i--){
//    servoValues[i] = servoValues[i-1];
//  }

//for(int i=0;i<numServos;i++){//wtf
//    servoPositions[i] =amplitude;//add values for all servos depending on values in the constructor
 /*   
 numServos = 
  amplitude = 
  period = 
  wavelength = 
    */
    


}

/*
  
//  float dx = TWO_PI/period*
 // float wavelength = //number of servos for one full wavet
  float amplitude = new float[servo/xspacing]
  
 float  wavelengths_entire = wavelength*(TWO_PI)/numServos;
  float amplitude = numServos / wavelength_entire; //36 servos / 2
  float period = wavelengths_entire/time;
  float time = //time per
  
  float period = //how long until it repeats*/
//  int xspacing = wavelength 
//  
//loop through all of them, calculate the positions


//what greg showed me: a pointer to an int is really a pointer to the 0th position in an array. so int* myarray
//because it allots a value to something that is the first in a bunch, you dont know how many
//so it is used here cause i dont know how many servos and servopositions i will have

  //calc position of each
  //servo based on its prev position
  //add amp/period/wavelength

  //update the servo to that position
}
  //update the servoPosition array so that it corresponds with where it is at
float ServoWave::calcAmp(int p){
  
  //degree
  
  amplitude =  180*sin(p)+90;
  return amplitude;
}

void ServoWave::move(){
  // for all the servos from 0 to numServos
      // lookup a position i.e. servoPositions[i]
      // and write that to the corresponding servo, i.e. servos[i].write(...)
     
      for(int i=0;i<numServos;i++){//wtf
  //  servoPositions[i] =amplitude;
      amplitude = servoPositions[currentServo];
  
  servos[i].write(servoPositions[currentServo]);
  currentServo++;
  if(currentServo>numServos-1)
  {
   currentServo=0; 
  }
}


}
//do I have to adjust then do i have to pass down the values? 

/*
ServoWave
float ServoWave:: getSpeed(){
  return period;
  //again so wrong?
}
*/

