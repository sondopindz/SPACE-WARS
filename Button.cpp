#include "Button.h"

Button::Button()
{
    rect_.x = rect_.y = rect_.w = rect_.h = 0;
}
Button::~Button()
{
    Destroy();
}

bool Button::IsInside(SDL_Event &event)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool inside = true;
    if (x < rect_.x || x > rect_.x + rect_.w || y < rect_.y || y > rect_.y + rect_.h)
    {
        inside = false;
    }
    return inside;
}

void Button::HandlePlayButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &play, bool &QuitMenu)
{
	if(IsInside(event))
	{
	    LoadTexture("img//PlayButton2.png", renderer);
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		    play = true;
		    QuitMenu = true;
			menu = false;
		}
	}
	else
	{
		LoadTexture("img//PlayButton.png", renderer);
	}
}

void Button::HandleHelpButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &help)
{
	if(IsInside(event))
	{
	    LoadTexture("img//HelpButton2.png", renderer);
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		    help = true;
            menu = false;
		}
	}
	else
	{
		LoadTexture("img//HelpButton.png", renderer);
	}
}

void Button::HandleExitButton(SDL_Event &event, SDL_Renderer* renderer, bool &QuitMenu)
{
    if(IsInside(event))
	{
	    LoadTexture("img//ExitButton2.png", renderer);
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		    QuitMenu = !QuitMenu;
		}
	}
	else
	{
		LoadTexture("img//ExitButton.png", renderer);
	}
}

void Button::HandleBackButton(SDL_Event &event, SDL_Renderer* renderer, bool &menu, bool &help)
{
    if(IsInside(event))
	{
	    LoadTexture("img//BackButton2.png", renderer);
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		    menu = true;
		    help = false;
		}
	}
	else
	{
		LoadTexture("img//BackButton.png", renderer);
	}
}

void Button::HandleRestartButton(SDL_Event &event, SDL_Renderer* renderer, vector<Enemy*> &Enemy_List, Plane &plane_, vector<Bullet*> &Bullet_List, int &wave, long &current_score, bool &GameOver, bool &Win, int &check)
{
    if(IsInside(event))
	{
	    LoadTexture("img//RestartButton2.png", renderer);
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		    GameOver = false;
		    check = 0;
		    Win = false;
            current_score = 0;
            wave = 0;
            Enemy_List.erase(Enemy_List.begin(), Enemy_List.begin() + Enemy_List.size());
            Bullet_List.erase(Bullet_List.begin(), Bullet_List.begin() + Bullet_List.size());
            plane_.SetRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
            plane_.set_life(3);
		}
	}
	else
	{
		LoadTexture("img//RestartButton.png", renderer);
	}
}

