#include "Text.h"

Text::Text()
{
    texture = NULL;
    width = 0;
    height = 0;
    color.r = 0;
    color.g = 0;
    color.b = 0;
}

Text::~Text()
{

}

bool Text::LoadFromRenderText(TTF_Font*font, SDL_Renderer* renderer)
{
    Free();
    SDL_Surface* text_surface = TTF_RenderText_Solid(font,str.c_str(),color);
    if(text_surface)
    {
        texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        width = text_surface->w;
        height = text_surface->h;
        SDL_FreeSurface(text_surface);
    }
    return texture != NULL;
}

void Text::Free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void Text::SetColor(Uint8 red,Uint8 green, Uint8 blue)
{
    color.r = red;
    color.g = green;
    color.b = blue;
}

void Text::SetColor(int type)
{
    if(type == WHITECOLOR)
    {
        color = {255, 255, 255};
    }
    else if(type == REDCOLOR)
    {
        color = {255, 0, 0};
    }
}

void Text::RenderText(SDL_Renderer* renderer, int x_pos, int y_pos, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = {x_pos, y_pos, width, height};
    if(clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

