#ifndef BUTTON_H
#define BUTTON_H

#include "Entity.h"
#include "Common_Function.h"
#include "Enemy.h"
#include "Plane.h"
#include "Bullet.h"

class Button : public Entity
{
    public:
        Button();
        ~Button();

        bool IsInside(SDL_Event &event);
        void HandlePlayButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &play, bool &QuitMenu);
        void HandleHelpButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &help);
        void HandleExitButton(SDL_Event &event, SDL_Renderer* renderer, bool &QuitMenu);
        void HandleBackButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &help);
        void HandleRestartButton(SDL_Event &event, SDL_Renderer* renderer, vector<Enemy*> &Enemy_List, Plane &plane_, vector<Bullet*> &Bullet_List, int &wave, long &current_score, bool &GameOver, bool &Win, int &check);

};

#endif

