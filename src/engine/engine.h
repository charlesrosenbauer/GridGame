#ifndef __ENGINE_HEADER__
#define __ENGINE_HEADER__

#include "stdint.h"





typedef enum{
  ISNIL    = 0,
  ISPLAYER = 1,
  ISROCK   = 2,
  ISMONSTER= 3 } Type;


typedef struct{
  // Placeholder for now
}PlayerObj;


typedef struct{
  // Placeholder for now, might not actually be necessary
}RockObj;


typedef struct{
  // Placeholder for now, possibly just simple AI state
  // I want to see if I can use Branch-predictor -style algos for AI.
}MonsterObj;


typedef union{
  PlayerObj  p;
  RockObj    r;
  MonsterObj m;
}Properties;


typedef struct{
  // Really just for local usage, as it's not high-performance.
  float x, y, dx, dy;
  Type type;
  Properties prop;
}FlatObj;


typedef struct{
  float* xs;
  float* ys;
  float* dxs;
  float* dys;
  Type * types;
  Properties* props;

  int allocsize, fillsize;
}Objs;



FlatObj pullObj  (Objs*, int);
void    changeObj(Objs*, int, FlatObj);
int     insertObj(Objs*, FlatObj);
void    initObjs (Objs*, int);












#endif
