#include <iostream>
#include "Game.h"
#include "time.h"
#include "Interfaz.h"
#include "mapsMatrixForGraphs.h"

Game* game = NULL;
int personaje;
int main(int argc, char* argv[]) {
	srand(time(NULL));
	//Variables

	//To manage the delay of the game
	const int frameDelay = 1000 / 60;

	Uint32 frameS;
	int frameT;
	interfaz* inter = new interfaz();
	inter->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
	while (inter->running() == true) {
		inter->dibujar();
		inter->eventos();
	}
	personaje = inter->respuesta;
	inter->clean();
	if (inter->cerrado == true) {
		SDL_Quit();
		return 0;
	}
	//Created classes.
	Game* game = new Game();

	//Game inicialization.
	game->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 1, personaje,grafoMlvl1);
	//Main loop of the game.

	while (game->running()) {

		frameS = SDL_GetTicks();//To handle delay

		game->handleEvents();
		game->update();
		game->render();


		frameT = SDL_GetTicks() - frameS;
		if (frameDelay > frameT) {// To have always the same FPS
			SDL_Delay(frameDelay - frameT);
		}
	}


	game->clean();
	if (game->cerrado == true) {
		SDL_Quit();
		return 0;
	}
	//Created classes.
	Game* game2 = new Game();

	//Game inicialization.
	game2->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 2, personaje,grafoMlvl2);
	//Main loop of the game.
	while (game2->running()) {

		frameS = SDL_GetTicks();//To handle delay

		game2->handleEvents();
		game2->update();
		game2->render();


		frameT = SDL_GetTicks() - frameS;
		if (frameDelay > frameT) {// To have always the same FPS
			SDL_Delay(frameDelay - frameT);
		}
	}


	game2->clean();
	if (game2->cerrado == true) {
		SDL_Quit();

		return 0;
	}
	Game* game3 = new Game();
	game3->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 3, personaje,grafoMlvl3);
	//Main loop of the game.
	while (game3->running()) {

		frameS = SDL_GetTicks();//To handle delay

		game3->handleEvents();
		game3->update();
		game3->render();


		frameT = SDL_GetTicks() - frameS;
		if (frameDelay > frameT) {// To have always the same FPS
			SDL_Delay(frameDelay - frameT);
		}
	}


	game3->clean();
	SDL_Quit();
	return 0;
}