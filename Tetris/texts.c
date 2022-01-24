#include "mydefs.h"

int show_score(SDL_Renderer* renderer, TTF_Font* font, int score){
    char score_text[128];
    sprintf(score_text, "SCORE: %d", score);

    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (0.1);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, score_text);
    return 0;
}

int show_lines(SDL_Renderer* renderer, TTF_Font* font, int lines){
    char lines_text[128];
    sprintf(lines_text, "LINES: %d", lines);

    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (0.4);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, lines_text);
    return 0;
}

int show_next(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_HEIGHT - 4*(GAME_HEIGHT/GRID_HEIGHT);
    message_rect.w = GAME_WIDTH * (0.4);
    message_rect.h = GAME_WIDTH * (0.2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "NEXT: ");
    return 0;
}

int game_over(SDL_Renderer* renderer, TTF_Font* font, int score){
    char score_text[128];
    sprintf(score_text, "GAME OVER YOUR SCORE WAS: %d", score);

    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (0.5);
    message_rect.y = GAME_WIDTH * (0.2);
    message_rect.w = GAME_WIDTH * (1);
    message_rect.h = GAME_WIDTH * (0.2);;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, score_text);
    SDL_RenderClear(renderer);
    return 0;
}

int generate_text(SDL_Renderer* renderer, SDL_Rect* message_rect, TTF_Font* font, char text[]){
    SDL_Color colour = {255, 255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, colour);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    //SDL_QueryTexture(message, NULL, NULL, message_rect->w, message_rect->h);
    SDL_RenderCopy(renderer, message, NULL, message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
    return 0;
}

int show_controlls(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (0.8);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "CONTROLLS: ");
    return 0;
}

int show_up(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH;
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "^   - ROTATE");
    return 0;
}
int show_down(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (1.1);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "v  - FASTER");
    return 0;
}
int show_move(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (1.2);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "<,> - MOVE TETROMINO");
    return 0;
}
int show_drop(SDL_Renderer* renderer, TTF_Font* font){
    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (1.3);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, font, "SPACEBAR - DROP");
    return 0;
}