#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

#include <iostream>
using namespace std;

RenderWindow::RenderWindow(const char* pTitle, int pWidth, int pHeight) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pWidth, pHeight, SDL_WINDOW_SHOWN);

	if ( window == NULL ){
		cout << "Window failed to init " << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* pFilepath){
	SDL_Texture* texture = NULL;

	texture = IMG_LoadTexture(renderer, pFilepath);
	if( texture == NULL ){
		cout << "Failed to load texture => " << SDL_GetError() << endl; 
	}

	return texture;
}

void RenderWindow::cleanUp(){
	SDL_DestroyWindow(window);
}

void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}

void RenderWindow::render(Entity& pEntity){
	SDL_Rect src;
	
	src.x = pEntity.getCurrentFrame().x;
	src.y = pEntity.getCurrentFrame().y;
	src.w = pEntity.getCurrentFrame().w;
	src.h = pEntity.getCurrentFrame().h;

	SDL_Rect dst;
	
	dst.y = pEntity.getPos().getY();
	dst.x = pEntity.getPos().getX();
	dst.w = pEntity.getCurrentFrame().w * 2;
	dst.h = pEntity.getCurrentFrame().h * 2;

	SDL_RenderCopy(renderer, pEntity.getTexture(), &src, &dst);
}
void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}