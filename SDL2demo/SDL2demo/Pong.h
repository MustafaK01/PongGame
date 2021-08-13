#pragma once
#include"GameObj.h"
class Ball : public GameObj {
public:
	void move(double deltaTime);
};
class Pong {
	public:
		static const int screen_Width = 800;
		static const int screen_Height = 400;
		GameObj* player;
		GameObj* player2;
		Ball* ball;
		void init();
		void renderProcess(SDL_Surface surface);
		void setPlayerDirection(double direction);
		void setPlayer2Direction(double direction);
		void update(double deltaTime);
		void impactCollisionDetect();
		void reset();
		void checkReset();
};
