#include ServoWave.h

ServoWave::ServoWave(int _numServos, int _amplitude, long _period, int _wavelength){
  numServos = _numServos;
  amplitude = _amplitude;
  period = _period;
  wavelength = _wavelength;

  // set currentServo to 0
  // initliaze the servoPosition array
  // initialize the servo array
}


ServoWave::addServo(Servo servo){
  servos[currentServo] = servo;
  currentServo++;
}

ServoWave::update(){
//  calculate the position of each
//  servo based on its previous position
//  and the amplitude/period/wavelength

//  update the servo to that position

//  update the servoPosition array so that it corresponds with reality
}
