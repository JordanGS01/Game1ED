#pragma once
#include "Game.h"


//------->DE MOMENTO ESTA CLASE NO SE ESTA UTILIZANDO<-------\\

class GameObject {

public:
	//Constructor and destructor.
	GameObject(const char* spritesSheet, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	//The "x" and "y" pos are used to manage the position in the map of the object
	int xpos;
	int ypos;

	SDL_Texture* objText;
	SDL_Rect srcRect, destRect;

};