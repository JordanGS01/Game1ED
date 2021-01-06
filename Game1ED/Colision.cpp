#include "Colision.h"


bool Colision::comprobarMuroarriba(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23])
{
	int mod = coordenada_pj_y % 32;
	int extremo1 = (coordenada_pj_y - mod) - 32;
	int num_linea = extremo1 / 32;
	int num_columna = (coordenada_pj_x + 16) / 32;
	int num_columna1 = (coordenada_pj_x + 24) / 32;
	int num_columna2 = (coordenada_pj_x + 8) / 32;
	if (matriz_juego[num_linea][num_columna] == 1 || matriz_juego[num_linea][num_columna1] == 1 || matriz_juego[num_linea][num_columna2] == 1) {
		return true;
	}
	else {
		return false;
	}
};
bool Colision::comprobarMuroderecha(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23])
{
	int mod = coordenada_pj_x % 32;
	int extremo1 = (coordenada_pj_x - mod) + 32;
	int num_columna = extremo1 / 32;
	int num_linea = (coordenada_pj_y + 16) / 32;
	int num_linea1 = (coordenada_pj_y + 24) / 32;
	int num_linea2 = (coordenada_pj_y + 8) / 32;
	if (matriz_juego[num_linea][num_columna] == 1 || matriz_juego[num_linea1][num_columna] == 1 || matriz_juego[num_linea2][num_columna] == 1) {
		return true;
	}
	else {
		return false;
	}
};
bool Colision::comprobarMuroizquierda(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23])
{
	int mod = coordenada_pj_x % 32;
	int extremo1 = (coordenada_pj_x - mod) - 32;
	int num_columna = extremo1 / 32;
	int num_linea = (coordenada_pj_y + 16) / 32;
	int num_linea1 = (coordenada_pj_y + 24) / 32;
	int num_linea2 = (coordenada_pj_y + 8) / 32;
	if (matriz_juego[num_linea][num_columna] == 1 || matriz_juego[num_linea1][num_columna] == 1 || matriz_juego[num_linea2][num_columna] == 1) {
		return true;
	}
	else {
		return false;
	}
	/*if (matriz_juego[(coordenada_pj_x - 32) / 32][coordenada_pj_y / 32] == 1) {
		return true;
	}
	else {
		return false;
	}*/
};
bool Colision::comprobarMuroabajo(int coordenada_pj_x, int coordenada_pj_y, int matriz_juego[23][23])
{
	int mod = coordenada_pj_y % 32;
	int extremo1 = (coordenada_pj_y - mod) + 32;
	int num_linea = extremo1 / 32;
	int num_columna = (coordenada_pj_x + 16) / 32;
	int num_columna1 = (coordenada_pj_x + 24) / 32;
	int num_columna2 = (coordenada_pj_x + 8) / 32;
	if (matriz_juego[num_linea][num_columna] == 1 || matriz_juego[num_linea][num_columna1] == 1 || matriz_juego[num_linea][num_columna2] == 1) {
		return true;
	}
	else {
		return false;
	}
};