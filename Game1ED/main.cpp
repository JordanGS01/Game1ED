#include <iostream>
#include <fstream>
#include "Game.h"
#include "time.h"
#include "Interfaz.h"
#include "mapsMatrixForGraphs.h"
using namespace std;

Game* game = NULL;
int personaje;
int saveSlot = 3;
int level = 1;


bool saveGame();
bool loadGameInfo();

int main(int argc, char* argv[]) {
	srand(time(NULL));
	//Variables

	//To manage the delay of the game
	const int frameDelay = 1000 / 10;

	//PRUEBA
	bool loaded = true;

	Uint32 frameS;
	int frameT;
	interfaz* inter = new interfaz();
	inter->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
	while (inter->running() == true) {
		inter->dibujar();
		inter->eventos();
	}

	//SaveSlot 0 means that we want to initiate a new game
	if (!loaded) {//PRUEBA
		personaje = inter->respuesta;
	}
	else {
		if (!loadGameInfo()) {
			personaje = inter->respuesta;
		}
	}
	inter->clean();

	if (inter->cerrado == true) {
		SDL_Quit();
		return 0;
	}


	if (level == 1) {
		Game* game = new Game();
		game->setGameSlot(saveSlot);
		saveGame();
		
		/*if (game->getGameSlot() > 0) {
			game->setLoaded(loaded);
		}*/
		if (loaded) {
			game->setLoaded(true);
			loaded = false;
		}

		//Game inicialization.
		game->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, level, personaje, grafoMlvl1);
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
		level++;
	}

	if (level == 2) {
		Game* game2 = new Game();
		game2->setGameSlot(saveSlot);
		saveGame();
		/*if (game2->getGameSlot() > 0) {
			game2->setLoaded(true);
		}*/
		if (loaded) {
			game2->setLoaded(true);
			loaded = false;
		}

		//Game inicialization.
		game2->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, level, personaje, grafoMlvl2);
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
		level++;
	}

	if (level == 3) {
		Game* game3 = new Game();
		game3->setGameSlot(saveSlot);
		saveGame();
		/*if(game3->getGameSlot() > 0) {
			game3->setLoaded(true);
		}*/
		if (loaded) {
			game3->setLoaded(true);
			loaded = false;
		}

		game3->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0, level, personaje, grafoMlvl3);
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
}

bool saveGame() {
	if (saveSlot == 1) {
		ofstream file6("archives/s1/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}
	
	else if (saveSlot == 2) {
		ofstream file6("archives/s2/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}

	else if (saveSlot == 3) {
		ofstream file6("archives/s3/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}

	else {
		ofstream file6("archives/s4/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}
}

bool loadGameInfo() {
	
	if (saveSlot == 1) {
		ifstream file6("archives/s1/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}

	if (saveSlot == 2) {
		ifstream file6("archives/s2/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}

	if (saveSlot == 3) {
		ifstream file6("archives/s3/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}

	else {
		ifstream file6("archives/s4/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return false;
		}
		else {
			//personaje    saveslot   level
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.close();
			return true;
		}
	}
}