/**********************************************\
*                                              *
* AUTHOR: Muly                                 *
*                                              *
* CREATE: 2024.05.06                           *
*                                              *
* FOR:    Mishander                            *
*                                              *
* ABOUT: cross-platform metronome written in C *
*                                              *
\**********************************************/

#include "include/UI.h"

void button_event( BUTTON *b, SDL_Event *eve )
{
  if (eve->motion.x >= b->rec.x && eve->motion.x <= b->rec.w &&
      eve->motion.y <= b->rec.h && eve->motion.y >= b->rec.y) {
    if (!(b->over))
      b->over = 1;

  }
  else {
    if (b->over)
      b->over = 0;
  }
}
