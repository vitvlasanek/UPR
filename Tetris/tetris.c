#include "mydefs.h"
#include <stdbool.h>
#include <time.h>

int main()
{
    SDL_Event event;

    Colours* colours = (set_colours());
    Grid* grid = (Grid*)malloc(sizeof(Grid));;                                                                      // struct s parametry herní mřížky
    if (create_grid (grid)){                                                                                        // vytvoření mřížky
        fprintf(stderr, "Could not alloc memory for grid");
    }

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
    TTF_Font* font = TTF_OpenFont("Roboto-Black.ttf", GAME_WIDTH/10);
    if (font == NULL) {
        fprintf(stderr, "Font not found\n");
        return 1;
    }
    
    // parametry aktivního tetromina
    Tetromino_active * tetromino_active = alloc_tetromino_active();
    if(!tetromino_active){
        fprintf(stderr, "Could not alloc active tetromino\n");
        return 1;
    }

    // 7 typů tetromin
    Tetromino_type *type = alloc_type_tetromino();
    if(!type){
        fprintf(stderr, "Could not alloc tetromino types\n");
        return 1;
    }

    for (int i = 0; i < 7; i++)
    {
        load_tetrominos(&type[i], i);
    }
    

    bool quit = false;

    int timer = 0;
    int counter = 0;
    int next_type = 0;
    unsigned long long in_time = SDL_GetTicks();
    int score = 0;
    int lines = 0;
    srand(time(NULL));
    while (!quit)
    {

        unsigned long long  now = SDL_GetTicks();
		timer -= now - in_time;
		in_time = now;

        if (!tetromino_active->status){
            int cleared_lines = check_grid(grid);
            score += cleared_lines *  (cleared_lines + 9);
            lines += cleared_lines;
            copy_random(tetromino_active, &type[next_type]);
            next_type = rand() % 7;
        }
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_DOWN){
                    move_down(tetromino_active, grid);
                }
                else if (event.key.keysym.sym == SDLK_UP){
                    rotate_tetromino(tetromino_active, grid);
                }
                else if (event.key.keysym.sym == SDLK_RIGHT){
                    move_right(tetromino_active, grid);
                }
                else if (event.key.keysym.sym == SDLK_LEFT){
                    move_left(tetromino_active, grid);
                }
                else if (event.key.keysym.sym == SDLK_SPACE){
                    tetromino_active->y = tetromino_active->ghost;
                }
                else if (event.key.keysym.sym == SDLK_ESCAPE){
                    quit = true;
                }
            }
        }
        
        if(timer < 0){
            if(move_down(tetromino_active, grid)){
                fprintf(stderr, "Game over!");
                int stop = 0;
                while (!SDL_PollEvent(&event)){
                    game_over(renderer, font, score);
                }
                quit = true;
            }
            timer = 1000;
        }

        ghost_pos(tetromino_active, grid);
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
        fill_right(renderer);
        draw_next(&type[next_type], renderer, colours);
        draw_ghost(tetromino_active, renderer, colours);
        fill_cells(grid, renderer, GAME_HEIGHT / GRID_HEIGHT, colours, tetromino_active);                   //generováíní mřížky (mydefs.c)

        show_next(renderer, font);
        show_controlls(renderer, font);
        show_up(renderer, font);
        show_down(renderer, font);
        show_move(renderer, font);
        show_drop(renderer, font);
        show_score(renderer, font, score);
        show_lines(renderer, font, lines);

        SDL_RenderPresent(renderer);  // Prezentace kreslítka
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);	
    TTF_Quit();
    SDL_Quit();

    free_all(grid, &tetromino_active, colours, type);
    return 0;
}