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

  for (int i = 0; i < TOTAL_INDICES; i++) {
    // wave[i] = (sin(a) + 1.0) * ampMax;//ampMax defines the amount it strays from the 0 position 
    wave[i] = lmap(sin(a),-1.0,1.0,0.0,angle);//180.0);
    a+=0.1;//
    Serial.println(wave[i]);
  }

  for (int i = 0; i < TOTAL_NODES; i++) {
    index[i] = i*indexSpacing%TOTAL_INDICES;//i*wavelength;
  }
}
  

void ServoWave::update(){
       // Serial.print(ampMax);
  for (int i=0;i<TOTAL_NODES;i++) {
        Serial.print((ampMax*wave[index[i]])); 
    //Just fyi, multiplying ampMax by  ((float)wave[index[i]]) is changing the max amplitude
    Serial.print(" ");
    index[i] = (index[i]+1) % TOTAL_INDICES;//TOTAL_INDICES;//numservos in wavelength  
  }
  Serial.println();
}

void ServoWave::calcIndex(float p){
   for (int i = 0; i < TOTAL_NODES; i++) {
     indexSpacing = p;
    index[i] = (index[i]+(i*indexSpacing))%TOTAL_INDICES;//i*wavelength;
  }
}
void ServoWave::calcPeriod(float per){
  TOTAL_INDICES = TWO_PI/period;
  for (int i = 0; i < TOTAL_INDICES; i++) {
    // wave[i] = (sin(a) + 1.0) * ampMax;//ampMax defines the amount it strays from the 0 position 
    wave[i] = lmap(sin(a),-1.0,1.0,0.0,angle);//180.0);
    a+=period;
  }
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
    servos[i].write(ampMax/2*wave[index[i]]); 
    //changing ampMax will change max amplitude
  }
}

