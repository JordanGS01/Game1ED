#include "Victoria.h"
#include "Textures.h"
#include "SDL_ttf.h"
#include <string>
#include <sstream>

SDL_Renderer* Victoria::render = nullptr;

void Victoria::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		ventana = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		render = SDL_CreateRenderer(ventana, -1, 0);

		isRunning = true;
	}
	else {
		isRunning = false;

	}
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

}

void Victoria::dibujar(time_t tiempo) {
	std::stringstream ss;
	ss << tiempo;
	std::string ts = ss.str();
	const char* c = ts.c_str();
	titulo.w = 350;
	titulo.h = 100;
	titulo.x = 150;
	titulo.y = 50;

	aviso.x = 200;
	aviso.y = 200;
	aviso.w = 300;
	aviso.h = 40;

	puntuacion.x = 200;
	puntuacion.y = 250;
	puntuacion.w = 300;
	puntuacion.h = 150;

	SDL_Color blanco = { 255, 255, 255 };
	SDL_Color rojo = { 255, 0,0 };

	SDL_Texture* tit = Texture::LoadText("Has Ganado !!", rojo, this->render);
	SDL_Texture* mensaje = Texture::LoadText("Puntuacion: ", blanco, this->render);
	SDL_Texture* punt = Texture::LoadText(c, blanco, this->render);

	Texture::draw_text(tit, titulo, this->render);
	Texture::draw_text(mensaje, aviso, this->render);
	Texture::draw_text(punt, puntuacion, this->render);

	SDL_RenderPresent(this->render);
}

void Victoria::clean() {
	SDL_DestroyWindow(ventana);
	SDL_DestroyRenderer(render);
}
