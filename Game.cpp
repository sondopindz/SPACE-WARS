#include "Game.h"


Game::Game() {
    window = NULL;
    renderer = NULL;
}

Game::~Game() {

}

bool Game::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_EVERYTHING) == GA_FAILED)
    {
        return false;
    }
    window = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH , SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (!window)
    {
        std::cout << "Error creating window:" << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void Game::Clean()
{
    //SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::Run()
{
    Plane plane_;
    vector<Enemy*> Enemy_list;
    vector<Bullet*> Bullet_list;
    int wave = 0;

    SDL_Texture* texture_bg = IMG_LoadTexture(renderer,"loadImage/back2.png");
    plane_.LoadTexture("loadImage/plane1.png",renderer);

    SDL_Event e;
    Uint32 frameStart;
    Uint32 frameTime;

    bool quit = false;

    while (!quit)
    {
        frameStart = SDL_GetTicks();
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
        {
            quit = true;
            break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture_bg,NULL,NULL);
        //Implement Plane
        plane_.HandleInputAction(e,renderer);
        plane_.Show(renderer);
        plane_.MakeBullet(renderer);
        //Implement Enemy
        GenerateEnemy(Enemy_list,renderer,wave);
        Collision(Enemy_list,Bullet_list,plane_,renderer,quit);
        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            SDL_Delay(DELAY_TIME - frameTime);
        }
    }


    for (int i = 0; i < int(Bullet_list.size()); i++)
    {
        Bullet* bullet = Bullet_list[i];
        if (bullet != NULL)
        {
            delete bullet;
            bullet = NULL;
        }
    }
    Bullet_list.clear();

    for (int j = 0; j < int(Enemy_list.size()); j++)
    {
        Enemy* enemy = Enemy_list[j];
        if (enemy != NULL)
        {
            delete enemy;
            enemy = NULL;
        }
    }
    Enemy_list.clear();

    Clean();

    SDL_Quit();
}

