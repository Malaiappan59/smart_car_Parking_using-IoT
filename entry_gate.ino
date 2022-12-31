#include <Servo.h>
  Servo Serv;

  int pinIR=2;
  int pinServo=3;
  int val=0;

  void setup(){
    Serv.attach(pinServo);
  }

  void loop(){
    val = digitalRead(pinIR);
  
    if (val ==1){
      Serv.write(50);
    
    }
    else
    {
      Serv.write(10);
      delay(2000);
    }
  }
