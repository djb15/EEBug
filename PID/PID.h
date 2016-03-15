#ifndef PID_h
#define PID_h
#define LIBRARY_VERSION	1.1.1

class PID
{
    
    
    public:
    
    //Constants used in some of the functions below
    #define AUTOMATIC   1
    #define MANUAL	0
    #define DIRECT  0
    #define REVERSE  1
    
   
    PID(double*, double*, double*, double, double, double, int);
    void SetMode(int Mode);               // * sets PID to either Manual (0) or Auto (non-0)
    bool Compute();                       // * performs the PID calculation.  it should be
    //   called every time loop() cycles. ON/OFF and
    //   calculation frequency can be set using SetMode
    //   SetSampleTime respectively
    
    void SetOutputLimits(double, double); //clamps the output to a specific range. 0-255 by default, but
    //it's likely the user will want to change this depending on
    //the application
    
    
    //We probably wont have to use these functions
    void SetTunings(double, double, double);
    void SetControllerDirection(int);	  // * Sets the Direction, or "Action" of the controller. DIRECT
    //   means the output will increase when error is positive. REVERSE
    //   means the opposite.  it's very unlikely that this will be needed
    //   once it is set in the constructor.
    void SetSampleTime(int);              // * sets the frequency, in Milliseconds, with which
    //   the PID calculation is performed.  default is 100
    
    
    
    //Display functions ****************************************************************
    double GetKp();						  // These functions query the pid for interal values.
    double GetKi();						  //  they were created mainly for the pid front-end,
    double GetKd();						  // where it's important to know what is actually
    int GetMode();						  //  inside the PID.
    int GetDirection();					  //
    
    


    private:
    
    void Initialize();
    
    double dispKp;				// * we'll hold on to the tuning parameters in user-entered
    double dispKi;				//   format for display purposes
    double dispKd;				//
    
    double kp;                  // * (P)roportional Tuning Parameter
    double ki;                  // * (I)ntegral Tuning Parameter
    double kd;                  // * (D)erivative Tuning Parameter
    
    int controllerDirection;
    
    double *myInput;              // * Pointers to the Input, Output, and Setpoint variables
    double *myOutput;             //   This creates a hard link between the variables and the
    double *mySetpoint;           //   PID, freeing the user from having to constantly tell us
    //   what these values are.  with pointers we'll just know.
    
    unsigned long lastTime;
    double ITerm, lastInput;
    
    unsigned long SampleTime;
    double outMin, outMax;
    bool inAuto;
};
#endif