/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.02.24                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>

#include "UI.h"
#include "../../lib/include/SDL2/SDL.h"


typedef struct {
  SDL_Event eve;
  size_t blen;
  BUTTON *b;
} WINDOW;

typedef struct {
  SDL_Window *win;
  SDL_Renderer *ren;
  WINDOW *main;
  WINDOW *settings;
} _APP;

extern _APP APP;
extern WINDOW *active_window;

void window_init( WINDOW **w, char *title);

int button_draw( WINDOW *w, BUTTON *b );

int button_add( WINDOW *_w, TITLE t, uint16_t x,
                uint16_t y, uint16_t w, uint16_t h,
                int (*act)(void) );

int button_event( WINDOW *w );

int window_update( WINDOW *w );

int window_event( WINDOW *w );

#endif
