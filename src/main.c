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

int main ()
{
  /* init window */
  window_init(&MAIN_WINDOW, 400, 200, "lol");
  SDL_Color clr = {255, 255, 255, 255};
  TITLE t = {};
  button_init(MAIN_WINDOW.b, t, 50, 50, 50, 50, clr, NULL );
  /* window loop */
  for (;;) {
    window_event(&MAIN_WINDOW);
    window_update(&MAIN_WINDOW);
    //code
  }
  return 0;
}
