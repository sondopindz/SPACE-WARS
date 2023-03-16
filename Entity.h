

#ifndef ENTITY_H
#define ENTITY_H
#include "Common_Function.h"
#include<bits/stdc++.h>
#include<string>
class Entity
{
public:
  Entity();
  ~Entity();

  void SetRect(const int& x, const int& y) {rect_.x = x, rect_.y = y;}
  SDL_Rect GetRect() const {return rect_;}
  void Show(SDL_Renderer* renderer);
  void LoadTexture(string path,SDL_Renderer* renderer);
  void SetTexture(SDL_Texture* texture);
protected:
  SDL_Rect rect_;
  SDL_Texture* p_object_;
};

#endif
