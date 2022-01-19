#include "mydefs.h"

void create_grid(Grid *grid, int y_cnt_a, int x_cnt) {
    int y_cnt_b = y_cnt_a + 2;
    grid->cell = (char*) malloc (y_cnt_b * x_cnt * sizeof(char));
    memset(grid->cell, 0, (y_cnt_b * x_cnt * sizeof(char)));
    grid->y_cnt = y_cnt_b;
    grid->x_cnt = x_cnt;
}


void fill_cells(Grid* grid, SDL_Renderer* renderer, int cell_size, Colours* colours, Tetromino_active* tetromino){
    
    int cells_cnt = grid->y_cnt * GRID_WIDTH;
    char* new_cells = (char*) malloc (sizeof(char)* cells_cnt);
    //char new_cells[cells_cnt];
    memcpy(new_cells, grid->cell, cells_cnt);

    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            
            int index = (tetromino->y + y) * GRID_WIDTH + (tetromino->x + x);
            if (tetromino->y + y < GRID_HEIGHT + 2 && x + tetromino->x >= 0 && x + tetromino->x < GRID_WIDTH){
                if (new_cells[index] == 0)
                {
                    new_cells[index] += tetromino->real_data[y * tetromino->side + x];
                }
            }
        }
    }

    for (int y = 0; y < (GRID_HEIGHT + 2); y++){
        for (int x = 0; x < GRID_WIDTH; x++)
        {

            int i = x + GRID_WIDTH * y;
			//if (new_cells[i + (2 * GRID_WIDTH)] != 0)
            if (new_cells[i] != 0)
			{
                char value = new_cells[i];
				SDL_Rect rect;

				rect.x = (x * cell_size)+1;
				rect.y = ((y - 2) * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value] / 2, colours->g[value] / 2, colours->b[value] / 2, 255);
	            SDL_RenderFillRect(renderer, &rect);

                rect.x = (x * cell_size)+3;
				rect.y = ((y - 2) * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, colours->r[value], colours->g[value], colours->b[value], 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
    free(new_cells);
}

void draw_ghost(Tetromino_active* tetromino, SDL_Renderer* renderer, Colours* colours){
    int cell_size = GAME_HEIGHT / GRID_HEIGHT;
    for (int y = 0; y < tetromino->side; y++){
        for (int x = 0; x < tetromino->side; x++){
            int i = x + tetromino->side * y;
			if (tetromino->real_data[i] != 0)
			{
                char value = tetromino->real_data[i];
				SDL_Rect rect;

                int x_grid= x + tetromino->x;
				int y_grid = y + tetromino->ghost - 2;

                rect.x = (x_grid * cell_size)+1;
				rect.y = (y_grid * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value] / 2, colours->g[value] / 2, colours->b[value] / 2, 255);
	            SDL_RenderFillRect(renderer, &rect);

                rect.x = (x_grid * cell_size)+3;
				rect.y = (y_grid * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
}

void fill_right(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect right;
        right.x = GAME_WIDTH;
        right.y = 0;
        right.w = GAME_WIDTH;
        right.h = GAME_HEIGHT;
        SDL_RenderFillRect(renderer, &right);
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

void copy_down(Grid* grid, int line){
    char * new_cells = (char*) malloc (sizeof(char) * GAME_WIDTH);
    for (int y = line; y > 0; y--){
        for (int x = 0; x < GRID_WIDTH; x++){
            int index = y * GRID_WIDTH + x;
            new_cells[x] = grid->cell[index];
            grid->cell[index + GRID_WIDTH] = new_cells[x];
        }
    }
    free(new_cells);
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