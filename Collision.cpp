#include "Collision.h"

void Collision(vector<Enemy*>&Enemy_List,vector<Bullet*> &Bullet_List, Plane &plane_,SDL_Renderer* renderer,bool &quit)
{
    for(int i=0;i<Enemy_List.size();i++)
    {
        Enemy *p_enemy=Enemy_List[i];
        if(p_enemy!=NULL)
        {
            p_enemy->MoveEnemy();
            p_enemy->Show(renderer);
            if(p_enemy->canspawnbullet()==1)
            {
                p_enemy->MakeBullet(renderer,Bullet_List,plane_);
            }
            SDL_Rect spaceshipRect = plane_.GetRect();
            if(p_enemy != NULL)
            {
                SDL_Rect ChickenRect = p_enemy->GetRect();
                bool Chicken_to_Spaceship = CheckCollision(spaceshipRect, ChickenRect);
                if (Chicken_to_Spaceship)
                {
                    plane_.got_hit();
                    plane_.SetRect(SCREEN_WIDTH/2,SCREEN_HEIGHT - HEIGHT_PLANE);
                    if(plane_.get_life() == 0)
                    {
                        quit = true;
                        break;
                    }
                }
            }
        }
    }

    for(int j=0;j<Bullet_List.size();j++)
    {
        Bullet*p_bullet=Bullet_List[j];
        if(p_bullet!=NULL)
        {
            SDL_Rect BulletRect=p_bullet->GetRect();
            SDL_Rect Main_Rect=plane_.GetRect();
            bool ThreatBullet_to_plane_=CheckCollision(BulletRect,Main_Rect);
            if(ThreatBullet_to_plane_)
            {
                plane_.got_hit();
                plane_.SetRect(SCREEN_WIDTH/2,SCREEN_HEIGHT - HEIGHT_PLANE);
                if(plane_.get_life() == 0)
                {
                    quit = true;
                    break;
                }
                p_bullet->set_is_move(false);
                //Bullet_List.erase(Bullet_List.begin()+j);
            }
            if(p_bullet->get_is_move()==true)
            {
                p_bullet->HandleMove();
                p_bullet->Show(renderer);
            }
            else
            {
                Bullet_List.erase(Bullet_List.begin()+j);
                j--;
                    delete p_bullet;
                    p_bullet=NULL;
            }
        }
    }


    vector<Bullet*> plane__bullet_arr=plane_.GetBulletList();
    for(int k=0;k<plane__bullet_arr.size();k++)
    {
        Bullet*p_bullet=plane__bullet_arr[k];
        if(p_bullet!=NULL)
        {
            if(Enemy_List.size() > 0)
            {
                for(int h=0;h<Enemy_List.size();h++)
                {
                Enemy* p_enemy=Enemy_List[h];
                if(p_enemy!=NULL)
                {
                    SDL_Rect ThreatRect;
                    ThreatRect=p_enemy->GetRect();
                    SDL_Rect BulletRect=p_bullet->GetRect();
                    bool plane_Bullet_to_Threat=CheckCollision(ThreatRect,BulletRect);
                    if(plane_Bullet_to_Threat)
                    {
                        p_enemy->increase_die();
                        plane_.RemoveBullet(k);
                        if(p_enemy->check_die())
                        {
                            if(p_enemy!=NULL)
                            {
                                Enemy_List.erase(Enemy_List.begin()+h);
                                delete p_enemy;
                                p_enemy=NULL;
                            }
                        }
                    }
                }
            }
        }
        }
    }

}


