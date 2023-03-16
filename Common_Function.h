
#ifndef COMMON_FUNCTION
#define COMMON_FUNCTION

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
using namespace std;

#define GA_FAILED -1
#define GA_SUCCESS 0


//Screen
const int SCREEN_WIDTH      = 500;
const int SCREEN_HEIGHT     = 750;
const int FPS = 100;
const int DELAY_TIME = 1000 / FPS;

//plane
const int WIDTH_PLANE = 25;
const int HEIGHT_PLANE = 40;
const int SPEED_PLANE = 4;
const int POS_X_START_PLANE  = SCREEN_WIDTH/2;
const int POS_Y_START_PLANE  = SCREEN_HEIGHT - HEIGHT_PLANE;
const int SPEED_BULLET_MAIN = 4;
const int WIDTH_BULLET_PLANE = 5;
const int HEIGHT_BULLET_PLANE = 8;


//Enemy
const int SPEED_BULLET_ENEMY = 2;
const int NUM_ENEMIES = 5;
const int SPEED_ENEMY = 1;


const double PI  =3.141592653589793238463;

namespace SDLCommonFunc
{
    int MakeRandValue();
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}


#endif
