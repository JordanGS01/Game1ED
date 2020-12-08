#include "Interfaz.h"
#include "Textures.h"
#include "SDL_ttf.h"

SDL_Renderer* interfaz::render = nullptr;
SDL_Event interfaz::evento;

void interfaz::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

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
void interfaz::dibujar() {
	SDL_RenderClear(render);

	pos_tit_vent.w = 100;
	pos_tit_vent.h = 100;
	pos_tit_vent.x = pos_tit_vent.y = 200;

	pos_p1.x = 0;
	pos_p1.y = 0;
	pos_p1.h = 32;
	pos_p1.w = 32;

	pos_p1_vent.w = pos_p1_vent.h = 32;
	pos_p1_vent.x = 200;
	pos_p1_vent.y = 350;

	pos_p2_vent.w = pos_p1_vent.h = 32;
	pos_p2_vent.x = 250;
	pos_p2_vent.y = 300;
	//create a rect
	Message_rect.x = 125;
	Message_rect.y = 100;
	Message_rect.w = 500;
	Message_rect.h = 100;

	Msg.x = 200;
	Msg.y = 200;
	Msg.w = 300;
	Msg.h = 40;

	numeros.x = 200;
	numeros.y = 300;
	numeros.h = 50;
	numeros.w = 300;
	SDL_Color blanco = { 255, 255, 255 };
	SDL_Color rojo = { 255, 0,0 };
	SDL_Color vino = { 94,33,41 };
	SDL_Texture* fondo = IMG_LoadTexture(render, "sprites/fondo.gif");
	SDL_RenderCopy(render, fondo, NULL, NULL);

	SDL_Texture* pj1 = Texture::LoadTexture_inter("sprites/rightMovement.png");
	SDL_Texture* pj2 = Texture::LoadTexture_inter("sprites/BelenRight.png");
	SDL_Texture* pj3 = Texture::LoadTexture_inter("sprites/JordanRight.png");
	SDL_Texture* titulo = Texture::LoadText("Dungeon War Runners", rojo);
	SDL_Texture* mensaje = Texture::LoadText("Selecciona el Personaje", blanco);
	SDL_Texture* numerostext = Texture::LoadText("1          2          3         ", vino);

	Texture::draw_text(mensaje, Msg);
	Texture::draw_text(titulo, Message_rect);
	Texture::draw_text(numerostext, numeros);

	Texture::draw_interfaz(pj1, pos_p1, pos_p1_vent);
	pos_p1_vent.x = 285;
	Texture::draw_interfaz(pj2, pos_p1, pos_p1_vent);
	pos_p1_vent.x = 400;
	Texture::draw_interfaz(pj3, pos_p1, pos_p1_vent);

	pos_p1_vent.x = 200;
	SDL_RenderPresent(render);
}
void interfaz::eventos() {
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
			respuesta = 1;
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
void interfaz::clean() {//Clean the memory from every information created by the program.
	SDL_DestroyWindow(ventana);
	SDL_DestroyRenderer(render);
};