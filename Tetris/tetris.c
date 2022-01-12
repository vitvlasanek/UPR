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
  
    Grid grid;
    create_grid (&grid, 20, 10);
    int pivot;
    
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// SDL_RenderClear(renderer);
    // generate_grid(&grid, renderer, 30);                         //vykreslení mřížky (mydefs.c)
    // SDL_RenderPresent(renderer);

    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        generate_grid(&grid, renderer, 30);                     //generováíní mřížky (mydefs.c)
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);      // Nastavení barvy na mřížky
        for (int i = 0; i < 10; i++){
            SDL_RenderDrawLine(renderer, i * (GAME_WIDTH / 10), 0, i * (GAME_WIDTH / 10), 600); // Vykreslení čar mřížky
        }
        SDL_RenderPresent(renderer);  // Prezentace kreslítka
    }
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();


    return 0;
}
