
#include "Common_Function.h"


void SDLCommonFunc::Render(SDL_Texture* &texture_,SDL_Renderer* renderer_, SDL_Rect pos)
{
    SDL_RenderCopy(renderer_,texture_,NULL,&pos);
}
