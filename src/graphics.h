#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SDL2/SDL.h>
#include "window.h"
#include "stdbool.h"

void rect(int x, int y, int w, int h, SDL_Color color, Window win, bool fill);

#endif