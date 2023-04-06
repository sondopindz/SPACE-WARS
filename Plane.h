#ifndef PLANE_H
#define PLANE_H

#include "Entity.h"
#include "Common_Function.h"
#include "Bullet.h"

class Plane : public Entity
{
    public:
        Plane();
        ~Plane();

        void HandleInputAction(SDL_Event &events, SDL_Renderer* renderer, Mix_Chunk* shoot);

        //Bullet
        vector<Bullet*> GetBulletList() const {return bullet_list;}
        void MakeBullet(SDL_Renderer* renderer);
        void RemoveBullet(const int& idx);

        //Life
        void got_hit(){life--;}
        void life_decrease()
        {
            if(life > 0)
            {
                life--;
            }
        }
        void life_increase()
        {
            if(life < 3 && life > 0)
            {
                life++;
            }
        }
        int get_life() {return life;}

    private:
        int life;
        vector<Bullet*> bullet_list;

};

#endif
