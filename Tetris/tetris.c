#include "mydefs.h"
#include <stdbool.h>
#include <time.h>

int main()
{
    SDL_Event event;
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
    if (TTF_Init()){
        fprintf(stderr, "TTF_Init Error\n");
        return 1;
    }
    
    Grid grid;                                                                      // struct s parametry herní mřížky
    Tetromino_active tetromino_active;                                              // parametry aktivního tetromina
    Tetromino_type type[7];                                                         // 7 typů tetromin
    create_grid (&grid, GRID_HEIGHT, GRID_WIDTH);                                   // vytvoření mřížky
    //tetromino_active.real_data = (unsigned char*) malloc (sizeof(unsigned char)* 16);

    for (int i = 0; i < 7; i++)
    {
        //alloc_type_tetromino(&type[i]);
        load_tetrominos(&type[i], i);
    }
    

    tetromino_active.status = false;
    bool quit = false;

    int timer = 0;
    int counter = 0;
    unsigned long long in_time = SDL_GetTicks();
    int score = 0;
    while (!quit)
    {

        unsigned long long  now = SDL_GetTicks();
		timer -= now - in_time;
		in_time = now;

        if (!tetromino_active.status){
            score += check_grid(&grid);
            srand (time(NULL));
            unsigned char rand_type = rand() % 7;
            copy_random(&tetromino_active, &type[rand_type]);
        }
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_DOWN){
                    move_down(&tetromino_active, &grid);
                }
                else if (event.key.keysym.sym == SDLK_UP){
                    rotate_tetromino(&tetromino_active, &grid);
                }
                else if (event.key.keysym.sym == SDLK_RIGHT){
                    move_right(&tetromino_active, &grid);
                }
                else if (event.key.keysym.sym == SDLK_LEFT){
                    move_left(&tetromino_active, &grid);
                }
                else if (event.key.keysym.sym == SDLK_ESCAPE){
                    quit = true;
                }
            }
        }
        
        if(timer < 0){
            move_down(&tetromino_active, &grid);
            timer = 1000;
        }

        ghost_pos(&tetromino_active, &grid);
        SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);    // Nastavení barvy na červenou
        for (int x = 0; x < GRID_WIDTH + 1; x++){
            SDL_RenderDrawLine(renderer, x * (GAME_WIDTH / GRID_WIDTH), 0, x * (GAME_WIDTH / GRID_WIDTH), 600); // Vykreslení čar mřížky
        }
        for (int y = 0; y < GRID_HEIGHT; y++){
            SDL_RenderDrawLine(renderer, 0, y * (GAME_HEIGHT / GRID_HEIGHT), 300, y * (GAME_HEIGHT / GRID_HEIGHT)); // Vykreslení čar mřížky
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        draw_ghost(&tetromino_active, renderer, colours);
        fill_cells(&grid, renderer, GAME_HEIGHT / GRID_HEIGHT, colours, &tetromino_active);                   //generováíní mřížky (mydefs.c)
        fill_right(renderer);
        show_score(renderer, score);
        //game_over(renderer, score);
        SDL_RenderPresent(renderer);  // Prezentace kreslítka
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);	
    TTF_Quit();
    SDL_Quit();

    //free(tetromino_active.real_data);
    free(colours);
    free(grid.cell);
    return 0;
}