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

#include <stdlib.h>
#include <stdio.h>

#include "include/window.h"

void w_main(), setting();

void w_main()
{
  active_window = APP.main;
  window_init(&active_window, "metronome", 1);
  TITLE t = {};
  button_init(active_window->b, t, 50, 50, 50, 50, setting );
}

void setting()
{
  active_window = APP.settings;
  window_init(&active_window, "settings", 1);
  TITLE t = {};
  button_init(active_window->b, t, 50, 50, 100, 50, w_main );
}

int main()
{
  /* init window */
  APP.win = SDL_CreateWindow("metronome", 0, 0, 400, 200, 0);
  APP.ren = SDL_CreateRenderer(APP.win, -1, SDL_RENDERER_ACCELERATED);
  w_main();
  /* window loop */
  for (;;) {
    window_update(active_window);
    window_event(active_window);
    //code
  }
  return 0;
}
