#ifndef ANIMATION_H
#define ANIMATION_H
#include <stdint.h>
#include <Arduino.h>
#define ANIMATION_FRAME_COUNT 1
#define ANIMATION_WIDTH 128
#define ANIMATION_HEIGHT 64
#define ANIMATION_FPS 1
const uint16_t animation_delays[ANIMATION_FRAME_COUNT] = {1000};
PROGMEM const uint8_t animation_frames[ANIMATION_FRAME_COUNT][1024] = {{
  {0}
}};
#endif
