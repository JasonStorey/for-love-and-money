#include "tlc_config.h"
#include <Tlc5940.h>
#include "User_input.h"
#include "Patterns.h"
#include "Channel_group.h"
#include <Wire.h>
#include <RTClib.h>

#define ON 100
#define OFF 4095

RTC_DS1307 RTC;
#include "Channels.h"
#include "Modes.h"

void setup() { 
  Serial.begin(57600); // opens serial port, sets data rate to 9600 bps
  input.init();
  Tlc.init(OFF);
  Wire.begin();
  RTC.begin();

  Serial.println("START!");

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
  systemTime = millis();
  
  setMode(input.readButtonState());
  runMode(input.readPot(), input.readInfiniteEncoder());
  
  Tlc.update();
}
