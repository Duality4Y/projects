#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char** args)
{
    SDL_Surface* screen = NULL;
    //start sdl
    SDL_Init(SDL_INIT_VIDEO);
    
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
    
    int systemX = videoInfo->current_w;
    int systemY = videoInfo->current_h;
    uint8_t bpp = videoInfo->vfmt->BitsPerPixel;
    
    screen = SDL_SetVideoMode(systemX, systemY, bpp, SDL_SWSURFACE);
    if(!screen)
    {
        printf("SDL_SetVideoMode failed\n");
        return 0;
    }
    
    SDL_Rect rect = {0,0,320,240};
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 200, 200, 0) );
    
    //update screen
    SDL_Flip(screen);
    //pause
    SDL_Delay(2000);
    //quit sdl
    SDL_Quit();
    
    return 0;
}
