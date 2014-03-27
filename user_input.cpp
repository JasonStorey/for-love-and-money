#include "User_input.h"

const int numOfReadings = 30;
int analogueReadings[numOfReadings] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int User_input::init() {
  
  // POTENTIOMETER
  analogInPin = A0;
  analogueIndex = 0;
  analogueTotal = 0;
  
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

  sensitivity = 4;
  
  val; 
  encoderPinA = 8;
  encoderPinB = 7;
  encoderPosition = 0;
  pinAPrev = LOW;
  debounceVal1 = LOW;
  timer = millis();

  pinAVal = LOW;
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
}

int User_input::readPot() {
  analogueTotal = analogueTotal - analogueReadings[analogueIndex];
  analogueReadings[analogueIndex] = 1023 - analogRead(analogInPin); // 0 - 1023
  analogueTotal = analogueTotal + analogueReadings[analogueIndex];
  analogueIndex = (analogueIndex + 1) % numOfReadings;
  return analogueTotal / numOfReadings;
}

int User_input::readButtonState() {
  int tempMode = 0;
  
  _prevButtonState1 = _buttonState1;
  _prevButtonState2 = _buttonState2;
  _prevButtonState3 = _buttonState3;
  _prevButtonState4 = _buttonState4;
  
  _buttonState1 = digitalRead(_buttonPin1);
  _buttonState2 = digitalRead(_buttonPin2);
  _buttonState3 = digitalRead(_buttonPin3);
  _buttonState4 = digitalRead(_buttonPin4);
  
  if(_buttonState1 == 1 && _prevButtonState1 == 1) {
    tempMode = 1;
  }
  if(_buttonState2 == 1 && _prevButtonState2 == 1) {
    tempMode = 2;
  }
  if(_buttonState3 == 1 && _prevButtonState3 == 1) {
    tempMode = 3;
  }
  if(_buttonState4 == 1 && _prevButtonState4 == 1) {
    tempMode = 4;
  }
  
  return tempMode;
}

int User_input::readInfiniteEncoder() {
  if(millis() - timer > 3) {
    timer = millis();
  } else {
    return encoderPosition * sensitivity;
  }
  
  int tempPos = encoderPosition;
  pinAVal = digitalRead(encoderPinA);
  
  if ((pinAPrev == LOW) && (debounceVal1 = HIGH) && (pinAVal == HIGH)) {
    if (digitalRead(encoderPinB) == LOW) {
      encoderPosition--;
    } else {
      encoderPosition++;
    }
    
    if(encoderPosition > 0) {
      tempPos = encoderPosition;
    } else {
      encoderPosition = 0;
    }
    
    if(encoderPosition > 15) {
      encoderPosition = 15;
    }
  } 
  pinAPrev = debounceVal1;
  debounceVal1 = pinAVal;
  return tempPos * sensitivity;
}

User_input input;
