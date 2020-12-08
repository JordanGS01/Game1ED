#pragma once
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Game.h"

class interfaz {
public:
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	static SDL_Renderer* render;
	static SDL_Event evento;
	void dibujar();

	bool running() { return isRunning; };
	void eventos();
	void clean();
	int respuesta;
	SDL_Rect pos_p1;
	SDL_Rect pos_titulo;
	SDL_Rect pos_tit_vent;
	SDL_Rect pos_p1_vent;
	SDL_Rect Message_rect, Msg, numeros, pos_p2_vent;
	bool cerrado = true;
private:

	SDL_Window* ventana;
	bool isRunning;

};

#endif // !INTERFAZ_H
