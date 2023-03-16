
#include "Entity.h"

Entity::Entity()
{
  rect_.x = 0;
  rect_.y = 0;
  p_object_ = NULL;
}

Entity::~Entity()
{

}

void Entity::Show(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,p_object_,NULL,&rect_);
}

void Entity::LoadTexture(string path,SDL_Renderer* renderer)
{
    p_object_ = IMG_LoadTexture(renderer,path.c_str());
}

void Entity::SetTexture(SDL_Texture* texture)
{
    p_object_ = texture;
}
