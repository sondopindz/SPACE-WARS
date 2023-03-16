
#ifndef PLANE_H
#define PLANE_H

#include "Entity.h"
#include "Common_Function.h"
#include <vector>
#include "Bullet.h"

class Plane : public Entity
{
public:
  Plane();
  ~Plane();

  void HandleInputAction(SDL_Event &events,SDL_Texture* &texture_plane,SDL_Renderer* renderer,SDL_Texture* &bullet);

    std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}
    void MakeBullet( SDL_Renderer* renderer,SDL_Texture* bullet);
    void RemoveBullet(const int& idx);
  private:

  std::vector<Bullet*> p_bullet_list_;
};



#endif
