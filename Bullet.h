#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
    public:
        Bullet();
        ~Bullet();

        void HandleMove();

        void set_angle(const double& Angle) {angle = Angle;}
        void set_speed(const double& Speed) {speed = Speed;}
        bool get_is_move() const {return is_move;}
        void set_is_move(bool is_move_) {is_move = is_move_;}

        void set_pos(const double &xPos, const double &yPos)
        {
            x_pos = xPos;
            y_pos = yPos;
        }
        void set_random_angle1();

    private:
        double speed;
        double x_pos;
        double y_pos;
        double angle;
        bool is_move;

};

#endif


