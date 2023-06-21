#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"

using namespace std;

class RenderWindow{
	public:
		RenderWindow(const char* pTitle, int pWidth, int pHeight);
		SDL_Texture* loadTexture(const char* pFilepath);
		int getRefreshRate();
		void display();
		void render(Entity& pEntity);
		void clear();
		void cleanUp();

	private:	
		SDL_Window* window;
		SDL_Renderer* renderer;
};