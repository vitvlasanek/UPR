#include "mydefs.h"

int fill_cells(Grid* grid, SDL_Renderer* renderer, int cell_size, Colours* colours, Tetromino_active* tetromino){
    
    int cells_cnt = grid->y_cnt * GRID_WIDTH;
    unsigned char* new_cells = (unsigned char*) malloc (sizeof(char)* cells_cnt);
    //unsigned char new_cells[cells_cnt];
    memcpy(new_cells, grid->cell, cells_cnt);

    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            
            int index = (tetromino->y + y) * GRID_WIDTH + (tetromino->x + x);
            if (tetromino->y + y < GRID_HEIGHT + 2 && x + tetromino->x >= 0 && x + tetromino->x < GRID_WIDTH){
                if (new_cells[index] == 0){
                    new_cells[index] += tetromino->real_data[y * tetromino->side + x];
                }                
            }
        }
    }

    for (int y = 0; y < (GRID_HEIGHT + 2); y++){
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            int i = x + GRID_WIDTH * y;
            if (new_cells[i] != 0)
			{
                unsigned char value = new_cells[i];
				SDL_Rect rect;

				rect.x = (x * cell_size)+1;
				rect.y = ((y - 2) * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value] / 2, colours->g[value] / 2, colours->b[value] / 2, 255);
	            SDL_RenderFillRect(renderer, &rect);

                rect.x = (x * cell_size)+3;
				rect.y = ((y - 2) * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, colours->r[value], colours->g[value], colours->b[value], 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
    free(new_cells);
    return 0;
}

void draw_ghost(Tetromino_active* tetromino, SDL_Renderer* renderer, Colours* colours){
    int cell_size = GAME_HEIGHT / GRID_HEIGHT;
    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            int i = x + tetromino->side * y;
			if (tetromino->real_data[i] != 0)
			{
                unsigned char value = tetromino->real_data[i];
				SDL_Rect rect;

                int x_grid= x + tetromino->x;
				int y_grid = y + tetromino->ghost - 2;
                
                //vnější obrys
                rect.x = (x_grid * cell_size)+1;
				rect.y = (y_grid * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value] / 2, colours->g[value] / 2, colours->b[value] / 2, 255);
	            SDL_RenderFillRect(renderer, &rect);

                //výplň
                rect.x = (x_grid * cell_size)+3;
				rect.y = (y_grid * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
}

void draw_next(Tetromino_type* tetromino, SDL_Renderer* renderer, Colours* colours){
    int cell_size = GAME_HEIGHT / GRID_HEIGHT;
    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            int i = x + tetromino->side * y;
			if (tetromino->tetromino[i] != 0)
			{
                unsigned char value = tetromino->tetromino[i];
				SDL_Rect rect;

                int x_grid= x + GRID_WIDTH + 6;
				int y_grid = y + GRID_HEIGHT - 4;
                
                //vnější obrys
                rect.x = (x_grid * cell_size)+1;
				rect.y = (y_grid * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value] / 2, colours->g[value] / 2, colours->b[value] / 2, 255);
	            SDL_RenderFillRect(renderer, &rect);

                //výplň
                rect.x = (x_grid * cell_size)+3;
				rect.y = (y_grid * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, colours->r[value], colours->g[value], colours->b[value], 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
}

void fill_right(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect right;
        right.x = GAME_WIDTH;
        right.y = 0;
        right.w = GAME_WIDTH;
        right.h = GAME_HEIGHT;
        SDL_RenderFillRect(renderer, &right);
}

Colours* set_colours(){     //barvy jednotlivých tvarů tetromin
    
    Colours* colours = (Colours*) malloc (sizeof(Colours));

    colours->r[1] = 0;
    colours->g[1] = 255;
    colours->b[1] = 255;

    colours->r[2] = 0;
    colours->g[2] = 0;
    colours->b[2] = 255;

    colours->r[3] = 255;
    colours->g[3] = 128;
    colours->b[3] = 0;

    colours->r[4] = 255;
    colours->g[4] = 255;
    colours->b[4] = 0;

    colours->r[5] = 0;
    colours->g[5] = 255;
    colours->b[5] = 0;

    colours->r[6] = 128;
    colours->g[6] = 0;
    colours->b[6] = 255;

    colours->r[7] = 255;
    colours->g[7] = 0;
    colours->b[7] = 0;
    return colours;
}

int draw_keys(SDL_Renderer* renderer, SDL_Surface * image){

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    
    SDL_Rect rect;
    rect.x = GAME_WIDTH * (1.1);
    rect.y = GAME_WIDTH * (0.8);
    rect.w = GAME_WIDTH * (0.8);
    rect.h = GAME_WIDTH * (0.65);


    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    //SDL_RenderClear(renderer);
    SDL_DestroyTexture(texture);
    return 0;
}