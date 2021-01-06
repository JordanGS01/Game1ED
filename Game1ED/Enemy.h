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
	void killPlayer(int x, int y, GameObj* player) {
		if (((x == this->getXPos()) && (y == this->getYPos())) || (x+4 == this->getXPos()) && (y+4 == this->getYPos()) || (x-4 == this->getXPos()) && (y-4 == this->getYPos()) || (x+4 == this->getXPos()) && (y-4 == this->getYPos()) || (x-4 == this->getXPos()) && (y+4 == this->getYPos()))  {
			player->life -= 1;
			player->xpos = player->initPosX;
			player->ypos = player->initPosY;
			SoundManager::playChunk(player->deadSound);
		}
	}

	void seekPlayer(GameObj* player) {
		/*if (counterMovement == 8) {
			counterMovement = 0;*/
			Nodo* auxNodo = grafoMapa->buscaNodo(xpos / 32, ypos / 32);//OJO, CAMBIO IMPORTANTE ACA (y,x)
			if (auxNodo != nullptr) {
				this->nodoActual = auxNodo;
			}
		/*}
		counterMovement++;*/

		char dir = grafoMapa->Dijkstra(this->nodoActual, player->nodoActual);
		//
		/*std::cout << dir << " " << std::endl;
		system("pause");*/
		//
		if (dir == 'U') {
			subYPos();
			//SDL_Delay(10);
		}
		else if(dir == 'D') {
			addYPos();
			//SDL_Delay(10);
		}
		else if(dir == 'L') {
			subXPos();
			//SDL_Delay(10);
		}
		else {
			addXPos();
			//SDL_Delay(10);
		}
	}

	void enemyUpdate() {
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = srcY;

		destRect.h = 32;
		destRect.w = 32;
		destRect.x = ypos;//OJO ACA, CAMBIO
		destRect.y = xpos;//OJO ACA, CAMBIO
	}
};

#endif // !ENEMY.H
