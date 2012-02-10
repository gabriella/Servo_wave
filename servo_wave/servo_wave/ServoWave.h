class ServoWave
{

public:
   ServoWave(int _numServos, int _amplitude, long _period, int _wavelength);

   int numServos;
   int amplitude; //0-90
   long period; // time in millis
   int wavelength; // in number of servos
   Servo[] servos;
   int currentServo; // index in servos
   
   int[] servoPositions; // array of ints representing the current pos of all servos
   
   void addServo(Servo s);
  
   void update(); // real magic
   
   float getSpeed(); // wavelength / period
};

/*

ServoWave myWave;
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
