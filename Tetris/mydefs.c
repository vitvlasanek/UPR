#include "mydefs.h"

void create_grid(Grid *grid, int height, int width) {
    grid->cell = (int*) malloc (height * width * sizeof(int));
    memset(grid->cell, 0, (height * width * sizeof(int)));
    grid->height = height;
    grid->width = width;
}

void generate_grid(Grid* grid, SDL_Renderer* renderer, int size){
    for (int y = 0; y < grid->height; y++){
        for (int x = 0; x < grid->width; x++)
        {

            int index =   y * x;
			if (grid->cell[index] == 0)
			{
				SDL_Rect rect;
				rect.x = (x * size)+1;
				rect.y = (y * size)+1;
				rect.h = size-1;
				rect.w = size-1;
				SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
}
