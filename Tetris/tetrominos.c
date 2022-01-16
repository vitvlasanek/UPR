#include "mydefs.h"

void copy_random(Tetromino_active* tetromino, Tetromino_type* type, char rand_num){
    tetromino->side = type->side;

    // for (int i; i < (type->side * type->side); i++){
    //     tetromino->real_data[i] = type->tetromino[i];
    // }

    tetromino->real_data = type->tetromino;
    tetromino->pattern = type->tetromino;
    tetromino->rot = 0;
    tetromino->id = rand_num;
    tetromino->x = rand() % (GRID_WIDTH - type->side);
    tetromino->y = 2;    
}

void rotate_tetromino (Tetromino_active* tetromino){
    tetromino->rot++;
    int rot = tetromino->rot % 4;
    int s = tetromino->side;
    for (int y = 0; y < s; y++){
        for (int x = 0; x < s; x++){
            switch(rot){
                case 0:
                    tetromino->real_data[s * y + x] = tetromino->pattern[s * y + x];
                case 1:
                    tetromino->real_data[s * y + x] = tetromino->pattern[y + s * (s - 1 - x)];
                case 2:
                    tetromino->real_data[s * y + x] = tetromino->pattern[(s - 1 - x) + s * (s - 1 - y)];
                case 3:
                    tetromino->real_data[s * y + x] = tetromino->pattern[x * s + (s - 1 - y)];
            }
        }
    }
}

void move_right (Tetromino_active* tetromino){
    if (tetromino->x < (GAME_WIDTH - tetromino->side)){
        tetromino->x++;
    }
}

void move_left (Tetromino_active* tetromino){
    if (tetromino->x > 0){
        tetromino->x--;
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
