#include "mydefs.h"

void create_grid(Grid *grid, int y_cnt_a, int x_cnt) {
    int y_cnt_b = y_cnt_a + 2;
    grid->cell = (unsigned char*) malloc (y_cnt_b * x_cnt * sizeof(unsigned char));
    memset(grid->cell, 0, (y_cnt_b * x_cnt * sizeof(unsigned char)));
    grid->y_cnt = y_cnt_b;
    grid->x_cnt = x_cnt;
}

void copy_down(Grid* grid, int line){
    unsigned char * new_cells = (unsigned char*) malloc (sizeof(unsigned char) * GAME_WIDTH);
    for (int y = line; y > 0; y--){
        for (int x = 0; x < GRID_WIDTH; x++){
            int index = y * GRID_WIDTH + x;
            new_cells[x] = grid->cell[index];
            grid->cell[index + GRID_WIDTH] = new_cells[x];
        }
    }
    free(new_cells);
}

int check_line(Grid* grid, int line){
    for (int x = 0; x < GRID_WIDTH; x++)
    {
        int index = (line + 1) * GRID_WIDTH + x;
        if (grid->cell[index] == 0){
            return 0;
        }
    }
    copy_down(grid, line);
    return 1;
}

int check_grid (Grid* grid){
    int cleared = 0;
    for (int y = GRID_HEIGHT ; y >= 0; y--){
        if (check_line(grid, y) != 0){
        cleared++;
        y++;
        }
    }
    return cleared;
}