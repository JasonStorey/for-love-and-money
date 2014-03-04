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
Channel_group TRACK("TRACK", TRACK_CHANNELS, 6, 0, 0, true, off, on, off, millis());
Channel_group LOVE("LOVE", LOVE_CHANNELS, 7, 0, 0, true, off, on, off, millis());
Channel_group MONEY("MONEY", MONEY_CHANNELS, 5, 0, 0, true, off, on, off, millis());

void setup() { 
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  input.init();
  Tlc.init(off);
}

void loop() {
  
  WE.flash(1000, on);
  TRACK.fade(10, 300);
  LOVE.phase(100, 1);
  
  //MONEY.pinball(100, 5); //Doesn't work .... check timer
  MONEY.set(off); // 'off' is currently 'on' because of log curve reversal :(
  //MONEY.print();
  
  Serial.println(input.readButtonState());

  Tlc.update();
}
