
#ifndef COMMON_FUNCTION
#define COMMON_FUNCTION

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#define GA_FAILED -1
#define GA_SUCCESS 0


//Screen
const int WIDTH_BACKGROUND  = 4800;
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_WIDTH      = 1024;
const int SCREEN_HEIGHT     = 688;
const int FPS = 120;
const int DELAY_TIME = 1000 / FPS;


//Plane
const int WIDTH_PLANE = 63;
const int HEIGHT_PLANE = 112;
const int POS_X_START_PLANE  = SCREEN_WIDTH/2;
const int POS_Y_START_PLANE  = SCREEN_HEIGHT - HEIGHT_PLANE;
const int SPEED_BULLET_MAIN = 5;


//Threats
const int SPEED_BULLET_THREATS = 10;

namespace SDLCommonFunc
{
  void Render(SDL_Texture* &texture_,SDL_Renderer* renderer_, SDL_Rect pos);

}


#endif

