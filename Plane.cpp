

#include "Plane.h"
#include <bits/stdc++.h>
using namespace std;

Plane::Plane()
{
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = WIDTH_PLANE;
  rect_.h = HEIGHT_PLANE;
  x_val_ = 0;
  y_val_ = 0;
}

Plane::~Plane()
{

}

const Uint8* state = SDL_GetKeyboardState(NULL);

void Plane::HandleInputAction(SDL_Event &events,SDL_Texture* &texture_plane,SDL_Renderer* renderer,SDL_Texture* &bullet)
{
    if(state[SDL_SCANCODE_1])
    {
        SDL_Texture* texture_plane1 = IMG_LoadTexture(renderer,"loadImage/plane1.png");
        texture_plane = texture_plane1;
        SDL_Texture* bullet1 = IMG_LoadTexture(renderer,"loadImage/laser.png");
        bullet = bullet1;
    }
    if(state[SDL_SCANCODE_2])
    {
        SDL_Texture* texture_plane2 = IMG_LoadTexture(renderer,"loadImage/plane2.png");
        texture_plane = texture_plane2;
        SDL_Texture* bullet2 = IMG_LoadTexture(renderer,"loadImage/bullet_plane2.png");
        bullet = bullet2;
    }
    if(state[SDL_SCANCODE_3])
    {
        SDL_Texture* texture_plane3 = IMG_LoadTexture(renderer,"loadImage/plane3.png");
        texture_plane = texture_plane3;
        SDL_Texture* bullet3 = IMG_LoadTexture(renderer,"loadImage/bullet_plane3.png");
        bullet = bullet3;
    }
    if(state[SDL_SCANCODE_UP]||state[SDL_SCANCODE_W])
      rect_.y = max(0, rect_.y - SPEED_PLANE);
    if (state[SDL_SCANCODE_DOWN] ||state[SDL_SCANCODE_S])
        rect_.y = min(SCREEN_HEIGHT - HEIGHT_PLANE, rect_.y + SPEED_PLANE);
    if (state[SDL_SCANCODE_RIGHT] ||state[SDL_SCANCODE_D])
      rect_.x = min(SCREEN_WIDTH - WIDTH_PLANE, rect_.x + SPEED_PLANE);

    if (state[SDL_SCANCODE_LEFT] ||state[SDL_SCANCODE_A])
      rect_.x = max(0, rect_.x - SPEED_PLANE);
    if(events.type == SDL_MOUSEBUTTONDOWN)
    {
        Bullet* p_bullet = new Bullet();
        if (events.button.button == SDL_BUTTON_LEFT)
        {
          p_bullet->SetWidthHeight(WIDTH_LASER, HEIGHT_LASER);

        }
        else if (events.button.button == SDL_BUTTON_RIGHT)
        {
          p_bullet->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);

        }
        p_bullet->SetRect(this->rect_.x + this->rect_.w - 36, this->rect_.y - this->rect_.h*0.2);
        p_bullet->set_is_move(true);
        p_bullet->set_y_val(SPEED_BULLET_MAIN);
        p_bullet_list_.push_back(p_bullet);
    }
    if(events.type == SDL_KEYDOWN)
    {
        switch(events.key.keysym.sym)
        {
      case SDLK_UP:
      case SDLK_w:
           y_val_ += SPEED_PLANE; break;
      case SDLK_DOWN:
      case SDLK_s:
        y_val_ -= SPEED_PLANE; break;
      case SDLK_LEFT:
      case SDLK_a:
        x_val_ += SPEED_PLANE; break;
      case SDLK_RIGHT:
      case SDLK_d:
           x_val_ -= SPEED_PLANE; break;
        }
    }
}

void Plane::MakeBullet(SDL_Renderer* renderer,SDL_Texture* texture_bullet)
{
  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    Bullet* p_bullet_ = p_bullet_list_[i];
    if (p_bullet_ != NULL)
    {
      if (p_bullet_->get_is_move())
      {
        p_bullet_->Show(texture_bullet,renderer);
        p_bullet_->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
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




