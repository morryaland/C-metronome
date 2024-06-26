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
  char title[255];
} TITLE;

typedef struct {
  TITLE t;
  uint8_t over;
  int (*act)( void );
  SDL_Rect rec;
} BUTTON;

#endif
