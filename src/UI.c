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

#include "include/window.h"
#include "include/log.h"

int button_add( WINDOW *_w, TITLE t, uint16_t x,
                uint16_t y, uint16_t w, uint16_t h,
                int (*act)(void) )
{
  _w->b = realloc(_w->b, (_w->blen + 1) * sizeof(BUTTON));
  if (!_w->b) {
    error(DEFAULT_LOG_FILE, "window realloc == NULL\n");
    return -1;
  }
  int blen = (_w->blen)++;
  _w->b[blen].t = t;
  _w->b[blen].act = act;
  _w->b[blen].rec.x = x; _w->b[blen].rec.y = y; _w->b[blen].rec.w = w; _w->b[blen].rec.h = h;
  return 0;
}

int button_event( WINDOW *w )
{
  for (int i = 0; i < w->blen; i++) {
    if (w->eve.motion.x >= w->b[i].rec.x && w->eve.motion.x <= w->b[i].rec.w + w->b[i].rec.x &&
        w->eve.motion.y >= w->b[i].rec.y && w->eve.motion.y <= w->b[i].rec.h + w->b[i].rec.y) {
      if (!(w->b[i].over))
        w->b[i].over = 1;
      if (w->eve.button.button == SDL_BUTTON_LEFT)
        w->b[i].act();
    }
    else {
      if (w->b[i].over)
        w->b[i].over = 0;
    }
  }
  return 0;
}
