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

void window_init( WINDOW **win, char *title, size_t blen );

void button_draw( WINDOW *w, BUTTON *b );

void window_update( WINDOW *w );

void window_event( WINDOW *w );

#endif
