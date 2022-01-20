#include "mydefs.h"

int show_score(SDL_Renderer* renderer, int score){
    SDL_Color colour = {255, 255, 255, 255};

    char score_text[128];
    sprintf(score_text, "SCORE: %d", score);

    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (1.1);
    message_rect.y = GAME_WIDTH * (0.1);
    message_rect.w = GAME_WIDTH * (0.8);
    message_rect.h = GAME_WIDTH * (0.3);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, score_text);
    return 0;
}

int game_over(SDL_Renderer* renderer, int score){
    SDL_Color colour = {255, 255, 255, 255};

    char score_text[128];
    sprintf(score_text, "GAME OVER\nYOUR SCORE WAS: %d", score);

    SDL_Rect message_rect;
    message_rect.x = GAME_WIDTH * (0.5);
    message_rect.y = GAME_WIDTH * (0.3);
    message_rect.w = GAME_WIDTH * (1.5);
    message_rect.h = GAME_WIDTH * (0.7);;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generate_text(renderer, &message_rect, score_text);
    return 0;
}

int generate_text(SDL_Renderer* renderer, SDL_Rect* message_rect, char text[]){
    TTF_Font* font = TTF_OpenFont("Roboto-Black.ttf", GAME_WIDTH/10);
    if (font == NULL) {
        fprintf(stderr, "Font not found\n");
        return 1;
    }
    SDL_Color colour = {255, 255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, colour);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    //SDL_QueryTexture(message, NULL, NULL, message_rect->w, message_rect->h);
    SDL_RenderCopy(renderer, message, NULL, message_rect);
    return 0;
}