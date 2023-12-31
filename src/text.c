#ifndef TEXT_C_
#define TEXT_C_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "window.h"

SDL_Texture* text(char* text, char* font, int size, int x, int y, SDL_Color color, Window win) {
    TTF_Font* Font = TTF_OpenFont(font, size);
    if (Font == NULL) {
        printf("Font loading error! File %s not found.", font);
        return NULL;
    }

    SDL_Surface* textSurface = TTF_RenderText_Blended(Font, text, color);
    if (textSurface == NULL) {
        return NULL;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(win.renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

    return textTexture;
}

#endif