#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "Math.hpp"

class Entity{
	public:
		Entity( Vector2f pPos, SDL_Texture* pTexture );
		Vector2f& getPos(){
			return pos;
		}
		SDL_Texture* getTexture();
		SDL_Rect getCurrentFrame();
	private:
		Vector2f pos;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
};