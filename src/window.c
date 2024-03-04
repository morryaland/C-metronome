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

RESOLUTION init_resolution( uint w, uint h ) {
  RESOLUTION resolution;
  resolution.WIDTH  = w;
  resolution.HEIGHT = h;
  windres = 1;
  return resolution; 
}

/* events */

int windres = 0;
