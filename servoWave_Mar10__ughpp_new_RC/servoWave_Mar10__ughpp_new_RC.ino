#include <Servo.h>

#include "ServoWave.h"
#include <Metro.h>

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

  if(Serial.available()){
    incomingData=Serial.read();
    if(incomingData=='x'){
      servoWave.ampMax++; 
      Serial.print(" ampMax = ");
      Serial.println(servoWave.ampMax);      
    }
    else if(incomingData=='z'){
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

    if(incomingData=='s'){
      servoWave.dx=servoWave.dx+0.01; 
      Serial.print(" dx = ");
      Serial.println(servoWave.dx);      
    }
    else if(incomingData=='a'){
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

    if(incomingData=='w'){
      servoWave.speed=servoWave.speed-0.01;
      Serial.print(" speed = ");
      Serial.println(servoWave.speed);      
    }
    else if(incomingData=='q'){
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

  // servoWave.ampMax  = map(analogRead(analogPin1), 0,1023, 0,90);
  //servoWave.dx = analogRead(analogPin3)/1000.00;// map(analogRead(analogPin2),0,1023,0,5);//check these values...
  // servoWave.speed  = map(analogRead(analogPin2),0,1023, 0,200)/1000.00;
  //Serial.print("amplitude:");
  //Serial.print(servoWave.ampMax);
  //Serial.print(" dx:");
  //Serial.print(servoWave.dx);
  //Serial.print(" speed:");
  //Serial.println(servoWave.speed);
  for(int i=0;i<12;i++){
    servoWave.update(); 
    servoWave.move();
  }
  delay(20);
}



