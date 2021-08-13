#include<SDL.h>
#include"GameObj.h"
#include<iostream>
#include"Pong.h"
SDL_Window* window;
SDL_Surface* surface;
Pong* pongGame;
int main(int arcg,char * args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Pong", 10, 20, Pong::screen_Width, Pong::screen_Height, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	pongGame = new Pong();
	pongGame->init();
	Uint64 now=SDL_GetPerformanceCounter();
	Uint64 last=0;
	double deltaTime=0;
	bool exit=1;
	SDL_Event event;
	while (exit==1) {
		while (SDL_PollEvent(&event)) {
			if (event.type==SDL_QUIT) {
				exit=0;
			}
		}
		const Uint8* keyBoardState = SDL_GetKeyboardState(NULL);
		if (keyBoardState[SDL_SCANCODE_ESCAPE] == true) {
			exit=0;
		}
		if (keyBoardState[SDL_SCANCODE_UP]==true)
		{
			pongGame->setPlayer2Direction(-1);
		}
		if (keyBoardState[SDL_SCANCODE_W] == true)
		{
			pongGame->setPlayerDirection(-1);
		}
		else if (keyBoardState[SDL_SCANCODE_DOWN] == true)
		{
			pongGame->setPlayer2Direction(1);
		}
		else if (keyBoardState[SDL_SCANCODE_S] == true)
		{
			pongGame->setPlayerDirection(1);
		}
		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (now - last) / (double)SDL_GetPerformanceFrequency();
		SDL_FillRect(surface, NULL, 0x000000000);
		pongGame->update(deltaTime);
		pongGame->renderProcess(*surface);
		
		SDL_UpdateWindowSurface(window);
		/*
		if (std::cin>>exit&&exit==0) {
			break;
		}
		*/
		
	}
	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);
	/*
	window = NULL;
	surface = NULL;
	*/
	return 0;
}