
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

void Entity::Show(SDL_Texture* texture_,SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,texture_,NULL,&rect_);
}
