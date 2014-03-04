#include "User_input.h"

int User_input::init() {
  
  _buttonPin1 = 2;
  _buttonPin2 = 4;
  _buttonPin3 = 5;
  _buttonPin4 = 6;
  
  pinMode(_buttonPin1, INPUT);
  pinMode(_buttonPin2, INPUT);
  pinMode(_buttonPin3, INPUT);
  pinMode(_buttonPin4, INPUT);
  
  _buttonState1 = 0;
  _buttonState2 = 0;
  _buttonState3 = 0;
  _buttonState4 = 0;
}

int User_input::readButtonState() {
  int tempMode = 0;
  _buttonState1 = digitalRead(_buttonPin1);
  _buttonState2 = digitalRead(_buttonPin2);
  _buttonState3 = digitalRead(_buttonPin3);
  _buttonState4 = digitalRead(_buttonPin4);
  
  if(_buttonState1 == 1) {
    tempMode = 1;
  }
  if(_buttonState2 == 1) {
    tempMode = 2;
  }
  if(_buttonState3 == 1) {
    tempMode = 3;
  }
  if(_buttonState4 == 1) {
    tempMode = 4;
  }
  
  return tempMode;
}

User_input input;
