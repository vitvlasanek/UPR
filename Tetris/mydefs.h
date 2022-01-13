#include <stdlib.h>
#include <SDL2/SDL.h>

#ifndef MYDEFS_H
#define MYDEFS_H

#define GAME_WIDTH 300
#define GAME_HEIGHT 600
#define GRID_WIDTH 10	
#define GRID_HEIGHT 20

typedef struct Grid_
{
    int width;
    int height;
    int* cell; 
}Grid;

typedef struct Tetromino_
{
	int x;
	int y;
	int r;
	int g;
	int b;
}Tetromino;

void create_grid(Grid *grid, int height, int width);
void generate_grid(Grid* grid, SDL_Renderer* renderer, int size);

#endif
