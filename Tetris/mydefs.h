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

//struktura aktivního tetromina
typedef struct T_active {
    unsigned char* real_data;                   //pole s tvarem tetromina
    int ghost;
    bool status;
    unsigned char side;                         //délka nejdelší strany tetromina
	int x;                                      //pozice tetromina x
	int y;                                      //pozice tetromina y
}Tetromino_active;


//struktura pro vyorová tetromina
typedef struct T_type {
    unsigned char * tetromino;                   //pole s tvarem tetromina
    unsigned char side;                         //délka nejdelší strany tetromina
}Tetromino_type;

//struktura s barvami jednotlivých typů tetromin
typedef struct Colours_ {
    unsigned char r[8];                         //red RGB index tetromin <0;255>
    unsigned char g[8];                         //green RGB index tetromin <0;255>
    unsigned char b[8];                         //blue RGB index tetromin <0;255>
}Colours;



// graphics.c
int fill_cells(Grid* grid, SDL_Renderer* renderer, int size, Colours* colours, Tetromino_active* tetromino);
void fill_right(SDL_Renderer* renderer);
void draw_ghost(Tetromino_active* tetromino, SDL_Renderer* renderer, Colours* colours);
void draw_next(Tetromino_type* tetromino, SDL_Renderer* renderer, Colours* colours);
Colours* set_colours();
int draw_keys(SDL_Renderer* renderer, SDL_Surface * image);


// mydefs.c
int create_grid(Grid *grid);
int check_grid (Grid* grid);
int check_line(Grid* grid, int line);
int copy_down(Grid* grid, int line);
int free_all(Grid ** grid, Tetromino_active ** Tetromino_active, Colours ** colours, Tetromino_type * type);
int score_count(int cleared);

// texts.c
int generate_text(SDL_Renderer* renderer, SDL_Rect* message_rect, TTF_Font* font, char text[]);
int show_score(SDL_Renderer* renderer, TTF_Font* font, int score);
int game_over(SDL_Renderer* renderer, TTF_Font* font);
int game_over_score(SDL_Renderer* renderer, TTF_Font* font, int score);
int show_next(SDL_Renderer* renderer, TTF_Font* font);
int show_lines(SDL_Renderer* renderer, TTF_Font* font, int lines);
int show_controls(SDL_Renderer* renderer, TTF_Font* font);
int game_over_text(SDL_Renderer* renderer, TTF_Font* font);


// tetrominos.c
void copy_random(Tetromino_active* tetromino, Tetromino_type* type);
void tetromino_place(Tetromino_active* tetromino, Grid* grid);
Tetromino_type * alloc_type_tetromino();
void load_tetrominos(Tetromino_type* type, unsigned char i);
Tetromino_active * alloc_tetromino_active();

// movements.c
void ghost_pos(Tetromino_active* tetromino, Grid* grid);
void move_right (Tetromino_active* tetromino, Grid* grid);
void move_left (Tetromino_active* tetromino, Grid* grid);
int move_down (Tetromino_active* tetromino, Grid* grid);
void rotate_tetromino (Tetromino_active* tetromino, Grid* grid);

#endif