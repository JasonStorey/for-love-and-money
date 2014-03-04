#ifndef Channels_h
#define Channels_h

static int WE_CHANNELS[1] = {16};
static int DO_CHANNELS[2] = {9,10};
static int THIS_CHANNELS[2] = {7,8};
static int FOR_CHANNELS[1] = {6};
static int LOVE_CHANNELS[7] = {23,24,25,26,27,28,29};
static int AND_CHANNELS[1] = {5};
static int MONEY_CHANNELS[5] = {0,1,2,3,4};

static int STAR_CHANNELS[5] = {11,12,13,14,15};
static int TRACK_CHANNELS[6] = {17,18,19,20,21,22};
static int TRACK_TOP_CHANNELS[3] = {17,18,19};
static int TRACK_BOTTOM_CHANNELS[3] = {20,21,22};
static int LVE_CHANNELS[4] = {23,24,25,26};
static int HEART_CHANNELS[3] = {27,28,29};

// (name, channels, numOfChannels, phase, phaseSpeed, asc, brightness, maxBrightness, minBrightness, timer)
Channel_group WE("WE", WE_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group DO("DO", DO_CHANNELS, 2, 0, 0, true, off, on, off, millis());
Channel_group THIS("THIS", THIS_CHANNELS, 2, 0, 0, true, off, on, off, millis());
Channel_group FOR("FOR", FOR_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group LOVE("LOVE", LOVE_CHANNELS, 7, 0, 0, true, off, on, off, millis());
Channel_group AND("AND", AND_CHANNELS, 1, 0, 0, true, off, on, off, millis());
Channel_group MONEY("MONEY", MONEY_CHANNELS, 5, 0, 0, true, off, on, off, millis());

Channel_group STAR("STAR", STAR_CHANNELS, 5, 0, 0, true, off, on, off, millis());
Channel_group TRACK("TRACK", TRACK_CHANNELS, 6, 0, 0, true, off, on, off, millis());
Channel_group TRACK_TOP("TRACK_TOP", TRACK_TOP_CHANNELS, 3, 0, 0, true, off, on, off, millis());
Channel_group TRACK_BOTTOM("TRACK_BOTTOM", TRACK_BOTTOM_CHANNELS, 3, 0, 0, true, off, on, off, millis());
Channel_group LVE("LVE", LVE_CHANNELS, 4, 0, 0, true, off, on, off, millis());
Channel_group HEART("HEART", HEART_CHANNELS, 3, 0, 0, true, off, on, off, millis());

#endif
