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
  HEART.configure(100, 0, true, minBrightness, ON, minBrightness, millis());
  LVE.configure(130, 0, true, minBrightness, ON, minBrightness, millis());
  AND.configure(50, 0, true, minBrightness, ON, minBrightness, millis());
  MONEY.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  
  STAR.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  TRACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis()); 
  BACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis());   
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
  
//  STAR.fade(15, 300);
  STAR.wave(5, 300, 0.5);  
  TRACK.fade(15, 300);
  BACK.fade(15, 300);  
}

/*********************** WAVE MODE ***********************/

void initWaveMode() {
  const int minBrightness = 4000;
  const int middleBrightness = 3000;  
  const int maxBrightness = 800;
  
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(82, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  DO.configure(68, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  THIS.configure(54, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  FOR.configure(42, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  HEART.configure(0, 0, false, minBrightness, ON, minBrightness, millis());
  LVE.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  AND.configure(14, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  MONEY.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  
  STAR.configure(0, 0, true, middleBrightness, ON, middleBrightness, millis());
  TRACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis()); 
  BACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  TRACK_TOP.configure(0, 0, true, minBrightness, ON, minBrightness, millis()); 
  TRACK_BOTTOM.configure(0, 0, true, minBrightness, ON, minBrightness, millis());   
}

void waveMode() {
  WE.fade(30, 100);
  DO.fade(30, 100);
  THIS.fade(30, 100);
  FOR.fade(30, 100);
  HEART.wave(25, 40, 1.04);  
  LVE.wave(8, 40, 1.42);
  AND.fade(30, 100);
  MONEY.fade(30, 100);
  
  STAR.wave(30, 80, 0.5);  
  BACK.setPercentage(100);

  TRACK_TOP.phase(100, -1);
  TRACK_BOTTOM.phase(100, -1);
}

/*********************** UTILS ***********************/

void setMode(int mode) {
  MODE = mode;
  switch(MODE) {
    case 0:
      initFadeMode();
      break;
     
    case 1:
      initWaveMode();
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
      
    case 1:
      waveMode();
      break;
      
    default:
      Serial.println('default');
  }
}

#endif
