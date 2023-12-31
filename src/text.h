#ifndef TEXT_H_
#define TEXT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "window.h"
SDL_Texture* text(char* text, char* font, int size, int x, int y, SDL_Color color, Window win);

#endif