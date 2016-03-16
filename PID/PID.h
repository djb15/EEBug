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
    
   
    PID(int*, int*, int*, int, int, int, int);
    void SetMode(int Mode);               // * sets PID to either Manual (0) or Auto (non-0)
    bool Compute();                       // * performs the PID calculation.  it should be
    //   called every time loop() cycles. ON/OFF and
    //   calculation frequency can be set using SetMode
    //   SetSampleTime respectively
    
    void SetOutputLimits(int, int); //clamps the output to a specific range. 0-255 by default, but
    //it's likely the user will want to change this depending on
    //the application
    
    
    //We probably wont have to use these functions
    void SetTunings(int, int, int);
    void SetControllerDirection(int);	  // * Sets the Direction, or "Action" of the controller. DIRECT
    //   means the output will increase when error is positive. REVERSE
    //   means the opposite.  it's very unlikely that this will be needed
    //   once it is set in the constructor.
    void SetSampleTime(double);              // * sets the frequency, in Milliseconds, with which
    //   the PID calculation is performed.  default is 100
    
    
    
    //Display functions ****************************************************************
    int GetKp();						  // These functions query the pid for interal values.
    int GetKi();						  //  they were created mainly for the pid front-end,
    int GetKd();						  // where it's important to know what is actually
    int GetMode();						  //  inside the PID.
    int GetDirection();					  //
    
    


    private:
    
    void Initialize();
    
    int dispKp;				// * we'll hold on to the tuning parameters in user-entered
    int dispKi;				//   format for display purposes
    int dispKd;				//
    
    int kp;                  // * (P)roportional Tuning Parameter
    int ki;                  // * (I)ntegral Tuning Parameter
    int kd;                  // * (D)erivative Tuning Parameter
    
    int controllerDirection;
    
    int *myInput;              // * Pointers to the Input, Output, and Setpoint variables
    int *myOutput;             //   This creates a hard link between the variables and the
    int *mySetpoint;           //   PID, freeing the user from having to constantly tell us
    //   what these values are.  with pointers we'll just know.
    
    unsigned long lastTime;
    int ITerm, lastInput;
    
    unsigned long SampleTime;
    int outMin, outMax;
    bool inAuto;
};
#endif
