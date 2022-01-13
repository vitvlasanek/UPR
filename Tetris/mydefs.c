#include "mydefs.h"

void create_grid(Grid *grid, int height, int width) {
    grid->cell = (int*) malloc (height * width * sizeof(int));
    memset(grid->cell, 0, (height * width * sizeof(int)));
    grid->height = height;
    grid->width = width;
}

void generate_grid(Grid* grid, SDL_Renderer* renderer, int size){
    for (int y = 0; y < grid->height; y++){
        //printf("  r = \t%d\n",y);
        for (int x = 0; x < grid->width; x++)
        {
            //printf("%d",x);
            // předělat
            int index =   y * x;
			if (grid->cell[index] != 0)
			{
                printf("tisknu");
				SDL_Rect rect;
				rect.x = x * size;
				rect.y = y * size;
				rect.h = size;
				rect.w = size;
				SDL_SetRenderDrawColor(renderer, 255, 0, 50, 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
}
