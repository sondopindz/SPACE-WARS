

#include "Bullet.h"

Bullet::Bullet()
{
  rect_.x = 0;
  rect_.y = 0;
  is_move = false;
  angle = 0;
  speed = 0;
}

Bullet::~Bullet()
{
    Destroy();
}

void Bullet::set_random_angle1()
{
    angle=rand()%(165-15+1)+15;
}

void Bullet::HandleMove()
{
    if(is_move)
    {
        rect_.x+=speed*cos(angle*PI/180);
        rect_.y+=speed*sin(angle*PI/180);
    }
    if(rect_.y <= 0 || rect_.y>=SCREEN_HEIGHT)
    {
        is_move=false;
    }
    if(rect_.x<=0 || rect_.x>=SCREEN_WIDTH)
    {
        is_move=false;
    }

}

