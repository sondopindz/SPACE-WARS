#ifndef COLLISION_H
#define COLLISION_H

#include "Enemy.h"
#include "Plane.h"
#include "Bullet.h"

#include "Common_Function.h"
using namespace std;

void Collision(vector<Enemy*>&Enemy_List,vector<Bullet*> &Bullet_List,Plane &plane_,SDL_Renderer* renderer,bool &quit);

#endif // COLLISION_H

