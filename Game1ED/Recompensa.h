#pragma once
#include "SDL_Mixer.h"
class Recompensa {
public:
	Recompensa(const char* sonido, int coordenadas[5][2]);
	bool comprobarRecompensa(int coordenada_pj_x, int coordenada_pj_y, int coordenadasRecompensa[5][2], int matriz_juego[23][23], Recompensa* rec);
	bool comprobarPuerta(int x, int y, bool vic);
	int coordenadasRecompensa[5][2];
	Mix_Chunk* sonidoRecompensa;
	int num_recompensas = 0;
};