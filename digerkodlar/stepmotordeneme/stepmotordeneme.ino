/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-stepper-motor-28byj-48-uln2003/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  Based on Stepper Motor Control - one revolution by Tom Igoe
*/

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
    myStepper.setSpeed(190);//180 hızlı
    myStepper.step(stepsPerRevolution);
  }
  else if (roofstatus == 4)
  {
    myStepper.setSpeed(190);//180 hızlı
    myStepper.step(-stepsPerRevolution);
  }

  stepcount=0;

  // step one revolution in one direction:
//  myStepper.setSpeed(5);
//  Serial.println("clockwise");
//  myStepper.step(stepsPerRevolution);
//  delay(1000);
//
//  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-stepsPerRevolution);
//  delay(1000);
}
