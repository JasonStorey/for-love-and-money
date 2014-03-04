#include "User_input.h"

int User_input::init() {
  // BUTTON
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

  // INFINITE ENCODER
  LLpin = 7;
  LRpin = 8;
  
  pinMode(LLpin, INPUT);
  pinMode(LRpin, INPUT);
  
  encoder0Pos = 1;
  encoder0PinALast = LOW;
  n = LOW;
  sensitivity = 3;
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

int User_input::readInfiniteEncoder() {
  n = digitalRead(LLpin);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(LRpin) == LOW) {
       encoder0Pos += sensitivity;
     } else {
       encoder0Pos -= sensitivity;
     }
   }
   if(encoder0Pos < 1) {
     encoder0Pos = 1;
   }
   
   if(encoder0Pos > 120) {
     encoder0Pos = 120;  
   }
   encoder0PinALast = n;
   
   return encoder0Pos;
}

User_input input;
