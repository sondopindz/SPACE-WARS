
#ifndef PLANE_H
#define PLANE_H

#include "Entity.h"
#include "Common_Function.h"
#include <vector>
#include "Bullet.h"

#define SPEED_PLANE 5

class Plane : public Entity
{
public:
  Plane();
  ~Plane();

  void HandleInputAction(SDL_Event &events,SDL_Texture* &texture_plane,SDL_Renderer* renderer,SDL_Texture* &bullet);
  void HandleMove();

  void SetBulletList(std::vector<Bullet*> bullet_list) {p_bullet_list_ = bullet_list;}
    std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}
    void MakeBullet( SDL_Renderer* renderer,SDL_Texture* texture_bullet);
    void RemoveBullet(const int& idx);

  private:
  int x_val_;
  int y_val_;

  std::vector<Bullet*> p_bullet_list_;
};



#endif
