#include"Pong.h"
void Pong::init() {
	player = new GameObj();
	player2 = new GameObj();
	ball = new Ball();
	reset();

};
void Pong::renderProcess(SDL_Surface surface) {

	player->GameObj::renderProcess(surface);
	player2->GameObj::renderProcess(surface);
	ball->GameObj::renderProcess(surface);
}
void Pong::setPlayerDirection(double direction) {
	player->setDirection(0, direction);
}
void Pong::setPlayer2Direction(double direction) {
	player2->setDirection(0, direction);
}
void Pong::update(double deltaTime) {
	player->move(deltaTime);
	player2->move(deltaTime);
	ball->move(deltaTime);
	impactCollisionDetect();
	checkReset();
}
void Ball::move(double deltaTime) {
	GameObj::move(deltaTime);
	if (y <= 0 && directionY <= 0) {
		directionY *= -1;
	}
	if (y+height >= Pong::screen_Height&&directionY>=0) {
		directionY *= -1;
	}

}
void Pong::impactCollisionDetect() {
	SDL_Rect playerRectangle = player->getRect();
	SDL_Rect player2Rectangle = player2->getRect();
	SDL_Rect ballRectangle = ball->getRect();
	if(SDL_HasIntersection(&playerRectangle , &ballRectangle)) {
		if (ball->directionX < 0) {
			ball->directionX *= -1;
			return;
		}
	}
	if (SDL_HasIntersection(&player2Rectangle, &ballRectangle)) {
		if (ball->directionX > 0) {
			ball->directionX *= -1;
			return;
		}
	}
}
void Pong::checkReset() {
	if (ball->x <= 0) {
		reset();
	}
	if (ball->x >= screen_Width) {
		reset();
	}
}
void Pong::reset() {
	double pSize_X = 10;
	double pSize_Y = 100;
	double pPos_Y = (screen_Height - pSize_Y) / 2.0f;
	player->setSize(pSize_X, pSize_Y);
	player->setPosition(0, pPos_Y);
	player->setSpeed(200);
	player2->setSize(pSize_X, pSize_Y);
	player2->setPosition(screen_Width - pSize_X, pPos_Y);
	player2->setSpeed(200);
	ball->setPosition(screen_Width / 2, screen_Height / 2);
	ball->setSize(10, 10);
	ball->setSpeed(220);
	ball->setDirection(-1, 1);
}
