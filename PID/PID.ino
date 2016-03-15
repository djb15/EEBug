
#include <PID.h>
#define PIN_INPUT //whatever pin is the input 2, 3, 7
#define PIN_OUTPUT //whatever pin is the output 5, 6

double Setpoint, Input, Output;

double Kp = 2, Ki = 5, Kd = 1;

PID myPID (&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


void setup() {
  // put your setup code here, to run once:

  Input = analogRead (PIN_INPUT);
  Setpoint = 100;

  myPID.SetMode (AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:
  Input = analogRead (PIN_INPUT);
  myPID.Compute();
  analogWrite (PIN_OUTPUT, Output);



  

}
