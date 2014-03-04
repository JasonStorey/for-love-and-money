#include "tlc_config.h"
#include "Tlc5940.h"
#include <math.h>
#include "Channel_group.h"
#include "Channels.h"

int on = 100;
int off = 4095;
float R;
int num = 0;

// (name, channels, numOfChannels, phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer)
Channel_group WE("WE", WE_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group TRACK("TRACK", TRACK_CHANNELS, 6, 0, 0, true, off, on, off, millis());
Channel_group LOVE("LOVE", LOVE_CHANNELS, 7, 0, 0, true, off, on, off, millis());
Channel_group MONEY("MONEY", MONEY_CHANNELS, 5, 0, 0, true, off, on, off, millis());

void setup() { 
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  R = (100 * log10(2))/(log10(4095));
  Tlc.init(off);
}

void loop() {
  
  WE.flash(1000, on);
  TRACK.fade(20, 100);
  LOVE.phase(100, 1);
  //MONEY.pinball(100, 5); //Doesn't work .... check timer
  //LOVE.print();
  
  //delay(1000);
  
  Serial.println(pwm(num));
  if(num == 100) {
    num = 0;
  } else {
    num++;
  } 
  
  Tlc.update();
}

int pwm(int interval) {
  int brightness = 0;
  return brightness = pow(2, (interval / R)) - 1;
}
