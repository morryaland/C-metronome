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

WINDOW MAIN_WINDOW;

void window_init( WINDOW *win, uint32_t w, uint32_t h, char *title )
{
  SDL_Init(SDL_INIT_VIDEO);
  win->win = SDL_CreateWindow(title, 0, 0, w, h, 0);
  win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED);
}

void window_update( WINDOW *w )
{
  SDL_SetRenderDrawColor(w->ren, 0, 0, 0, 255);
  SDL_RenderClear(w->ren);
  for (int i = 0; i < BUTTONLEN; i++) {
    if (w->b[i].over) {
    SDL_SetRenderDrawColor(w->ren, 20, 20, 20, 255);
    SDL_RenderFillRect(w->ren, &(w->b[i].rec));
    }
    SDL_SetRenderDrawColor(w->ren, w->b[i].clr.r, w->b[i].clr.g,
                           w->b[i].clr.b, w->b[i].clr.a);
    SDL_RenderDrawRect(w->ren, &(w->b[i].rec));
  }
  SDL_RenderPresent(w->ren);
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
      for (int i = 0; i < BUTTONLEN; i++) {
        button_event(&(w->b[i]), &(w->eve));
      }
    }
  }
}
