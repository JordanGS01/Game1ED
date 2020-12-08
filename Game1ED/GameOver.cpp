#include "GameOver.h"
#include "Textures.h"
#include "SDL_ttf.h"

SDL_Renderer* GameOver::renderer1 = nullptr;
SDL_Event GameOver::cerrado;
void GameOver::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		ventana = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer1 = SDL_CreateRenderer(ventana, -1, 0);
		isRunning = true;
	}
	else {//If there's some problem, we didn't initialize anything.
		isRunning = false;
	}
	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
}
void GameOver::dibujar() {
	SDL_RenderClear(renderer1);

	SDL_Color rojo = { 255, 0,0 };
	SDL_Color blanco = { 255,255,255 };


	titulo.x = 125;
	titulo.y = 100;
	titulo.w = 500;
	titulo.h = 100;

	tecla.x = 150;
	tecla.y = 400;
	tecla.w = 300;
	tecla.h = 50;

	SDL_Texture* tit = Texture::LoadTextG("Game Over", rojo);
	SDL_Texture* teclas = Texture::LoadTextG("Presione X para Salir", blanco);

	Texture::draw_textG(tit, titulo);
	Texture::draw_textG(teclas, tecla);

	SDL_RenderPresent(renderer1);
}
void GameOver::cerrar() {
	SDL_PollEvent(&cerrado);
	switch (cerrado.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (cerrado.key.keysym.sym) {
		case SDLK_x:
			isRunning = false;
			break;
		}
	}
}
void GameOver::clean() {
	SDL_DestroyRenderer(renderer1);
	SDL_DestroyWindow(ventana);
}
