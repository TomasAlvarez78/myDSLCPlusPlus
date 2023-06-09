#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

#include "RenderWindow.hpp"

int main(int argc, char* args []){
	cout << "Hey" << endl;
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "ERROR SDL_INIT_VIDEO => " << SDL_GetError() << endl;
	if (!IMG_Init(IMG_INIT_PNG))
		cout << "ERROR IMG_INIT_PNG => " << SDL_GetError() << endl;

	RenderWindow window("Game", 480, 480);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning){
		while( SDL_PollEvent(&event)){
			if( event.type == SDL_QUIT){
				gameRunning = false;
			}
			window.clear();
			window.render(grassTexture);
			window.display();
		}
	}

	window.cleanUp();

	SDL_Quit();

	return 0;
}

 