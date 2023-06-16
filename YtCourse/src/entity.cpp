#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

#include <iostream>
using namespace std;

Entity::Entity( float pX, float pY, SDL_Texture* pTexture ): x(pX), y(pY), texture(pTexture){
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y;
}					

SDL_Texture* Entity::getTexture(){
	return texture;
}
SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}