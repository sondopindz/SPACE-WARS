

#include "Bullet.h"

Bullet::Bullet()
{
  rect_.x = 0;
  rect_.y = 0;
  is_move_ = false;
}

Bullet::~Bullet()
{

}

void Bullet::HandleMove()
{
  if (is_move_)
  {
    rect_.y -= SPEED_BULLET_MAIN;
    if (rect_.y < 0)
    {
      is_move_ = false;
    }
  }
}

void Bullet::HandleMoveEnemyBullet()
{
      if(is_move_)
    {
        rect_.y += SPEED_BULLET_ENEMY;
    }
  if (rect_.y + rect_.h >  SCREEN_HEIGHT)
  {
    is_move_ = false;
  }
}
void Bullet::MoveSin()
{
        rect_.x+=3*cos(60*PI/180);
        rect_.y+=3*sin(60*PI/180);
}


