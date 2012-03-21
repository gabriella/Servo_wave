#include <Servo.h>

#include "ServoWave.h"
#include <Metro.h>

const int analogPin1 = A0 ;
const int analogPin2 =A1;
const int analogPin3 = A2;

int periodState = 0;
int lastPeriodState = 0;

ServoWave servoWave;
int numServos = 12;//this has to be 15

void setup(){
  Serial.begin(57600);

  servoWave = ServoWave(numServos, 135, 0.05, 5, 180, 4);
  //ServoWave::ServoWave(int _numServos, float _angle, float _period, int _wavelength, int _ampMax, int _indexSpacing){
  for(int i=0;i<numServos;i++){
    servoWave.servos[i].attach(i+2);
    servoWave.addServo(servoWave.servos[i]);
  }
}

void loop(){
  servoWave.ampMax  = map(analogRead(analogPin1), 0,1023, 1,3);
  periodState = analogRead(analogPin2)*0.005;// map(analogRead(analogPin2),0,1023,0,5);//check these values...
  servoWave.indexSpacing  = map(analogRead(analogPin2),0,1023, 1,20);

  for(int i=0;i<12;i++){
    servoWave.update(); 
    servoWave.move();
    
    if(periodState!=lastPeriodState){
      //period = perdiodState;
     servoWave.calcIndex(periodState); 
    }
     lastPeriodState=periodState;
    // Serial.println(periodState);
  }
}


