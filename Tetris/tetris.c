#include "mydefs.h"
#include <stdbool.h>

int main()
{
    // SDL_Window* window;
    // SDL_Renderer* renderer;
    // pre_launch(window, renderer);
    Colours* colours = (Colours*) malloc (sizeof(Colours));
    set_colours(colours);

    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Tetris UPR", 100, 100, GAME_WIDTH * 2, GAME_HEIGHT, SDL_WINDOW_SHOWN);
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

    Grid grid;                                              //struct s parametry herní mřížky
    create_grid (&grid, GRID_HEIGHT, GRID_WIDTH);           //vytvoření mřížky
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
            else if (event.type == SDLK_DOWN){

            }
            else if (event.type == SDLK_UP){

            }
            else if (event.type == SDLK_RIGHT){

            }
            else if (event.type == SDLK_LEFT){

            }
            else if (event.type == SDLK_ESCAPE){
                quit = true;
            }

        }

        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);    // Nastavení barvy na červenou
        for (int i = 1; i < GRID_WIDTH + 1; i++){
            SDL_RenderDrawLine(renderer, i * (GAME_WIDTH / GRID_WIDTH), 0, i * (GAME_WIDTH / GRID_WIDTH), 600); // Vykreslení čar mřížky
        }
        for (int i = 1; i < GRID_HEIGHT; i++){
            SDL_RenderDrawLine(renderer, 0, i * (GAME_HEIGHT / GRID_HEIGHT), 300, i * (GAME_HEIGHT / GRID_HEIGHT)); // Vykreslení čar mřížky
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        fill_cells(&grid, renderer, GAME_HEIGHT / GRID_HEIGHT, colours);                   //generováíní mřížky (mydefs.c)
        fill_right(renderer);
        SDL_RenderPresent(renderer);  // Prezentace kreslítka
    }
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();


    return 0;
}
