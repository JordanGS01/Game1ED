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
	game->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 1);
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


	/*Game* game2 = new Game();
	//Game inicialization.
	game2->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 2);
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
	game2->clean();*/

	/*Game* game3 = new Game();
	game3->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, 3);
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


	game3->clean();*/
	SDL_Quit();
	return 0;
}