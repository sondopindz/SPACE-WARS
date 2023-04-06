#ifndef COLLISION_H
#define COLLISION_H

#include "Enemy.h"
#include "Plane.h"
#include "Bullet.h"
#include "Common_Function.h"

void Collision(vector<Enemy*> &Enemy_List, vector<Bullet*> &Bullet_List, Plane &plane_, SDL_Renderer* renderer, Mix_Chunk* explo, bool &Gameover, long &current_score, Mix_Chunk* hit);

#endif

