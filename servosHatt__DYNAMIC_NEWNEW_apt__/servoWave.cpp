#include "servoWave.h"
#include "Metro.h"
ServoWave::ServoWave() {
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}


ServoWave::ServoWave(int _numServos, float _angle, float _period, int _wavelength, float _ampMax, int _indexSpacing){

  numServos = _numServos;//servos of the whole unit
  angle = _angle;//height of wave 
  period = _period; //in milliseconds
  wavelength = _wavelength;//how many servos long the wave will be
  ampMax=_ampMax;
  
  //long unsigned periodBis = period;
  

  float a=0;
   //p = 0.5;
  //int total = int(TWO_PI/0.01);//total num of index pioints, until the amplitude is back at zero
   numServos = _numServos;
  //set currentServo to 0
   currentServo = 0;
   lastPosition=-1;
   steps = 2;
  long previousMillis = 0;
  long lastUpdatedAt = millis();
  
   TOTAL_INDICES=360;
   TOTAL_NODES=10;
  //initialize servoPosition array


  for(int i=0;i<numServos;i++){
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument     
  }

  for (int i = 0; i < TOTAL_INDICES; i++) {
   // wave[i] = (sin(a) + 1.0) * ampMax;//ampMax defines the amount it strays from the 0 position
    
   wave[i] = lmap(sin(a),-1.0,1.0,0.0,ampMax);//180.0);
   // a+=0.05;
    a+=period;//
    Serial.println(wave[i]);
  }


 for (int i = 0; i < TOTAL_NODES; i++) {
    //int servoSpacing = wavelength/steps;
    int servoSpacing = (1/wavelength)*indexSpacing;
    
    //this has to be an index of like period/wavelength - basically it affects the amt of time it takes for the wave to go through x number of servos
    index[i] = i*indexSpacing;//i*wavelength;
//    Serial.print(" indexSpacing: ");
//    Serial.println(indexSpacing);
  }

}

void ServoWave::update(){
  
   
  
  for (int i=0;i<TOTAL_NODES;i++) {
    Serial.print((float)wave[index[i]]);
  Serial.print(" ");
    //Serial.print(index[i]);
    //Serial.print(" ");
    index[i] = (index[i]+1) % TOTAL_INDICES;//TOTAL_INDICES;//numservos in wavelength
    
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
     servos[i].write(wave[index[i]]); 
 }
}
int ServoWave::calculateAngle(){
}
void ServoWave::passDownValues(int firstValue){

}

void ServoWave::adjustServos(int curA){
}

//why not on mega only


