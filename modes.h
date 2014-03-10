#ifndef Modes_h
#define Modes_h

int MODE = 0;

void setSystemBrightness(float brightness) {
   
  WE.setSystemBrightness(brightness);
  DO.setSystemBrightness(brightness);
  THIS.setSystemBrightness(brightness);
  FOR.setSystemBrightness(brightness);
  HEART.setSystemBrightness(brightness);
  LVE.setSystemBrightness(brightness);
  AND.setSystemBrightness(brightness);
  MONEY.setSystemBrightness(brightness);
  
  STAR.setSystemBrightness(brightness);
  BACK.setSystemBrightness(brightness);

  TRACK.setSystemBrightness(brightness);
  TRACK_TOP.setSystemBrightness(brightness);
  TRACK_BOTTOM.setSystemBrightness(brightness);
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
    Tlc.clear();
    Tlc.setAll(OFF);
}

/*********************** FADE MODE ***********************/

void initFadeMode() {
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(80, 0, true, OFF, ON, OFF, millis());
  DO.configure(70, 0, true, OFF, ON, OFF, millis());
  THIS.configure(60, 0, true, OFF, ON, OFF, millis());
  FOR.configure(50, 0, true, OFF, ON, OFF, millis());
  HEART.configure(10, 0, true, OFF, ON, OFF, millis());
  LVE.configure(25, 0, true, OFF, ON, OFF, millis());
  HEART.load(pattern1, PATTERN_1_RESOLUTION);
  
  AND.configure(15, 0, true, OFF, ON, OFF, millis());
  MONEY.configure(0, 0, true, OFF, ON, OFF, millis());
  
  STAR.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK_TOP.configure(0, 0, true, OFF, ON, OFF, millis());
  TRACK_BOTTOM.configure(0, 0, true, OFF, ON, OFF, millis());
  BACK.configure(0, 0, true, OFF, ON, OFF, millis());   
}

void fadeMode() {
  WE.fade(30, 100);
  DO.fade(30, 100);
  THIS.fade(30, 100);
  FOR.fade(30, 100);
//  HEART.fade(30, 100);  
  LVE.fade(30, 100);
  HEART.play(30, 5, true, false);
  AND.fade(30, 100);  
  MONEY.fade(30, 100);

  STAR.wave(35, 200, 0.5, 1.0);
  TRACK_TOP.wave(50, 200, 0.9, 0.5);
  TRACK_BOTTOM.wave(50, 200, 0.9, 0.5);  
  BACK.setPercentage(80);
}

/*********************** WAVE MODE ***********************/

void initWaveMode() {
  const int minBrightness = OFF;
  const int middleBrightness = OFF;  
  const int maxBrightness = ON;
  
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
  HEART.wave(25, 40, 1.04, 1.0);  
  LVE.wave(8, 40, 1.42, 1.0);
  AND.fade(30, 100);
  MONEY.fade(30, 100);
  
  STAR.wave(35, 200, 0.5, 1.0);
  BACK.setPercentage(100);
  TRACK_TOP.wave(5, 50, 1.95, 0.7);
  TRACK_BOTTOM.wave(5, 50, 1.95, 0.7);
//  TRACK_TOP.phase(100, -1);
//  TRACK_BOTTOM.phase(100, -1);
}

/*********************** PATTERN MODE ***********************/

void initPatternMode() {
  initOffMode();
  
  WE.configure(180, 0, true, OFF, ON, OFF, millis());
  DO.configure(24, 0, true, OFF, ON, OFF, millis());
  THIS.configure(40, 0, true, OFF, ON, OFF, millis());
  FOR.configure(100, 0, true, OFF, ON, OFF, millis());
  HEART.configure(12, 0, true, OFF, ON, OFF, millis());
  LVE.configure(140, 0, true, OFF, ON, OFF, millis());
  AND.configure(48, 0, true, OFF, ON, OFF, millis());
  MONEY.configure(0, 0, true, OFF, ON, OFF, millis());
  
  WE.load(pattern2, PATTERN_2_RESOLUTION);
  DO.load(pattern2, PATTERN_2_RESOLUTION);
  THIS.load(pattern2, PATTERN_2_RESOLUTION);
  FOR.load(pattern2, PATTERN_2_RESOLUTION);
  HEART.load(pattern2, PATTERN_2_RESOLUTION);
  LVE.load(pattern2, PATTERN_2_RESOLUTION);
  AND.load(pattern2, PATTERN_2_RESOLUTION);
//  MONEY.load(pattern2, PATTERN_2_RESOLUTION);
}

void patternMode() {
  WE.play(15, 0, false, true);
  DO.play(10, 0, false, true);
  THIS.play(5, 0, false, true);
  FOR.play(12, 0, false, true);
  HEART.play(8, 3, true, true);
  LVE.play(9, 2, false, true);
  AND.play(7, 0, false, true);
//  MONEY.play(11, 0, false, true);
  
  MONEY.pinball(200, 5); //Doesn't work .... check timer
  STAR.setPercentage(80);
  BACK.setPercentage(80);
  TRACK.setPercentage(80);
}

/*********************** PINBALL MODE ***********************/

void initPinballMode() {
  initOffMode();
}

void pinballMode() {
  PINBALL.pinball(100, 12);
}

/*********************** UTILS ***********************/

void setMode(int mode) {
  if(mode == MODE || mode == 4) { return; }
  
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
//      initPinballMode();
      break; 
      
    default:
      initOffMode();
  }
}

void runMode(int potReading) {
  
  float systemBrightness = (float)potReading / 1023;
  setSystemBrightness(systemBrightness);

  switch(MODE) {
    case 1:
      fadeMode();
      break; 
      
    case 2:
      waveMode();
      break;
      
    case 3:
      patternMode();
//      pinballMode();
      break;
      
    default:
      offMode();
  }
}

#endif
