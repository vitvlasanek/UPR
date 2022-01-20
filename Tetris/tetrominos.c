#include "mydefs.h"

void copy_random(Tetromino_active* tetromino, Tetromino_type* type){
    tetromino->side = type->side;
    //tetromino->real_data = (unsigned char*) malloc (sizeof(unsigned char) * tetromino->side);
    tetromino->real_data = type->tetromino;
    tetromino->x = rand() % (GRID_WIDTH - type->side);
    tetromino->ghost = tetromino->x;
    tetromino->y = 0;
    tetromino->status = true;    
}

void tetromino_place(Tetromino_active* tetromino, Grid* grid){
    
    tetromino->status = false;
    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            int index = (tetromino->y + y) * grid->x_cnt + (tetromino->x + x);
            if (tetromino->y + y < GRID_HEIGHT + 2 && x + tetromino->x >= 0 && x + tetromino->x < GRID_WIDTH){
                grid->cell[index] += tetromino->real_data[y * tetromino->side + x];
            }
        }
    }
}

void alloc_type_tetromino(Tetromino_type* type){
    type->tetromino = (unsigned char*) malloc (sizeof(unsigned char) * 16);
}

void load_tetrominos(Tetromino_type* type, unsigned char i){
    static unsigned char t1[16] = {
        0,0,0,0,
        1,1,1,1,
        0,0,0,0,
        0,0,0,0};
    static unsigned char t2[9] = {
        2, 0, 0,
        2, 2, 2,
        0, 0, 0};
    static unsigned char t3[9] = {
        0, 0, 3,
        3, 3, 3,
        0, 0, 0};
    static unsigned char t4[4] = {
        4,4,
        4,4};
    static unsigned char t5[9] = {
        0, 5, 5,
        5, 5, 0,
        0, 0, 0};
    static unsigned char t6[9] = {
        0, 6, 0,
        6, 6, 6,
        0, 0, 0};
    static unsigned char t7[9] = {
        7, 7, 0,
        0, 7, 7,
        0, 0, 0};
    static unsigned char t0[1] = {0};

    if (i == 0){
        type->tetromino = t1;
        type->side = 4;
    }
    else if (i == 1){ 
        type->tetromino = t2;
        type->side = 3;
    }
    else if (i == 2){
        type->tetromino = t3;
        type->side = 3;
 
    }
    else if (i == 3){
        type->tetromino = t4;
        type->side = 2;
 
    }
    else if (i == 4){
        type->tetromino = t5;
        type->side = 3; 
    }
    else if (i == 5){
        type->tetromino = t6;
        type->side = 3; 
    }
    else if (i == 6){
        type->tetromino = t7;
        type->side = 3; 
    } 
    else{
        type->tetromino = t0;
        type->side = 0;
    }   
}