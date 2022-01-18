#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifndef MYDEFS_H
#define MYDEFS_H

#define GAME_WIDTH 300
#define GAME_HEIGHT 600
#define GRID_WIDTH 10	
#define GRID_HEIGHT 20

//struct pro mřížku (počet polí v x, počet polí v y, buňky)
typedef struct Grid_ {
    int x_cnt;
    int y_cnt;
    char* cell; 
}Grid; 

typedef struct T_active {
    char id;
    unsigned char* real_data;
    char* pattern;
    char side;
	int x;
	int y;
	char rot;                                   //rotace <0;4>
    int safe_area;
    int bottom;
}Tetromino_active;

typedef struct T_type {
    unsigned char* tetromino;
    unsigned char side;
}Tetromino_type;

typedef struct Colours_ {
    unsigned char r[8];
    unsigned char g[8];
    unsigned char b[8];
}Colours;

void create_grid(Grid *grid, int height, int width);
void fill_cells(Grid* grid, SDL_Renderer* renderer, int size, Colours* colours, Tetromino_active* tetromino_active, Tetromino_type* typer);
void fill_right(SDL_Renderer* renderer);
void move_right (Tetromino_active* tetromino, Grid* grid);
void move_left (Tetromino_active* tetromino, Grid* grid);
void move_down (Tetromino_active* tetromino, Grid* grid);

void load_tetrominos(Tetromino_type* type, char i);
unsigned char rotate_indexcalc (Tetromino_active* tetromino, int x, int y);
void rotate_tetromino (Tetromino_active* tetromino, Grid* grid);



int pre_launch(SDL_Window* window, SDL_Renderer* renderer);
void set_colours(Colours* colours);
char choose_random();
void copy_random(Tetromino_active* tetromino, Tetromino_type* type, char rand_num);
void alloc_type_tetromino(Tetromino_type* type);

#endif