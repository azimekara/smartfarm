#include <Stepper.h>


int roofstatus=0;
int stepcount=0;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm

  // initialize the serial port
  Serial.begin(115200);
}

void loop() {

  if (Serial.available() > 0)
  {
    roofstatus = Serial.read();
    Serial.println(roofstatus);
  }

    if (roofstatus == 1)
  {
    // set the speed
    myStepper.setSpeed(50);//50 yavaş
    myStepper.step(stepsPerRevolution);
  }
    else if (roofstatus == 2)
  {
    myStepper.setSpeed(100);//100 orta,180 hızlı
    myStepper.step(stepsPerRevolution);
  }
  else if (roofstatus == 3)
  {
    myStepper.setSpeed(190);//190 hızlı
    myStepper.step(stepsPerRevolution);
  }
  else if (roofstatus == 4)
  {
    myStepper.setSpeed(190);//190 hızlı
    myStepper.step(-stepsPerRevolution);
  }

}
