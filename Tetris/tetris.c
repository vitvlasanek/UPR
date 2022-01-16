#include "mydefs.h"
#include <stdbool.h>
#include <time.h>

int main()
{

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
    
    Grid grid;                                                      // struct s parametry herní mřížky
    Tetromino_active tetromino_active;                              // parametry aktivního tetromina
    Tetromino_type type[7];                                         // 7 typů tetromin
    create_grid (&grid, GRID_HEIGHT, GRID_WIDTH);                   // vytvoření mřížky
    tetromino_active.real_data = (unsigned char*) malloc (sizeof(char)* 16);
    tetromino_active.pattern = (char*) malloc (sizeof(char)* 16);

    for (int i = 0; i < 7; i++)
    {
        //alloc_type_tetromino(&type[i]);
        load_tetrominos(&type[i], i);
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d\t",type[1].tetromino[i]);
    //     printf("%d\t",type[2].tetromino[i]);
    //     printf("%d\t",type[3].tetromino[i]);
    //     printf("%d\t",type[4].tetromino[i]);
    //     printf("%d\t",type[5].tetromino[i]);
    //     printf("\n");
    // }
    
    srand (time(NULL));
    char rand_type = rand() % 7;
    copy_random(&tetromino_active, &type[rand_type], rand_type);

    for (int i = 0; i < 16; i++)
    {
        printf("%d", tetromino_active.real_data[i]);
    }
    printf("\n");

    // for (int i = 0; i < tetromino_active.side * tetromino_active.side; i++)
    // {
    //     printf("%d", tetromino_active.real_data[i]);
    // }

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN) {

                if (event.type == SDLK_DOWN){

                }
                else if (event.key.keysym.sym == SDLK_UP){
                    rotate_tetromino(&tetromino_active);
                }
                else if (event.key.keysym.sym == SDLK_RIGHT){
                    move_right(&tetromino_active);
                }
                else if (event.key.keysym.sym == SDLK_LEFT){
                    move_left(&tetromino_active);
                }
                else if (event.key.keysym.sym == SDLK_ESCAPE){
                    quit = true;
                }
            }

        }

        SDL_SetRenderDrawColor(renderer, 48, 48, 48, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);    // Nastavení barvy na červenou
        for (int x = 0; x < GRID_WIDTH + 1; x++){
            SDL_RenderDrawLine(renderer, x * (GAME_WIDTH / GRID_WIDTH), 0, x * (GAME_WIDTH / GRID_WIDTH), 600); // Vykreslení čar mřížky
        }
        for (int y = 0; y < GRID_HEIGHT; y++){
            SDL_RenderDrawLine(renderer, 0, y * (GAME_HEIGHT / GRID_HEIGHT), 300, y * (GAME_HEIGHT / GRID_HEIGHT)); // Vykreslení čar mřížky
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        fill_cells(&grid, renderer, GAME_HEIGHT / GRID_HEIGHT, colours, &tetromino_active);                   //generováíní mřížky (mydefs.c)

        fill_right(renderer);
        SDL_RenderPresent(renderer);  // Prezentace kreslítka
        printf("%d", tetromino_active.rot);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(colours);
    free(grid.cell);
    return 0;
}