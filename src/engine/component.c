#include "stdint.h"
#include "stdlib.h"

#include "engine.h"




void initObjs(Objs* o, int sz){
  int sz_ = (sz < 128)? 256 : (sz * 2);

  o-> xs  = (float     *)malloc(sz_ * sizeof(float));
  o-> ys  = (float     *)malloc(sz_ * sizeof(float));
  o->dxs  = (float     *)malloc(sz_ * sizeof(float));
  o->dys  = (float     *)malloc(sz_ * sizeof(float));

  o->types= (Type      *)malloc(sz_ * sizeof(Type));
  o->props= (Properties*)malloc(sz_ * sizeof(Properties));

  o->allocsize = sz_;
  o->fillsize  = sz;
}





FlatObj pullObj(Objs* o, int i){
  FlatObj ret;

  if((i < 0) || (i >= o->fillsize)){
    ret.x    = 0;
    ret.y    = 0;
    ret.dx   = 0;
    ret.dy   = 0;
    ret.type = ISNIL;
    return ret;
  }

  ret.x    = o->   xs[i];
  ret.y    = o->   ys[i];
  ret.dx   = o->  dxs[i];
  ret.dy   = o->  dys[i];
  ret.type = o->types[i];
  ret.prop = o->props[i];
  return ret;
}





void changeObj(Objs* o, int i, FlatObj f){

  if((i < 0) || (i >= o->fillsize)) return;

  o->xs   [i] = f.x;
  o->ys   [i] = f.y;
  o->dxs  [i] = f.dx;
  o->dys  [i] = f.dy;
  o->types[i] = f.type;
  o->props[i] = f.prop;
}





void extendObjs(Objs* o, int mul, int inc){
  float     * xs    = o->xs;
  float     * ys    = o->ys;
  float     * dxs   = o->dxs;
  float     * dys   = o->dys;
  Type      * types = o->types;
  Properties* props = o->props;

  o->allocsize = (o->allocsize * mul) + inc;

  o->xs    = (float*     )malloc(sizeof(float)      * o->allocsize);
  o->ys    = (float*     )malloc(sizeof(float)      * o->allocsize);
  o->dxs   = (float*     )malloc(sizeof(float)      * o->allocsize);
  o->dys   = (float*     )malloc(sizeof(float)      * o->allocsize);
  o->types = (Type *     )malloc(sizeof(Type )      * o->allocsize);
  o->props = (Properties*)malloc(sizeof(Properties) * o->allocsize);

  for(int i = 0; i < o->fillsize; i++){
    o->xs   [i] = xs   [i];
    o->ys   [i] = ys   [i];
    o->dxs  [i] = dxs  [i];
    o->dys  [i] = dys  [i];
    o->types[i] = types[i];
    o->props[i] = props[i];
  }

  free(xs);
  free(ys);
  free(dxs);
  free(dys);
  free(types);
  free(props);
}




int  insertObj(Objs* o, FlatObj f){
  if(o->fillsize + 1 >= o->allocsize){
    extendObjs(o, 2, 0);
  }

  int i = o->fillsize;
  o->fillsize++;
  o->xs   [i] = f.x;
  o->ys   [i] = f.y;
  o->dxs  [i] = f.dx;
  o->dys  [i] = f.dy;
  o->types[i] = f.type;
  o->props[i] = f.prop;

  return i;
}
