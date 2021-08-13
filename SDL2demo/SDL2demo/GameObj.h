#pragma once
#include <SDL.h>
class GameObj {
	public:
		double x, y, width, height;
		double speed,directionX,directionY;
		GameObj();
		void setPosition(double x, double y);
		void setSize(double width, double height);
		void renderProcess(SDL_Surface surface);
		void move(double deltaTime);
		void setDirection(double directionX, double directionY);
		void setSpeed(double speed);
		SDL_Rect getRect();
};