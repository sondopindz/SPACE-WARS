#ifndef ENEMY_H
#define ENEMY_H

#include "Common_Function.h"
#include "Entity.h"
#include "Bullet.h"
#include "Plane.h"

class Enemy : public Entity
{
    public:
        Enemy();
        ~Enemy();

        //Move
        void MoveEnemy();

        //Type
        void set_type_enemy(const int &type_) {type = type_;}
        void set_y_limit(const int &yLimit) {y_limit = yLimit;}
        void set_status(SDL_Renderer* renderer);

        //Bullet
        int canspawnbullet();
        void MakeBullet(SDL_Renderer* renderer, vector<Bullet*> &bullet_list, Plane &plane_);

        //action when die
        void increase_die() {die++;}
        bool check_die();
        int get_score() const {return score;}

        //angle
        void set_angle_rotate_speed(const double &angleSpeed) {angle_rotate_speed = angleSpeed;}
        void rotate_angle();
        void set_angle(int angle_){angle = angle_;};

    private:
        int y_limit;
        int type;
        int angle;
        bool reverse_direction;
        double angle_rotate_speed;

        int die;
        int score;
        int delay_shoot_time;

        unsigned long long CurrentTime;
        unsigned long long LastTime;

};

#endif
