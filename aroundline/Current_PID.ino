#include "PID.h"

#define RIGHT_PIN_INPUT 2
#define LEFT_PIN_INPUT 3

#define RIGHT_PIN_OUTPUT 0
#define LEFT_PIN_OUTPUT 1


double Setpoint, right_Input, left_Input, right_Output, left_Output;

double Kp = 3, Ki = 0, Kd = 2;

PID myPID (&right_Input, &right_Output, &Setpoint, Kp, Ki, Kd, DIRECT);

PID myPID2 (&left_Input, &left_Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  // put your setup code here, to run once:

  right_Input = analogRead (RIGHT_PIN_INPUT);
  left_Input = analogRead (LEFT_PIN_INPUT);
  Setpoint = 60; //Change to the high value of white

  myPID.SetMode (AUTOMATIC);
  myPID2.SetMode (AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:
  right_Input = analogRead (RIGHT_PIN_INPUT);
  left_Input = analogRead (LEFT_PIN_INPUT);
  
  if (right_Input < Setpoint - 5){
    myPID.Compute();
    analogWrite (RIGHT_PIN_OUTPUT, right_Output * 2);
  }
  else if (left_Input < Setpoint -5){
    myPID2.Compute();
    analogWrite (LEFT_PIN_OUTPUT, left_Output * 2);
  }
  else{
    analogWrite (RIGHT_PIN_OUTPUT, 50);
    analogWrite (LEFT_PIN_OUTPUT, 50);
  }
  
  
}
