#include "mydefs.h"

void show_score(SDL_Renderer* renderer, int score){
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    SDL_Color colour = {255, 255, 255};


    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "your score is: ", colour); 

    // now you can convert it into a texture
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 100;  //controls the rect's x coordinate 
    Message_rect.y = 100; // controls the rect's y coordinte
    Message_rect.w = 200; // controls the width of the rect
    Message_rect.h = 200; // controls the height of the rect

    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);
}