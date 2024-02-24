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

#include <stdlib.h>
#include <raylib.h>

#ifndef uint
#define uint unsigned int
#endif

typedef struct {
  uint WIDTH;
  uint HEIGHT;
} RESOLUTION;

#define SCREEN_WIDTH  MAIN_SCREEN.WIDTH
#define SCREEN_HEIGHT MAIN_SCREEN.HEIGHT

extern static RESOLUTION MAIN_SCREEN;

#define X400_200 init_resolution(400, 200)
#define X600_400 init_resolution(600, 400)
#define X800_600 init_resolution(800, 600)

RESOLUTION init_resolution( uint, uint );

#endif
