#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

#include <iostream>
using namespace std;

Entity::Entity( Vector2f pPos, SDL_Texture* pTexture ): pos(pPos), texture(pTexture){
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

SDL_Texture* Entity::getTexture(){
	return texture;
}
SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}