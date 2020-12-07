#include "GameObj.h"
#include "Textures.h"

GameObj::GameObj(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int x, int y) {

	rightMovement = Texture::LoadTexture(rightSheet);
	leftMovement = Texture::LoadTexture(leftSheet);
	upMovement = Texture::LoadTexture(upSheet);
	downMovement = Texture::LoadTexture(downSheet);

	mainTexture = rightMovement;

	life = 3;

	xpos = x;
	ypos = y;

	initPosX = x;
	initPosY = y;

	srcY = 0;
}

void GameObj::initGrafo(Grafo* GM) {
	grafoMapa = GM;
	nodoActual = grafoMapa->buscaNodo(xpos / 32, ypos / 32);
}

//*******METHODS*******
void GameObj::update() {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = srcY;

	destRect.h = 32;
	destRect.w = 32;
	destRect.x = xpos;
	destRect.y = ypos;

}

void GameObj::render() {
	SDL_RenderCopy(Game::renderer, mainTexture, &srcRect, &destRect);
}
//This functions helps to manage the movement of the objects.
void GameObj::subXPos() {//Move left (sub to X coordinate)
	xpos = xpos - 4;
}
void GameObj::addXPos() {//Move right (add to X coordinate)
	xpos = xpos + 4;
};

void GameObj::subYPos() {//Move up (sub to Y coordinate)
	ypos = ypos - 4;
};

void GameObj::addYPos() {//Move down (add to Y coordinate)
	ypos = ypos + 4;
};


void GameObj::addYsrc() {//This helps to move throught the source sprite sheet to print the different movements.
	if (srcRect.y >= 64) {
		srcY = 0;
	}

	else {
		srcY += 32;
	}
};




//Chagers of main texture.
void GameObj::setRightToMain() { mainTexture = rightMovement; }

void GameObj::setLeftToMain() { mainTexture = leftMovement; }

void GameObj::setDownToMain() { mainTexture = downMovement; }

void GameObj::setUpToMain() { mainTexture = upMovement; }

int GameObj::getXPos() { return xpos; };
int GameObj::getYPos() { return ypos; };