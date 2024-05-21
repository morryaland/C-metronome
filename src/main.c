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
#include "include/log.h"


int w_main(), setting();

int w_main()
{
  active_window = APP.main;
  if (!active_window) {
    window_init(&active_window, "metronome");
    TITLE t = {};
    if (button_add(active_window, t, 50, 50, 50, 50, setting) < 0) {
      error(DEFAULT_LOG_FILE, "button_add setting\n");
      return -1;
    }
  }
  return 0;
}

int setting()
{
  active_window = APP.settings;
  if (!active_window) {
    window_init(&active_window, "settings");
    TITLE back = {"back", NULL};
    if (button_add(active_window, back, 50, 50, 100, 50, w_main ) < 0) {
      error(DEFAULT_LOG_FILE, "button_add main\n");
      return -1;
    }
  }
  return 0;
}

int main()
{
  /* init window */
  SDL_Init(SDL_INIT_VIDEO);
  APP.win = SDL_CreateWindow("metronome", 0, 0, 400, 200, 0);
  if (!APP.win) {
    error(DEFAULT_LOG_FILE, "win == NULL\n");
    return -1;
  }
  APP.ren = SDL_CreateRenderer(APP.win, -1, SDL_RENDERER_ACCELERATED);
  if (!APP.ren) {
    error(DEFAULT_LOG_FILE, "ren == NULL\n");
    return -1;
  }
  w_main();
  /* window loop */
  for (;;) {
    if (window_update(active_window) < 0) {
      error(DEFAULT_LOG_FILE, "window_update\n");
      return -1;
    }
    if (window_event(active_window) < 0) {
      error(DEFAULT_LOG_FILE, "window_event\n");
      return -1;
    }
    SDL_Delay(41);
  }
  return 0;
}
