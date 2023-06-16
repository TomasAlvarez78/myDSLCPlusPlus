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
	cout << "Function display" << endl;
	SDL_RenderPresent(renderer);

}
void RenderWindow::render(SDL_Texture* texture){
	cout << "Function render" << endl;
	SDL_RenderCopy(renderer,texture, NULL, NULL);
}
void RenderWindow::clear(){
	cout << "Function clear" << endl;
	SDL_RenderClear(renderer);
}