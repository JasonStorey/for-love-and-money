#include "tlc_config.h"
#include <Tlc5940.h>
#include <math.h>
#include "User_input.h"
#include "Channel_group.h"

int on = 100;
int off = 4095;

#include "Channels.h"

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
