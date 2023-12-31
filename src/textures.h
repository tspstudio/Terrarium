#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

SDL_Texture* img(char* path, int x, int y, int w, int h, Window win);

#endif