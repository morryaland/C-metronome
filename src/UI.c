/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.05.06                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#include "include/UI.h"

void button_init( BUTTON *b, TITLE t, uint16_t x,
                  uint16_t y, uint16_t w, uint16_t h,
                  SDL_Color clr, void (*act)(void) )
{
  b->t = t;
  b->clr = clr;
  b->act = act;
  b->rec.x = x; b->rec.y = y; b->rec.w = w; b->rec.h = h;
}

void button_event( BUTTON *b, SDL_Event *eve )
{
  if (eve->motion.x >= b->rec.x && eve->motion.x <= b->rec.w + b->rec.x &&
      eve->motion.y >= b->rec.y && eve->motion.y <= b->rec.h + b->rec.y) {
    if (!(b->over))
      b->over = 1;
    if (eve->button.button == SDL_BUTTON_LEFT) {
      b->press = 1;
      puts("1");
    }
  }
  else {
    if (b->over)
      b->over = 0;
  }
}
