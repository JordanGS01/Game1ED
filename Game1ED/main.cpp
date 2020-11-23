#include <iostream>
#include "Game.h"
#include "time.h"

Game* game = NULL;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	//Variables

	//To manage the delay of the game
	const int frameDelay = 1000 / 60;

	Uint32 frameS;
	int frameT;

	//Created classes.
	Game* game = new Game();

	//Game inicialization.
	game->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);

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
	return 0;
}