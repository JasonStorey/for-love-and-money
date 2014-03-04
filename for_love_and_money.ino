#include "tlc_config.h"
#include <Tlc5940.h>
#include <math.h>
#include "User_input.h"
#include "Channel_group.h"
#include "Channels.h"

int on = 100;
int off = 4095;

// (name, channels, numOfChannels, phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer)
Channel_group WE("WE", WE_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group DO("DO", DO_CHANNELS, 2, 0, 0, true, off, on, off, millis());
Channel_group THIS("THIS", THIS_CHANNELS, 2, 0, 0, true, off, on, off, millis());
Channel_group FOR("FOR", FOR_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group LOVE("LOVE", LOVE_CHANNELS, 7, 0, 0, true, off, on, off, millis());
Channel_group AND("AND", AND_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group MONEY("MONEY", MONEY_CHANNELS, 5, 0, 0, true, off, on, off, millis());

Channel_group STAR("STAR", STAR_CHANNELS, 5, 0, 0, true, off, on, off, millis());
Channel_group TRACK("TRACK", TRACK_CHANNELS, 6, 0, 0, true, off, on, off, millis());
Channel_group TRACK_TOP("TRACK_TOP", TRACK_TOP_CHANNELS, 3, 0, 0, true, off, on, off, millis());
Channel_group TRACK_BOTTOM("TRACK_BOTTOM", TRACK_BOTTOM_CHANNELS, 3, 0, 0, true, off, on, off, millis());
Channel_group LVE("LVE", LVE_CHANNELS, 4, 0, 0, true, off, on, off, millis());
Channel_group HEART("HEART", HEART_CHANNELS, 3, 0, 0, true, off, on, off, millis());

void setup() { 
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  input.init();
  Tlc.init(off);
}

void loop() {
  
  //WE.flash(1000, on);
  //LOVE.phase(100, 1);
  WE.fade(5, 300);
  DO.fade(5, 300);
  THIS.fade(5, 300);
  FOR.fade(5, 300);  
  LOVE.fade(5, 300);
  AND.fade(5, 300);  
  MONEY.fade(5, 300);

  STAR.fade(15, 300);  
  TRACK.fade(15, 300); 
  
  //MONEY.pinball(100, 5); //Doesn't work .... check timer
  //MONEY.set(off); // 'off' is currently 'on' because of log curve reversal :(
  //MONEY.print();
  
  Serial.println(input.readPot());

  Tlc.update();
}
