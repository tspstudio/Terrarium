#ifndef TEXTURES_C_
#define TEXTURES_C_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "textures.h"
#include "window.h"

SDL_Texture* img(char* path, int x, int y, int w, int h, Window win) {
    SDL_Surface* surface = IMG_Load(path);
    if (surface == NULL) {
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(win.renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect rect = { x, y, x+w, y+h };

    SDL_RenderCopy(win.renderer, texture, NULL, &rect);

    return texture;
}

#endif