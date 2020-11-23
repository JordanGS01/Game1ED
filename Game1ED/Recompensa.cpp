#include "Recompensa.h"
#include "SoundManager.h"

Recompensa::Recompensa(const char* sonido, int coordenadas[5][2]) {
	Recompensa::sonidoRecompensa = SoundManager::chargeWAV(sonido);
	for (int row = 0; row < 5; row++) {
		for (int column = 0; column < 2; column++) {
			Recompensa::coordenadasRecompensa[row][column] = coordenadas[row][column];
		}
	}
}

bool Recompensa::comprobarRecompensa(int coordenada_pj_x, int coordenada_pj_y, int coordenadasRecompensa[5][2], int matriz_juego[23][23]) {
	for (int x_recompensa = 0; x_recompensa < 5; x_recompensa++) {
		if (coordenada_pj_x + 32 >= coordenadasRecompensa[x_recompensa][0] && coordenada_pj_x + 32 <= coordenadasRecompensa[x_recompensa][0] + 32 && coordenada_pj_y + 32 >= coordenadasRecompensa[x_recompensa][1] && coordenada_pj_y + 32 < coordenadasRecompensa[x_recompensa][1] + 32 || coordenada_pj_x >= coordenadasRecompensa[x_recompensa][0] && coordenada_pj_x <= coordenadasRecompensa[x_recompensa][0] + 32 && coordenada_pj_y >= coordenadasRecompensa[x_recompensa][1] && coordenada_pj_y < coordenadasRecompensa[x_recompensa][1] + 32) {
			int f = coordenadasRecompensa[x_recompensa][0] / 32;
			int q = coordenadasRecompensa[x_recompensa][1] / 32;
			matriz_juego[q][f] = 0;
			//Mix_PlayChannel(-1, Recompensa::sonidoRecompensa, 0);
			SoundManager::playChunk(Recompensa::sonidoRecompensa);
			coordenadasRecompensa[x_recompensa][0] = 999;
			coordenadasRecompensa[x_recompensa][1] = 999;
		}
	}

	return false;
}