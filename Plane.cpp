#include "Plane.h"
#include <bits/stdc++.h>
using namespace std;

Plane::Plane()
{
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = WIDTH_PLANE;
  rect_.h = HEIGHT_PLANE;
}

Plane::~Plane()
{

}

const Uint8* state = SDL_GetKeyboardState(NULL);

void Plane::HandleInputAction(SDL_Event &events,SDL_Texture* &texture_plane,SDL_Renderer* renderer,SDL_Texture* &bullet)
{
    if(state[SDL_SCANCODE_1])
    {
        texture_plane = IMG_LoadTexture(renderer,"loadImage/plane1.png");
        bullet = IMG_LoadTexture(renderer,"loadImage/laser.png");
    }
    if(state[SDL_SCANCODE_2])
    {
        texture_plane = IMG_LoadTexture(renderer,"loadImage/plane2.png");
        bullet = IMG_LoadTexture(renderer,"loadImage/bullet_plane2.png");
    }
    if(state[SDL_SCANCODE_3])
    {
        texture_plane = IMG_LoadTexture(renderer,"loadImage/plane3.png");
        bullet = IMG_LoadTexture(renderer,"loadImage/bullet_plane3.png");
    }
    if(state[SDL_SCANCODE_UP]||state[SDL_SCANCODE_W])
    {
      rect_.y = max(0, rect_.y - SPEED_PLANE);
    }
    if (state[SDL_SCANCODE_DOWN] ||state[SDL_SCANCODE_S])
    {
        rect_.y = min(SCREEN_HEIGHT - HEIGHT_PLANE, rect_.y + SPEED_PLANE);
    }

    if (state[SDL_SCANCODE_RIGHT] ||state[SDL_SCANCODE_D])
    {
      rect_.x = min(SCREEN_WIDTH - WIDTH_PLANE, rect_.x + SPEED_PLANE);
    }
    if (state[SDL_SCANCODE_LEFT] ||state[SDL_SCANCODE_A])
    {
      rect_.x = max(0, rect_.x - SPEED_PLANE);
    }
    if(events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT)
        {
          Bullet* p_bullet = new Bullet();
          p_bullet->SetWidthHeight(WIDTH_BULLET_PLANE, HEIGHT_BULLET_PLANE);
          p_bullet->SetRect(this->rect_.x + this->rect_.w /2 - 2, this->rect_.y - this->rect_.h*0.2);
          p_bullet->set_is_move(true);
          p_bullet_list_.push_back(p_bullet);
        }
    }
}

void Plane::MakeBullet(SDL_Renderer* renderer, SDL_Texture* bullet)
{
  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    Bullet* p_bullet_ = p_bullet_list_[i];
    if (p_bullet_ != NULL)
    {
      if (p_bullet_->get_is_move())
      {
        p_bullet_->SetTexture(bullet);
        p_bullet_->Show(renderer);
        p_bullet_->MoveSin();
      }
      else
      {
        if (p_bullet_ != NULL)
        {
          p_bullet_list_.erase(p_bullet_list_.begin() + i);
          i--;
          delete p_bullet_;
          p_bullet_ = NULL;
        }
      }
    }
  }
}

void Plane::RemoveBullet(const int& idx)
{
  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    if (idx < p_bullet_list_.size())
   {
      Bullet* p_bullet = p_bullet_list_[idx];
      p_bullet_list_.erase(p_bullet_list_.begin() + idx);

      if (p_bullet != NULL)
      {
        delete p_bullet;
        p_bullet = NULL;
      }
    }
  }
}

