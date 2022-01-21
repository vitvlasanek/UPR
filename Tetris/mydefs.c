#include "mydefs.h"

int create_grid(Grid *grid) {
    int y_cnt_b = GRID_HEIGHT + 2;
    grid->cell = (unsigned char*) malloc (y_cnt_b * GRID_WIDTH * sizeof(char));
    if (!grid->cell){
        return 1;
    }
    memset(grid->cell, 0, (y_cnt_b * GRID_WIDTH * sizeof(char)));
    grid->y_cnt = y_cnt_b;
    grid->x_cnt = GRID_WIDTH;
    return 0;
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
        if (check_line(grid, y)){
            cleared++;
            y++;
        }
    }
    return cleared;
}