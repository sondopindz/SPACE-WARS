#ifndef ENEMYARRAY_H
#define ENEMYARRAY_H

#include "Enemy.h"
#include "Common_Function.h"
#include "Plane.h"

const int Num_of_ThreatArray1 = 5;
const int Num_of_ThreatArray2 = 5;
const int Num_of_ThreatArray3 = 2;
const int Num_of_ThreatArray4 = 3;
const int Num_of_ThreatArray5 = 3;

void EnemyArray_Random(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type1(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type2(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type3(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type4(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type5(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type6(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyArray_Type7(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);
void EnemyBoss(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer);

void GenerateEnemy(vector<Enemy*> &Enemy_List, SDL_Renderer* renderer, int &wave, Plane &plane_);

#endif

