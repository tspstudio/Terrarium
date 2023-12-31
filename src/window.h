#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int status;
} Window;

Window wininit();

#endif