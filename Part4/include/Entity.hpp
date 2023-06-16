#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Entity{
	public:
		Entity( double x, double y, SDL_Texture* texture );
	private:
		double x, y
		SDL_Rect currentFrame;
		SDL_Texture* texture;
};