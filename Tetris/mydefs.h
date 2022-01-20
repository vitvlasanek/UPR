#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifndef MYDEFS_H
#define MYDEFS_H

#define GRID_HEIGHT 20
#define GRID_WIDTH 10	
#define GAME_HEIGHT 600
#define GAME_WIDTH 300

#define BACKGROUND_R 48
#define BACKGROUND_G 48
#define BACKGROUND_B 48

//struct pro mřížku (počet polí v x, počet polí v y, buňky)
typedef struct Grid_ {
    int x_cnt;
    int y_cnt;
    unsigned char* cell; 
}Grid; 

typedef struct T_active {
    unsigned char* real_data;                            //pole s tvarem tetromina
    int ghost;
    bool status;
    unsigned char side;                                  //délka nejdelší strany tetromina
	int x;                                      //pozice tetromina x
	int y;                                      //pozice tetromina y
}Tetromino_active;

typedef struct T_type {
    unsigned char* tetromino;                   //pole s tvarem tetromina
    unsigned char side;                         //délka nejdelší strany tetromina
}Tetromino_type;

typedef struct Colours_ {
    unsigned char r[8];                         //red RGB index tetromin <0;255>
    unsigned char g[8];                         //green RGB index tetromin <0;255>
    unsigned char b[8];                         //blue RGB index tetromin <0;255>
}Colours;

void create_grid(Grid *grid, int height, int width);
void fill_cells(Grid* grid, SDL_Renderer* renderer, int size, Colours* colours, Tetromino_active* tetromino);
void fill_right(SDL_Renderer* renderer);
void move_right (Tetromino_active* tetromino, Grid* grid);
void move_left (Tetromino_active* tetromino, Grid* grid);
void move_down (Tetromino_active* tetromino, Grid* grid);

void load_tetrominos(Tetromino_type* type, unsigned char i);
void rotate_tetromino (Tetromino_active* tetromino, Grid* grid);



int pre_launch(SDL_Window* window, SDL_Renderer* renderer);
void set_colours(Colours* colours);
unsigned char choose_random();
void copy_random(Tetromino_active* tetromino, Tetromino_type* type);
void alloc_type_tetromino(Tetromino_type* type);
void tetromino_place(Tetromino_active* tetromino, Grid* grid);
void draw_ghost(Tetromino_active* tetromino, SDL_Renderer* renderer, Colours* colours);
void ghost_pos(Tetromino_active* tetromino, Grid* grid);
int check_grid (Grid* grid);
int check_line(Grid* grid, int line);
void copy_down(Grid* grid, int line);
int show_score(SDL_Renderer* renderer, int score);
int game_over(SDL_Renderer* renderer, int score);
int generate_text(SDL_Renderer* renderer, SDL_Rect* message_rect, char text[]);


#endif