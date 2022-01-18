#include "mydefs.h"

void copy_random(Tetromino_active* tetromino, Tetromino_type* type, char rand_num){
    tetromino->side = type->side;

    // for (int i; i < (type->side * type->side); i++){
    //     tetromino->real_data[i] = type->tetromino[i];
    // }
    //tetromino->real_data = (unsigned char*) malloc (sizeof(char) * tetromino->side);
    tetromino->real_data = type->tetromino;
    tetromino->pattern = type->tetromino;
    tetromino->id = rand_num;
    tetromino->rot = 0;
    tetromino->x = rand() % (GRID_WIDTH - type->side);
    tetromino->y = 2;    
}


void rotate_tetromino (Tetromino_active* tetromino, Grid* grid){
    int tetromino_size = tetromino->side * tetromino->side;                                     //velikost pole (strana^2)
    unsigned char tetromino_rotated[tetromino_size];                                            //nové pole s rotovaným tetrominem

    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){

            char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y) * GRID_WIDTH];     //index v poli odpovídající poloze tetromina
            int index = tetromino->side * y + x;   
            tetromino_rotated[index] = rotate_indexcalc(tetromino ,x ,y);

            if (tetromino_rotated[index] != 0 && gr_val != 0) {                                 //konrola 
                return;
            }     
        }
    }

    memcpy(tetromino->real_data, tetromino_rotated, tetromino_size);
}


unsigned char rotate_indexcalc (Tetromino_active* tetromino, int x, int y){
    int s = tetromino->side;
    return tetromino->real_data[y + s * (s - 1 - x)];
    //int rotation = tetromino->rot % 4;
    // switch(1){
    //     case 0:
    //         printf ("%d\t\t", tetromino->real_data[s * y + x]);
    //         return tetromino->real_data[s * y + x];
    //     case 1:
    //         printf ("%d\t\t", tetromino->real_data[y + s * (s - 1 - x)]);
    //         return tetromino->real_data[y + s * (s - 1 - x)];
    //     case 2:
    //         printf ("%d\t\t", tetromino->real_data[(s - 1 - x) + s * (s - 1 - y)]);
    //         return tetromino->real_data[(s - 1 - x) + s * (s - 1 - y)];
    //     case 3:
    //         printf ("%d\t\t", tetromino->real_data[x * s + (s - 1 - y)]);
    //         return tetromino->real_data[x * s + (s - 1 - y)];
    //     default:
    //         return tetromino->real_data[s * y + x];
    // }
}

void move_right (Tetromino_active* tetromino, Grid* grid){
    if (tetromino->x == (GRID_WIDTH - tetromino->side)){
        return;
    }

    else{
        for (int y = 0; y < tetromino->side; y++){
            for (int x = 0; x < tetromino->side; x++){
                char t_val = tetromino->real_data[(y * tetromino->side + x)];
                char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y) * GRID_WIDTH + 1];
                if (t_val != 0 && gr_val != 0){
                    return;
                }
            }
        }
        tetromino->x++; 
    }
}

void move_left (Tetromino_active* tetromino, Grid* grid){
    if (tetromino->x == 0){
        return;
    }
    else
    {
        for (int y = 0; y < tetromino->side; y++){
            for (int x = 0; x < tetromino->side; x++){
                char t_val = tetromino->real_data[(y * tetromino->side + x)];
                char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y) * GRID_WIDTH - 1];
                if (t_val != 0 && gr_val != 0){
                    return;
                }
            }
        }
        tetromino->x--;  
    }
}

void move_down (Tetromino_active* tetromino, Grid* grid){
    if (tetromino->y == GRID_HEIGHT + 2 - tetromino->side){
        return;
    }
    else
    {
        for (int y = 0; y < tetromino->side; y++){
            for (int x = 0; x < tetromino->side; x++){
                char t_val = tetromino->real_data[(y * tetromino->side + x)];
                char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y + 1) * GRID_WIDTH];
                if (t_val != 0 && gr_val != 0){
                    return;
                }
            }
        }
    tetromino->y++;  
    }
}


void alloc_type_tetromino(Tetromino_type* type){
    type->tetromino = (char*) malloc (sizeof(char) * 16);
}

void load_tetrominos(Tetromino_type* type, char i){
    static unsigned char t1[] = {
        0,0,0,0,
        1,1,1,1,
        0,0,0,0,
        0,0,0,0};
    static unsigned char t2[] = {
        2, 0, 0,
        2, 2, 2,
        0, 0, 0};
    static unsigned char t3[] = {
        0, 0, 3,
        3, 3, 3,
        0, 0, 0};
    static unsigned char t4[] = {
        4,4,
        4,4};
    static unsigned char t5[] = {
        0, 5, 5,
        5, 5, 0,
        0, 0, 0};
    static unsigned char t6[] = {
        0, 6, 0,
        6, 6, 6,
        0, 0, 0};
    static unsigned char t7[] = {
        7, 7, 0,
        0, 7, 7,
        0, 0, 0};
    static unsigned char t0[] = {0};

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