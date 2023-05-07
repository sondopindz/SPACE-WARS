#include "Bullet.h"

Bullet::Bullet()
{
    rect_.x = rect_.y = rect_.w = rect_.h = 0;
    speed = 0;
    angle = 90;
    is_move = false;
    type = 0;
}

Bullet::~Bullet()
{
    Destroy();
}

void Bullet::set_random_angle1()
{
    angle = rand()%(165-15+1) + 15;
}

void Bullet::HandleMove()
{
    if(type == 0)
    {
        x_pos += speed*cos(angle*M_PI/180);
        y_pos += speed*sin(angle*M_PI/180);
    }
    if(type == 1)
    {
        y_pos += 3;
        x_pos = c + int(1.0*(350 - c)/(350*350)*(y_pos - 400)*(y_pos - 400));
    }

    if(y_pos <= 0 || y_pos >= SCREEN_HEIGHT)
    {
        is_move = false;
    }
    if(x_pos <= 0 || x_pos >= SCREEN_WIDTH)
    {
        is_move = false;
    }

    rect_.x = x_pos;
    rect_.y = y_pos;
}

