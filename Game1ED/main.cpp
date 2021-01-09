#include <iostream>
#include <fstream>
#include "Game.h"
#include "time.h"
#include "Interfaz.h"
#include "mapsMatrixForGraphs.h"
#include "MainMenu.h"
#include "Cargar.h"
#include <ctime>
#include <sstream>
#include "Victoria.h"
using namespace std;

Game* game = NULL;
int personaje;
int saveSlot = 1;
int level = 1;
string nj,s1,s2,s3,s4,s5;
clock_t finalTime;
clock_t t1 = 10000;
clock_t t2 = 10000;
clock_t t3 = 10000;
clock_t t4 = 10000;
clock_t t5 = 10000;
Victoria* victoria = new Victoria();


bool saveGame();
bool loadGameInfo();
bool saveScores();
bool loadScores();
void scoresSetter(std::string n, clock_t t);
std::string timeConvertor(string pos, string s, clock_t time);

int main(int argc, char* argv[]) {
	srand(time(NULL));

	//To manage the delay of the game
	const int frameDelay = 1000 / 10;

	bool loaded = false;

	Uint32 frameS;
	int frameT;
	bool atras = true;
	int respuestaM;
	MainMenu* menu = new MainMenu();
	Cargar* pantallaCargar = new Cargar();
	while (atras) {
		menu->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
		while (menu->running()) {
			menu->dibujar();
			menu->eventos();
		}
		respuestaM = menu->respuesta;
		if (menu->cerrado == true) {
			SDL_Quit();
			return 0;
		}


		switch (respuestaM) {
		case 1:
			atras = false;
			pantallaCargar->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
			while (pantallaCargar->running())
			{
				pantallaCargar->dibujar("Digite el numero del slot en que desea guardar");
				pantallaCargar->eventos();
			}
			pantallaCargar->clean();
			if (pantallaCargar->cerrado == true) {
				SDL_Quit();
				return 0;
			}
			saveSlot = pantallaCargar->respuesta;
			break;
		case 2:
			atras = false;
			pantallaCargar->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
			while (pantallaCargar->running())
			{
				pantallaCargar->dibujar("Digite el slot que desea cargar");
				pantallaCargar->eventos();
			}
			pantallaCargar->clean();
			if (pantallaCargar->cerrado == true) {
				SDL_Quit();
				return 0;
			}
			saveSlot = pantallaCargar->respuesta;
			loaded = true;
			break;
		case 3:
			menu->scores = true;
			loadScores();

			while (menu->scores) {	
				
				string fs1, fs2, fs3, fs4, fs5;
				if (t1 != 10000) {
					fs1 = timeConvertor("1)", s1, t1);
				}
				if (t2 != 10000) {
					fs2 = timeConvertor("2)", s2, t2);
				}
				if (t3 != 10000) {
					fs3 = timeConvertor("3)", s3, t3);
				}
				if (t4 != 10000) {
					fs4 = timeConvertor("4)", s4, t4);
				}
				if (t5 != 10000) {
					fs5 = timeConvertor("5)", s5, t5);
				}

				menu->dibujarPuntuaciones(fs1, fs2, fs3, fs4, fs5);
				menu->eventos();
			}
			break;
		case 4:
			SDL_Quit();
			return 0;
			break;
		}
		menu->clean();
		menu->setRunning(true);
	}

	if (!loaded) {
		cout << "Ingrese el nombre del jugador " << endl;
		cin >> nj;
	}
	
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

	if (!loaded) {
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
		game->playerName = nj;
		game->setGameSlot(saveSlot);
		game->initClock();
		saveGame();
		
		if (loaded) {
			game->setLoaded(true);
			nj = game->playerName;
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

		finalTime += game->getClock();
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
		game2->playerName = nj;
		game2->initClock();
		saveGame();

		if (loaded) {
			game2->setLoaded(true);
			nj = game2->playerName;
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

		finalTime += game2->getClock();
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
		game3->playerName = nj;
		game3->initClock();
		saveGame();
	
		if (loaded) {
			game3->setLoaded(true);
			nj = game3->playerName;
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

		bool exitButton = game3->exitBut;
		if (!exitButton) {
			finalTime += game3->getClock();
			finalTime = finalTime / CLOCKS_PER_SEC;

			scoresSetter(game3->playerName, finalTime);

			victoria->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
			while (victoria->running()) {
				victoria->dibujar(finalTime);
			}
			victoria->clean();
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
			return false;
		}
		else {
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.write((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}
	
	else if (saveSlot == 2) {
		ofstream file6("archives/s2/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.write((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}

	else if (saveSlot == 3) {
		ofstream file6("archives/s3/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.write((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}

	else {
		ofstream file6("archives/s4/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekp(0);
			file6.write((char*)&personaje, sizeof(int));
			file6.write((char*)&saveSlot, sizeof(int));
			file6.write((char*)&level, sizeof(int));
			file6.write((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}
}

bool saveScores() {
		ofstream file8("archives/scoresInfo.bin", ios::binary);
		if (!file8.is_open()) {
			return false;
		}
		else {
			file8.seekp(0);
			file8.write((char*)&s1, sizeof(string));
			file8.write((char*)&t1, sizeof(clock_t));
			
			file8.write((char*)&s2, sizeof(string));
			file8.write((char*)&t2, sizeof(clock_t));

			file8.write((char*)&s3, sizeof(string));
			file8.write((char*)&t3, sizeof(clock_t));

			file8.write((char*)&s4, sizeof(string));
			file8.write((char*)&t4, sizeof(clock_t));

			file8.write((char*)&s5, sizeof(string));
			file8.write((char*)&t5, sizeof(clock_t));
			file8.close();
			return true;
		}
}

bool loadGameInfo() {
	
	if (saveSlot == 1) {
		ifstream file6("archives/s1/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.read((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}

	else if (saveSlot == 2) {
		ifstream file6("archives/s2/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.read((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}

	else if (saveSlot == 3) {
		ifstream file6("archives/s3/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.read((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}

	else {
		ifstream file6("archives/s4/gameInfo.bin", ios::binary);
		if (!file6.is_open()) {
			return false;
		}
		else {
			file6.seekg(0);
			file6.read((char*)&personaje, sizeof(int));
			file6.read((char*)&saveSlot, sizeof(int));
			file6.read((char*)&level, sizeof(int));
			file6.read((char*)&finalTime, sizeof(clock_t));
			file6.close();
			return true;
		}
	}
}

bool loadScores() {
		ifstream file8("archives/scoresInfo.bin", ios::binary);
		if (!file8.is_open()) {
			return false;
		}
		else {
			file8.seekg(0);
			file8.read((char*)&s1, sizeof(string));
			file8.read((char*)&t1, sizeof(clock_t));

			file8.read((char*)&s2, sizeof(string));
			file8.read((char*)&t2, sizeof(clock_t));

			file8.read((char*)&s3, sizeof(string));
			file8.read((char*)&t3, sizeof(clock_t));

			file8.read((char*)&s4, sizeof(string));
			file8.read((char*)&t4, sizeof(clock_t));

			file8.read((char*)&s5, sizeof(string));
			file8.read((char*)&t5, sizeof(clock_t));
			file8.close();
			return true;
		}
}

void scoresSetter(std::string n,clock_t t ) {
	loadScores();
	
	if (finalTime < t1) {
		t5 = t4;
		s5 = s4;

		t4 = t3;
		s4 = s3;

		t3 = t2;
		s3 = s2;

		t2 = t1;
		s2 = s1;

		t1 = t;
		s1 = n;

		saveScores();
	}

	else if (finalTime < t2) {
		t5 = t4;
		s5 = s4;

		t4 = t3;
		s4 = s3;

		t3 = t2;
		s3 = s2;

		t2 = t;
		s2 = n;

		saveScores();
	}

	else if (finalTime < t3) {
		t5 = t4;
		s5 = s4;

		t4 = t3;
		s4 = s3;

		t3 = t;
		s3 = n;

		saveScores();
	}

	else if (finalTime < t4) {
		t5 = t4;
		s5 = s4;

		t4 = t;
		s4 = n;

		saveScores();
	}

	else if (finalTime < t5) {
		t5 = t;
		s5 = n;

		saveScores();
	}

	return;
}

std::string timeConvertor(string pos,string s, clock_t time) {
	std::string finalString;
	std::stringstream ss;
	ss << time;
	finalString = pos + s + " " + ss.str();
	return finalString;
}