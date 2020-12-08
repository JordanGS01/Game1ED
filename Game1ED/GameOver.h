#pragma once
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Game.h"
class GameOver {
public:
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void dibujar();
	void clean();
	void cerrar();
	bool running() { return isRunning; };
	static SDL_Renderer* renderer1;
	SDL_Rect titulo, tecla;
	static SDL_Event cerrado;
	bool isRunning;
private:
	SDL_Window* ventana;
};

#endif // !GAMEOVER_H
