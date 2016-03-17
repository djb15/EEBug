
#include "PID.h"
#define RIGHT_PIN_INPUT 2
#define LEFT_PIN_INPUT 3
#define RIGHT_PIN_OUTPUT 0
#define LEFT_PIN_OUTPUT 1

int Setpoint, right_Input, left_Input, right_Output, left_Output;

int Kp = 2, Ki = 5, Kd = 1;

PID myPID (&right_Input, &right_Output, &Setpoint, Kp, Ki, Kd, DIRECT);
PID myPID2 (&left_Input, &left_Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  // put your setup code here, to run once:

  right_Input = analogRead (RIGHT_PIN_INPUT);
  left_Input = analogRead (LEFT_PIN_INPUT);
  
  Setpoint = 60;

  myPID.SetMode (AUTOMATIC);
  myPID2.SetMode (AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:
  right_Input = analogRead (RIGHT_PIN_INPUT);
  left_Input = analogRead (LEFT_PIN_INPUT);
  myPID.Compute();
  myPID2.Compute();
  analogWrite (RIGHT_PIN_OUTPUT, right_Output);
  analogWrite (LEFT_PIN_OUTPUT, left_Output);

}
