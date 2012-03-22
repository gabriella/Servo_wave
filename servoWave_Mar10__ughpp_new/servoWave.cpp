#include "servoWave.h"
#include "Metro.h"
ServoWave::ServoWave() {
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}

ServoWave::ServoWave(int _numServos, float _angle, float _period, int _wavelength, int _ampMax, int _indexSpacing){

  numServos = _numServos;//servos of the whole unit
  angle = _angle;//height of wave 
  period = _period; //in milliseconds
  wavelength = _wavelength;//how many servos long the wave will be
  ampMax=_ampMax;
  indexSpacing=_indexSpacing;
   a=0;
  numServos = _numServos;
  currentServo = 0;//set currentServo to 0
  long previousMillis = 0;
  long lastUpdatedAt = millis();

  TOTAL_INDICES=TWO_PI/0.1;//total num of index pioints, until the amplitude is back at zero
  TOTAL_NODES=10;
  
  //initialize servoPosition array
  for(int i=0;i<numServos;i++){
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument     
  }
  TOTAL_INDICES=TWO_PI/period;//TWO_PI/period;
 // TOTAL_INDICES = 0.125;
  Serial.println(TOTAL_INDICES);
  Serial.println(a);
  Serial.println(period);
  Serial.println(ampMax);
  Serial.println(angle); 
}

void ServoWave::update(){
int amp = 10;
a +=0.02;
float x = a;
for (int i=0;i<TOTAL_NODES;i++){

wave[i] = lmap(sin((x*period)*amp), -1.0,1.0, 0.0, 180.0) ;
  x+=TOTAL_INDICES; 
 Serial.print(wave[i]);
 Serial.print(" ");
}
  Serial.println();
}

float ServoWave::lmap(float val, float inMin, float inMax, float outMin, float outMax) {
  return outMin + (outMax - outMin) * ((val - inMin) / (inMax - inMin));
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
  for (int i=0;i<10;i++){
   // servos[i].write(ampMax/2*wave[index[i]]); 
   servos[i].write(wave[i]);
    //changing ampMax will change max amplitude
  }
}

