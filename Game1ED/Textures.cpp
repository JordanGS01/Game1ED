#include "Textures.h"
#include "SDL_ttf.h"
#include "Interfaz.h"
#include "GameOver.h"

//Creates and return a SDL_Texture object and return it.
//Recives the image direction.
SDL_Texture* Texture::LoadTexture(const char* texture) {

	SDL_Surface* auxsurface = IMG_Load(texture);
	SDL_Texture* textureElement = SDL_CreateTextureFromSurface(Game::renderer, auxsurface);
	SDL_FreeSurface(auxsurface);
	return textureElement;
}
SDL_Texture* Texture::LoadTexture_inter(const char* texture) {

	SDL_Surface* auxsurface = IMG_Load(texture);
	SDL_Texture* textureElement = SDL_CreateTextureFromSurface(interfaz::render, auxsurface);
	SDL_FreeSurface(auxsurface);
	return textureElement;
}
SDL_Texture* Texture::LoadText(const char* texto, SDL_Color color) {
	TTF_Font* font = TTF_OpenFont("FFF_Tusj.ttf", 24);
	SDL_Surface* mensaje = TTF_RenderText_Solid(font, texto, color);
	SDL_Texture* textureElement = SDL_CreateTextureFromSurface(interfaz::render, mensaje);
	SDL_FreeSurface(mensaje);
	return textureElement;
}

//Draws a texture inmediatly on the screen.
//Recives the texture to draw, the source rectangle and the destination rectangle of the image.
void Texture::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}
void Texture::draw_interfaz(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(interfaz::render, texture, &src, &dest);
}
void Texture::draw_text(SDL_Texture* texture, SDL_Rect dest) {
	SDL_RenderCopy(interfaz::render, texture, NULL, &dest);
}
void Texture::draw_textG(SDL_Texture* texture, SDL_Rect dest) {
	SDL_RenderCopy(GameOver::renderer1, texture, NULL, &dest);
}
SDL_Texture* Texture::LoadTextG(const char* texto, SDL_Color color) {
	TTF_Font* font = TTF_OpenFont("FFF_Tusj.ttf", 24);
	SDL_Surface* mensaje = TTF_RenderText_Solid(font, texto, color);
	SDL_Texture* textureElement = SDL_CreateTextureFromSurface(GameOver::renderer1, mensaje);
	SDL_FreeSurface(mensaje);
	return textureElement;
}