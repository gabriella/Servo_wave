#ifndef ServoWave_h
#define ServoWave_h
#include <Servo.h>
#include "Arduino.h"

class ServoWave //ServoManager
//collection of functions and variables

{
  
  public:
  //constructor creates an INSTNACE of the class (has the same name as the class)
   ServoWave();
   ServoWave(int _numServos, float _theta,  float _dx, int _ampMax, float _speed);
   ~ServoWave();
   
   float lmap(float val, float inMin, float inMax, float outMin, float outMax);
  
float theta;
   int ampMax;
   float speed;
float dx;
   int numServos;
   float angle;//0=90


   Servo servos[12];
   int steps;
   int lastPosition;
  int currentServo;//index in servos
  float servoPositions[12];//array of ints representing the current pos of all servos
  int servoAngles[16];//array for remembering the previous 16 angles
  void passDownValues(int firstValue);
  
    void calcIndex(float p);
    void calcPeriod(float per);
  long lastUpdatedAt;
    int index[10];//index of number of servos per wavelength
  int total;
  float wave[360];
  //float wave[TWO_PI/0.01];
  float p;//make this period
  int TOTAL_INDICES;
    int TOTAL_NODES;
  void adjustServos(int curA);
  void addServo(Servo s);
  void addServo(Servo s, int startPosition);
  void move();
  void update();//where the stuff happens
  //int calculateAngle();
  float calcAmp(int per);//wavelength/period
 // Metro metro;
 long   previousMillis;
  
  //void moveServo(int whichServo, int whatAngle); //servoWave.moveServo(0, 70);
};
  

#endif
