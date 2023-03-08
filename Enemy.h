

#ifndef ENEMY_H
#define ENEMY_H
#include "Common_Function.h"
#include "Entity.h"
#include "Bullet.h"
#include <vector>

#define WIDTH_ENEMY 80
#define HEIGHT_ENEMY 30

class Enemy : public Entity
{
public:
  Enemy();
  ~Enemy();

  void HandleMove(const int& x_bordr, const int& y_border);

  void set_x_val(const int& val) {x_val_ = val;}
  void set_y_val(const int& val) {y_val_ = val;}
  int get_x_val() const {return x_val_;}
  int get_y_val() const {return y_val_;}

  void SetBulletList(std::vector<Bullet*> bullet_list) {p_bullet_list_ = bullet_list;}
  std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}

  void InitBullet(Bullet* p_bullet);
  void MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit);
  void Reset(const int& xboder);
  void ResetBullet(Bullet* p_bullet);
private:
  int x_val_;
  int y_val_;

  std::vector<Bullet*> p_bullet_list_;
};

#endif
