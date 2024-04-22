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

#include <string.h>

#include "include/window.h"

SCREEN MAIN_SCREEN;

RESOLUTION init_resolution( uint w, uint h ) {
  RESOLUTION resolution;
  resolution.width  = w;
  resolution.height = h;
  return resolution; 
}

EXIT_CODE init_screen( SCREEN *screen, RESOLUTION resolution, char *title )
{
  screen->resolution = resolution;
  strcpy(screen->title, title);
  /* code */
  return SUCCESS;
}

EXIT_CODE screen_resize( SCREEN *screen, RESOLUTION resolution )
{
  screen->resolution = resolution;
  screen->resize = true;
  return SUCCESS;
}

void window_event( SCREEN *screen )
{
  /* code */
}
