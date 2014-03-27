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
  
  PINBALL.setSystemBrightness(brightness);  
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

  PINBALL.configure(0, 0, true, OFF, ON, OFF, millis());
}

void offMode() {
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

void fadeMode(int time) {
  WE.fade(1 + time, 100);
  DO.fade(1 + time, 100);
  THIS.fade(1 + time, 100);
  FOR.fade(1 + time, 100);
  LVE.fade(1 + time, 100);
//  HEART.play(1 + time, 5, true, false);
  AND.fade(1 + time, 100);  
  MONEY.fade(1 + time, 100);

  STAR.wave(6 + time, 200, 0.5, 1.0);
  TRACK_TOP.wave(21 + time, 200, 0.9, 0.5);
  TRACK_BOTTOM.wave(21 + time, 200, 0.9, 0.5);  
  BACK.setPercentage(80);
}

/*********************** WAVE MODE ***********************/

void initWaveMode() {
  const int minBrightness = OFF;
  const int middleBrightness = OFF;  
  const int maxBrightness = ON;
  
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
//  WE.configure(82, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
//  DO.configure(68, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
//  THIS.configure(54, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
//  FOR.configure(42, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  HEART.configure(0, 0, false, minBrightness, ON, minBrightness, millis());
  LVE.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
//  AND.configure(14, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
//  MONEY.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, millis());
  
  STAR.configure(0, 0, true, middleBrightness, ON, middleBrightness, millis());
  TRACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis()); 
  BACK.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  TRACK_TOP.configure(0, 0, true, minBrightness, ON, minBrightness, millis()); 
  TRACK_BOTTOM.configure(0, 0, true, minBrightness, ON, minBrightness, millis());
  PINBALL.load(pattern2, PATTERN_2_RESOLUTION);
}

void waveMode(int time) {
//  WE.fade(20 + time, 100);
//  DO.fade(20 + time, 100);
//  THIS.fade(20 + time, 100);
//  FOR.fade(20 + time, 100);
  HEART.wave(15 + time, 40, 1.04, 1.0);  
  LVE.wave(1 + time, 40, 1.42, 1.0);
//  AND.fade(20 + time, 100);
//  MONEY.fade(20 + time, 100);
  
  STAR.wave(15 + time, 70, 0.5, 1.0);
  BACK.setPercentage(100);
  TRACK_TOP.wave(1 + time, 50, 1.95, 0.7);
  TRACK_BOTTOM.wave(1 + time, 50, 1.95, 0.7);
//  TRACK_TOP.phase(100, -1);
//  TRACK_BOTTOM.phase(100, -1);
  PINBALL.play(5 + time, 2, false, true);

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
  
//  WE.load(pattern2, PATTERN_2_RESOLUTION);
//  DO.load(pattern2, PATTERN_2_RESOLUTION);
//  THIS.load(pattern2, PATTERN_2_RESOLUTION);
//  FOR.load(pattern2, PATTERN_2_RESOLUTION);
  HEART.load(pattern2, PATTERN_2_RESOLUTION);
  LVE.load(pattern2, PATTERN_2_RESOLUTION);
//  AND.load(pattern2, PATTERN_2_RESOLUTION);
  
  PINBALL.load(pattern2, PATTERN_2_RESOLUTION);
}

void patternMode(int time) {
//  WE.play(15, 0, false, true);
//  DO.play(15, 0, false, true);
//  THIS.play(15, 0, false, true);
//  FOR.play(15, 0, false, true);
  HEART.play(1 + time, 5, true, true);
  LVE.play(1 + time, 2, false, true);
//  AND.play(15, 0, false, true);
//  
//  MONEY.pinball(200, 5);

  PINBALL.play(1 + time, 2, false, true);
  
  STAR.wave(1 + time, 20, 0.5, 1.0);
  BACK.setPercentage(80);
  TRACK_TOP.wave(1 + time, 6, 1.6, 0.7);
  TRACK_BOTTOM.wave(1 + time, 6, 1.6, 0.7);
}

/*********************** CRUDE MODE ***********************/

void initCrudeMode() {
  initOffMode();
}

void crudeMode(int time) {
  WE.flash(15 + time * 5, ON);
  DO.fade(1 + time * 5, 100);
  THIS.fade(1 + time * 5, 100);
  FOR.fade(1 + time * 5, 100);
  HEART.phase(1 + time * 5, 1);
  LVE.phase(1 + time * 5, 1);
  AND.fade(1 + time * 5, 100);
  
  MONEY.pinball(200, 5);
  
  STAR.phase(1 + time * 5, 1);
  BACK.setPercentage(80);
  TRACK_TOP.phase(1 + time * 5, -1);
  TRACK_BOTTOM.phase(1 + time * 5, -1);
}

/*********************** CRUDE MODE ***********************/

void initJazzMode() {
  initOffMode();
}

void jazzMode() {  
  WE.flash(100, ON);
  DO.flash(100, ON);
//  THIS.flash(100, ON);
//  FOR.flash(100, ON);
//  HEART.flash(100, ON);
  LVE.flash(100, ON);
//  AND.flash(100, ON);
//
//  MONEY.flash(100, ON);
//  PINBALL.pinball(100, 12);

//
//  STAR.flash(100, OFF);
//  BACK.setPercentage(80);
//  TRACK_TOP.flash(100, OFF);
//  TRACK_BOTTOM.flash(100, OFF);
} 

/*********************** PINBALL MODE ***********************/

void initPinballMode() {
  initOffMode();
}

void pinballMode(int time) {
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
      initCrudeMode();
      break;
    
    case 5:
      initJazzMode();
      break;
      
    default:
      initOffMode();
  }
}

void runMode(int potReading, int infiniteEncoderReading) {
  
  float systemBrightness = (float)potReading / 1023;
  setSystemBrightness(systemBrightness);

  switch(MODE) {
    case 1:
      fadeMode(infiniteEncoderReading);
      break; 

    case 2:
      waveMode(infiniteEncoderReading);
      break;

    case 3:
      crudeMode(infiniteEncoderReading);
      break;

    case 5:
      jazzMode();
      break;

    default:
      offMode();
  }
}

#endif
