#ifndef Modes_h
#define Modes_h

int MODE = 0;

/*********************** FADE MODE ***********************/

void initFadeMode() {
  const int minBrightness = 4000;
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(300, 0, true, minBrightness, ON, minBrightness, millis());
  DO.configure(250, 0, true, minBrightness, ON, minBrightness, millis());
  THIS.configure(200, 0, true, minBrightness, ON, minBrightness, millis());
  FOR.configure(150, 0, true, minBrightness, ON, minBrightness, millis());
  HEART.configure(130, 0, true, minBrightness, ON, minBrightness, millis());
  LVE.configure(100, 0, true, minBrightness, ON, minBrightness, millis());
  AND.configure(50, 0, true, minBrightness, ON, minBrightness, millis());
  MONEY.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  
  STAR.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  TRACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis());  
}

void fadeMode() {
  WE.fade(5, 300);
  DO.fade(5, 300);
  THIS.fade(5, 300);
  FOR.fade(5, 300);
  HEART.fade(5, 300);  
  LVE.fade(5, 300);
  AND.fade(5, 300);  
  MONEY.fade(5, 300);
  
  STAR.fade(15, 300);  
  TRACK.fade(15, 300); 
}

/*********************** UTILS ***********************/

void setMode(int mode) {
  MODE = mode;
  switch(MODE) {
    case 0:
      initFadeMode();
      break; 
      
    default:
      Serial.println('default');
  }
}

void runMode() {
  switch(MODE) {
    case 0:
      fadeMode();
      break; 
      
    default:
      Serial.println('default');
  }
}

#endif
