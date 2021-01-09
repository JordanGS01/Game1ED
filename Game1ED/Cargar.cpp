#include "Cargar.h"
#include "SDL_ttf.h"
#include "Textures.h"
using namespace std;


SDL_Renderer* Cargar::render = nullptr;
SDL_Event Cargar::evento;

void Cargar::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		ventana = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		render = SDL_CreateRenderer(ventana, -1, 0);

		isRunning = true;
	}
	else {//If there's some problem, we didn't initialize anything.
		isRunning = false;

	}
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

void Cargar::dibujar(const char* texto) {
	aviso.x = 200;
	aviso.y = 200;
	aviso.w = 350;
	aviso.h = 40;

	slots.x = 150;
	slots.y = 250;
	slots.w = 500;
	slots.h = 50;

	SDL_Color blanco = { 255,255,255 };
	SDL_Color vino = { 94,33,41 };
	SDL_Texture* fondo = IMG_LoadTexture(render, "sprites/fondo.gif");
	SDL_RenderCopy(render, fondo, NULL, NULL);

	SDL_Texture* seleccion = Texture::LoadText(texto, blanco, render);
	SDL_Texture* select_slot = Texture::LoadText("Slot 1    Slot 2    Slot 3    Slot 4", vino, render);

	Texture::draw_text(seleccion, aviso, render);
	Texture::draw_text(select_slot, slots, render);

	SDL_RenderPresent(render);
}

void Cargar::clean() {//Clean the memory from every information created by the program.
	SDL_DestroyWindow(ventana);
	SDL_DestroyRenderer(render);
};

void Cargar::eventos() {
	SDL_PollEvent(&evento);
	switch (evento.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (evento.key.keysym.sym)
		{
		case SDLK_1:
			respuesta
				= 1;
			cerrado = false;
			isRunning = false;
			break;

		case SDLK_2:
			respuesta = 2;
			cerrado = false;
			isRunning = false;
			break;

		case SDLK_3:
			respuesta = 3;
			cerrado = false;
			isRunning = false;
			break;


		case SDLK_4:
			respuesta = 4;
			cerrado = false;
			isRunning = false;
			break;

		}
	}
}