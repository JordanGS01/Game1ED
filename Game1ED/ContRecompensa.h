#pragma once
#ifndef CONTRECOMPENSA_H
#define CONTRECOMPENSA_H
#include "Game.h"

class ContRecompensa {

public:

	ContRecompensa(const char* CantRecompensa, const char* Recomp, int xposNum, int yposNum, int xposOro, int yposOro);

	int srcY;
	void render();
	void update();


private:
	int xposNum;
	int yposNum;
	int xposOro;
	int yposOro;

	SDL_Texture* mainTextureNum;
	SDL_Texture* mainTextureOro;

	SDL_Rect srcRectNum, destRectNum;
	SDL_Rect srcRectOro, destRectOro;

};

#endif
