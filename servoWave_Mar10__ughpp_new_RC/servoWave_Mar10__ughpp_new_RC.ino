#include <Servo.h>

#include "ServoWave.h"
//#include <Metro.h>

const int analogPin1 = A0 ;
const int analogPin2 =A1;
const int analogPin3 = A2;

int lastPeriodState = 0;
int lastIndexState = 0;

ServoWave servoWave;
int numServos = 12;//this has to be 15

int incomingData;
void setup(){
  Serial.begin(57600);

  servoWave = ServoWave(numServos, 0, 0.4, 60, 0.04);
  //ServoWave::ServoWave(int _numServos, float _angle, float _period, int _wavelength, int _ampMax, int _indexSpacing){
  //  //   ServoWave(int _numServos, float _theta,  float _dx, int _ampMax, float _speed);
  for(int i=0;i<numServos;i++){
    servoWave.servos[i].attach(i+2);
    servoWave.addServo(servoWave.servos[i]);
  }
}

void loop(){

  //1 increases amplitude. 2 decreases amp
  //3 increases period, 4 decreases
  //5 increases speed, 6 decreases
  
  if(Serial.available()){
    incomingData=Serial.read();
    if(incomingData=='1'){
      servoWave.ampMax++; 
      Serial.print(" ampMax = ");
      Serial.println(servoWave.ampMax);      
    }
    else if(incomingData=='2'){
      servoWave.ampMax--;
      Serial.print(" ampMax = ");
      Serial.println(servoWave.ampMax);
    }
    if(servoWave.ampMax>=90){
      servoWave.ampMax = 90; 
    }
    if(servoWave.ampMax<=10){
      servoWave.ampMax=  10;  
    }

    if(incomingData=='3'){
      servoWave.dx=servoWave.dx+0.01; 
      Serial.print(" dx = ");
      Serial.println(servoWave.dx);      
    }
    else if(incomingData=='4'){
      servoWave.dx=servoWave.dx-0.01;
      Serial.print(" dx = ");
      Serial.println(servoWave.dx);

    }
    if(servoWave.dx>=1){
      servoWave.dx = 1; 
    }
    if(servoWave.dx<=.10){
      servoWave.dx=  .10;  
    }

    if(incomingData=='5'){
      servoWave.speed=servoWave.speed-0.01;
      Serial.print(" speed = ");
      Serial.println(servoWave.speed);      
    }
    else if(incomingData=='6'){
      servoWave.speed=servoWave.speed+0.01;
      Serial.print(" speed = ");
      Serial.println(servoWave.speed);
    }
    if(servoWave.speed>=.200){
      servoWave.speed = .200; 
    }
    if(servoWave.speed<=.010){
      servoWave.speed=  .010;  
    }
  }


  for(int i=0;i<12;i++){
    servoWave.update(); 
    servoWave.move();
  }
  delay(20);
}



