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
  for(int i = 0; i < _numOfChannels; i++) {
    channel = _channels[i];
    Tlc.set(channel, tempBrightness);
  }
  _brightness = tempBrightness;
}

void Channel_group::setPhase(int phase) {
  _phase = phase;
};

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
