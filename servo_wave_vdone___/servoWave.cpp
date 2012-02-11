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

  //initialize the servos
  //servoPositions = new int[numServos];
  //initializr the servo array
  //servos = new Servo[numServos];

  //set currentServo to 0
  int currentServo = 0;

  //initialize servoPosition array
  for(int i=0;i<numServos;i++){//wtf
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
  }
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

  for(int i=0;i<numServos;i++){
    //  servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
    //how do i use wavelength

    long freq=1;//this is a constant that sin is changing
    //return a foloat based on numservos sin(period) is 
    //period = period + time;
    period = freq+period;
//Serial.println(sin(period));
    calcAmp(period);
  }
}
//update the servoPosition array so that it corresponds with where it is at
float ServoWave::calcAmp(int p){
  amplitude =  90*sin(p)+90;
// Serial.println(amplitude);
  return amplitude;
}

void ServoWave::move(){
  // for all the servos from 0 to numServos
  // lookup a position i.e. servoPositions[i]
  // and write that to the corresponding servo, i.e. servos[i].write(...)
  
  //HERE IS WHERE I CAN USE THE WAVELENGTH -= GET THE POSITION OF THE 
  
  for(int i=0;i<numServos;i++){//wtf
    //  servoPositions[i] =amplitude;
    amplitude = servoPositions[currentServo];

    servos[i].write(amplitude);
    currentServo++;
    if(currentServo>numServos-1)
    {
      currentServo=0; 
    }
  }
}
