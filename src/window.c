#ifndef WINDOW_C_
#define WINDOW_C_

#include <SDL2/SDL.h>
#include "window.h"
#include <time.h>
#include <SDL2/SDL_ttf.h>

Window wininit() {
    Window win;
    win.window = NULL;
    win.renderer = NULL;
    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        win.status = 1;
        return win;
    }
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Terrarium", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        win.status = 1;
        return win;
    }
    win.window = window;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
        win.status = 2;
		return win;
	}
    win.renderer = renderer;
    if (TTF_Init() != 0) {
        win.status = 3;
        return win;
    }
    win.status = 0;
    return win;
}

#endif