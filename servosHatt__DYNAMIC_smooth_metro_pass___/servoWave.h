#ifndef ServoWave_h
#define ServoWave_h
#include <Servo.h>
#include "Arduino.h"
#include "Metro.h"


class ServoWave //ServoManager
//collection of functions and variables


{
  
  public:
  //constructor creates an INSTNACE of the class (has the same name as the class)
   ServoWave();
   ServoWave(int _numServos, int _amplitude, unsigned long _period, int _wavelength, int _ampMax);
   ~ServoWave();
//   boolean iniitServo(iint indexServo);
//   boolean iniatAllServo();
   int ampMax;
   int numServos;
   int angle;//0=90
   long period;//time in millis
   int wavelength;//in numb of servos
   Servo servos[15];
   int steps;
   int lastPosition;
  int currentServo;//index in servos
  int servoPositions[15];//array of ints representing the current pos of all servos
  int servoAngles[16];//array for remembering the previous 16 angles
  void passDownValues();
  long lastUpdatedAt;
  
  void adjustServos(int curA);
  void addServo(Servo s);
  void addServo(Servo s, int startPosition);
  void move();
  void update();//where the stuff happens
  int calculateAngle();
  float calcAmp(int per);//wavelength/period
  //Metro metro;
 long   previousMillis;
  
  //void moveServo(int whichServo, int whatAngle); //servoWave.moveServo(0, 70);
};
  

#endif
