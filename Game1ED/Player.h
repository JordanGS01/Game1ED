#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#include "Game.h"


class Player{ //: public GameObject{

public:
	Player(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int xpos, int ypos);//Constructor
	~Player();//Destructor

	void render();
	void update();

	//This functions helps to manage the movement of the objects.
	void subXPos();
	void addXPos();

	void subYPos();
	void addYPos();

	int getXPos();
	int getYPos();

	//Function that hels to move across the sprites sheets.
	void addYsrc();

	//To change the texture throught different movements.
	void setRightToMain();
	void setLeftToMain();
	void setDownToMain();
	void setUpToMain();

	//Sounds that the player can make.
	Mix_Chunk* deadSound;
	Mix_Chunk* apearSound;
private:
	int life;

	int xpos;
	int ypos;

	int srcY;

	SDL_Rect srcRect, destRect;

	SDL_Texture* mainTexture;

	SDL_Texture* rightMovement;
	SDL_Texture* leftMovement;
	SDL_Texture* upMovement;
	SDL_Texture* downMovement;
};

#endif