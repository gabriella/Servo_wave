#include "servoWave.h"
#include "Metro.h"
ServoWave::ServoWave() {
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}

ServoWave::ServoWave(int _numServos, float _theta,  float _dx, int _ampMax, float _speed){

  //theta = theta, period = speed, amp = amp, 

  
  numServos = _numServos;//servos of the whole unit
  theta = _theta;//height of wave 
 // period = _period; //in milliseconds
  dx = _dx;//how many servos long the wave will be
  ampMax=_ampMax;
  speed = _speed;
  //indexSpacing=_indexSpacing;
  
   theta=0;
   dx = 0.3;
   speed = 0.009;
  numServos = _numServos;
  
  currentServo = 0;//set currentServo to 0
  long previousMillis = 0;
  long lastUpdatedAt = millis();

  TOTAL_NODES=10;
  
  //initialize servoPosition array
  for(int i=0;i<numServos;i++){
    servoPositions[i] = 90.00; // starting position for all servos. could be passed as an argument     
  }

  Serial.println(theta);
  Serial.println(dx);
  Serial.println(ampMax);
  Serial.println(speed); 
}

void ServoWave::update(){
//  Serial.println(theta);
//  Serial.println(dx);
//  Serial.println(ampMax);
//  Serial.println(speed); 
  
theta +=speed;
float x = theta;
//Serial.print
for (int i=0;i<numServos;i++){

servoPositions[i] = sin(x)*ampMax;
x+=dx;
 
 Serial.print(90+servoPositions[i]);
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
   servos[i].write(90+servoPositions[i]);
  }
}

