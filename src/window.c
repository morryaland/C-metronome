/**********************************************\
*                                              *
* AUTHOR: Muly                                 *
*                                              *
* CREATE: 2024.02.24                           *
*                                              *
* FOR:    Mishander                            *
*                                              *
* ABOUT: cross-platform metronome written in C *
*                                              *
\**********************************************/

#include "include/window.h"

WINDOW MAIN_WINDOW;

void window_init( WINDOW *win, uint32_t w, uint32_t h, char *title )
{
  SDL_Init(SDL_INIT_VIDEO);
  win->win = SDL_CreateWindow(title, 0, 0, w, h, 0);
  win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED);
  /* button event */
}

void window_update( WINDOW *w )
{
  SDL_SetRenderDrawColor(w->ren, 96, 128, 255, 255);
  SDL_RenderClear(w->ren);
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
      case SDL_MOUSEMOTION:
        for (int i = 0; i < BUTTONLEN; i++) {
          button_event(&(w->b[i]), &(w->eve));
        }
        break;
      default:
        break;
    }
  }
}
