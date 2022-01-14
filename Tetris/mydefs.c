#include "mydefs.h"

void create_grid(Grid *grid, int y_cnt, int x_cnt) {
    grid->cell = (int*) malloc (y_cnt * x_cnt * sizeof(int));
    memset(grid->cell, 0, (y_cnt * x_cnt * sizeof(int)));
    grid->y_cnt = y_cnt;
    grid->x_cnt = x_cnt;
}


void fill_cells(Grid* grid, SDL_Renderer* renderer, int size, Colours* colours){
    grid->cell[1] = 1;
    grid->cell[2] = 2;
    grid->cell[3] = 3;
    grid->cell[4] = 4;
    grid->cell[5] = 5;
    grid->cell[6] = 6;
    grid->cell[7] = 7;
    for (int y = 0; y < grid->y_cnt; y++){
        for (int x = 0; x < grid->x_cnt; x++)
        {

            int i =   x + grid->x_cnt * y;
			if (grid->cell[i] != 0)
			{
                unsigned char value = grid->cell[i];
				SDL_Rect rect;
				rect.x = (x * size)+1;
				rect.y = (y * size)+1;
				rect.h = size-1;
				rect.w = size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value]/4, colours->g[value]/4, colours->b[value]/4, 255);
	            SDL_RenderFillRect(renderer, &rect);
                rect.x = (x * size)+3;
				rect.y = (y * size)+3;
				rect.h = size-5;
				rect.w = size-5;
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
