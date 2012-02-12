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
  int numServos = 15;
  //set currentServo to 0
  int currentServo = 0;



  //Serial.println(currentPosition);
  int lastPosition=-1;

  //initialize servoPosition array
  for(int i=0;i<numServos;i++){//wtf
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
    //(angle)

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
  //amplitude +=0.02;
  //float x =amplitude;

  // n is number of positions per half cycle
  // so y pos +=180/n

  //numservos / num
  //wavelength is the number of servos per one cycle

//have one go, modulo for the period/n or something (phas fact. being delay from one to the next)
long counter=0 ;

    if(counter%1000==0){


  if(amplitude > lastPosition||amplitude<=0){
    lastPosition =amplitude;

    amplitude+=180/wavelength; 
    
        }
  
  if(amplitude < lastPosition||amplitude>=180){
    lastPosition = amplitude;

    amplitude-=180/wavelength; 
    
    //try to add more steps
    //change 180 to be a different steps
    //set current servos to zero and return
  }
 }
 counter++;

}

  //servoPositions[amplitude];




  //for(int i=0;i<numServos;i++){
 

  //compare the position it is at now, from the position last, then if less, subtract, if greater, add that value

//lastPosition = currentPositio
 // servoPositions[lastPosition] = servoPositions[amplitude];



//update the servoPosition array so that it corresponds with where it is at
float ServoWave::calcAmp(int p){
  int a =  90*sin(p)+90;
  // Serial.println(amplitude);
  return a;
}

void ServoWave::move(){
  // for all the servos from 0 to numServos
  // lookup a position i.e. servoPositions[i]
  // and write that to the corresponding servo, i.e. servos[i].write(...)

  //HERE IS WHERE I CAN USE THE WAVELENGTH -= GET THE POSITION OF THE 

/*  for(int i=0;i<numServos;i++){//wtf

 for(int i=0;i<1;i++){
 servos[i].write(amplitude);
 }

    //  servoPositions[i] =amplitude;
    servoPositions[currentServo] = amplitude;

    servos[i].write(servoPositions[currentServo] );
    currentServo++;
    if(currentServo>numServos-1)
    {
      currentServo=0; 
    }
  }
  */
//    for(int i=0;i<numServos;i++){//wtf
//  servo.write(amplitude);
//    }
}


