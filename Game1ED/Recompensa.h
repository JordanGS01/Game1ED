#pragma once
#ifndef RECOMPENSA_H
#define RECOMPENSA_H
#include "Game.h"


class Recompensa {
public:
	Recompensa(const char* sonido, int coordenadas[5][2]);
	bool comprobarRecompensa(int coordenada_pj_x, int coordenada_pj_y, int coordenadasRecompensa[5][2], int matriz_juego[23][23]);
	int coordenadasRecompensa[5][2];
	Mix_Chunk* sonidoRecompensa;

};
#endif