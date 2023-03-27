
#include "Enemy.h"

Enemy::Enemy()
{
  rect_.x = SCREEN_WIDTH/2;
  rect_.y = 0;
  rect_.w = WIDTH_ENEMY;
  rect_.h = HEIGHT_ENEMY;
  die = 0;
  score = 0;
  type = 0;
  speed = 0;
  angle_rotate_speed=0;
  reverse_direction=0;
  CurrentTime=0;
  LastTime=0;
  y_limit=0;
  delay_shoot_time=1000;
}

Enemy::~Enemy()
{
    Destroy();
}
void Enemy::SetWidthHeight(const int x,const int y)
{
    rect_.w = x;
    rect_.h = y;
}

void Enemy::MoveEnemy()
{
    if(type == 0)
    {
        rect_.y += SPEED_ENEMY;
        if (rect_.y + rect_.h > SCREEN_HEIGHT)
        {
        rect_.x  = MakeRandValue();
        rect_.y= 0;
        }
    }
    else if(type==1 || type==4 || type == 5)
    {
        if(rect_.y>=y_limit)
        {
            rect_.y=y_limit;
        }
        rect_.y+=speed;
    }
    else if(type==2)
    {
        if(rect_.x>=100)
        {
            rect_.x=100;
        }
        rect_.x+=speed;
    }
    else if(type== 3)
    {
        if(rect_.x<=600-rect_.w)
        {
            rect_.x=600-rect_.w;
        }
        rect_.x-=speed;
    }
}

int Enemy::canspawnbullet()
{
    CurrentTime=SDL_GetTicks();
    int check_can_spawn=0;
    if(type==1 || type==4 || type == 5 || type == 0)
    {
        if(CurrentTime>LastTime+delay_shoot_time && rect_.y>=y_limit)
        {
            LastTime=CurrentTime;
            check_can_spawn=1;
        }
    }
    else if(type==2 || type==3)
    {
        if(CurrentTime>LastTime+1000)
        {
            LastTime=CurrentTime;
            check_can_spawn=1;
        }
    }
    return check_can_spawn;
}

void Enemy::rotate_angle()
{
    if(reverse_direction==1)
    {
        angle_rotate_speed=-angle_rotate_speed;
        reverse_direction=0;
    }
    if(angle>=360)
    {
        angle=0;
    }
    angle+=angle_rotate_speed;
}


// 1.1=1 , 2.1=4 , 4.1,4.2=2,3 , 3.1=5

void Enemy::MakeBullet(SDL_Renderer* renderer,vector<Bullet*> &bullet_list,Plane &plane_)
{
    if(type == 0)
    {
        Bullet* p_bullet = new Bullet();
        delay_shoot_time = 2500;
        p_bullet->LoadTexture("loadImage/bullet_plane3.png",renderer);
        p_bullet->set_is_move(true);
        p_bullet->set_angle(90);
        p_bullet->set_speed(2);
        p_bullet->SetWidthHeight(WIDTH_BULLET_ENEMY, HEIGHT_BULLET_ENEMY);
        p_bullet->SetRect(rect_.x + rect_.w*0.47, rect_.y + rect_.h*0.8);
        bullet_list.push_back(p_bullet);
    }
    if(type==1)
    {
        delay_shoot_time=700;
        Bullet*p_bullet=new Bullet();
        p_bullet->LoadTexture("img//BulletThreat.png",renderer);
        p_bullet->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
        p_bullet->set_is_move(true);
        if(plane_.GetRect().x-this->rect_.x>=0)
        {
            p_bullet->set_angle(atan((plane_.GetRect().y-this->rect_.y)/(plane_.GetRect().x-this->rect_.x))*180/PI);
        }
        else if(plane_.GetRect().x-this->rect_.x<0)
        {
            p_bullet->set_angle(180+atan((plane_.GetRect().y-this->rect_.y)/(plane_.GetRect().x-this->rect_.x))*180/PI);
        }
        p_bullet->set_speed(2);
        p_bullet->set_pos(this->rect_.x+this->GetRect().w/2-(p_bullet->GetRect().w)/2,this->rect_.y+24);
        bullet_list.push_back(p_bullet);
    }
    else if(type==4)
    {
        delay_shoot_time=200;
        Bullet*p_bullet1=new Bullet();
        p_bullet1->LoadTexture("img//BulletThreat6.png",renderer);
        p_bullet1->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
        p_bullet1->set_is_move(true);
        p_bullet1->set_angle(angle);
        rotate_angle();
        p_bullet1->set_speed(2);
        p_bullet1->set_pos(this->rect_.x+this->GetRect().w/2-(p_bullet1->GetRect().w)/2,this->rect_.y+15);
        bullet_list.push_back(p_bullet1);

        Bullet*p_bullet2=new Bullet();
        p_bullet2->LoadTexture("img//BulletThreat6.png",renderer);
        p_bullet2->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
        p_bullet2->set_is_move(true);
        p_bullet2->set_angle(angle+20);
        rotate_angle();
        p_bullet2->set_speed(2);
        p_bullet2->set_pos(this->rect_.x+this->GetRect().w/2-(p_bullet2->GetRect().w)/2,this->rect_.y+15);
        bullet_list.push_back(p_bullet2);
    }
    else if(type==2 || type==3)
    {
        Bullet*p_bullet=new Bullet();
        delay_shoot_time= 300;
        p_bullet->LoadTexture("img//BulletThreat2.png",renderer);
        p_bullet->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
        p_bullet->set_is_move(true);
        p_bullet->set_random_angle1();
        p_bullet->set_speed(2);
        p_bullet->set_pos(this->rect_.x+this->GetRect().w/2-(p_bullet->GetRect().w)/2,this->rect_.y+24);
        bullet_list.push_back(p_bullet);
    }
    else if(type==5)
    {
        for(int i=0;i<12;i++)
        {
            delay_shoot_time= 700;
            Bullet*p_bullet=new Bullet();
            p_bullet->LoadTexture("img//BulletThreat.png",renderer);
            p_bullet->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
            p_bullet->set_speed(2);
            p_bullet->set_angle(0+30*i);
            p_bullet->set_is_move(true);
            p_bullet->set_pos(rect_.x+rect_.w/2-(p_bullet->GetRect().w)/2,rect_.y+15);
            bullet_list.push_back(p_bullet);
        }
    }
}


void Enemy::set_status(SDL_Renderer* renderer)
{
    if(type == 0)
    {
        LoadTexture("loadImage/enemy.png",renderer);
        speed=2;
        score=100;
    }
    else if(type == 1)
    {
        LoadTexture("img/SpaceThreat1.png",renderer);
        speed=2;
        score=100;
    }
    else if(type == 4)
    {
        LoadTexture("img/SpaceThreat6.png",renderer);
        speed=2;
        score=500;
    }
    else if(type ==3 || type == 2)
    {
        LoadTexture("img/SpaceThreat2.png",renderer);
        speed=2;
        score=300;
    }
    else if(type == 5)
    {
        LoadTexture("img//SpaceThreat2.png",renderer);
        speed=2;
        score=300;
    }
}

bool Enemy::check_die()
{
    if(type==1)
    {
        if(die==2) return 1;
    }
    else if(type==4)
    {
        if(die==3) return 1;
    }
    else if(type==2 || type==3 || type == 5)
    {
        if(die==2) return 1;
    }
    else if(type==0)
    {
        if(die==1) return 1;
    }
    return 0;
}
