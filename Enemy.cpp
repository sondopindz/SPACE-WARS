/*
#include "Enemy.h"

Enemy::Enemy()
{
  rect_.x = SCREEN_WIDTH;
  rect_.y = SCREEN_HEIGHT*0.5;
  rect_.w = WIDTH_ENEMY;
  rect_.h = HEIGHT_ENEMY;

  x_val_ = 0;
  y_val_ = 0;
}

Enemy::~Enemya
{
  if (p_bullet_list_.size() > 0)
  {
    for (int i = 0; i < p_bullet_list_.size(); i++)
    {
      Bullet* p_bullet = p_bullet_list_[i];
      if (p_bullet != NULL)
      {
        delete p_bullet;
        p_bullet = NULL;
      }
    }
    p_bullet_list_.clear();
  }
}


void Enemy::InitBullet(Bullet* p_bullet,SDL_Texture* &tx_bullet_enemy,SDL_Renderer* renderer,const char path)
{
  if (p_bullet)
  {
      tx_bullet_enemy = IMG_LoadTexture(renderer,path.c_str());
      p_bullet->set_is_move(true);
      p_bullet->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
      p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.5);
      p_bullet->set_x_val(SPEED_BULLET_THREATS);
      p_bullet_list_.push_back(p_bullet);
  }
}


void Enemy::MakeBullet(SDL_Texture* texture,SDL_Renderer* renderer, const int& x_limit, const int& y_limit)
{
  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    Bullet* p_bullet = p_bullet_list_.[i];
    if (p_bullet)
    {
      if (p_bullet->get_is_move())
      {
        p_bullet->Show(texture,renderer);
        p_bullet->HandleMoveRightToLeft();
      }
      else
      {
        p_bullet->set_is_move(true);
        p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.5);
      }
    }
  }
}

void Enemy::HandleMove(const int& x_bordr, const int& y_border)
{
  rect_.y += y_val_;
  if (rect_.y + rect.h > SCREEN_HEIGHT)
  {
    rect_.x  = SDLCommonFunc::MakeRandValue();
    rect_.y= 0;
  }
}

void Enemy::Reset(const int& xboder)
{
  rect_.x = xboder;
  rect_.y = SDLCommonFunc::MakeRandValue();

  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    Bullet* p_bullet = p_bullet_list_[i];
    if (p_bullet)
    {
      ResetBullet(p_bullet);
    }
  }
}

void Enemy::ResetBullet(Bullet* p_bullet)
{
   p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.5);
}*/
