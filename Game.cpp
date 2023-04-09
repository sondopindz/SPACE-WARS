#include "Game.h"

Game::Game()
{
    window = NULL;
    renderer = NULL;
}

Game::~Game()
{

}

bool Game::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return false;
    }
    window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();
    return true;
}

void Game::Clean()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Run()
{
    Plane plane_;
    vector<Enemy*> Enemy_List;
    vector<Bullet*> Bullet_List;
    Entity GameOverUI;
    Entity WinGame;
    Button PlayButton;
    Button HelpButton;
    Button ExitButton;
    Button BackButton;
    Button RestartButton;
    Button game_menu;
    Button game_help;
    Button game_pause;
    Text currentscore;
    Text numberofcurrentscore;
    Text highscore;
    Text numberofhighscore;
    Text Lives;
    Text Wave;
    Text Paused;
    Text Rating;
    Text life;
    TTF_Font* font = TTF_OpenFont("fonts//VCR_OSD_MONO_1.001.ttf", 25);

    //Load Texture
    SDL_Texture* texture_bg = IMG_LoadTexture(renderer, "img/background.png");
    GameOverUI.LoadTexture("img//GameOver.png", renderer);
    WinGame.LoadTexture("img/WinGame.png", renderer);
    game_menu.LoadTexture("img//menu.png", renderer);
    game_help.LoadTexture("img//help.png", renderer);
    game_pause.LoadTexture("img//Pause.png", renderer);
    game_menu.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_help.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_pause.SetWidthHeight(800, 200);
    GameOverUI.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
    WinGame.SetWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);

    PlayButton.SetWidthHeight(106, 42);
    HelpButton.SetWidthHeight(106, 42);
    ExitButton.SetWidthHeight(106, 42);
    BackButton.SetWidthHeight(106, 42);
    RestartButton.SetWidthHeight(190, 42);

    //Init Sounds
    Mix_Chunk* plane_shoot = Mix_LoadWAV("musics/ES_Gunshot Shotgun 162 - SFX Producer (1).wav");
    Mix_Chunk* explo = Mix_LoadWAV("musics/mixkit-arcade-game-explosion-2759.wav");
    Mix_Chunk* Menu = Mix_LoadWAV("musics/Menu.wav");
    Mix_Chunk* BGM = Mix_LoadWAV("musics//bgm.wav");
    Mix_Chunk* hit = Mix_LoadWAV("musics/mixkit-arcade-space-shooter-dead-notification-272.wav");
    Mix_Chunk* game_over = Mix_LoadWAV("musics/game_over.wav");
    Mix_Chunk* win_game = Mix_LoadWAV("musics/success-fanfare-trumpets-6185.wav");

    Mix_VolumeChunk(plane_shoot, MIX_MAX_VOLUME/7);
    Mix_VolumeChunk(explo, MIX_MAX_VOLUME/3);
    Mix_VolumeChunk(Menu, MIX_MAX_VOLUME/4);
    Mix_VolumeChunk(BGM, MIX_MAX_VOLUME/4);
    Mix_VolumeChunk(hit, MIX_MAX_VOLUME/4);
    Mix_VolumeChunk(game_over, MIX_MAX_VOLUME/4);
    Mix_VolumeChunk(win_game, MIX_MAX_VOLUME/2);

    currentscore.SetColor(Text::REDCOLOR);
    numberofcurrentscore.SetColor(Text::WHITECOLOR);
    numberofhighscore.SetColor(Text::WHITECOLOR);
    highscore.SetColor(Text::REDCOLOR);
    Lives.SetColor(Text::REDCOLOR);
    Paused.SetColor(Text::WHITECOLOR);
    Wave.SetColor(Text::WHITECOLOR);
    Rating.SetColor(Text::REDCOLOR);
    life.SetColor(Text::WHITECOLOR);

    string str_high_score = GetHighScoreFromFile("high_score.txt");
    string str_highscore = "HI-SCORE";
    string str_currentscore = "SCORE";
    string str_lives = "HEALTH";
    string str_paused = "PAUSED";

    Lives.Set_Text(str_lives);
    Lives.LoadFromRenderText(font, renderer);

    currentscore.Set_Text(str_currentscore);
    currentscore.LoadFromRenderText(font, renderer);

    highscore.Set_Text(str_highscore);
    highscore.LoadFromRenderText(font, renderer);

    Paused.Set_Text(str_paused);
    Paused.LoadFromRenderText(font, renderer);

    bool play = false;
    bool menu = true;
    bool help = false;
    bool QuitMenu = false;
    SDL_Event e;

    while(!QuitMenu)
    {
        if(!Mix_Playing(1))
        {
            Mix_PlayChannel(1, Menu, -1);
        }
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT)
        {
            QuitMenu = true;
        }
        if(menu)
        {
            SDL_RenderClear(renderer);

            PlayButton.SetRect(SCREEN_WIDTH/2 - PlayButton.GetRect().w/2, SCREEN_HEIGHT/2 + 110);
            HelpButton.SetRect(SCREEN_WIDTH/2 - PlayButton.GetRect().w/2, SCREEN_HEIGHT/2 + 210);
            ExitButton.SetRect(SCREEN_WIDTH/2 - PlayButton.GetRect().w/2, SCREEN_HEIGHT/2 + 310);

            PlayButton.HandlePlayButton(e, renderer, menu, play, QuitMenu);
            HelpButton.HandleHelpButton(e, renderer, menu, help);
            ExitButton.HandleExitButton(e, renderer, QuitMenu);

            game_menu.Show(renderer);
            HelpButton.Show(renderer);
            PlayButton.Show(renderer);
            ExitButton.Show(renderer);
        }
        if(help)
        {
            SDL_RenderClear(renderer);

            BackButton.SetRect(30, SCREEN_HEIGHT - BackButton.GetRect().h - 30);
            PlayButton.SetRect(SCREEN_WIDTH - PlayButton.GetRect().w - 30, SCREEN_HEIGHT - BackButton.GetRect().h - 30);

            PlayButton.HandlePlayButton(e, renderer, menu, play, QuitMenu);
            BackButton.HandleBackButton(e, renderer, menu, help);

            game_help.Show(renderer);
            PlayButton.Show(renderer);
            BackButton.Show(renderer);
        }
        SDL_RenderPresent(renderer);

        PlayButton.Destroy();
        HelpButton.Destroy();
        BackButton.Destroy();
        ExitButton.Destroy();
        plane_.Destroy();
    }

    Mix_HaltChannel(1);
    plane_.LoadTexture("img/plane1.png", renderer);
    //SDL_Texture* bullet_text = IMG_LoadTexture(renderer, "img/laser.png");
    int wave = 0;
    long current_score = 0;
    int plane_type = 1;

    bool paused = false;
    bool GameOver = false;
    bool Win = false;
    int check = 0;
    Uint32 frameStart;
    Uint32 frameTime;

    while(play)
    {
        if(!Mix_Playing(2))
        {
            Mix_PlayChannel(2, BGM, -1);
        }
        if(!GameOver && !Win)
        {
            if(paused)
            {
                SDL_PollEvent(&e);
                if(e.type == SDL_QUIT)
                {
                    play = false;
                }
                if(e.type == SDL_KEYDOWN)
                {
                    if(e.key.keysym.sym == SDLK_p)
                    {
                        paused = false;
                    }
                    if(e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        play = false;
                    }
                }
                SDL_RenderClear(renderer);
                game_pause.SetRect(SCREEN_WIDTH/2 - game_pause.GetRect().w/2, SCREEN_HEIGHT/3 - game_pause.GetRect().h);
                game_pause.Show(renderer);
                SDL_RenderPresent(renderer);
            }
            else if(!paused)
            {
                frameStart = SDL_GetTicks();
                SDL_PollEvent(&e);
                if (e.type == SDL_QUIT)
                {
                    play = false;
                    break;
                }
                if(e.type == SDL_KEYDOWN)
                {
                    if(e.key.keysym.sym == SDLK_p)
                    {
                        paused = true;
                    }
                    if(e.key.keysym.sym == SDLK_ESCAPE)
                    {
                        play = false;
                    }
                }
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture_bg, NULL, NULL);

                //Implement Plane
                plane_.HandleInputAction(e, renderer, plane_shoot, plane_type);
                plane_.Show(renderer);
                plane_.MakeBullet(renderer);

                //Implement Enemy
                GenerateEnemy(Enemy_List, renderer, wave, plane_);
                Collision(Enemy_List, Bullet_List, plane_, renderer, explo, GameOver, current_score, hit, game_over);

                UpdateHighScore("high_score.txt", current_score, str_high_score);
                highscore.RenderText(renderer, SCREEN_WIDTH/2 - 50, 10);
                currentscore.RenderText(renderer, 10, 10);
                Lives.RenderText(renderer, SCREEN_WIDTH - 120, 10);

                numberofcurrentscore.Set_Text(number_to_string(current_score));
                numberofcurrentscore.LoadFromRenderText(font, renderer);
                numberofcurrentscore.RenderText(renderer, 10, 35);

                numberofhighscore.Set_Text(str_high_score);
                numberofhighscore.LoadFromRenderText(font, renderer);
                numberofhighscore.RenderText(renderer, SCREEN_WIDTH/2 - 40, 35);

                life.Set_Text(number_to_string1(plane_.get_life()));
                life.LoadFromRenderText(font, renderer);
                life.RenderText(renderer, SCREEN_WIDTH - 85, 30);

                SDL_RenderPresent(renderer);

                frameTime = SDL_GetTicks() - frameStart;
                if (frameTime < DELAY_TIME)
                {
                    SDL_Delay(DELAY_TIME - frameTime);
                }

            }
        }
        else if(GameOver && !Win)
        {
            SDL_PollEvent(&e);
            if(e.type == SDL_QUIT)
            {
                play = false;
            }
            Mix_HaltChannel(2);

            RestartButton.HandleRestartButton(e, renderer, Enemy_List, plane_, Bullet_List, wave, current_score, GameOver, Win, check);
            ExitButton.HandleExitButton(e, renderer, play);
            SDL_RenderClear(renderer);
            GameOverUI.Show(renderer);

            RestartButton.SetRect(30, SCREEN_HEIGHT - RestartButton.GetRect().h - 30);
            RestartButton.Show(renderer);
            ExitButton.SetRect(SCREEN_WIDTH - ExitButton.GetRect().w - 30, SCREEN_HEIGHT - ExitButton.GetRect().h - 30);
            ExitButton.Show(renderer);

            numberofcurrentscore.Set_Text(number_to_string(current_score));
            numberofcurrentscore.LoadFromRenderText(font, renderer);
            numberofcurrentscore.RenderText(renderer, SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 );

            Wave.Set_Text(number_to_string1(wave));
            Wave.LoadFromRenderText(font, renderer);
            Wave.RenderText(renderer, SCREEN_WIDTH/2 - 10,SCREEN_HEIGHT/2 - 15 + 100);

            Rating.Set_Text(RatingBaseOnScore(current_score));
            Rating.LoadFromRenderText(font, renderer);
            Rating.RenderText(renderer, SCREEN_WIDTH/2 - 10, SCREEN_HEIGHT/2 - 15 + 190);

            SDL_RenderPresent(renderer);
        }
        if(wave == 9)
        {
            Win = true;
            SDL_PollEvent(&e);
            if(e.type == SDL_QUIT)
            {
                play = false;
            }
            Mix_HaltChannel(2);
            if(check == 0)
            {
                Mix_PlayChannel(7, win_game, 0);
                check = 1;
            }

            RestartButton.HandleRestartButton(e, renderer, Enemy_List, plane_, Bullet_List, wave, current_score, GameOver, Win, check);
            ExitButton.HandleExitButton(e, renderer, play);
            SDL_RenderClear(renderer);
            WinGame.Show(renderer);

            RestartButton.SetRect(30, SCREEN_HEIGHT - RestartButton.GetRect().h - 30);
            RestartButton.Show(renderer);
            ExitButton.SetRect(SCREEN_WIDTH - ExitButton.GetRect().w - 30, SCREEN_HEIGHT - ExitButton.GetRect().h - 30);
            ExitButton.Show(renderer);

            numberofcurrentscore.Set_Text(number_to_string(current_score));
            numberofcurrentscore.LoadFromRenderText(font, renderer);
            numberofcurrentscore.RenderText(renderer, SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 );

            Wave.Set_Text(number_to_string1(wave - 1));
            Wave.LoadFromRenderText(font, renderer);
            Wave.RenderText(renderer, SCREEN_WIDTH/2 - 10,SCREEN_HEIGHT/2 - 15 + 100);

            Rating.Set_Text(RatingBaseOnScore(current_score));
            Rating.LoadFromRenderText(font, renderer);
            Rating.RenderText(renderer, SCREEN_WIDTH/2 - 10, SCREEN_HEIGHT/2 - 15 + 190);

            SDL_RenderPresent(renderer);
        }
    }

    for (int i = 0; i < int(Bullet_List.size()); i++)
    {
        Bullet* bullet = Bullet_List[i];
        if (bullet != NULL)
        {
            delete bullet;
            bullet = NULL;
        }
    }
    Bullet_List.clear();

    for (int j = 0; j < int(Enemy_List.size()); j++)
    {
        Enemy* enemy = Enemy_List[j];
        if (enemy != NULL)
        {
            delete enemy;
            enemy = NULL;
        }
    }
    Enemy_List.clear();

    Mix_FreeChunk(plane_shoot);
    plane_shoot = NULL;
    Mix_FreeChunk(explo);
    explo = NULL;
    Mix_FreeChunk(Menu);
    Menu = NULL;
    Mix_FreeChunk(BGM);
    BGM = NULL;
    Mix_FreeChunk(game_over);
    game_over = NULL;
    Mix_FreeChunk(win_game);
    win_game = NULL;

    GameOverUI.Destroy();

    Clean();
    SDL_Quit();
}

