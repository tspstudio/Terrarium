#ifndef GRAPHICS_C_
#define GRAPHICS_C_

#include <SDL2/SDL.h>
#include "graphics.h"
#include "window.h"
#include "stdbool.h"

void rect(int x, int y, int w, int h, SDL_Color color, Window win, bool fill) {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(win.renderer, color.r, color.g, color.b, color.a);
    if (!fill) {
        SDL_RenderDrawRect(win.renderer, &rect);
    } else {
        SDL_RenderFillRect(win.renderer, &rect);
    }
    
}

#endif