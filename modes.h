#ifndef Modes_h
#define Modes_h

int MODE = 1;

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
  STAR.wave(5, 600, 0.5);  
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

/*********************** PATTERN MODE ***********************/

void initPatternMode() {
  const int minBrightness = OFF;
  const int middleBrightness = OFF;  
  const int maxBrightness = ON;
  
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  DO.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  THIS.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  FOR.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  HEART.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  LVE.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  AND.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  MONEY.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  
  STAR.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  TRACK.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  BACK.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  TRACK_TOP.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  TRACK_BOTTOM.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  
  WE.load(pattern1, PATTERN_1_RESOLUTION);
  DO.load(pattern1, PATTERN_1_RESOLUTION);
  THIS.load(pattern1, PATTERN_1_RESOLUTION);
  FOR.load(pattern1, PATTERN_1_RESOLUTION);
  HEART.load(pattern1, PATTERN_1_RESOLUTION);
  LVE.load(pattern1, PATTERN_1_RESOLUTION);
  AND.load(pattern1, PATTERN_1_RESOLUTION);
  MONEY.load(pattern1, PATTERN_1_RESOLUTION);
  
  STAR.load(pattern1, PATTERN_1_RESOLUTION);
  TRACK.load(pattern1, PATTERN_1_RESOLUTION);
  BACK.load(pattern1, PATTERN_1_RESOLUTION);
  TRACK_TOP.load(pattern1, PATTERN_1_RESOLUTION);
  TRACK_BOTTOM.load(pattern1, PATTERN_1_RESOLUTION);  
}

void patternMode() {
  WE.play(30, 5);
  DO.play(30, 5);
  THIS.play(30, 5);
  FOR.play(30, 5);
  HEART.play(30, 5);
  LVE.play(30, 5);
  AND.play(30, 5);
  MONEY.play(30, 5);
  
  STAR.play(30, 5);
  BACK.play(30, 5);

  TRACK_TOP.play(30, 5);
  TRACK_BOTTOM.play(30, 5);
}

/*********************** OFF MODE ***********************/

void initOffMode() {
 
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(0, 0, true, OFF, ON, OFF, millis());
  DO.configure(0, 0, true, OFF, ON, OFF, millis());
  THIS.configure(0, 0, true, OFF, ON, OFF, millis());
  FOR.configure(0, 0, true, OFF, ON, OFF, millis());
  HEART.configure(0, 0, true, OFF, ON, OFF, millis());
  LVE.configure(0, 0, true, OFF, ON, OFF, millis());
  AND.configure(0, 0, true, OFF, ON, OFF, millis());
  MONEY.configure(0, 0, true, OFF, ON, OFF, millis());
  
  STAR.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK.configure(0, 0, true, OFF, ON, OFF, millis());
  BACK.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK_TOP.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK_BOTTOM.configure(0, 0, true, OFF, ON, OFF, millis());
}

void offMode() {
  Tlc.setAll(OFF);
}
/*********************** UTILS ***********************/

void setMode(int mode) {
  if(mode == MODE) { return; }
  
  MODE = mode;
  switch(MODE) {
    case 1:
      initFadeMode();
      break;
     
    case 2:
      initWaveMode();
      break;
      
    case 3:
      initPatternMode();
      break; 
      
    default:
      initOffMode();
  }
}

void runMode() {
  switch(MODE) {
    case 1:
      fadeMode();
      break; 
      
    case 2:
      waveMode();
      break;
      
    case 3:
      patternMode();
      break;
      
    default:
      offMode();
  }
}

#endif
