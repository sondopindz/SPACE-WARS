
#include "Enemy.h"

Enemy::Enemy()
{
  rect_.x = SCREEN_WIDTH/2;
  rect_.y = 0;
  rect_.w = 0;
  rect_.h = 0;
  die = 0;
  score = 0;
  type = 1;
  CurrentTime=0;
  LastTime=0;
  y_limit=0;
  delay_shoot_time=300;
  changespawn=0;
}

Enemy::~Enemy()
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
void Enemy::SetWidthHeight(const int x,const int y)
{
    rect_.w = x;
    rect_.h = y;
}

void Enemy::InitBullet(Bullet* p_bullet)
{
  if (p_bullet)
  {
      p_bullet->set_is_move(true);
      p_bullet->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
      p_bullet->SetRect(rect_.x + rect_.w*0.47, rect_.y + rect_.h*0.8);
      p_bullet_list_.push_back(p_bullet);
  }
}

void Enemy::MakeBullet(SDL_Renderer* renderer)
{
  for (int i = 0; i < p_bullet_list_.size(); i++)
  {
    Bullet* p_bullet = p_bullet_list_[i];
    if (p_bullet)
    {
      if (p_bullet->get_is_move())
      {
        p_bullet->Show(renderer);
        p_bullet->HandleMoveEnemyBullet();
      }
      else
      {
        p_bullet->set_is_move(true);
        p_bullet->SetRect(rect_.x + rect_.w*0.47, rect_.y + rect_.h*0.8);
      }
    }
  }
}

void Enemy::MoveEnemy()
{
  rect_.y += SPEED_ENEMY;
  if (rect_.y + rect_.h > SCREEN_HEIGHT)
  {
    rect_.x  = SDLCommonFunc::MakeRandValue();
    rect_.y= 0;
  }
}

void Enemy::Reset()
{
  rect_.x = SDLCommonFunc::MakeRandValue();
  rect_.y = 0;
}

void Enemy::ResetBullet(Bullet* p_bullet)
{
   p_bullet->SetRect(rect_.x + rect_.w*0.47, rect_.y + rect_.h*0.8);
}
