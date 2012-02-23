#include "servoWave.h"
#include "Metro.h"
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
  float p = 0.5;
  //int total = int(TWO_PI/0.01);//total num of index pioints, until the amplitude is back at zero
  int numServos = _numServos;
  //set currentServo to 0
  int currentServo = 0;
  int lastPosition=-1;
  int steps = 5;
  long previousMillis = 0;
  long lastUpdatedAt = millis();
  
  int TOTAL_INDICES=200;
  int TOTAL_NODES=10;
  //initialize servoPosition array



  for(int i=0;i<numServos;i++){
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument     
  }





//float wave[200]= wave[200] ;
//  int index[10]=index[10];
  float a=0;


  for (int i = 0; i < TOTAL_INDICES; i++) {
    wave[i] = (sin(a) + 1.0) * 180.0;
    a+=0.05;
    Serial.println(wave[i]);
  }
  for (int i = 0; i < TOTAL_NODES; i++) {
    index[i] = i*5;
  }
}

void ServoWave::update(){
  for (int i=0;i<TOTAL_NODES;i++) {
    Serial.print((float)wave[index[i]]);
    Serial.print(" ");
    Serial.println(index[i]);
    index[i] = (index[i]+1) % TOTAL_INDICES;
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




void ServoWave::move(){
  //  for (int i=0;i<10;i++){
  //    servos[i].write(wave[index[i]]); 
  //  }
}
int ServoWave::calculateAngle(){
}
void ServoWave::passDownValues(int firstValue){

}

void ServoWave::adjustServos(int curA){
}



