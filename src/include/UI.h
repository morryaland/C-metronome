/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.05.06                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#ifndef UI_H
#define UI_H

#include "../../lib/include/SDL2/SDL.h"

typedef struct {
} TITLE;

typedef struct {
  TITLE t;
  uint8_t press;
  uint8_t over;
  SDL_Rect rec;
} BUTTON;

void button_event( BUTTON *b, SDL_Event *eve );

#endif
