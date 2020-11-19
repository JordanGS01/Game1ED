#include "GameObj.h"
#include "Textures.h"

//------->DE MOMENTO ESTE CPP NO SE ESTA UTILIZANDO<-------\\

GameObject::GameObject(const char* spritesSheet, int x, int y) {

	objText = Texture::LoadTexture(spritesSheet);
	//Positions of the game object in the map.
	xpos = x;
	ypos = y;


}

void GameObject::update() {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 32;
	destRect.w = 32;
	destRect.x = xpos;
	destRect.y = ypos;

}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objText, &srcRect, &destRect);
}

