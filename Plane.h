
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

  void HandleInputAction(SDL_Event &events,SDL_Renderer* renderer);

    std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}
    void MakeBullet( SDL_Renderer* renderer);
    void RemoveBullet(const int& idx);
    //life
    void got_hit(){life--;}
    void life_decrease()
    {
        if(life>0)
        {
            life--;
        }
    }
    void life_increase()
    {
        if(life<3 && life>0)
        {
            life++;
        }
    }
    int get_life() {return life;}

  private:
    int life;
  std::vector<Bullet*> p_bullet_list_;
};



#endif
