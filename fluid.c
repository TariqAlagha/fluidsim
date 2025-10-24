#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define COLOR_WHITE 0xffffffff
#define COLOR_BLUE 0x4287f5
#define COLOR_GRAY 0x1f1f1f1f
#define CELL_SIZE 20
#define COLUMNS SCREEN_WIDTH/CELL_SIZE
#define ROWS SCREEN_HEIGHT/CELL_SIZE
#define LINE_WIDTH 2



struct Cell
{
    int type;
    int fill_level;

};

void draw_grid(SDL_Surface* surface)
{

    for (int i=0; i<COLUMNS; i++)
    {
        SDL_Rect column = (SDL_Rect) {i*CELL_SIZE, 0, LINE_WIDTH, SCREEN_HEIGHT};
        SDL_FillRect(surface, &column, COLOR_GRAY);
    }
    for (int j=0; j<ROWS; j++)
    {
        SDL_Rect row = (SDL_Rect) {0, j*CELL_SIZE, SCREEN_WIDTH, LINE_WIDTH};
        SDL_FillRect(surface, &row, COLOR_GRAY);
    }
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Fluid Sim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    draw_grid(surface);

    SDL_Rect rectangle = (SDL_Rect){50,50,100,50};
    SDL_FillRect(surface, &rectangle, COLOR_WHITE);

    SDL_Rect blue_rectangle = (SDL_Rect){150,50,100,50};
    SDL_FillRect(surface, &blue_rectangle, COLOR_BLUE);
    
    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);

}
