
#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include<math.h>
#define WIDTH_LASER 3
#define HEIGHT_LASER 6

#define WIDTH_BULLET_ENEMY 3
#define HEIGHT_BULLET_ENEMY 6

class Bullet : public Entity
{
public:

  Bullet();
  ~Bullet();
  void HandleMove();

  void set_speed(const double& Speed) {speed=Speed;}
  bool get_is_move() const {return is_move;}
  void set_is_move(bool is_move_) {is_move = is_move_;}
  void SetWidthHeight(const int& widht,const int& height) {rect_.w = widht; rect_.h = height;}
  void set_pos(const double& xPos, const double& yPos)
  {
    rect_.x=xPos;
    rect_.y=yPos;
  }

  void set_angle(const double& angle_) {angle=angle_;}
  void set_random_angle1();

private:
  double speed;
  double angle;
  bool is_move;
};


#endif
