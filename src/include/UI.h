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
  void (*act)( void );
  SDL_Rect rec;
  SDL_Color clr;
} BUTTON;

void button_init( BUTTON *b, TITLE t, uint16_t x,
                  uint16_t y, uint16_t w, uint16_t h,
                  SDL_Color clr, void (*act)(void) );

void button_event( BUTTON *b, SDL_Event *eve );

#endif
