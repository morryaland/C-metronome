/*********************
*                    *
* AUTHOR: Muly22     *
*                    *
* CREATE: 2024.02.24 *
*                    *
* FOR:    Mishander  *
*                    *
*********************/

#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <stdlib.h>
//
#include "exit_code.h"

#ifndef uint
#define uint unsigned int
#endif

#ifndef BYTE
#define BYTE 0xFF
#endif

typedef struct {
  uint width;
  uint height;
} RESOLUTION;

typedef struct {
  RESOLUTION resolution;
  char title[BYTE];
  /* EVENTS */
  bool resize;
  bool open;
} SCREEN;

#define SCREEN_WIDTH  MAIN_SCREEN.resolution.width
#define SCREEN_HEIGHT MAIN_SCREEN.resolution.height

extern SCREEN MAIN_SCREEN;

#define X800_600 init_resolution( 800, 600 )
#define X600_400 init_resolution( 600, 400 )
#define X400_200 init_resolution( 400, 200 )

RESOLUTION init_resolution( uint, uint );

EXIT_CODE init_screen( SCREEN *screen, RESOLUTION resolution, char *title );

void window_event( SCREEN *screen );

#endif
