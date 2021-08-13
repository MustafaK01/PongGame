#include"GameObj.h"
#include"Pong.h"
GameObj::GameObj() {
	x = 0;
	y = 0;
	directionX = 0;
	directionY = 0;
	height = 0;
	width = 0;
	speed = 0;
}
void GameObj::setPosition(double x, double y) {
	this->x = x;
	this->y = y;
}
void GameObj::setSize(double width, double height) {
	this->width = width;
	this->height=height;
}
void GameObj::renderProcess(SDL_Surface surface) {
	SDL_Rect rectangle;
	rectangle.x = this->x;
	rectangle.y = this->y;
	rectangle.w = this->width;
	rectangle.h = this->height;
	Uint32 color = SDL_MapRGB(surface.format, 255, 255, 255);
	SDL_FillRect(&surface, &rectangle, color);
}
void GameObj::move(double deltaTime) {
	x += directionX * speed*deltaTime;
	y += directionY * speed*deltaTime;
	if (y < 0) {
		y = 0;
	}
	if (y + height > Pong::screen_Height) {
		y = Pong::screen_Height - height;
	}
}
void GameObj::setDirection(double directionX, double directionY) {
	this->directionX = directionX;
	this -> directionY = directionY;
}

void GameObj::setSpeed(double speed){
	this->speed = speed;
}
SDL_Rect GameObj::getRect() {
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = width;
	rectangle.h = height;
	return rectangle;
}
