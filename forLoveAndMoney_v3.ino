#include "tlc_config.h"
#include "Tlc5940.h"
#include <math.h>

const int LLpin = 7;
const int LRpin = 8;
const int left = -1;
const int right = 1;
int infiniteEncoderReading = 0;

int buttonStateLL = 0;
int buttonStateLR = 0;

const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int buttonPin4 = 6;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int selectedButton = 0;

const int analogInPin = A0;
int analogValue = 0;
int waitTime = 10;

unsigned long currentMillis = 0;
int on = 100;
const int off = 4095;
int mode = 0;
int dir = 0;

const int NUMBER_OF_CHANNELS = 30;
int WE_CHANNELS[1] = {16};
int DO_CHANNELS[2] = {9,10};
int THIS_CHANNELS[2] = {7,8};
int FOR_CHANNELS[1] = {6};
int LOVE_CHANNELS[7] = {23,24,25,26,27,28,29};
int AND_CHANNELS[1] = {5};
int MONEY_CHANNELS[5] = {0,1,2,3,4};

int STAR_CHANNELS[5] = {11,12,13,14,15};
int TRACK_CHANNELS[6] = {17,18,19,20,21,22};
int TRACK_TOP_CHANNELS[3] = {17,18,19};
int TRACK_BOTTOM_CHANNELS[3] = {20,21,22};
int LVE_CHANNELS[4] = {23,24,25,26};
int HEART_CHANNELS[3] = {27,28,29};

typedef struct {
  char *name;
  int *channels;
  int numOfChannels;
  int phase;
  int phaseSpeed;
  boolean asc;
  int brightness;
  unsigned long timer;
} CH_GRP;

CH_GRP we_grp;
CH_GRP do_grp;
CH_GRP this_grp;
CH_GRP for_grp;
CH_GRP love_grp;
CH_GRP and_grp;
CH_GRP money_grp;
CH_GRP star_grp;
CH_GRP track_grp;
CH_GRP track_top_grp;
CH_GRP track_bottom_grp;
CH_GRP lve_grp;
CH_GRP heart_grp;

const int wordsLength = 7;
CH_GRP* words_collection[wordsLength] = {&we_grp, &do_grp, &this_grp, &for_grp, &love_grp, &and_grp, &money_grp};

boolean mode_one_selected = false;

void setChGrp(CH_GRP *channel_group, int brightness);
void setCollection(CH_GRP* collection, int brightness, int lengthOfCollection);
void configureGroup(CH_GRP *channel_group, char *name, int *channels, int numOfChannels, int phase, int phaseSpeed, boolean asc, int brightness, unsigned long timer);
void pinballChGrp(CH_GRP *channel_group, int offset);
void flashChGrp(CH_GRP *channel_group, int startBrightness);
void fadeChGrp(CH_GRP *channel_group, int resolution);
void phaseChGrp(CH_GRP *channel_group, int offset);
void printGroup(CH_GRP channel_group);
void randomizeChGrp(CH_GRP *channel_group, int minChan);
void waveChGrp(CH_GRP *channel_group, int resolution);
void fadePopChGrp(CH_GRP *channel_group, int resolution);
void tick(void (*f)(CH_GRP*, int), long interval, CH_GRP *channel_group, int offsest);


void setup()
{
  pinMode(LLpin, INPUT);
  pinMode(LRpin, INPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  Tlc.init(off);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  resetAllGroups();
}

double readValue = 0;
int maxBrightness = on;

void loop()
{
  currentMillis = millis();

  int prevSelectedButton = selectedButton;
  selectedButton = readButtonState();
  
  if(prevSelectedButton != selectedButton) {
    mode = selectedButton;
  }
    
  analogValue = analogRead(analogInPin); // 0 - 1023
  infiniteEncoderReading = readInfiniteEncoder();
  waitTime = infiniteEncoderReading * 2;
  
  readValue = (analogValue < 1010) ? analogValue : 1023;
  maxBrightness = ((readValue / 1023) * (off - on)) + on;
  
  switch(mode) {
    case 0:
    mode_one_selected = false;
    resetAllGroups();
    break;
    
    case 1:
    if(!mode_one_selected) {
      mode_one_selected = true;
      setupModeOne();
    }

    modeOne();
    break;
    
    case 2:
    tick(flashChGrp,   waitTime, &we_grp, on);
    tick(fadeChGrp,    waitTime, &do_grp, 150);  
    tick(fadeChGrp,    waitTime, &this_grp, 150);
    tick(fadeChGrp,    waitTime, &for_grp, 150);
    tick(phaseChGrp,   waitTime, &lve_grp, 1);  
    tick(fadeChGrp,    waitTime, &and_grp, 150);
    tick(pinballChGrp, waitTime, &money_grp, money_grp.numOfChannels);  
    tick(phaseChGrp,   waitTime, &heart_grp, 1);
    tick(phaseChGrp,   waitTime, &star_grp, -1);
    tick(phaseChGrp,   waitTime, &track_top_grp, -1);
    tick(phaseChGrp,   waitTime, &track_bottom_grp, -1);
    break;
    
    case 3:
    tick(flashChGrp,   waitTime*40, &we_grp, on);
    tick(fadeChGrp,    waitTime, &do_grp, 150);
    tick(fadeChGrp,    waitTime, &this_grp, 150);
    tick(fadeChGrp,    waitTime, &for_grp, 150);
    tick(phaseChGrp,   waitTime, &lve_grp, 1);
    tick(fadeChGrp,    waitTime, &and_grp, 150);
    tick(fadeChGrp,    waitTime, &money_grp, 150);
    tick(phaseChGrp,   waitTime*2, &heart_grp, 1);
    tick(fadeChGrp,    waitTime/2, &star_grp, 150);
    tick(phaseChGrp,   waitTime/2, &track_top_grp, -1);
    tick(phaseChGrp,   waitTime/2, &track_bottom_grp, -1);
    break;
    
    default:
    resetAllGroups();
  }
  
  //setCollection(*words_collection, off, wordsLength);

  //tick(waveChGrp,   waitTime/4, &heart_grp, 100);
  //tick(randomizeChGrp, waitTime, &lve_grp, 1);

  Tlc.update();
}

/* MODES */

int res = 50;
void setupModeOne() {
    configureGroup(&we_grp, "WE", WE_CHANNELS, 1, res, 0, true, off, millis());
    configureGroup(&do_grp, "DO", DO_CHANNELS, 2, (res / 7) * 6, 0, true, off, millis());
    configureGroup(&this_grp, "THIS", THIS_CHANNELS, 2, (res / 7) * 5, 0, true, off, millis());
    configureGroup(&for_grp, "FOR", FOR_CHANNELS, 1, (res / 7) * 4, 0, true, off, millis());
    configureGroup(&love_grp, "LOVE", LOVE_CHANNELS, 7, (res / 7) * 3, 0, true, off, millis());
    configureGroup(&and_grp, "AND", AND_CHANNELS, 1, (res / 7) * 2, 0, true, off, millis());
    configureGroup(&money_grp, "MONEY", MONEY_CHANNELS, 5, (res / 7), 0, true, off, millis());
}

void modeOne() {
    tick(fadeChGrp,    waitTime, &we_grp, res);  
    tick(fadeChGrp,    waitTime, &do_grp, res);
    tick(fadeChGrp,    waitTime, &this_grp, res);
    tick(fadeChGrp,    waitTime, &for_grp, res);
    tick(fadeChGrp,    waitTime, &love_grp, res);
    tick(fadeChGrp,    waitTime, &and_grp, res);
    tick(fadeChGrp,    waitTime, &money_grp, res);
    tick(fadeChGrp,    waitTime, &star_grp, res);
}

/* CONTROLS */
int val;
int encoder0Pos = 1;
int encoder0PinALast = LOW;
int n = LOW;
int sensitivity = 3;

int readInfiniteEncoder() {
  n = digitalRead(LLpin);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(LRpin) == LOW) {
       encoder0Pos += sensitivity;
     } else {
       encoder0Pos -= sensitivity;
     }
   }
   if(encoder0Pos < 1) {
     encoder0Pos = 1;
   }
   
   if(encoder0Pos > 120) {
     encoder0Pos = 120;  
   }
   encoder0PinALast = n;
   
   Serial.println(encoder0Pos);
   return encoder0Pos;
}

int readButtonState() {
  int tempMode = 0;
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if(buttonState1 == 1) {
    tempMode = 1;
  }
  if(buttonState2 == 1) {
    tempMode = 2;
  }
  if(buttonState3 == 1) {
    tempMode = 3;
  }
  if(buttonState4 == 1) {
    tempMode = 4;
  }
  
  return tempMode;
}

/* PATTERNS */

void waveChGrp(CH_GRP *channel_group, int resolution) {
  int maxOn = on;// + (off/2);
  int phase = channel_group->phase;
  int range = off - maxOn;
  int increment = range / resolution;

  int offset = increment * channel_group->numOfChannels;
  int brightness = channel_group->asc ? maxOn + (phase * increment) : off - (phase * increment);
  
  if(channel_group->phase < resolution) {
    for(int i = 0; i < channel_group->numOfChannels; i++) {
      
      int chanBrightness = channel_group->asc ? brightness - (offset * i) : brightness + (offset * i);
      
      if(chanBrightness > off) {
        chanBrightness = off;
      } else if (chanBrightness < maxOn) {
        chanBrightness = maxOn;
      }
      
      Tlc.set(channel_group->channels[i], chanBrightness);
      
    }
    channel_group->phase = channel_group->phase + 1;
  } else {
    channel_group->asc = !channel_group->asc;
    channel_group->phase = 0;
    waveChGrp(channel_group, resolution);
  }
}

void randomizeChGrp(CH_GRP *channel_group, int minChan) {
  int offset = random(minChan, channel_group->numOfChannels);
  phaseChGrp(channel_group, offset);
}

void pinballChGrp(CH_GRP *channel_group, int offset) {
  int cycle = channel_group->numOfChannels - offset;
  int phase = channel_group->phase;
  int limit = addFactors(channel_group->numOfChannels, cycle);
  int channelToLight = phase % (limit - offset);
  int channelsToKeep = cycle;

  if(phase < limit) {
    setChGrp(channel_group, off);
    for(int i = 0; i < channelsToKeep; i++) {
      Tlc.set(channel_group->channels[channel_group->numOfChannels - i - 1], maxBrightness);
    }
    Tlc.set(channel_group->channels[channelToLight], maxBrightness);

    channel_group->phase = channel_group->phase + 1;
  } else {
    if(cycle < channel_group->numOfChannels) {   
      pinballChGrp(channel_group, offset-1);
    } else {
      channel_group->phase = 0;
      setChGrp(channel_group, off);
    }
  }
}

//void rotateChGrp(CH_GRP *channel_group, int brightness) {
//  int phase = channel_group->phase;
//  for(int i = 0; i < channel_group->numOfChannels; i++) {
//    if(i < phase) {
//      Tlc.set(channel_group->channels[i], brightness);
//    } else {
//      Tlc.set(channel_group->channels[i], off);
//    }
//  }
//  if(phase < channel_group->numOfChannels) {
//    channel_group->phase = phase + 1;
//  } else {
//    channel_group->phase = 0;
//  }
//}

void flashChGrp(CH_GRP *channel_group, int startBrightness) {
  channel_group->phase = channel_group->phase ? 0 : 1;
  int brightness = channel_group->phase ? (startBrightness == on ? on : off) : (startBrightness == on ? off : on);
  setChGrp(channel_group, brightness);
}

void phaseChGrp(CH_GRP *channel_group, int offset) {
  Tlc.set(channel_group->channels[channel_group->phase], off);
  int newPhase = channel_group->phase + channel_group->phaseSpeed + offset;
  newPhase = newPhase % channel_group->numOfChannels;
  if(newPhase < 0) {
    newPhase = newPhase + channel_group->numOfChannels; 
  }
  channel_group->phase = newPhase;
  Tlc.set(channel_group->channels[newPhase], maxBrightness);
}

void fadeChGrp(CH_GRP *channel_group, int resolution) {
  int phase = channel_group->phase;
  int range = off - on;
  int increment = range / resolution;
  
  int brightness = channel_group->asc ? on + (phase * increment) : off - (phase * increment);  
  
  if(channel_group->phase < resolution) {
    setChGrp(channel_group, brightness);    
    channel_group->phase = channel_group->phase + 1;
  } else {
    channel_group->asc = !channel_group->asc;
    channel_group->phase = 0;
    fadeChGrp(channel_group, resolution);
  }
}

void fadePopChGrp(CH_GRP *channel_group, int resolution) {
  int phase = channel_group->phase;
  int range = off - on;
  int increment = range / resolution;
  
  int brightness = channel_group->asc ? on + (phase * increment) : off - (phase * increment);
  double tempbrightness = log(brightness - on) / log(range);
  tempbrightness = (tempbrightness * range) + on;
  brightness = round(tempbrightness);
  
  if(channel_group->phase < resolution) {
    setChGrp(channel_group, brightness);    
    channel_group->phase = channel_group->phase + 1;
  } else {
    channel_group->asc = !channel_group->asc;
    channel_group->phase = 0;
    fadeChGrp(channel_group, resolution);
  }
}

/* UTILITIES */

int getLog(int number, int minNumber, int maxNumber) {
  double range = log(maxNumber)-log(minNumber);
  double val = log(number) - log(minNumber);
  double logNum = val / range;
  return logNum;
}

int percentOfRange(int num, int minNum, int maxNum) {
  int range = maxNum - minNum;
  double tempNum = (double)num / range;
  return tempNum * 100;
}

void setCollection(CH_GRP* collection, int brightness, int lengthOfCollection) {
  for(int i = 0; i < lengthOfCollection; i++) {
    setChGrp(&collection[i], brightness);
  }
}

void setChGrp(CH_GRP *channel_group, int brightness) {
  double tempBrightness = ((double)brightness - on) / (off - on);
  int range = off - maxBrightness;
  tempBrightness = (tempBrightness * range) + maxBrightness;
  
  int newBrightness = tempBrightness;

  //getLog(newBrightness - maxBrightness+1, 1, off - maxBrightness + 1);
  
  int channel;  
  for(int i = 0; i < channel_group->numOfChannels; i++) {
    channel = channel_group->channels[i];
    Tlc.set(channel, newBrightness);
  }
  channel_group->brightness = newBrightness;
}

void tick(void (*f)(CH_GRP*, int), long interval, CH_GRP *channel_group, int offset) {
  if(currentMillis - channel_group->timer > interval) {
    channel_group->timer = currentMillis;
    (*f)(channel_group, offset);
  }
}

int addFactors(int n, int reps) {
  int result = n;
  for(int i = 0; i < reps; i++) {
    result = result + n - (i+1);
  }
  return result;
}

/* SETUP*/

void resetAllGroups() {
  Tlc.setAll(off);
  configureGroup(&we_grp, "WE", WE_CHANNELS, 1, 0, 0, true, off, millis());
  configureGroup(&do_grp, "DO", DO_CHANNELS, 2, 0, 0, true, off, millis());
  configureGroup(&this_grp, "THIS", THIS_CHANNELS, 2, 0, 0, true, off, millis());
  configureGroup(&for_grp, "FOR", FOR_CHANNELS, 1, 0, 0, true, off, millis());
  configureGroup(&love_grp, "LOVE", LOVE_CHANNELS, 7, 0, 0, true, off, millis());
  configureGroup(&and_grp, "AND", AND_CHANNELS, 1, 0, 0, true, off, millis());
  configureGroup(&money_grp, "MONEY", MONEY_CHANNELS, 5, 0, 0, true, off, millis());
  
  configureGroup(&star_grp, "STAR", STAR_CHANNELS, 5, 0, 0, true, off, millis());  
  configureGroup(&track_grp, "TRACK", TRACK_CHANNELS, 6, 0, 0, true, off, millis());  
  configureGroup(&track_top_grp, "TRACK TOP", TRACK_TOP_CHANNELS, 3, 0, 0, true, off, millis());  
  configureGroup(&track_bottom_grp, "TRACK BOTTOM", TRACK_BOTTOM_CHANNELS, 3, 0, 0, true, off, millis());  
  configureGroup(&lve_grp, "LVE", LVE_CHANNELS, 4, 0, 0, true, off, millis());  
  configureGroup(&heart_grp, "HEART", HEART_CHANNELS, 3, 0, 0, true, off, millis()); 
}

void configureGroup(CH_GRP *channel_group, char *name, int *channels, int numOfChannels, int phase, int phaseSpeed, boolean asc, int brightness, unsigned long timer) {
  channel_group->name = name;
  channel_group->channels = channels;
  channel_group->numOfChannels = numOfChannels;
  channel_group->phase = phase;
  channel_group->phaseSpeed = phaseSpeed;
  channel_group->asc = asc;
  channel_group->brightness = brightness;
  channel_group->timer = timer;  
}

/* TESTING */

void printGroup(CH_GRP channel_group) {
  Serial.println(channel_group.name);
  Serial.print("1st Ch : ");
  Serial.println(channel_group.channels[0]);
  Serial.print("No. Ch : ");
  Serial.println(channel_group.numOfChannels);
  Serial.print("Phase  : ");  
  Serial.println(channel_group.phase);
  Serial.print("Asc?   : ");
  Serial.println(channel_group.asc);
  Serial.print("Grp Br : ");  
  Serial.println(channel_group.brightness);
  Serial.print("Timer  : ");  
  Serial.println(channel_group.timer);
  Serial.println("------------------");  
}
