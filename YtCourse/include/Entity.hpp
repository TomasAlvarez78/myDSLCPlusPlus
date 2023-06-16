#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Entity{
	public:
		Entity( float pX, float pY, SDL_Texture* pTexture );
		float getX();
		float getY();
		SDL_Texture* getTexture();
		SDL_Rect getCurrentFrame();

	private:
		float x, y;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
};