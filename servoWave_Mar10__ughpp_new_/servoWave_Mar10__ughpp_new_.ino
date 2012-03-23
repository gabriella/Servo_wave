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
  //servoWave.ampMax  = map(analogRead(analogPin1), 0,1023, 1,3);
 //servoWave.period = analogRead(analogPin3)*0.0005;// map(analogRead(analogPin2),0,1023,0,5);//check these values...
 // servoWave.indexSpacing  = map(analogRead(analogPin2),0,1023, 1,20);

  for(int i=0;i<12;i++){
    servoWave.update(); 
    servoWave.move();
    
   
    // Serial.println(periodState);
  }
  delay(10);
}


