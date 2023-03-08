

#ifndef ENTITY_H
#define ENTITY_H
#include "Common_Function.h"

class Entity
{
public:
  Entity();
  ~Entity();

  void SetRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;}
  SDL_Rect GetRect() const {return rect_;}
    void Show(SDL_Texture* texture_,SDL_Renderer* renderer);
protected:
  SDL_Rect rect_;
  SDL_Texture* p_object_;
};

#endif
