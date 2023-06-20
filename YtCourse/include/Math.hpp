#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

class Vector2f{
	private:
		float x, y;
	public:
		Vector2f():x(0.0f), y(0.0f){}
		Vector2f(float pX, float pY):x(pX), y(pY){}
		float getX() { return x; }
		float getY() { return y; }
		void print(){
			cout << x << " " << y << endl;
		}
};