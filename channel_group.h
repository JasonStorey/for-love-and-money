#ifndef Channel_group_h
#define Channel_group_h

#include "Arduino.h"
#include <avr/pgmspace.h>
#include "tlc_config.h"
#include "Tlc5940.h"

class Channel_group {
  
  public:
    Channel_group(char *name, int *channels, int numOfChannels, int phase, int phaseSpeed, boolean asc, int brightness, int maxBrightness, int minBrightness, unsigned long timer);
    void configure(int phase, int phaseSpeed, boolean asc, int brightness, int maxBrightness, int minBrightness, unsigned long timer);
    void set(int brightness);
    void setPercentage(int percent);
    void setPhase(int phase);
    void print();
    void load(prog_uint16_t* pattern, int patternLength);
    void play(long interval);
    void play(long interval, int offset);
    void flash(long interval, int startBrightness);
    void fade(long interval, int resolution);
    void wave(long interval, int resolution, float offset);
    void phase(long interval, int offset);
    void pinball(long interval, int offset);
    void setSystemBrightness(float brightness);
  
  private:
    boolean intervalElapsed(long interval);
    int addFactors(int n, int reps);
    int getLogBrightness(float interval);
    int getPercentage(int num, int total);

    char *_name;
    int *_channels;
    int _numOfChannels;
    int _phase;
    int _phaseSpeed;
    boolean _asc;
    int _brightness;
    int _maxBrightness;
    int _minBrightness;
    unsigned long _timer;
    float R;
    prog_uint16_t* _pattern;
    int _patternLength;
    float _systemBrightness;
};

#endif
