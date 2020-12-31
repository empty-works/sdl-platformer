#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../include/RenderWindow.hpp"

int main(int argc, char* argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "Error: SDL_Init has failed." << SDL_GetError() << std::endl;
	}

	if(!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "Error: IMG_Init has failed." << SDL_GetError() << std::endl;
	}

	RenderWindow window("GAME v1.0", 1280, 720);

	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
