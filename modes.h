#ifndef Modes_h
#define Modes_h

int MODE = 0;

void initFadeMode() {
  WE.setPhase(300);
  DO.setPhase(250);
  THIS.setPhase(200);
  FOR.setPhase(150);
  LOVE.setPhase(100);
  AND.setPhase(50);
  MONEY.setPhase(0); 
}

void fadeMode() {
  WE.fade(5, 300);
  DO.fade(5, 300);
  THIS.fade(5, 300);
  FOR.fade(5, 300);  
  LOVE.fade(5, 300);
  AND.fade(5, 300);  
  MONEY.fade(5, 300);
}

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
