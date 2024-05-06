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

#include "../../lib/include/SDL2/SDL.h"
#include "UI.h"

#define BUTTONLEN 1

typedef struct {
  SDL_Window *win;
  SDL_Renderer *ren;
  SDL_Event eve;
  BUTTON b[BUTTONLEN];
} WINDOW;

extern WINDOW MAIN_WINDOW;

void window_init( WINDOW *win, uint32_t w, uint32_t h, char *title );

void window_update( WINDOW *w );

void window_event( WINDOW *w );

#endif
