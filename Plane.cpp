#include "Plane.h"

Plane::Plane()
{
    rect_.x = SCREEN_WIDTH/2;
    rect_.y = SCREEN_HEIGHT - HEIGHT_PLANE;
    rect_.w = WIDTH_PLANE;
    rect_.h = HEIGHT_PLANE;
    life = 3;
}

Plane::~Plane()
{
    Destroy();
}

const Uint8* state = SDL_GetKeyboardState(NULL);

void Plane::HandleInputAction(SDL_Event &events, SDL_Renderer* renderer, Mix_Chunk* shoot)
{
    if(state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
    {
      rect_.y = max(0, rect_.y - SPEED_PLANE);
    }
    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
    {
        rect_.y = min(SCREEN_HEIGHT - HEIGHT_PLANE, rect_.y + SPEED_PLANE);
    }

    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
    {
      rect_.x = min(SCREEN_WIDTH - WIDTH_PLANE, rect_.x + SPEED_PLANE);
    }
    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
    {
      rect_.x = max(0, rect_.x - SPEED_PLANE);
    }
    if(events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            Bullet* bullet = new Bullet();
            if(bullet != NULL)
            {
                bullet->LoadTexture("img/laser.png", renderer);
                Mix_PlayChannel(3, shoot, 0);
                bullet->set_angle(-90);
                bullet->set_speed(SPEED_BULLET_MAIN);
                bullet->SetWidthHeight(WIDTH_BULLET_PLANE, HEIGHT_BULLET_PLANE);
                bullet->set_pos(rect_.x + rect_.w /2 - 2, rect_.y - rect_.h*0.2);
                bullet->set_is_move(true);
                bullet_list.push_back(bullet);
            }
        }
    }
}

void Plane::MakeBullet(SDL_Renderer* renderer)
{
    for (int i = 0; i < bullet_list.size(); i++)
    {
        Bullet* bullet = bullet_list[i];
        if (bullet != NULL)
        {
            if (bullet->get_is_move())
            {
                bullet->Show(renderer);
                bullet->HandleMove();
            }
            else
            {
                bullet_list.erase(bullet_list.begin() + i);
                if(bullet != NULL)
                {
                    delete bullet;
                    bullet = NULL;
                }
            }
        }
    }
}

void Plane::RemoveBullet(const int &idx)
{
    if (idx < bullet_list.size() && bullet_list.size() > 0)
    {
        Bullet* bullet = bullet_list[idx];
        bullet_list.erase(bullet_list.begin() + idx);
        if (bullet != NULL)
        {
            delete bullet;
            bullet = NULL;
        }
    }
}

