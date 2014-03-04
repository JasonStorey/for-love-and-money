#include "tlc_config.h"
#include <Tlc5940.h>
#include <math.h>
#include "User_input.h"
#include "Channel_group.h"

#define ON 100
#define OFF 4095

#include "Channels.h"
#include "Modes.h"

void setup() { 
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  input.init();
  Tlc.init(OFF);
  setMode(0);
}

void loop() {
  runMode();
  
  //WE.flash(1000, on);
  //LOVE.phase(100, 1);

//  STAR.fade(15, 300);  
//  TRACK.fade(15, 300); 
  
  //MONEY.pinball(100, 5); //Doesn't work .... check timer
  //MONEY.set(off); // 'off' is currently 'on' because of log curve reversal :(
  //MONEY.print();
  
  //Serial.println(input.readPot());

  Tlc.update();
}
