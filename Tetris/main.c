#include "mydefs.h"
#include <stdbool.h>


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("SDL experiments", 100, 100, GAME_WIDTH, GAME_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // SDL_Event e;
    // bool quit = false;
    // int pos = 100;

    // while (!quit)
    // {
    //     while (SDL_PollEvent(&e))
    //     {
    //         if (e.type == SDL_QUIT)
    //         {
    //             quit = true;
    //         }
    //     }
    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Nastavení barvy na černou
    //     SDL_RenderClear(renderer);                      // Vykreslení pozadí

    //     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Nastavení barvy na červenou
    //     SDL_RenderDrawLine(renderer, pos, pos, pos + 100, pos + 100); // Vykreslení čáry

    //     pos++;

    //     SDL_RenderPresent(renderer);  // Prezentace kreslítka
    // }
    
    Grid grid;
    create_grid (&grid, 20, 10);
    int pivot;
    


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
