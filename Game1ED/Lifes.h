#pragma once
#ifndef LIFES_H
#define LIFES_H
#include "Game.h"

class Life {

public:

	Life(const char* LifePlayer, int xpos, int ypos);

	void render();
	void update();

	void life3();
	void life2();
	void life1();
	void life0();
	int srcY;
private:
	int xpos;
	int ypos;


	SDL_Texture* mainTexture;

	SDL_Rect srcRect, destRect;

	SDL_Texture* corazones;
};

#endif
