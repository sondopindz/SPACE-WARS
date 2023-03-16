
#include "Common_Function.h"


int SDLCommonFunc::MakeRandValue()
{
  int rand_x = 10 + rand()%(SCREEN_WIDTH-20);
  return rand_x;
}

bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    if(object1.x+object1.w>=object2.x && object2.x+object2.w>=object1.x
       && object1.y+object1.h>=object2.y && object2.y+object2.h>=object1.y)
    {
        return true;
    }
    return false;
}
