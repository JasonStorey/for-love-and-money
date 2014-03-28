#ifndef User_input_h
#define User_input_h

#include <Arduino.h>

class User_input {
  
  public:
    int init();
    int readButtonState();
    int readInfiniteEncoder();
    int readPot();
    
  private:
    int analogInPin;
    int analogueIndex;
    int analogueTotal;
    
    int _buttonPin1;
    int _buttonPin2;
    int _buttonPin3;
    int _buttonPin4;

    int _buttonState1;
    int _buttonState2;
    int _buttonState3;
    int _buttonState4;
    
    int _prevButtonState1;
    int _prevButtonState2;
    int _prevButtonState3;
    int _prevButtonState4;
    
    int val; 
    int encoderPinA;
    int encoderPinB;   
    int encoderPosition;
    int pinAPrev;
    int debounceVal1;  
    unsigned long timer;
    int pinAVal;
    int sensitivity;
    
};

extern User_input input;

#endif
