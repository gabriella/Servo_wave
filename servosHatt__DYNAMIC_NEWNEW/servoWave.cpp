#include "servoWave.h"
ServoWave::ServoWave() {
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}

ServoWave::ServoWave(int _numServos, float _angle, unsigned long _period, int _wavelength, int _ampMax){

  numServos = _numServos;//servos of the whole unit
  angle = _angle;//height of wave 
  period = _period; //in milliseconds
  wavelength = _wavelength;//how many servos long the wave will be
  ampMax=_ampMax;
  //long unsigned periodBis = period;
  float p = 0;
  int total = int(TWO_PI/0.01);//total num of index pioints, until the amplitude is back at zero

  int numServos = _numServos;
  //set currentServo to 0
  int currentServo = 0;
  int lastPosition=-1;
  int steps = 5;
  long previousMillis = 0;
  long lastUpdatedAt = millis();

  float wave[total];
  p = 0;

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

  for(int i=0;i<total;i++){
    wave[i] = map(sin(p), -1,1,0,180);
    p+=0.05;//THIS IS WHA T NMUST INFLUENCE SPEED
    Serial.println(wave[i]);
  }
  for(int i=0;i<numServos;i++){
    index[i] = i*2;//CHANGE THIS FOR CHANGING THE DIFFERENCE BETEWWEEN THEM
  }
}
void ServoWave::move(){
  for(int i=0;i<numServos;i++){
    //angle  = wave[index[i]];
    //index[i] = (index[i]+1)%total;
    angle = servoPositions[i];
    Serial.println(angle);
  }
}

int ServoWave::calculateAngle(){
}
void ServoWave::passDownValues(int firstValue){
}

void ServoWave::adjustServos(int curA){
}


