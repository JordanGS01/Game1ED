#include "Lifes.h"
#include "Textures.h"

Life::Life(const char* LifePLayer, int x, int y) {

	mainTexture = Texture::LoadTexture(LifePLayer);
	xpos = x;
	ypos = y;

	srcY = 0;
}

void Life::update() {
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = srcY;

	destRect.h = 64;
	destRect.w = 64;
	destRect.x = xpos;
	destRect.y = ypos;

}

void Life::render() {
	SDL_RenderCopy(Game::renderer, mainTexture, &srcRect, &destRect);
}

void Life::life3() {
	srcRect.y = 0;
}

void Life::life2() {
	srcRect.y = 64;
}
void Life::life1() {
	srcRect.y = 128;
}
void Life::life0() {
	srcRect.y = 192;
}