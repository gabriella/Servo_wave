#include "ServoWave.h"


//constructor with four argiuments about the wave
ServoWave::ServoWave() {

  //try define
  //preprocessor 
}
ServoWave::~ServoWave() {
  delete servoPositions;
  delete servos;
}

ServoWave::ServoWave(int _numServos, int _angle, long _period, int _wavelength, int _ampMax){
  numServos = _numServos;//servos of the whole unit
  angle = _angle;//height of wave 
  period = _period; //in milliseconds
  wavelength = _wavelength;//how many servos long the wave will be
  ampMax=_ampMax;

  //initialize the servos
  //servoPositions = new int[numServos];
  //initializr the servo array
  //servos = new Servo[numServos];
  int numServos = _numServos;
  //set currentServo to 0
  int currentServo = 0;
  int lastPosition=-1;
  int steps = 5;

  //initialize servoPosition array
  for(int i=0;i<numServos;i++){//wtf
    servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
    //(angle)
  }
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

void ServoWave::update(){
}

void ServoWave::move(){

  int dir = 0;

  //Serial.println(curAngle);
  int newAngle=calculateAngle();
  servos[0].write(newAngle);
  int curAngle = servos[0].read();

  float dAngle =1;//  ampMax / steps;//distance of one unit to be changed;
  //  Serial.print(" steps = ");
  //  Serial.print(steps);
  //  Serial.print(" ampmax = ");
  //  Serial.print(ampMax);
  // Serial.print(" dangle (ampmax/steps) = ");
  // Serial.println(dAngle);

  if ((curAngle + dAngle) > (ampMax+90) ) {
    dir = -1;
    //newAngle = curAngle - dAngle;
  } 
  else if ((curAngle + dAngle) < (90-ampMax) ) {
    // newAngle = curAngle + dAngle;
    dir=1;
  }
 // Serial.print(" dir:");
 // Serial.print(dir);

  newAngle = curAngle+dAngle*dir;
//  Serial.print(" newAngle:");
//  Serial.print(newAngle);

  for(int i=1;i<numServos;i++){

    //HERE PUT IN A TIMING FUNCTION TO SEE IF IT WORKS
    
    
    newAngle = curAngle;

    curAngle = servos[i].read();
    //wait why i'm confused why i did this
    //  Serial.println(
    servos[i].write(newAngle);
    Serial.print(" S:");
    Serial.print(i);
    Serial.print(" ANG:");
   // Serial.print(newAngle);

    Serial.print(servos[i].read());
    //Serial.println();
  }
  Serial.println();
}

int ServoWave::calculateAngle(){
//angle= angle -90;
//Serial.println(lastPosition);
//Serial.println();
  if(angle> lastPosition||angle<=90-ampMax){
    lastPosition =angle;

    angle+=1;//180/wavelength; 
  }

  if(angle < lastPosition||angle>=90+ampMax){
    lastPosition = angle;

    angle-=1;//180/wavelength; 
  }
 
  return angle;
}

//how to control the speed
//how to build in trig? 
//how to control wavelength? 
//why isnT the steps thing working at all.

