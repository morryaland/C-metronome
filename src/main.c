/*********************
*                    *
* AUTHOR: Muly22     *
*                    *
* CREATE: 2024.02.24 *
*                    *
* FOR:    Mishander  *
*                    *
*********************/

#include <stdlib.h>
#include <stdio.h>
//
#include "window.h"

int main () {
  /* init window */
  MAIN_SCREEN = X400_200;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "metronome");  
  SetTargetFPS(60);
  
  /* window loop */
  while (!WindowShouldClose()) {
    
    /* events */
    if (IsKeyPressed(KEY_ENTER)) {
      MAIN_SCREEN = X800_600;
    }
    if (windres) {
      SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
      windres = 0;
    }
    
    /* draw */
    BeginDrawing();
      ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow(); 
  return 0;
}
