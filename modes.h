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

void updateChannelGroupClocks(unsigned long time) {
  WE.updateSystemTime(time);
  DO.updateSystemTime(time);
  THIS.updateSystemTime(time);
  FOR.updateSystemTime(time);
  HEART.updateSystemTime(time);
  LVE.updateSystemTime(time);
  AND.updateSystemTime(time);
  MONEY.updateSystemTime(time);
  
  STAR.updateSystemTime(time);
  TRACK.updateSystemTime(time);
  TRACK_TOP.updateSystemTime(time);
  TRACK_BOTTOM.updateSystemTime(time);
  BACK.updateSystemTime(time);
  PINBALL.updateSystemTime(time);  
}

/*********************** OFF MODE ***********************/

void initOffMode() {
 
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(0, 0, true, OFF, ON, OFF, systemTime);
  DO.configure(0, 0, true, OFF, ON, OFF, systemTime);
  THIS.configure(0, 0, true, OFF, ON, OFF, systemTime);
  FOR.configure(0, 0, true, OFF, ON, OFF, systemTime);
  HEART.configure(0, 0, true, OFF, ON, OFF, systemTime);
  LVE.configure(0, 0, true, OFF, ON, OFF, systemTime);
  AND.configure(0, 0, true, OFF, ON, OFF, systemTime);
  MONEY.configure(0, 0, true, OFF, ON, OFF, systemTime);
  
  STAR.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK.configure(0, 0, true, OFF, ON, OFF, systemTime);
  BACK.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK_TOP.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK_BOTTOM.configure(0, 0, true, OFF, ON, OFF, systemTime);

  PINBALL.configure(0, 0, true, OFF, ON, OFF, systemTime);
}

void offMode() {
    Tlc.setAll(OFF);
}

/*********************** FADE MODE ***********************/

void initFadeMode() {
  // phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer
  WE.configure(80, 0, true, OFF, ON, OFF, systemTime);
  DO.configure(70, 0, true, OFF, ON, OFF, systemTime);
  THIS.configure(60, 0, true, OFF, ON, OFF, systemTime);
  FOR.configure(50, 0, true, OFF, ON, OFF, systemTime);
  HEART.configure(10, 0, true, OFF, ON, OFF, systemTime);
  LVE.configure(25, 0, true, OFF, ON, OFF, systemTime);
  HEART.load(pattern1, PATTERN_1_RESOLUTION);
  
  AND.configure(15, 0, true, OFF, ON, OFF, systemTime);
  MONEY.configure(0, 0, true, OFF, ON, OFF, systemTime);
  
  STAR.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK_TOP.configure(0, 0, true, OFF, ON, OFF, systemTime);
  TRACK_BOTTOM.configure(0, 0, true, OFF, ON, OFF, systemTime);
  BACK.configure(0, 0, true, OFF, ON, OFF, systemTime);   
}

void fadeMode(int time) {
  WE.fade(1 + time, 100);
  DO.fade(1 + time, 100);
  THIS.fade(1 + time, 100);
  FOR.fade(1 + time, 100);
  LVE.fade(1 + time, 100);
  HEART.play(1 + time, 5, true, false);
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
//  WE.configure(82, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
//  DO.configure(68, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
//  THIS.configure(54, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
//  FOR.configure(42, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
  HEART.configure(0, 0, false, minBrightness, ON, minBrightness, systemTime);
  LVE.configure(0, 0, true, minBrightness, ON, minBrightness, systemTime);
//  AND.configure(14, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
//  MONEY.configure(0, 0, true, middleBrightness, maxBrightness, middleBrightness, systemTime);
  
  STAR.configure(0, 0, true, middleBrightness, ON, middleBrightness, systemTime);
  TRACK.configure(0, 0, true, minBrightness, ON, minBrightness, systemTime); 
  BACK.configure(0, 0, true, minBrightness, ON, minBrightness, systemTime);
  TRACK_TOP.configure(0, 0, true, minBrightness, ON, minBrightness, systemTime); 
  TRACK_BOTTOM.configure(0, 0, true, minBrightness, ON, minBrightness, systemTime);
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
  
  WE.configure(180, 0, true, OFF, ON, OFF, systemTime);
  DO.configure(24, 0, true, OFF, ON, OFF, systemTime);
  THIS.configure(40, 0, true, OFF, ON, OFF, systemTime);
  FOR.configure(100, 0, true, OFF, ON, OFF, systemTime);
  HEART.configure(12, 0, true, OFF, ON, OFF, systemTime);
  LVE.configure(140, 0, true, OFF, ON, OFF, systemTime);
  AND.configure(48, 0, true, OFF, ON, OFF, systemTime);
  MONEY.configure(0, 0, true, OFF, ON, OFF, systemTime);

  HEART.load(pattern2, PATTERN_2_RESOLUTION);
  LVE.load(pattern2, PATTERN_2_RESOLUTION);
  
  PINBALL.load(pattern2, PATTERN_2_RESOLUTION);
}

void patternMode(int time) {
  HEART.play(1 + time, 5, true, true);
  LVE.play(1 + time, 2, false, true);

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
  LVE.flash(100, ON);
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
  updateChannelGroupClocks(systemTime);
  
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
