#include "Player.h"
#include "Textures.h"

Player::Player(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int x, int y) {
	
	rightMovement = Texture::LoadTexture(rightSheet);
	leftMovement = Texture::LoadTexture(leftSheet);
	upMovement = Texture::LoadTexture(upSheet);
	downMovement = Texture::LoadTexture(downSheet);

	mainTexture = rightMovement;

	life = 3;

	xpos = x;
	ypos = y;

	srcY = 0;
}

//*******METHODS*******
void Player::update() {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = srcY;

	destRect.h = 32;
	destRect.w = 32;
	destRect.x = xpos;
	destRect.y = ypos;

}

void Player::render() {
	SDL_RenderCopy(Game::renderer, mainTexture, &srcRect, &destRect);
}

//This functions helps to manage the movement of the objects.

void Player::subXPos() {//Move left (sub to X coordinate)
	xpos = xpos - 4;
}
void Player::addXPos() {//Move right (add to X coordinate)
	xpos = xpos + 4;
};

void Player::subYPos() {//Move up (sub to Y coordinate)
	ypos = ypos - 4;
};

void Player::addYPos() {//Move down (add to Y coordinate)
	ypos = ypos + 4;
};


void Player::addYsrc() {//This helps to move throught the source sprite sheet to print the different movements.
	if (srcRect.y >= 64) {
		srcY = 0;
	}

	else {
		srcY += 32;
	}
};


//Chagers of main texture.
void Player::setRightToMain() { mainTexture = rightMovement; }

void Player::setLeftToMain() { mainTexture = leftMovement; }

void Player::setDownToMain() { mainTexture = downMovement; }

void Player::setUpToMain() { mainTexture = upMovement; }

int Player::getXPos() { return xpos; };
int Player::getYPos() { return ypos; };
