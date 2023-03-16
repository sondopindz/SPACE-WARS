
#ifndef BULLET_H
#define BULLET_H
#include "Entity.h"
#include<math.h>
#define WIDTH_LASER 3
#define HEIGHT_LASER 6

#define WIDTH_SPHERE 3
#define HEIGHT_SPHERE 6

class Bullet : public Entity
{
public:

  Bullet();
  ~Bullet();
  void HandleMove();
  void HandleMoveEnemyBullet();
  void MoveSin();

  bool get_is_move() const {return is_move_;}
  void set_is_move(bool is_move) {is_move_ = is_move;}
  void SetWidthHeight(const int& widht, const int& height) {rect_.w = widht; rect_.h = height;}

private:

  bool is_move_;
};


#endif
