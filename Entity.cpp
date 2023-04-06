#include "Entity.h"

Entity::Entity()
{
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = 0;
  rect_.h = 0;
  texture = NULL;
}

Entity::~Entity()
{
    Destroy();
}

void Entity::Show(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect_);
}

SDL_Texture* Entity::LoadTexture(const string &path, SDL_Renderer* renderer)
{
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, loadSurface);
    SDL_FreeSurface(loadSurface);
    return texture;
}

void Entity::Destroy()
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}
