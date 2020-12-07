#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "GameObj.h"
#include "SoundManager.h"
#include "Grafo.h"

class Enemy : public GameObj {
public:
	int counterMovement = 0;

	Enemy(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int xpos, int ypos)
		:GameObj(rightSheet, leftSheet, upSheet, downSheet, xpos, ypos) {
	};

	//This function helps to know if the Enemy object is on the same position of the player.
	void killPlayer(int x, int y, GameObj* player) {
		if ((x == getXPos()) && (y == getYPos())) {
			player->life -= 1;
			player->xpos = player->initPosX;
			player->ypos = player->initPosY;
			SoundManager::playChunk(player->deadSound);
		}
	}

	void seekPlayer(GameObj* player) {
		if (counterMovement == 8) {
			counterMovement = 0;
			nodoActual = grafoMapa->buscaNodo(xpos / 32, ypos / 32);
		}
		counterMovement++;

		char dir = grafoMapa->Dijkstra(nodoActual, player->nodoActual);
		
		if (dir == 'U') {
			subYPos();
			SDL_Delay(30);
		}
		else if(dir == 'D') {
			addYPos();
			SDL_Delay(30);
		}
		else if(dir == 'L') {
			subXPos();
			SDL_Delay(30);
		}
		else {
			addXPos();
			SDL_Delay(30);
		}
	}
};

#endif // !ENEMY.H
