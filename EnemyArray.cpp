#include "EnemyArray.h"

void EnemyArray_Random(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    for (int t = 0; t < NUM_ENEMIES; t++)
    {
        Enemy* enemy = new Enemy();
        if (enemy != NULL)
        {
            enemy->set_type_enemy(0);
            enemy->set_status(renderer);
            enemy->SetWidthHeight(30, 30);
            int rand_x = MakeRandValue();
            enemy->SetRect(rand_x, 0);
            EnemyArray.push_back(enemy);
        }
    }
}

void EnemyArray_Type1(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    for(int i = 0; i < Num_of_ThreatArray1; i++)
    {
        Enemy* enemy1 = new Enemy();
        if(enemy1 != NULL)
        {
            enemy1->set_type_enemy(1);
            enemy1->set_status(renderer);
            enemy1->SetWidthHeight(30, 38);
            enemy1->SetRect(SCREEN_WIDTH/2 + 100*(i-2), -85*2 - 25*i);
            enemy1->set_y_limit(200);
            EnemyArray.push_back(enemy1);
        }
    }

    for(int j = 0; j < Num_of_ThreatArray1; j++)
    {
        Enemy* enemy2 = new Enemy();
        if(enemy2 != NULL)
        {
            enemy2->set_type_enemy(1);
            enemy2->set_status(renderer);
            enemy2->SetWidthHeight(WIDTH_ENEMY, HEIGHT_ENEMY);
            enemy2->SetRect(SCREEN_WIDTH/2 + 100*(j-2), -85-25*j);
            enemy2->set_y_limit(300);
            EnemyArray.push_back(enemy2);
        }
    }
}

void EnemyArray_Type2(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    for(int i = 0; i < Num_of_ThreatArray2; i++)
    {
        Enemy* enemy1 = new Enemy();
        if(enemy1 != NULL)
        {
            enemy1->set_type_enemy(2);
            enemy1->set_status(renderer);
            enemy1->SetWidthHeight(40, 32);
            enemy1->SetRect(-85, SCREEN_WIDTH/4 + 65*(i-1.5));
            EnemyArray.push_back(enemy1);
        }
    }

    for(int j = 0; j < Num_of_ThreatArray2; j++)
    {
        Enemy* enemy2 = new Enemy();
        if(enemy2 != NULL)
        {
            enemy2->set_type_enemy(3);
            enemy2->set_status(renderer);
            enemy2->SetWidthHeight(40, 32);
            enemy2->SetRect(SCREEN_WIDTH, SCREEN_WIDTH/4 + 65*(j-1.5));
            EnemyArray.push_back(enemy2);
        }
    }
}

void EnemyArray_Type3(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    for(int i = 0; i < Num_of_ThreatArray3; i++)
    {
        Enemy* enemy = new Enemy();
        if(enemy != NULL)
        {
            enemy->set_type_enemy(4);
            enemy->set_angle(0);
            enemy->set_angle_rotate_speed(10);
            enemy->set_status(renderer);
            enemy->SetWidthHeight(40, 76);
            enemy->SetRect(SCREEN_WIDTH/2 - (enemy->GetRect().w)/2 + 200*(i-0.5), -85);
            enemy->set_y_limit(100);
            EnemyArray.push_back(enemy);
        }
    }
}

void EnemyArray_Type4(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    for(int i = 0; i < Num_of_ThreatArray4; i++)
    {
        Enemy* enemy = new Enemy();
        if(enemy != NULL)
        {
            enemy->set_type_enemy(5);
            enemy->set_status(renderer);
            enemy->SetWidthHeight(50, 50);
            enemy->SetRect((i+1)*SCREEN_WIDTH/4, -85);
            enemy->set_y_limit(150);
            EnemyArray.push_back(enemy);
        }
    }
}

void EnemyBoss(vector<Enemy*> &EnemyArray, SDL_Renderer* renderer)
{
    Enemy* enemy = new Enemy();
    if(enemy != NULL)
    {
        enemy->set_type_enemy(6);
        enemy->set_status(renderer);
        enemy->set_angle_rotate_speed(0.5);
        enemy->SetWidthHeight(100, 100);
        enemy->SetRect(SCREEN_WIDTH/2 - enemy->GetRect().w/2, -enemy->GetRect().h);
        enemy->set_y_limit(50);
        EnemyArray.push_back(enemy);
    }
}

void GenerateEnemy(vector<Enemy*> &Enemy_List, SDL_Renderer* renderer, int &wave, Plane &plane_)
{
    if(Enemy_List.size() <= 0)
    {
        wave += 1;
        if(wave <= 3)
        {
            EnemyArray_Random(Enemy_List, renderer);
        }
        else
        {
            if(wave == 4)
            {
                EnemyArray_Type1(Enemy_List, renderer);
            }
            if(wave == 5)
            {
                EnemyArray_Type2(Enemy_List, renderer);
            }
            if(wave == 6)
            {
                EnemyArray_Type3(Enemy_List, renderer);
            }
            if(wave == 7)
            {
                EnemyArray_Type4(Enemy_List, renderer);
            }
            if(wave == 8)
            {
                plane_.life_increase();
                EnemyBoss(Enemy_List, renderer);
            }
        }
    }
}


