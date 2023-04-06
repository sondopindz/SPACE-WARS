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
    y_limit = 0;
    angle = 0;
    angle_rotate_speed = 0;
    reverse_direction = 0;
    CurrentTime = 0;
    LastTime = 0;
    delay_shoot_time = 1000;
}

Enemy::~Enemy()
{
    Destroy();
}

void Enemy::MoveEnemy()
{
    if(type == 0)
    {
        rect_.y += 1;
        if (rect_.y + rect_.h > SCREEN_HEIGHT)
        {
            rect_.x = MakeRandValue();
            rect_.y = 0;
        }
    }
    else if(type == 1 || type == 4 || type == 5)
    {
        if(rect_.y >= y_limit)
        {
            rect_.y = y_limit;
        }
        rect_.y += SPEED_ENEMY;
    }
    else if(type == 2)
    {
        if(rect_.x >= 100)
        {
            rect_.x = 100;
        }
        rect_.x += SPEED_ENEMY;
    }
    else if(type == 3)
    {
        if(rect_.x <= 600 - rect_.w)
        {
            rect_.x = 600 - rect_.w;
        }
        rect_.x -= SPEED_ENEMY;
    }
}

int Enemy::canspawnbullet()
{
    CurrentTime = SDL_GetTicks();
    int check_can_spawn = 0;
    if(type == 1 || type == 4 || type == 5 || type == 0)
    {
        if(CurrentTime >= LastTime + delay_shoot_time && rect_.y >= y_limit)
        {
            LastTime = CurrentTime;
            check_can_spawn = 1;
        }
    }
    else if(type == 2 || type == 3)
    {
        if(CurrentTime > LastTime + delay_shoot_time)
        {
            LastTime = CurrentTime;
            check_can_spawn = 1;
        }
    }
    return check_can_spawn;
}

void Enemy::rotate_angle()
{
    if(reverse_direction)
    {
        angle_rotate_speed = -angle_rotate_speed;
        reverse_direction = 0;
    }
    if(angle >= 360)
    {
        angle = 0;
    }
    angle += angle_rotate_speed;
}

void Enemy::MakeBullet(SDL_Renderer* renderer, vector<Bullet*> &bullet_list, Plane &plane_)
{
    if(type == 0)
    {
        Bullet* bullet = new Bullet();
        delay_shoot_time = 2500;
        bullet->LoadTexture("img/bullet_plane3.png", renderer);
        bullet->set_is_move(true);
        bullet->set_angle(90);
        bullet->set_speed(2);
        bullet->SetWidthHeight(BULLET_ENEMY_W, BULLET_ENEMY_H);
        bullet->set_pos(rect_.x + rect_.w*0.47, rect_.y + rect_.h*0.8);
        bullet_list.push_back(bullet);
    }

    else if(type == 1)
    {
        delay_shoot_time = 2000;
        Bullet* bullet = new Bullet();
        bullet->LoadTexture("img//BulletThreat.png", renderer);
        bullet->SetWidthHeight(BULLET_ENEMY_W, BULLET_ENEMY_H);
        bullet->set_is_move(true);
        if(plane_.GetRect().x + plane_.GetRect().w/2 - rect_.x - rect_.w/2 > 0)
        {
            bullet->set_angle(atan((plane_.GetRect().y + plane_.GetRect().h/2 - rect_.y - rect_.h/2)/(plane_.GetRect().x + plane_.GetRect().w/2 - rect_.x - rect_.w/2))*180/M_PI);
        }
        else if(plane_.GetRect().x + plane_.GetRect().w/2 - rect_.x - rect_.w/2 < 0)
        {
            bullet->set_angle(180 + atan((plane_.GetRect().y + plane_.GetRect().h/2 - rect_.y - rect_.h/2)/(plane_.GetRect().x + plane_.GetRect().w/2 - rect_.x - rect_.w/2))*180/M_PI);
        }
        bullet->set_speed(3);
        bullet->set_pos(rect_.x + rect_.w/2 - (bullet->GetRect().w)/2, rect_.y + 24);
        bullet_list.push_back(bullet);
    }

    else if(type == 4)
    {
        delay_shoot_time = 100;
        Bullet* bullet1 = new Bullet();
        if(bullet1 != NULL)
        {
            bullet1->LoadTexture("img//BulletThreat6.png", renderer);
            bullet1->SetWidthHeight(BULLET_ENEMY_W, BULLET_ENEMY_H);
            bullet1->set_is_move(true);
            bullet1->set_angle(angle);
            rotate_angle();
            bullet1->set_speed(3);
            bullet1->set_pos(rect_.x + rect_.w/2 - (bullet1->GetRect().w)/2, rect_.y + 15);
            bullet_list.push_back(bullet1);
        }

        Bullet* bullet2 = new Bullet();
        if(bullet2 != NULL)
        {
            bullet2->LoadTexture("img//BulletThreat6.png",renderer);
            bullet2->SetWidthHeight(BULLET_ENEMY_W,BULLET_ENEMY_H);
            bullet2->set_is_move(true);
            bullet2->set_angle(angle+20);
            rotate_angle();
            bullet2->set_speed(3);
            bullet2->set_pos(rect_.x + rect_.w/2 - (bullet2->GetRect().w)/2, rect_.y + 15);
            bullet_list.push_back(bullet2);
        }
    }

    else if(type == 2 || type == 3)
    {
        Bullet* bullet = new Bullet();
        delay_shoot_time = 1000;
        if(bullet != NULL)
        {
            bullet->LoadTexture("img//BulletThreat2.png", renderer);
            bullet->SetWidthHeight(BULLET_ENEMY_W, BULLET_ENEMY_H);
            bullet->set_is_move(true);
            bullet->set_random_angle1();
            bullet->set_speed(3);
            bullet->set_pos(rect_.x + rect_.w/2, rect_.y + 24);
            bullet_list.push_back(bullet);
        }
    }

    else if(type == 5)
    {
        delay_shoot_time = 2200;
        for(int u = 0; u < 12; u++)
        {
            Bullet* bullet = new Bullet();
            if(bullet != NULL)
            {
                bullet->LoadTexture("img//BulletThreat.png", renderer);
                bullet->SetWidthHeight(BULLET_ENEMY_W, BULLET_ENEMY_H);
                bullet->set_is_move(true);
                bullet->set_angle(30*u);
                bullet->set_speed(3);
                bullet->set_pos(rect_.x + rect_.w/2 - (bullet->GetRect().w)/2, rect_.y + rect_.h/2 - bullet->GetRect().h/2);
                bullet_list.push_back(bullet);
            }
        }
    }
}

void Enemy::set_status(SDL_Renderer* renderer)
{
    if(type == 0)
    {
        LoadTexture("img/enemy.png", renderer);
        score = 200;
    }
    else if(type == 1)
    {
        LoadTexture("img/SpaceThreat1.png", renderer);
        score = 200;
    }
    else if(type == 4)
    {
        LoadTexture("img/SpaceThreat6.png", renderer);
        score = 500;
    }
    else if(type == 3 || type == 2)
    {
        LoadTexture("img/SpaceThreat2.png", renderer);
        score = 300;
    }
    else if(type == 5)
    {
        LoadTexture("img//SpaceThreat2.png", renderer);
        score = 500;
    }
}

bool Enemy::check_die()
{
    if(type == 1 || type == 2 || type == 3 || type == 5)
    {
        if(die == 3) return 1;
    }
    else if(type == 4)
    {
        if(die == 3) return 1;
    }
    else if(type == 0)
    {
        if(die == 2) return 1;
    }
    return 0;
}
