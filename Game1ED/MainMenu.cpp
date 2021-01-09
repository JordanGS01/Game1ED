#include "Game.h"
#include "MainMenu.h"
#include "Textures.h"
#include "SDL_ttf.h"


SDL_Renderer* MainMenu::render2 = nullptr;
SDL_Event MainMenu::evento;

void MainMenu::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		ventana = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		render2 = SDL_CreateRenderer(ventana, -1, 0);

		isRunning = true;
	}
	else {//If there's some problem, we didn't initialize anything.
		isRunning = false;

	}
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
}

void MainMenu::eventos() {
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
			if (!this->scores) {
				respuesta = 1;
				isRunning = false;
				cerrado = false;
			}
			break;

		case SDLK_2:
			if (!this->scores) {
				respuesta = 2;
				isRunning = false;
				cerrado = false;
			}
			break;

		case SDLK_3:
			if (!this->scores) {
				respuesta = 3;
				isRunning = false;
				cerrado = false;
			}
			break;


		case SDLK_4:
			if (!this->scores) {
				respuesta = 4;
				cerrado = false;
				isRunning = false;
			}
			break;

		case SDLK_x:
			this->scores = false;
		}
	}
}

void MainMenu::dibujar() {
	titulo.w = 300;
	titulo.h = 100;
	titulo.x = 150;
	titulo.y = 50;

	aviso.x = 200;
	aviso.y = 200;
	aviso.w = 300;
	aviso.h = 40;

	partidaNueva.x = 200;
	partidaNueva.y = 250;
	partidaNueva.w = 300;
	partidaNueva.h = 40;

	cargar.x = 200;
	cargar.y = 300;
	cargar.w = 200;
	cargar.h = 40;

	puntuacion.x = 200;
	puntuacion.y = 350;
	puntuacion.w = 300;
	puntuacion.h = 40;

	salir.x = 200;
	salir.y = 400;
	salir.w = 200;
	salir.h = 40;

	SDL_Texture* fondo = IMG_LoadTexture(render2, "sprites/fondo.gif");
	SDL_RenderCopy(render2, fondo, NULL, NULL);
	SDL_Color blanco = { 255, 255, 255 };
	SDL_Color rojo = { 255, 0,0 };
	SDL_Texture* tit = Texture::LoadText("Dungeon War Runners", rojo, render2);
	SDL_Texture* avi = Texture::LoadText("Selecciona la opcion con las teclas", blanco, render2);
	SDL_Texture* partida = Texture::LoadText("1) Partida Nueva", blanco, render2);
	SDL_Texture* carga = Texture::LoadText("2) Cargar Partida", blanco, render2);
	SDL_Texture* puntua = Texture::LoadText("3) Puntuaciones", blanco, render2);
	SDL_Texture* sal = Texture::LoadText("4) Salir", blanco, render2);

	Texture::draw_text(tit, titulo, render2);
	Texture::draw_text(avi, aviso, render2);
	Texture::draw_text(partida, partidaNueva, render2);
	Texture::draw_text(carga, cargar, render2);
	Texture::draw_text(puntua, puntuacion, render2);
	Texture::draw_text(sal, salir, render2);

	SDL_RenderPresent(render2);


}

void MainMenu::dibujarPuntuaciones(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5) {
	titulo.w = 300;
	titulo.h = 100;
	titulo.x = 150;
	titulo.y = 50;

	aviso.x = 150;
	aviso.y = 200;
	aviso.w = 300;
	aviso.h = 50;

	partidaNueva.x = 150;
	partidaNueva.y = 300;
	partidaNueva.w = 300;
	partidaNueva.h = 50;
	
	cargar.x = 150;
	cargar.y = 400;
	cargar.w = 300;
	cargar.h = 50;

	puntuacion.x = 150;
	puntuacion.y = 500;
	puntuacion.w = 300;
	puntuacion.h = 50;

	salir.x = 150;
	salir.y = 600;
	salir.w = 300;
	salir.h = 50;

	SDL_Texture* fondo = IMG_LoadTexture(render2, "sprites/fondo.gif");
	SDL_RenderCopy(render2, fondo, NULL, NULL);
	SDL_Color blanco = { 255, 255, 255 };
	SDL_Color rojo = { 255, 0,0 };
	SDL_Texture* tit = Texture::LoadText("Puntuaciones (x para salir)", rojo, render2);
	SDL_Texture* avi = Texture::LoadText(p1.c_str(), blanco, render2);
	SDL_Texture* partida = Texture::LoadText(p2.c_str(), blanco, render2);
	SDL_Texture* carga = Texture::LoadText(p3.c_str(), blanco, render2);
	SDL_Texture* puntua = Texture::LoadText(p4.c_str(), blanco, render2);
	SDL_Texture* sal = Texture::LoadText(p5.c_str(), blanco, render2);

	Texture::draw_text(tit, titulo, render2);
	Texture::draw_text(avi, aviso, render2);
	Texture::draw_text(partida, partidaNueva, render2);
	Texture::draw_text(carga, cargar, render2);
	Texture::draw_text(puntua, puntuacion, render2);
	Texture::draw_text(sal, salir, render2);

	SDL_RenderPresent(render2);


}

void MainMenu::clean() {
	SDL_DestroyWindow(ventana);
	SDL_DestroyRenderer(render2);
};