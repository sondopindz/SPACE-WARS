#include "Collision.h"

void Collision(vector<Enemy*>&Enemy_List, vector<Bullet*> &Bullet_List, Plane &plane_, SDL_Renderer* renderer, Mix_Chunk* explo, bool &Gameover, long &current_score, Mix_Chunk* hit)
{

    for(int i = 0; i < Enemy_List.size(); i++)
    {
        Enemy* enemy = Enemy_List[i];

        // Implement Enemy
        if(enemy != NULL)
        {
            enemy->MoveEnemy();
            enemy->Show(renderer);
            if(enemy->canspawnbullet())
            {
                enemy->MakeBullet(renderer, Bullet_List, plane_);
            }
            SDL_Rect plane_rect = plane_.GetRect();
            if(enemy != NULL)
            {
                // Check collision enemy and plane
                SDL_Rect enemy_rect = enemy->GetRect();
                bool enemy_to_plane = CheckCollision(plane_rect, enemy_rect);
                if (enemy_to_plane)
                {
                    plane_.got_hit();
                    plane_.SetRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
                    Mix_PlayChannel(5, hit, 0);
                    if(plane_.get_life() == 0)
                    {
                        Gameover = true;
                        break;
                    }
                }
            }
        }
    }

    for(int j = 0; j < Bullet_List.size(); j++)
    {
        Bullet* bullet = Bullet_List[j];
        if(bullet != NULL)
        {
            // Check collision enemy bullet and plane
            SDL_Rect bullet_rect = bullet->GetRect();
            SDL_Rect plane_rect = plane_.GetRect();
            bool enemy_bullet_to_plane = CheckCollision(bullet_rect, plane_rect);
            if(enemy_bullet_to_plane)
            {
                plane_.got_hit();
                plane_.SetRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - HEIGHT_PLANE);
                if(plane_.get_life() == 0)
                {
                    Gameover = true;
                    break;
                }
                bullet->set_is_move(false);
                Mix_PlayChannel(5, hit, 0);
            }

            // Implement enemy bullet
            if(bullet->get_is_move())
            {
                bullet->HandleMove();
                bullet->Show(renderer);
            }
            else
            {
                Bullet_List.erase(Bullet_List.begin() + j);
                delete bullet;
                bullet = NULL;
            }
        }
    }

    vector<Bullet*> plane_bullet_list = plane_.GetBulletList();
    for(int k = 0; k < plane_bullet_list.size(); k++)
    {
        Bullet* bullet = plane_bullet_list[k];
        if(bullet != NULL)
        {
            if(Enemy_List.size() > 0)
            {
                for(int h = 0; h < Enemy_List.size(); h++)
                {
                    Enemy* enemy = Enemy_List[h];
                    if(enemy != NULL)
                    {
                        // Check collision plane bullet and enemy
                        SDL_Rect enemy_rect = enemy->GetRect();
                        SDL_Rect bullet_rect = bullet->GetRect();
                        bool plane_bullet_to_enemy = CheckCollision(enemy_rect, bullet_rect);
                        if(plane_bullet_to_enemy)
                        {
                            enemy->increase_die();
                            plane_.RemoveBullet(k);
                            if(enemy->check_die())
                            {
                                Mix_PlayChannel(4, explo, 0);
                                current_score += enemy->get_score();
                                if(enemy != NULL)
                                {
                                    Enemy_List.erase(Enemy_List.begin() + h);
                                    delete enemy;
                                    enemy = NULL;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}


