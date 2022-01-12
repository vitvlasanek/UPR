#include "mydefs.h"

void choose_random(Tetromino allrots[], int* pivot, Grid* map){
    *pivot = 2;                             //
    int rand_num = rand() % 7;              //náhodná veličina určuje typ % počet typů
    int centre = map->width / 2;
    switch (rand_num)
    {
    case 0:
        spawn_tetromino (allrots, centre, -2);
        break;
    
    default:
        break;
    }
}

void spawn_tetromino(Tetromino allrots[], int x, int y);
