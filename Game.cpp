#include "Game.h"

Game::Game() {
    window = NULL;
    renderer = NULL;
}

Game::~Game() {

}

bool Game::Init() {
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_EVERYTHING) == GA_FAILED)
    {
        return false;
    }
    // Create window
    window = SDL_CreateWindow("GAME",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH , SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (!window) {
        std::cout << "Error creating window:" << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize resources
    //SDL_Surface* surface = IMG_Load("test.png");
    // = SDL_CreateTextureFromSurface(renderer, surface);
    //SDL_FreeSurface(surface);


    return true;
}

void Game::Clean() {
    // Clean resources
    SDL_DestroyTexture(texture);

    // Clean renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::Run() {

    // Main loop
    Plane plane_;
    plane_.SetRect(POS_X_START_PLANE,POS_Y_START_PLANE);
    SDL_Texture* texture_bg = IMG_LoadTexture(renderer,"loadImage/Background.png");
    SDL_Texture* texture_plane = IMG_LoadTexture(renderer,"loadImage/plane1.png");
    SDL_Texture* texture_bullet = IMG_LoadTexture(renderer,"loadImage/laser.png");
    SDL_Event e;



      //Make Enemy
  /*Enemy* p_threats = new Enemy[NUM_THREATS];

  for (int t = 0; t < NUM_THREATS; t++)
  {
    Enemy* p_threat = (p_threats + t);
    if (p_threat)
    {
      ret = p_threat->LoadImg(g_name_threats);
      if (ret == false)
      {
        delete [] p_threats;
        Clean();
        SDL_Quit();
        return 0;
      }

      int rand_y = SDLCommonFunc::MakeRandValue();
      p_threat->SetRect(SCREEN_WIDTH + t*VAL_OFFSET_START_POST_THREATS, rand_y);
      p_threat->set_x_val(SPEED_THREAT);

      BulletObject* p_bullet = new BulletObject();
      p_threat->InitBullet(p_bullet);
    }
  }*/


  	Uint32 frameStart;
	Uint32 frameTime;

    bool quit = false;
    while (!quit)
        {
        frameStart = SDL_GetTicks();
         //Handler events
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        plane_.HandleInputAction(e,texture_plane,renderer,texture_bullet);
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture_bg,NULL,NULL);
        plane_.Show(texture_plane,renderer);
        plane_.MakeBullet(renderer,texture_bullet);
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



