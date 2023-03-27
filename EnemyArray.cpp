#include "EnemyArray.h"
using namespace std;

void EnemyArray_Random(vector<Enemy*> &EnemyArray,SDL_Renderer* renderer)
{
    for (int t = 0; t < NUM_ENEMIES; t++)
    {
        Enemy* p_enemy = new Enemy();
        if (p_enemy != NULL)
        {
            p_enemy->set_type_enemy(0);
            p_enemy->set_status(renderer);
            p_enemy->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
            int rand_x = MakeRandValue();
            p_enemy->SetRect(rand_x, 0);
            EnemyArray.push_back(p_enemy);
        }

    }
}


void EnemyArray_Type1(vector<Enemy*> &EnemyArray,SDL_Renderer* renderer)
{
    for(int i=0;i<Num_of_ThreatArray1;i++)
    {
        Enemy* p_enemy1=new Enemy();
        if(p_enemy1 != NULL)
        {
            p_enemy1->set_type_enemy(1);
            p_enemy1->set_status(renderer);
            p_enemy1->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
            p_enemy1->set_x_pos(SCREEN_WIDTH/2-(p_enemy1->GetRect().w)/2+100*(i-2));
            p_enemy1->set_y_limit(200);
            p_enemy1->set_y_pos(-85*2-25*i);
            EnemyArray.push_back(p_enemy1);
        }
    }
    for(int j=0;j<Num_of_ThreatArray1;j++)
    {
        Enemy* p_enemy2=new Enemy();
        if(p_enemy2 != NULL)
        {
            p_enemy2->set_type_enemy(1);
            p_enemy2->set_status(renderer);
            p_enemy2->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
            p_enemy2->set_x_pos(SCREEN_WIDTH/2-(p_enemy2->GetRect().w)/2+100*(j-2));
            p_enemy2->set_y_limit(300);
            p_enemy2->set_y_pos(-85-25*j);
            EnemyArray.push_back(p_enemy2);
        }
    }
}

void EnemyArray_Type2(vector<Enemy*> &EnemyArray,SDL_Renderer* renderer)
{
    for(int i=0;i<Num_of_ThreatArray2;i++)
    {
        Enemy* p_enemy1=new Enemy();
        p_enemy1->set_type_enemy(2);
        p_enemy1->set_status(renderer);
        p_enemy1->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
        p_enemy1->set_x_pos(-85);
        p_enemy1->set_y_pos(SCREEN_WIDTH/3-(p_enemy1->GetRect().h)/2+100*(i-1.5));
        EnemyArray.push_back(p_enemy1);
    }
    for(int j=0;j<Num_of_ThreatArray2;j++)
    {
        Enemy* p_enemy2=new Enemy();
        p_enemy2->set_type_enemy(3);
        p_enemy2->set_status(renderer);
        p_enemy2->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
        p_enemy2->set_x_pos(SCREEN_WIDTH);
        p_enemy2->set_y_pos(SCREEN_WIDTH/3-(p_enemy2->GetRect().h)/2+100*(j-1.5));
        EnemyArray.push_back(p_enemy2);
    }
}
void EnemyArray_Type3(vector<Enemy*> &EnemyArray,SDL_Renderer* renderer)
{
    for(int i=0;i<Num_of_ThreatArray3;i++)
    {
        Enemy* p_enemy=new Enemy();
        p_enemy->set_type_enemy(4);
            p_enemy->set_angle(0);
            p_enemy->set_angle_rotate_speed(20);
        p_enemy->set_status(renderer);
        p_enemy->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
        p_enemy->set_x_pos(SCREEN_WIDTH/2-(p_enemy->GetRect().w)/2+200*(i-0.5));
        p_enemy->set_y_limit(100);
        p_enemy->set_y_pos(-85);
        EnemyArray.push_back(p_enemy);
    }
}

void EnemyArray_Type4(vector<Enemy*> &EnemyArray,SDL_Renderer* renderer)
{
    for(int i=0;i<Num_of_ThreatArray4;i++)
    {
        Enemy* p_enemy=new Enemy();
        p_enemy->set_type_enemy(5);
        p_enemy->set_status(renderer);
        p_enemy->SetWidthHeight(WIDTH_ENEMY,HEIGHT_ENEMY);
        p_enemy->set_x_pos(rand()%(650-int(p_enemy->GetRect().w)-150+1)+150);
        p_enemy->set_y_limit(200);
        p_enemy->set_y_pos(-85);
        EnemyArray.push_back(p_enemy);
    }
}

void GenerateEnemy(vector<Enemy*> &Enemy_List,SDL_Renderer* renderer,int &wave)
{
    if(Enemy_List.size()<=0)
    {
        wave+=1;
            if(wave <= 2)
            {
                EnemyArray_Random(Enemy_List,renderer);
            }
            else
            {
                /*int random = rand()%4+1;
            if(random==1)
            {
                EnemyArray_Type1(Enemy_List,renderer);
            }
            else if(random==2)
            {
                EnemyArray_Type2(Enemy_List,renderer);
            }
            else if(random==3)
            {
                EnemyArray_Type2(Enemy_List,renderer);
                EnemyArray_Type3(Enemy_List,renderer);
            }
            else if(random == 4)
            {
                EnemyArray_Type2(Enemy_List,renderer);
                EnemyArray_Type4(Enemy_List,renderer);
            }*/
            //EnemyArray_Type4(Enemy_List,renderer);
            //EnemyArray_Type3(Enemy_List,renderer);
            //EnemyArray_Type2(Enemy_List,renderer);
            EnemyArray_Type1(Enemy_List,renderer);
            }
    }
}


