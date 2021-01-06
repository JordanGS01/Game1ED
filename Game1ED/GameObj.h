#pragma once
#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "Game.h"
#include "Grafo.h"
#include "Textures.h"


class GameObj { //: public GameObject{

public:
	int posL;
	int posR;
	int posD;
	int posU;

	GameObj();
	GameObj(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int xpos, int ypos);//Constructor
	~GameObj();//Destructor

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
	
	//To initializate the graph and player dependencies of this.
	void initGrafo(Grafo* GM);

	//Sounds that the player can make.
	Mix_Chunk* deadSound;
	Mix_Chunk* apearSound;
	
	Grafo* grafoMapa;
	Nodo* nodoActual;

	int initPosX;
	int initPosY;
	
	int xpos;
	int ypos;

	int life;

	int srcY;

	SDL_Rect srcRect, destRect;

	SDL_Texture* mainTexture;

	SDL_Texture* rightMovement;
	SDL_Texture* leftMovement;
	SDL_Texture* upMovement;
	SDL_Texture* downMovement;
};

#endif
