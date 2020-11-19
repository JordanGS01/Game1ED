#include "Textures.h"

//Creates and return a SDL_Texture object and return it.
//Recives the image direction.
SDL_Texture* Texture::LoadTexture(const char* texture) {

	SDL_Surface* auxsurface = IMG_Load(texture);
	SDL_Texture* textureElement = SDL_CreateTextureFromSurface(Game::renderer, auxsurface);
	SDL_FreeSurface(auxsurface);
	return textureElement;
}

//Draws a texture inmediatly on the screen.
//Recives the texture to draw, the source rectangle and the destination rectangle of the image.
void Texture::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}