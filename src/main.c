#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "text.h"
#include "textures.h"
#include "graphics.h"
#include "stdbool.h"

int main() {
    Window window = wininit();
    if (window.status != 0) {
        return window.status;
    }

    SDL_Color color1 = {255,255,255,255};
    SDL_Texture* title = text("Terrarium","res/fonts/main.ttf",120,100,240,color1,window);
    SDL_Rect titleRect = {100,240,150,600};

    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
        SDL_RenderClear(window.renderer);

        SDL_RenderCopy(window.renderer,title,NULL,&titleRect);

        SDL_RenderPresent(window.renderer);
    }

    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
    return 0;
}