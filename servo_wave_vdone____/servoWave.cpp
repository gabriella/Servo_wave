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

  for(int i=0;i<numServos;i++){
    int changer = 1;

period = period + changer;
   amplitude = abs(sin(period));
   amplitude = map(amplitude, 0,1,0,180);
   
    changer=changer+0.1;
    
   // servoPositions[i] = 180; 
    
   //  amplitude = calcAmp(period);
  }
    
    
    //numpositions spaced in time
    //period / n is the 
    //servo
    
    /*
    
    //  servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
    //how do i use wavelength
    //servoPositions[i] = sin(x);
   // x+=(360/period);
    long freq=1;//this is a constant that sin is changing
    //return a foloat based on numservos sin(period) is 
    //period = period + time;
    // period = millis()*i*period;
    freq++;
    // amplitude = servoPositions[i];


    //period= i* 360/15;
    period += period*i;
    //have freq have to do with servoPosition
    //Serial.println(sin(period));


  }
  */
  
  //derivative for sin? is the cosine
  //for every servoposition i , get the cos, gives you a values for the slopem , translate to rotatein
  //subtract previos rot from 
  
  
  
}

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

  for(int i=0;i<numServos;i++){//wtf
  
  
  
  
  
    //  servoPositions[i] =amplitude;
    servoPositions[currentServo] = amplitude;

    servos[i].write(servoPositions[currentServo] );
    currentServo++;
    if(currentServo>numServos-1)
    {
      currentServo=0; 
    }
  }
}

