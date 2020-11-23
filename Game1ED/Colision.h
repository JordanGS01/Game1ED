#pragma once
#ifndef COLISION_H
#define COLISION_H

class Colision {
public:
	bool comprobarMuroabajo(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23]);
	bool comprobarMuroarriba(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23]);
	bool comprobarMuroizquierda(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23]);
	bool comprobarMuroderecha(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23]);
};

#endif 

