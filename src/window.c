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
#include "include/log.h"

_APP APP;
WINDOW *active_window;

void window_init( WINDOW **w, char *title )
{
  SDL_SetWindowTitle(APP.win, title);
  if (*w != NULL)
    return;
  *w = malloc(sizeof(WINDOW));
  (**w).blen = 0;
}

int button_draw( WINDOW *w, BUTTON *b )
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
  /*
  TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
  SDL_Color White = {255, 255, 255};
  SDL_Surface *surfaceMessage = 
              TTF_RenderText_Solid(Sans, b->t.text, White);
  SDL_Texture *texture = 
              SDL_CreateTextureFromSurface(APP.ren, surfaceMessage);
  SDL_RenderCopy(APP.ren, texture, NULL, &smallrec);
  */
  return 0;
}

int window_update( WINDOW *w )
{
  SDL_SetRenderDrawColor(APP.ren, 0, 0, 0, 255);
  SDL_RenderClear(APP.ren);
  for (int i = 0; i < w->blen; i++) {
    if (button_draw(w, (w->b + i)) < 0) {
      error(DEFAULT_LOG_FILE, "button_draw\n");
      return -1;
    }
  }
  SDL_RenderPresent(APP.ren);
  return 0;
}

int window_event( WINDOW *w )
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
      if (button_event(w) < 0) {
        error(DEFAULT_LOG_FILE, "button_event\n");
        return -1;
      }
    }
  }
  return 0;
}
