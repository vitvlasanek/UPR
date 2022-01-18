#include "mydefs.h"

void create_grid(Grid *grid, int y_cnt_a, int x_cnt) {
    int y_cnt_b = y_cnt_a + 2;
    grid->cell = (char*) malloc (y_cnt_b * x_cnt * sizeof(char));
    memset(grid->cell, 0, (y_cnt_b * x_cnt * sizeof(char)));
    grid->y_cnt = y_cnt_b;
    grid->x_cnt = x_cnt;
}


void fill_cells(Grid* grid, SDL_Renderer* renderer, int cell_size, Colours* colours, Tetromino_active* tetromino_active, Tetromino_type* type){
    
    int cells_cnt = grid->y_cnt * grid->x_cnt;
    //char* new_cells = (char*) malloc (sizeof(char)* cells_cnt);
    char new_cells[cells_cnt];
    memcpy(new_cells, grid->cell, cells_cnt);

    // tetromino_active->y = 5;

    for (int y = 0; y < tetromino_active->side; y++){
        for (int x = 0; x < tetromino_active->side; x++){
            
            int index = (tetromino_active->y + y) * grid->x_cnt + (tetromino_active->x + x);
            new_cells[index] = new_cells[index] + tetromino_active->real_data[y * tetromino_active->side + x];
        }
    }

    // for (int y = 0; y < tetromino_active->side; y++){
    //     for (int x = 0; x < tetromino_active->side; x++){           
    //         int index = (tetromino_active->y + y) * grid->x_cnt + (tetromino_active->x + x);
    //         new_cells[index] = rotate_tetromino(type, tetromino_active->rot, x ,y);
    //     }
    // }


    for (int y = 0; y < (grid->y_cnt + 2); y++){
        for (int x = 0; x < grid->x_cnt; x++)
        {

            int i = x + grid->x_cnt * y;
			if (new_cells[i + (2 * grid->x_cnt)] != 0)
			{
                char value = new_cells[i + (2 * grid->x_cnt)];
				SDL_Rect rect;
				rect.x = (x * cell_size)+1;
				rect.y = (y * cell_size)+1;
				rect.h = cell_size-1;
				rect.w = cell_size-1;
				SDL_SetRenderDrawColor(renderer, colours->r[value]/4, colours->g[value]/4, colours->b[value]/4, 255);
	            SDL_RenderFillRect(renderer, &rect);
                rect.x = (x * cell_size)+3;
				rect.y = (y * cell_size)+3;
				rect.h = cell_size-5;
				rect.w = cell_size-5;
				SDL_SetRenderDrawColor(renderer, colours->r[value], colours->g[value], colours->b[value], 255);
	            SDL_RenderFillRect(renderer, &rect);
			}
        }
    }
    //free(new_cells);
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