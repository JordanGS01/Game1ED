#include "ContRecompensa.h"
#include "Textures.h"

ContRecompensa::ContRecompensa(const char* NumRecompensas, const char* Recompen, int xNum, int yNum, int xOro, int yOro) {

	mainTextureNum = Texture::LoadTexture(NumRecompensas);
	xposNum = xNum;
	yposNum = yNum;

	mainTextureOro = Texture::LoadTexture(Recompen);
	xposOro = xOro;
	yposOro = yOro;

	srcY = 0;
}

void ContRecompensa::update() {
	srcRectNum.h = 64;
	srcRectNum.w = 64;
	srcRectNum.x = 0;
	srcRectNum.y = srcY;

	destRectNum.h = 70;
	destRectNum.w = 70;
	destRectNum.x = xposNum;
	destRectNum.y = yposNum;

	srcRectOro.h = 64;
	srcRectOro.w = 64;
	srcRectOro.x = 0;
	srcRectOro.y = 0;

	destRectOro.h = 50;
	destRectOro.w = 50;
	destRectOro.x = xposOro;
	destRectOro.y = yposOro;

}

void ContRecompensa::render() {
	SDL_RenderCopy(Game::renderer, mainTextureNum, &srcRectNum, &destRectNum);
	SDL_RenderCopy(Game::renderer, mainTextureOro, &srcRectOro, &destRectOro);
}
