#include "Channel_group.h"

Channel_group::Channel_group(char *name, int *channels, int numOfChannels, int phase, int phaseSpeed, boolean asc, int brightness, int maxBrightness, int minBrightness, unsigned long timer) {
  _name = name;
  _channels = channels;
  _numOfChannels = numOfChannels;
  _phase = phase;
  _phaseSpeed = phaseSpeed;
  _asc = asc;
  _brightness = brightness;
  _maxBrightness = maxBrightness;
  _minBrightness = minBrightness;
  _timer = timer;
  
  R = (100 * log10(2)) / (log10((_minBrightness - _maxBrightness)));
}

void Channel_group::set(int brightness) {
//  OLD LINEAR JAZZ
//  int channel;  
//  for(int i = 0; i < _numOfChannels; i++) {
//    channel = _channels[i];
//    Tlc.set(channel, brightness);
//  }
//  _brightness = brightness;
//  Serial.println(getPercentage(brightness - _maxBrightness, _minBrightness - _maxBrightness));
  setPercentage(getPercentage(brightness - _maxBrightness, _minBrightness - _maxBrightness));
}

void Channel_group::setPercentage(int percent) {
  int channel;
  int tempBrightness = getLogBrightness(percent);
  int i = 0;
  for(i = 0; i < _numOfChannels; i++) {
    channel = _channels[i];
    Tlc.set(channel, tempBrightness);
  }
  _brightness = tempBrightness;
}

void Channel_group::setPhase(int phase) {
  _phase = phase;
}

void Channel_group::configure(int phase, int phaseSpeed, boolean asc, int brightness, int maxBrightness, int minBrightness, unsigned long timer) {
  _phase = phase;
  _phaseSpeed = phaseSpeed;
  _asc = asc;
  _brightness = brightness;
  _maxBrightness = maxBrightness;
  _minBrightness = minBrightness;
  _timer = timer;
  
   R = (100 * log10(2)) / (log10((_minBrightness - _maxBrightness)));
}

/* PATTERNS */

void Channel_group::flash(long interval, int startBrightness) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed

  _phase = _phase ? 0 : 1;
  int brightness = _phase ? (startBrightness == _maxBrightness ? _maxBrightness : _minBrightness) : (startBrightness == _maxBrightness ? _minBrightness : _maxBrightness);
  set(brightness);
}

void Channel_group::fade(long interval, int resolution) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed
  
  int phase = _phase;
  int range = _minBrightness - _maxBrightness;
  int increment = range / resolution;
  
  int brightness = _asc ? _maxBrightness + (phase * increment) : _minBrightness - (phase * increment);  
  if(_phase < resolution) {
    set(brightness);
    _phase++;
  } else {
    _asc = !_asc;
    _phase = 0;
    fade(0, resolution);
  }
}

void Channel_group::wave(long interval, int resolution, float offset) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed
   
  int range = _minBrightness - _maxBrightness;
  
  float something = _asc ? (float)_phase / resolution : (float) (resolution - _phase) / resolution;
  if(_phase <= resolution) {
    int i = 0;
    for(i = 0; i < _numOfChannels; i++) {      
      int brightness = (range / 2) + (range / 2) * sin( something * 2.0 * PI + (i * offset));
      Tlc.set(_channels[i], getLogBrightness(getPercentage(brightness - _maxBrightness, _minBrightness - _maxBrightness)));
    }
    _phase++;
    
  } else {
    _phase = 0;
    wave(0, resolution, offset);
  }
}

void Channel_group::load(prog_uint16_t* pattern, int patternLength) {
  _pattern = pattern;
  _patternLength = patternLength;
}

void Channel_group::play(long interval) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed  
  
  if(_phase < _patternLength) {
    int val = pgm_read_word_near(_pattern + _phase);
    setPercentage(val);
    _phase++;
  } else {
    _phase = 0;
    play(interval);
  }
}

void Channel_group::play(long interval, int offset) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed  
  
  if(_phase < _patternLength) {    
    int val = 0;
    int brightness = _minBrightness;
    int i = 0;  
    for(i = 0; i < _numOfChannels; i++) {
      val = pgm_read_word_near(_pattern + ((_phase + (i * offset)) % _patternLength));
      brightness = getLogBrightness(val);
      Tlc.set(_channels[i], brightness);
      if(i == 0) {
        _brightness = brightness;
      }
    }
    _phase++;
  } else {
    _phase = 0;
    play(interval, offset);
  }
}

void Channel_group::phase(long interval, int offset) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed

  Tlc.set(_channels[_phase], _minBrightness);
  
  int newPhase = _phase + _phaseSpeed + offset;
  newPhase = newPhase % _numOfChannels;
  if(newPhase < 0) {
    newPhase = newPhase + _numOfChannels; 
  }
  _phase = newPhase;
  Tlc.set(_channels[newPhase], _maxBrightness);
}

void Channel_group::pinball(long interval, int offset) {
  
  if(!intervalElapsed(interval)) { return; } // Break until interval has passed

  int cycle = _numOfChannels - offset;
  int phase = _phase;
  int limit = addFactors(_numOfChannels, cycle);
  int channelToLight = phase % (limit - offset);
  int channelsToKeep = cycle;
  
  if(phase < limit) {
    set(_minBrightness);
    for(int i = 0; i < channelsToKeep; i++) {
      Tlc.set(_channels[_numOfChannels - i - 1], _maxBrightness);
    }
    Tlc.set(_channels[channelToLight], _maxBrightness);

    _phase++;
  } else {
    if(cycle < _numOfChannels) {   
      pinball(0, offset-1);
    } else {
      _phase = 0;
      set(_minBrightness);
    }
  }
}

/* UTILS */

int Channel_group::addFactors(int n, int reps) {
  int result = n;
  for(int i = 0; i < reps; i++) {
    result = result + n - (i+1);
  }
  return result;
}

boolean Channel_group::intervalElapsed(long interval) {
  if(millis() - _timer > interval) {
    _timer = millis();
    return true;
  } else {
    return false; 
  }
}

int Channel_group::getLogBrightness(int interval) {
  int brightness = brightness = pow(2, (interval / R)) - 1 + _maxBrightness;
  int reversedBrightness = _minBrightness - brightness + _maxBrightness;
  return reversedBrightness; // TODO: get smarter. Curve is the wrong way and I'm not smart enough to fix properly.
}

int Channel_group::getPercentage(int num, int total) {
  return ((float) num / total) * 100;
}

void Channel_group::print() {
  Serial.println(_name);
  Serial.print("1st Ch : ");
  Serial.println(_channels[0]);
  Serial.print("No. Ch : ");
  Serial.println(_numOfChannels);
  Serial.print("Phase  : ");  
  Serial.println(_phase);
  Serial.print("Asc?   : ");
  Serial.println(_asc);
  Serial.print("Grp Br : ");  
  Serial.println(_brightness);
  Serial.print("Max Br : ");  
  Serial.println(_maxBrightness);
  Serial.print("Min Br : ");  
  Serial.println(_minBrightness); 
  Serial.print("Timer  : ");  
  Serial.println(_timer);
  Serial.println("------------------");  
}
