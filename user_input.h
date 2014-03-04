#ifndef User_input_h
#define User_input_h

#include <Arduino.h>

class User_input {
  
  public:
    int init();
    int readButtonState();
    
  private:
    int _buttonPin1;
    int _buttonPin2;
    int _buttonPin3;
    int _buttonPin4;

    int _buttonState1;
    int _buttonState2;
    int _buttonState3;
    int _buttonState4;
    
};

extern User_input input;

#endif
