#include "mydefs.h"

void rotate_tetromino (Tetromino_active* tetromino, Grid* grid){
    unsigned char s = tetromino->side;
    int tetromino_size = s * s;                                             //velikost pole (strana^2)
    unsigned char tetromino_rotated[tetromino_size];                                                             //nové pole s rotovaným tetrominem
    int wallbang = 0;                                                                                     //odraz od zdi (o kolik)
    int bounce = 0;    
    int ghost_bounce = 0;                                                                                     // odraz od spod
    if(tetromino->x < 0){
        wallbang = - tetromino->x;
    }
    else if(tetromino->x > (GRID_WIDTH - s - 1)){
        wallbang = GRID_WIDTH - tetromino->x  - s;
    }
    else{
        wallbang = 0;
    }
    if (tetromino->y > (GRID_HEIGHT - s + 1)){
        bounce = tetromino->y + s - GRID_HEIGHT - 2;
    }
    
    for (int y = 0; y < s; y++){
        for (int x = 0; x < s; x++){

            unsigned char gr_val = grid->cell[(x + tetromino->x + wallbang) + (y + tetromino->y - bounce) * GRID_WIDTH];     //index v poli odpovídající poloze tetromina
            int index = s * y + x;   
            tetromino_rotated[index] = tetromino->real_data[y + s * (s - 1 - x)];

            if (tetromino_rotated[index] != 0 && gr_val != 0) {                                          //konrola 
                return;
            }     
        }
    }
    tetromino->x +=  wallbang;
    tetromino->y -= bounce;
    memcpy(tetromino->real_data, tetromino_rotated, tetromino_size);
}

void move_right (Tetromino_active* tetromino, Grid* grid){

    for (int y = 0; y < tetromino->side; y++){
        int index = y * tetromino->side  + GRID_WIDTH - tetromino->x - 1;
        if(tetromino->x > (GRID_WIDTH - tetromino->side - 1)){
            if (tetromino->real_data[index] != 0){
                return;
            }
        }
        else{
            for (int x = 0; x < tetromino->side; x++){
                unsigned char t_val = tetromino->real_data[(y * tetromino->side + x)];
                if (index < ((GRID_HEIGHT + 2) * GRID_WIDTH - 1)){
                    unsigned char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y) * GRID_WIDTH + 1];
                    if (t_val != 0 && gr_val != 0){
                        return;
                    }
                }
            }
        }
    }
    tetromino->x++; 
}

void move_left (Tetromino_active* tetromino, Grid* grid){
    for (int y = 0; y < tetromino->side; y++){
        int index = y * tetromino->side - tetromino->x;
        if(tetromino->x <= 0){
            if (tetromino->real_data[index] != 0){
                return;
            }
        }   
        else{
            for (int x = 0; x < tetromino->side; x++){
                unsigned char t_val = tetromino->real_data[(y * tetromino->side + x)];
                    if (index < (GRID_HEIGHT + 1) * GRID_WIDTH){
                    unsigned char gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->y) * GRID_WIDTH - 1];
                    if (t_val != 0 && gr_val != 0){
                        return;
                    }
                }
            }
        }
    } 
    tetromino->x--;  
}

int move_down (Tetromino_active* tetromino, Grid* grid){
    for (int x = 0; x < tetromino->side; x++){
        unsigned char index= ((GRID_HEIGHT - tetromino->y + 1) * tetromino->side + x);
        if (tetromino->y >= (GRID_HEIGHT - tetromino->side + 2) && tetromino->real_data[index] != 0){           //kontrola spodní pozice
            if (tetromino->y > 0){
            tetromino_place(tetromino, grid);
            return 0;
            }
            else{
            fprintf(stderr, "Game over!");
                return 1;
            }
            
        }
        else{
            for (int y = 0; y < tetromino->side; y++){                              //kontrola překážek
                unsigned char t_val = tetromino->real_data[(y * tetromino->side + x)];
                int index = (x + tetromino->x) + (y + tetromino->y + 1) * GRID_WIDTH;
                if (index < ((GRID_HEIGHT + 2) * GRID_WIDTH - 1)){
                unsigned char gr_val = grid->cell[index];
                    if (t_val != 0 && gr_val != 0){
                        if (tetromino->y > 0){
                            tetromino_place(tetromino, grid);
                            return 0;
                            }
                        else{
                            return 1;
                        }
                    }
                }
            }
        }
    }
    tetromino->y++;
    return 0;  
}

void ghost_pos(Tetromino_active* tetromino, Grid* grid){
    tetromino->ghost = tetromino->y;
    for (int i = 0; i < GRID_HEIGHT; i++){
        for (int x = 0; x < tetromino->side; x++){
            unsigned char index = ((GRID_HEIGHT - tetromino->ghost + 1) * tetromino->side + x);
            if (tetromino->ghost >= (GRID_HEIGHT - tetromino->side + 2) && tetromino->real_data[index] != 0){           //kontrola spodní pozice
                
                return;
            }
            else{
                for (int y = 0; y < tetromino->side ; y++){                                                              //kontrola překážek
                    if (y + tetromino->ghost - 1 < GRID_HEIGHT && x + tetromino->x >= 0 && x + tetromino->x < GRID_WIDTH){
                        int t_val = tetromino->real_data[(y * tetromino->side + x)];
                        int gr_val = grid->cell[(x + tetromino->x) + (y + tetromino->ghost + 1) * GRID_WIDTH];
                        if (t_val != 0 && gr_val != 0){
                            return;
                        }
                    }
                }
            }
        }
    tetromino->ghost++;
    } 
}
