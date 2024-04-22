/**********************************************\
*                                              *
* AUTHOR: Muly22                               *
*                                              *
* CREATE: 2024.02.24                           *
*                                              *
* FOR:    Mishander                            *
*                                              *
* ABOUT: cross-platform metronome written in C *
*                                              *
\**********************************************/

#include <stdlib.h>
#include <stdio.h>

#include "include/window.h"

int main () {
  /* init window */
  init_screen(&MAIN_SCREEN, X400_200, "lol");
  
  /* window loop */
  while (MAIN_SCREEN.open) {
    window_event(&MAIN_SCREEN);
    
  }
  return 0;
}
