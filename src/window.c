/*********************
*                    *
* AUTHOR: Muly22     *
*                    *
* CREATE: 2024.02.24 *
*                    *
* FOR:    Mishander  *
*                    *
*********************/

#include "window.h"

static RESOLUTION MAIN_SCREEN;

RESOLUTION init_resolution( uint w, uint h ) {
  RESOLUTION resolution;
  resolution.WIDTH  = w;
  resolution.HEIGHT = h;
  return resolution; 
}
