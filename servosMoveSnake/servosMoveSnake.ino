//code to move servos in a line in a wave like formateion

#include <Servo.h>
const int ledpin = 13;
int servosPins[] = {
  2,3,4,5,6,7,8,9,10,11,12};
int servoValues[] = {
  20, 40, 10,100,15,9,100,110,80,60,40};
const int NUM_SERVOS = 11;
Servo servos[NUM_SERVOS];
const int FIRST_SERVO_PIN=2;

int nextServoValue = 120;


int currentServo = 0;

const int UPDATE_INTERVAL = 500;

long lastUpdatedAt = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  //setup all your servos;
  //for(int i=0;i<NUM_SERVOS;i++)
  //servos[i].attach(FIRST_SERVO_PIN +i);
  servos[0].attach(2);
  servos[1].attach(3);
  servos[2].attach(4);
  servos[3].attach(5);
  servos[4].attach(6);
  servos[5].attach(7);
  servos[6].attach(8);
  servos[7].attach(9);
  servos[8].attach(10);
  servos[9].attach(11);
  servos[10].attach(12);



  lastUpdatedAt = millis();

  Serial.println("starting");
}

void loop(){
  //Serial.println(millis());

  if(Serial.available()>0){
    digitalWrite(13, HIGH);
    byte inByte =Serial.read();
    //int inByte = Serial.parseInteger();
    //Serial.println(inByte);
    if(inByte == 50||inByte==51){
      nextServoValue=nextServoValue+1;
      Serial.println("up");
    }
    else if(inByte==49||inByte==52){
      nextServoValue = nextServoValue-1;
      ; 
      Serial.println("down");
    }
    if(nextServoValue > 140){
      nextServoValue = 140;
    }
    else if(nextServoValue<60){
      nextServoValue = 60; 
    }
    // Serial.println(nextServoValue);
  }
  /*
   Serial.print("0: ");
   Serial.print(servoValues[0]);
   Serial.print("\t1: ");
   Serial.print(servoValues[1]); 
   Serial.print("\t2: ");
   Serial.println(servoValues[2]);
   Serial.print("\t2: ");
   Serial.println(servoValues[3]);
   Serial.print("\t2: ");
   Serial.println(servoValues[4]);
   Serial.print("\t2: ");
   Serial.println(servoValues[5]);
   Serial.print("\t2: ");
   Serial.println(servoValues[6]);
   Serial.print("\t2: ");
   Serial.println(servoValues[7]);
   Serial.print("\t2: ");
   Serial.println(servoValues[8]);
   Serial.print("\t2: ");
   Serial.println(servoValues[9]);
   Serial.print("\t2: ");
   Serial.println(servoValues[10]);
   Serial.print("\t2: ");
   
   */

  if(millis() - lastUpdatedAt  > UPDATE_INTERVAL){
    //Serial.println();
    //Serial.println();


    int myNewFirstValue = 90; //how ever you're calculating this
    //passDownServoValues(myNewFirstValue);
    // after hre your servoValues array is correct
    //adjustServos();
    
    loopServos();
    
    //passDownServoValues(nextServoValue);
    lastUpdatedAt = millis();
  }

  updateServos();

}

void passDownServoValues(int firstValue){
  // {100, 50, 1, 23, 17, 100};
  // {firstVAlue, 100, 50, 1, 23, 17}


  // {90, 90, 90}
  // {0, 0, 90}
  for(int i = NUM_SERVOS-1; i > 0; i--){//why cant write servoValues.length
    servoValues[i] = servoValues[i-1];
  }

  servoValues[0] = firstValue;
}

void updateServos(){
  for(int i =0; i < NUM_SERVOS; i++){
    servos[i].write(servoValues[i]);
  }
}

void loopServos(){
  passDownServoValues(servoValues[NUM_SERVOS-1]);
}

void adjustServos(){
  // update the current servo


  servos[currentServo].write(servoValues[currentServo]);

  currentServo++;
  if(currentServo > NUM_SERVOS-1){
    currentServo = 0;
    // passDownServoValues(myValue);why not
    // Serial.println("passing down");
    passDownServoValues(nextServoValue);

  }

 

}

//send values from xbee
//get one wave to start then stop
//bigger jump between steps

