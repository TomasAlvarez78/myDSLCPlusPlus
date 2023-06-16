#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

#include <iostream>
using namespace std;

RenderWindow::RenderWindow(const char* title, int width, int height) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if ( window == NULL ){
		cout << "Window failed to init " << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp(){
	SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow::loadTexture(const char* filepath){
	SDL_Texture* texture = NULL;

	texture = IMG_LoadTexture(renderer, filepath);
	if( texture == NULL ){
		cout << "Failed to load texture => " << SDL_GetError() << endl; 
	}

	return texture;
}

void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}

void RenderWindow::render(SDL_Texture* texture){
	SDL_Rect src;
	
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;

	SDL_Rect dst;
	
	dst.x = 0;
	dst.y = (480 - 32);
	dst.w = 32;
	dst.h = 32;

	SDL_RenderCopy(renderer,texture, &src, &dst);
}
void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}