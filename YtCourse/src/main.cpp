#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

int main(int argc, char* args []){

	int screenWidth = 1280;
	int screenHeight = 720;
	int scale = 2;
	int posHeight32Pix = screenHeight - (32 * scale);

	bool gameRunning = true;
	bool debug = true;

	if ( debug ){
		printf("Starting program");
		cout << endl;		
	}

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
		if ( debug ){
			printf("Generated grass at (%d, %d)", i, posHeight32Pix);
			cout << endl;	
		}
		Entity tempPlatform(Vector2f(i,posHeight32Pix),grassTexture);
		platforms.push_back(tempPlatform);
	}

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while(gameRunning){

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator  = utils::hireTimeInSeconds();

		while( accumulator >= timeStep){
			while( SDL_PollEvent(&event) ){
				if( event.type == SDL_QUIT ){
					gameRunning = false;
				}

			}
			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();

		for (Entity& p : platforms)
		{
			window.render(p);
		}

		window.display();
	}

	window.cleanUp();

	SDL_Quit();

	return 0;
}