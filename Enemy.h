

#ifndef ENEMY_H
#define ENEMY_H
#include "Common_Function.h"
#include "Entity.h"
#include "Bullet.h"
#include <vector>

#define WIDTH_ENEMY 30
#define HEIGHT_ENEMY 15

class Enemy : public Entity
{
public:
  Enemy();
  ~Enemy();
  void SetWidthHeight(const int x,const int y);
  //Move
  void MoveEnemy();
  void set_speed(const float &Speed) {speed=Speed;}


  //position
  void set_x_pos(const double &xPos) {rect_.x=xPos;}
  void set_y_pos(const double &yPos) {rect_.y=yPos;}
  double get_x_pos() const {return rect_.x;}
  double get_y_pos() const {return rect_.y;}

  //type
  void set_type_enemy(const int type_) {type=type_;}
  int get_type_enemy() const {return type;}
  void set_y_limit(const double &yLimit) {y_limit=yLimit;}
  void set_status(SDL_Renderer* screen);

  //Bullet
  std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}
  void InitBullet(Bullet* p_bullet);
  void MakeBullet(SDL_Renderer* renderer);
  void Reset();
  void ResetBullet(Bullet* p_bullet);

  //action when die
  void increase_die() {die++;}
  bool check_die();
  int get_score() const {return score;}
  //void Generate_Health(vector<Icon*>&health,SDL_Renderer* screen);

private:

  std::vector<Bullet*> p_bullet_list_;
  double speed;
  double y_limit;
  int type;
  double angle;
  bool changespawn;


  int die;
  int score;
  int delay_shoot_time;

  unsigned long long CurrentTime;
  unsigned long long LastTime;

};

#endif
