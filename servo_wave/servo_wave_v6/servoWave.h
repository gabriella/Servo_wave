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
   ServoWave(int _numServos, int _amplitude, long _period, int _wavelength);
   ~ServoWave();
   
   int numServos;
   int amplitude;//0=90
   long period;//time in millis
   int wavelength;//in numb of servos
   Servo* servos;
   

   
  int currentServo;//index in servos
  int* servoPositions;//array of ints representing the current pos of all servos
  
  void addServo(Servo s);
  void addServo(Servo s, int startPosition);
  void move();
  void update();//where the stuff happens
  float calcAmp(int per);//wavelength/period
  
  //void moveServo(int whichServo, int whatAngle); //servoWave.moveServo(0, 70);
};
  
  /*servoWave myWave;
  Servo servo1;
  Servo servo2;
  
  void setup(){
   myWave = new Wave(5, 90, 200, 2);
  servo1.attach(1);
 servo2.attach(2);
myWave.addServo(servo1);
myWave.addServo(servo2);
  }
  
  void loop(){
   myWave.update(); 
  }
  
*/
#endif
