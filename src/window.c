/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.02.24                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#include "include/window.h"

#define LOGING

_APP APP;
WINDOW *active_window;

void window_init( WINDOW **win, char *title, size_t blen )
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetWindowTitle(APP.win, title);
  if (*win != NULL)
    return;
  *win = malloc(sizeof(WINDOW));
  (**win).blen = blen;
  (**win).b = malloc(blen * sizeof(BUTTON));
}

void button_draw( WINDOW *w, BUTTON *b )
{
  if (b->over) {
    SDL_SetRenderDrawColor(APP.ren, 20, 20, 20, 255);
    SDL_RenderFillRect(APP.ren, &(b->rec));
  }
  SDL_SetRenderDrawColor(APP.ren, 255, 255, 255, 255);
  SDL_RenderDrawRect(APP.ren, &(b->rec));
  SDL_SetRenderDrawColor(APP.ren, 100, 255, 100, 255);
  SDL_Rect smallrec = {b->rec.x+2,b->rec.y+2,b->rec.w-4,b->rec.h-4};
  SDL_RenderDrawRect(APP.ren, &smallrec);
}

void window_update( WINDOW *w )
{
  SDL_SetRenderDrawColor(APP.ren, 0, 0, 0, 255);
  SDL_RenderClear(APP.ren);
  for (int i = 0; i < w->blen; i++) {
    button_draw(w, (w->b + i));
  }
  SDL_RenderPresent(APP.ren);
}

void window_event( WINDOW *w )
{
  while (SDL_PollEvent(&(w->eve)))
  {
    switch (w->eve.type)
    {
      case SDL_QUIT:
        exit(0);
        break;
      default:
        break;
    }
    if ( w->eve.type == SDL_MOUSEMOTION || w->eve.type == SDL_MOUSEBUTTONDOWN) {
      for (int i = 0; i < w->blen; i++) {
        button_event(w->b + i, &(w->eve));
      }
    }
  }
}
