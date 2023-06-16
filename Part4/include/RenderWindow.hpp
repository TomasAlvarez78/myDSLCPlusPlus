#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class RenderWindow{
	public:
		RenderWindow(const char* title, int width, int height);
		SDL_Texture* loadTexture(const char* filepath);
		void display();
		void render(SDL_Texture* texture);
		void clear();
		void cleanUp();

	private:	
		SDL_Window* window;
		SDL_Renderer* renderer;
};