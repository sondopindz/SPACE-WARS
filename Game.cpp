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
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::Run()
{
    Plane plane_;
    plane_.SetRect(POS_X_START_PLANE,POS_Y_START_PLANE);
    SDL_Texture* texture_bg = IMG_LoadTexture(renderer,"loadImage/back2.png");
    SDL_Texture* texture_plane = IMG_LoadTexture(renderer,"loadImage/plane1.png");
    SDL_Texture* texture_bullet = IMG_LoadTexture(renderer,"loadImage/laser.png");

    SDL_Event e;
    Uint32 frameStart;
    Uint32 frameTime;

      //Make Enemy
    Enemy* p_enemies = new Enemy[NUM_ENEMIES];
    for (int t = 0; t < NUM_ENEMIES; t++)
    {
        Enemy* p_enemy = (p_enemies + t);
        if (p_enemy)
        {
            p_enemy->set_type_enemy(1);
            p_enemy->LoadTexture("loadImage/enemy.png",renderer);
            int rand_x = SDLCommonFunc::MakeRandValue();
            p_enemy->SetRect(rand_x, 50);
            Bullet* p_bullet  = new Bullet();
            p_bullet->LoadTexture("loadImage/bullet_plane3.png",renderer);
            p_enemy->InitBullet(p_bullet);
        }
    }

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
        plane_.HandleInputAction(e,texture_plane,renderer,texture_bullet);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture_bg,NULL,NULL);

        //Implement Plane
        plane_.SetTexture(texture_plane);
        plane_.Show(renderer);
        plane_.MakeBullet(renderer,texture_bullet);

        //Implement Enemy
        for (int tt = 0; tt < NUM_ENEMIES; tt++)
        {
            Enemy* p_enemy = (p_enemies + tt);
            if (p_enemy)
            {
                //p_enemy->set_type_enemy(1);
                p_enemy->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
                p_enemy->MoveEnemy();
                p_enemy->Show(renderer);
                p_enemy->MakeBullet(renderer);

                //COLLISION ENEMY BULLET -> PLANE
                bool is_col1 = false;
                std::vector<Bullet*> bullet_arr = p_enemy->GetBulletList();
                for (int am = 0; am < bullet_arr.size(); am++)
                {
                    Bullet* p_bullet = bullet_arr[am];
                    if (p_bullet)
                    {
                        is_col1 = SDLCommonFunc::CheckCollision(p_bullet->GetRect(), plane_.GetRect());
                        if (is_col1 == true)
                        {
                            p_enemy->ResetBullet(p_bullet);
                            break;
                        }
                    }
                }

                //Check collision main and threats
                bool is_col = SDLCommonFunc::CheckCollision(plane_.GetRect(), p_enemy->GetRect());
                if (is_col1 || is_col)
                {
                    delete [] p_enemies;
                    quit = true;
                    break;
                }

                //Check collision main bullet with enemy.
                std::vector<Bullet*> bullet_list = plane_.GetBulletList();
                for (int im = 0; im < bullet_list.size(); im++)
                {
                    Bullet* p_bullet = bullet_list[im];
                    if (p_bullet != NULL)
                    {
                        bool col = SDLCommonFunc::CheckCollision(p_bullet->GetRect(), p_enemy->GetRect());
                        if (col)
                        {
                            p_enemy->Reset();
                            plane_.RemoveBullet(im);
                        }
                    }
                }
            }
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
        {
            SDL_Delay(DELAY_TIME - frameTime);
        }
    }

    Clean();

    SDL_Quit();
}

