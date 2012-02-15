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

ServoWave::ServoWave(int _numServos, int _amplitude, long _period, int _wavelength, int _ampMax){
  numServos = _numServos;//servos of the whole unit
  amplitude = _amplitude;//height of wave 
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
  //amplitude +=0.02;
  //float x =amplitude;
  /*
  for(int i=0;i<numServos;i++){
   int changer = 1;
   
   period = period + changer;
   amplitude = abs(sin(period));
   amplitude = map(amplitude, 0,1,0,180);
   
   changer=changer+0.1;
   */
  // servoPositions[i] = 180; 

  //  amplitude = calcAmp(period);
  //}


  //numpositions spaced in time
  //period / n is the 
  //servo

  /*
    
   //  servoPositions[i] = 90; // starting position for all servos. could be passed as an argument 
   //how do i use wavelength
   //servoPositions[i] = sin(x);
   // x+=(360/period);
   long freq=1;//this is a constant that sin is changing
   //return a foloat based on numservos sin(period) is 
   //period = period + time;
   // period = millis()*i*period;
   freq++;
   // amplitude = servoPositions[i];
   
   
   //period= i* 360/15;
   period += period*i;
   //have freq have to do with servoPosition
   //Serial.println(sin(period));
   
   
   }
   */

  //derivative for sin? is the cosine
  //for every servoposition i , get the cos, gives you a values for the slopem , translate to rotatein
  //subtract previos rot from 



}

//update the servoPosition array so that it corresponds with where it is at
float ServoWave::calcAmp(int p){
  int a =  90*sin(p)+90;
  // Serial.println(amplitude);
   return a;
}

void ServoWave::move(){

  // for all the servos from 0 to numServos
  // lookup a position i.e. servoPositions[i]
  // and write that to the corresponding servo, i.e. servos[i].write(...)

  //HERE IS WHERE I CAN USE THE WAVELENGTH -= GET THE POSITION OF THE 
  //int factor = 90;//just add this in order to get back to a servoWrite value of 0-180
  int dir = 0;




  //dont change this as this will be what inlusnces the next servo

  //Serial.println(curAngle);
  int newAngle=calculateAngle();
  servos[0].write(newAngle);
  int curAngle = servos[0].read();
  //    Serial.print(" curAng = ");
  //    Serial.print(curAngle);
  //    Serial.print("newan= ");
  //Serial.println(newAngle);

  float dAngle =100;//  ampMax / steps;//distance of one unit to be changed;
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
  Serial.print(" dir:");
  Serial.print(dir);


  newAngle = curAngle+dAngle*dir;
  Serial.print(" newAngle:");
  Serial.print(newAngle);

  for(int i=1;i<numServos;i++){
    newAngle = curAngle;

    curAngle = servos[i].read();
    //wait why i'm confused why i did this


    //  Serial.println(
    servos[i].write(newAngle);
    Serial.print(" S:");
    Serial.print(i);
    Serial.print(" ANG:");
    Serial.print(newAngle);
   // Serial.print(servos[i].read());

  }
  Serial.println();
  /*
  int lastAng = 0;
   int currentAngle=servoPositions[i];// = currentPositions;see that i set servoPositions ot be 90
   int angleChange = lastAng-currentAngle;
   
   angleChange = calculateAngle(); 
   currentAngle-=angleChange;
   
   lastAng = currentAngle;
  
   //Serial.println(servoPositions[currentAngle]);*/

}


int ServoWave::calculateAngle(){
//
  if(amplitude> lastPosition||amplitude<=0){
    lastPosition =amplitude;

    amplitude+=1*period;//180/wavelength; 

  }

  if(amplitude < lastPosition||amplitude>=180){
    lastPosition = amplitude;

    amplitude-=1*period;//180/wavelength; 

    //try to add more steps
    //change 180 to be a different steps
    //set current servos to zero and return
  }

  return amplitude;
  // servos[0].write(newAng);
 
}


//how to control the speed
//how to build in trig? 
//how to control wavelength? 
//why isnT the steps thing working at all.

