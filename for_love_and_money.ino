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
    Serial.println("START!");  
}

void loop() {
  
  // RTC Library is here - https://github.com/adafruit/RTClib
  DateTime now = RTC.now();
  
  if(now.hour() > 23) {
    Serial.print("\t");
    Serial.println(now.unixtime());
  }
  
  
/***************** STEVE NOTES ***************/

// The two functions below, setMode and runMode, are what run the patterns.
// Mode 3 seems to kill the Arduino pretty quickly... 
// Eg. setMode(3)

  setMode(input.readButtonState());
  runMode(input.readPot(), input.readInfiniteEncoder());

// Calling the following also causes strange readings from the RTC, but far less frequently, and rarely killed the Arduino.
// Tlc.setAll(random(0,4095));

/******************** FIN ******************/

  Tlc.update();
}
