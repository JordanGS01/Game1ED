#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "GameObj.h"
#include "SoundManager.h"
#include "Grafo.h"

class Enemy : public GameObj {
public:
	int counterMovement = 0;
	Enemy() {}
	Enemy(const char* rightSheet, const char* leftSheet, const char* upSheet, const char* downSheet, int x, int y)
		:GameObj(rightSheet, leftSheet, upSheet, downSheet, x, y) {
		this->xpos = y;
		this->ypos = x;
		this->initPosX = y;
		this->initPosY = x;
	};

	//This function helps to know if the Enemy object is on the same position of the player.
	bool killPlayer(int x, int y, GameObj* player) {
		if (((x == this->getXPos()) && (y == this->getYPos())) || (x+4 == this->getXPos()) && (y+4 == this->getYPos()) || (x-4 == this->getXPos()) && (y-4 == this->getYPos()) || (x+4 == this->getXPos()) && (y-4 == this->getYPos()) || (x-4 == this->getXPos()) && (y+4 == this->getYPos()))  {
			player->life -= 1;
			player->xpos = player->initPosX;
			player->ypos = player->initPosY;
			SoundManager::playChunk(player->deadSound);
			return true;
		}
		return false;
	}

	void seekPlayer(GameObj* player) {
			Nodo* auxNodo = grafoMapa->buscaNodo(xpos / 32, ypos / 32);//OJO, CAMBIO IMPORTANTE ACA (y,x)
			if (auxNodo != nullptr) {
				this->nodoActual = auxNodo;
			}

		char dir = grafoMapa->Dijkstra(this->nodoActual, player->nodoActual);
		if (dir == 'U') {
			subYPos();
		}
		else if(dir == 'D') {
			addYPos();
		}
		else if(dir == 'L') {
			subXPos();
		}
		else {
			addXPos();
		}
	}

	void enemyUpdate() {
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = srcY;

		destRect.h = 32;
		destRect.w = 32;
		destRect.x = ypos;
		destRect.y = xpos;
	}
};

#endif // !ENEMY.H
