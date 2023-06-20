#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

using namespace std;

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"


int main(int argc, char* args []){

	int screenWidth = 1080;
	int screenHeight = 480;
	int scale = 2;
	int posHeight32Pix = screenHeight - (32 * scale);

	bool gameRunning = true;
	bool debug = true;

	cout << "Hey" << endl;
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "ERROR SDL_INIT_VIDEO => " << SDL_GetError() << endl;
	if (!IMG_Init(IMG_INIT_PNG))
		cout << "ERROR IMG_INIT_PNG => " << SDL_GetError() << endl;

	RenderWindow window("Game", screenWidth, screenHeight);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	vector<Entity> platforms = {};

	// Filling floor with ground_grass_1.png
	for (int i = 0; i < screenWidth; i = i + 64)
	{
		debug ?	cout << i << endl : cout << "";
		Entity tempPlatform(Vector2f(i,posHeight32Pix),grassTexture);
		platforms.push_back(tempPlatform);
	}

	SDL_Event event;

	while(gameRunning){
		while( SDL_PollEvent(&event) ){
			if( event.type == SDL_QUIT ){
				gameRunning = false;
			}
			window.clear();

			for (Entity& p : platforms)
			{
				window.render(p);
			}

			window.display();
		}
	}

	window.cleanUp();

	SDL_Quit();

	return 0;
}