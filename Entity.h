#ifndef ENTITY_H
#define ENTITY_H

#include "Common_Function.h"

class Entity
{
    public:
        Entity();
        ~Entity();

        SDL_Texture* LoadTexture(const string &path, SDL_Renderer* renderer);
        void SetTexture(SDL_Texture* text){texture = text;};
        void Destroy();
        void Show(SDL_Renderer* renderer);
        SDL_Rect GetRect() const {return rect_;}
        void SetRect(const int &x, const int &y) {rect_.x = x; rect_.y = y;}
        void SetWidthHeight(const int &w, const int &h) {rect_.w = w; rect_.h = h;}

    protected:
        SDL_Texture* texture;
        SDL_Rect rect_;

};

#endif
