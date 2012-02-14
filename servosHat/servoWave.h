#ifndef ServoWave_h
#define ServoWave_h
#include <Servo.h>
#include "Arduino.h"

class ServoWave
//collection of functions and variables


{
  
  public:
  //constructor creates an INSTNACE of the class (has the same name as the class)
   ServoWave();
   ServoWave(int _numServos, int _amplitude, long _period, int _wavelength, int _ampMax);
   ~ServoWave();
   
   int ampMax;
   int numServos;
   int amplitude;//0=90
   long period;//time in millis
   int wavelength;//in numb of servos
   Servo servos[15];
   int steps;
   int lastPosition;
  int currentServo;//index in servos
  int servoPositions[15];//array of ints representing the current pos of all servos
  
  void addServo(Servo s);
  void addServo(Servo s, int startPosition);
  void move();
  void update();//where the stuff happens
  int calculateAngle();
  float calcAmp(int per);//wavelength/period
  
  //void moveServo(int whichServo, int whatAngle); //servoWave.moveServo(0, 70);
};
  

#endif
