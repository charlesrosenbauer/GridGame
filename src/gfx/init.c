#include "gfx.h"




GFX initGFX(int h, int w){
  GFX ret;

  SDL_Init(SDL_INIT_EVERYTHING);

  ret.screen = SDL_SetVideoMode(w, h, 32, 0);
  //ret.tiles =

  ret.winH = h;
  ret.winW = w;

  return ret; 
}
