#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include  "Common_Function.h"
#include "Plane.h"
#include "Entity.h"
#include "Enemy.h"
#include "EnemyArray.h"
#include "Collision.h"
#include "Button.h"
#include "Text.h"

class Game {
public:
    Game();
    ~Game();

    bool Init();
    void Run();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* texture;

    void Clean();

};

#endif // GAME_H
