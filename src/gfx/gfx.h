#ifndef __GFX_HEADER__
#define __GFX_HEADER__

#include "SDL/SDL.h"


typedef struct{
  SDL_Surface* screen;
  SDL_Surface* tiles;
  int winH, winW;
}GFX;




GFX initGFX(int, int);








#endif
