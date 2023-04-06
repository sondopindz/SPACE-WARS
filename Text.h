#ifndef TEXT_H
#define TEXT_H

#include "Common_Function.h"

class Text
{
    public:
        Text();
        ~Text();

        enum ColorType
        {
            WHITECOLOR = 0,
            REDCOLOR = 1,
            BLACKCOLOR = 2,
        };

        bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* renderer);
        void Free();
        void SetColor(Uint8 red, Uint8 green, Uint8 blue);
        void SetColor(int type);

        void RenderText(SDL_Renderer* renderer, int x_pos_, int y_pos_, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        int get_width() const {return width;}
        int get_height() const {return height;}
        void Set_Text(const string &text) {str = text;}
        string GetText() const {return str;}

    private:
        string str;
        SDL_Color color;
        SDL_Texture* texture;
        int width;
        int height;
};


#endif

