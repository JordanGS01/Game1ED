#include "Game.h"
#include "Textures.h"
#include "MMap.h"
#include "mapsMatrix.h"
#include "GameObj.h"
#include <iostream>
#include "Colision.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Recompensa.h"
#include "SoundManager.h"
#include "Lifes.h"
#include "ContRecompensa.h"
#include "Enemy.h"
#include "Grafo.h"
#include "GameOver.h"
#include <fstream>

using namespace std;

void save();
void loadPlayer();
void loadPrizes();
void loadEnemy1();
void loadEnemy3();

//_____________________________________
//Game objects
GameOver* fin = new GameOver();
const char* movimientoDerecha[3] = { "sprites/rightMovement.png","sprites/BelenRight.png","sprites/JordanRight.png" };
const char* movimientoArriba[3] = { "sprites/upMovement.png","sprites/BelenUp.png","sprites/JordanUp.png" };
const char* movimientoAbajo[3] = { "sprites/downMovement.png","sprites/BelenDown.png","sprites/JordanDown.png" };
const char* movimientoIzquierda[3] = { "sprites/leftMovement.png","sprites/BelenLeft.png","sprites/JordanLeft.png" };
Grafo* grafo = new Grafo();
GameObj* player1;
Map* maplv1;//Map of the first level
Colision* colision;
Life* vidas;
ContRecompensa* contadorRecomp;
SDL_Event Game::event;//To handle the game events.
SDL_Renderer* Game::renderer = nullptr;
Enemy* enemy1;
Enemy* enemy3;

int rec = 0;
int coordenadas_recompensa[5][2] = { {0,0},{0,0},{0,0},{0,0},{0,0} };
const char* pisos[3] = { "sprites/floor_lv1.png" ,"sprites/floor_nivel2.png","sprites/floor_lvl3.png" };
const char* muros[3] = { "sprites/new-wall-lv1.png" ,"sprites/muro_lvl2.png","sprites/muro_lvl3.png" };
int mapa[23][23];
bool victoria = false;
Recompensa* recompensas;

//Recives the title of the game, x and y possition in screen of the window, width and height if the window.
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int nivel,int personaje,int matriz[23][23]) {
	//Saving the important information we need to initialize the Game object
	this->level = nivel;
	this->player = personaje;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}
	else {//If there's some problem, we didn't initialize anything.
		isRunning = false;
	}
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4048);

	if (this->level == 1) {
		grafo->inicializaNodosMatriz(matriz);
		grafo->inicializaAristasMatriz(matriz);
		for (int row = 0; row < 23; row++) {
			for (int column = 0; column < 23; column++) {
				mapa[row][column] = mlvl1[row][column];
			}
		}
	}
	else if (this->level == 2) {
		grafo->inicializaNodosMatriz(matriz);
		grafo->inicializaAristasMatriz(matriz);
		for (int row = 0; row < 23; row++) {
			for (int column = 0; column < 23; column++) {
				mapa[row][column] = mlvl2[row][column];
			}
		}
	}
	else if (this->level == 3) {
		grafo->inicializaNodosMatriz(matriz);
		grafo->inicializaAristasMatriz(matriz);
		for (int row = 0; row < 23; row++) {
			for (int column = 0; column < 23; column++) {
				mapa[row][column] = mlvl3[row][column];
			}
		}
	}


	enemy1 = new Enemy("sprites/minotauro.png", "sprites/minotauro.png", "sprites/minotauro.png", "sprites/minotauro.png", 32, 672);
	enemy3 = new Enemy("sprites/minotauro2.png", "sprites/minotauro2.png", "sprites/minotauro2.png", "sprites/minotauro2.png", 672, 672);
	player1 = new GameObj(movimientoDerecha[this->player - 1], movimientoIzquierda[this->player - 1], movimientoArriba[this->player - 1], movimientoAbajo[this->player - 1], 32, 32);
	player1->deadSound = SoundManager::chargeWAV("sounds/death.wav");
	player1->apearSound = SoundManager::chargeWAV("sounds/beggining.wav");
	maplv1 = new Map(muros[nivel - 1], pisos[nivel - 1]);
	vidas = new Life("sprites/corazones.png", 520, 690);
	contadorRecomp = new ContRecompensa("sprites/numeros.png", "sprites/oro.png", 590, 685, 630, 690);

	recompensas = new Recompensa("sounds/reward.wav", coordenadas_recompensa);

	if (this->loaded) {
		/*player1 = new GameObj();
		enemy1 = new Enemy();
		enemy3 = new Enemy();*/
		this->loadPlayer();
		/*loadEnemy1();
		loadEnemy3();*/
		this->loadPrizes();
	}
	else {
		enemy1->initGrafo(grafo);
		enemy3->initGrafo(grafo);
		player1->initGrafo(grafo);

		
		srand((unsigned)time(0));

		int random;
		while (rec < 5) {
			for (int row = 0; row < 23; row++) {
				for (int column = 0; column < 23; column++) {
					random = rand() % 100;
					if (random < 1 && mapa[row][column] == 0) {
						mapa[row][column] = 2;
						coordenadas_recompensa[rec][0] = column * 32;
						coordenadas_recompensa[rec][1] = row * 32;
						rec++;
					}
					if (rec >= 5) {
						break;
					}
				}
			}
		}
		rec = 0;
		recompensas->num_recompensas = 5;

	}

	/*srand((unsigned)time(0));

	int random;
	while (rec < 5) {
		for (int row = 0; row < 23; row++) {
			for (int column = 0; column < 23; column++) {
				random = rand() % 100;
				if (random < 1 && mapa[row][column] == 0) {
					mapa[row][column] = 2;
					coordenadas_recompensa[rec][0] = column * 32;
					coordenadas_recompensa[rec][1] = row * 32;
					rec++;
				}
				if (rec >= 5) {
					break;
				}
			}
		}
	}
	rec = 0;*/

	//Aca se inicializara todo lo referente a sonidos
	/*SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4048);*/

	SoundManager::playChunk(player1->apearSound);
};


void Game::update() {
	player1->update();

	/*enemy1->seekPlayer(player1);
	enemy1->enemyUpdate();
	enemy1->killPlayer(player1->getXPos(),player1->getYPos(),player1);

	enemy3->seekPlayer(player1);
	enemy3->enemyUpdate();
	enemy3->killPlayer(player1->getXPos(), player1->getYPos(), player1);*/
	
	if (player1->life == 3) {
		vidas->srcY = 0;
	}
	if (player1->life == 2) {
		vidas->srcY = 64;
	}
	if (player1->life == 1) {
		vidas->srcY = 128;
	}
	if (player1->life == 0) {
		vidas->srcY = 192;

		Game::isRunning = false;
		fin->init("Dungeon WarRunners", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 736, 736, 0);
		while (fin->running()) {
			fin->dibujar();
			fin->cerrar();
		}
		fin->clean();
	}
	vidas->update();
	
	contadorRecomp->update();
	if (recompensas->num_recompensas == 5) {
		contadorRecomp->srcY = 320;
	}
	if (recompensas->num_recompensas == 4) {
		contadorRecomp->srcY = 256;
	}
	if (recompensas->num_recompensas == 3) {
		contadorRecomp->srcY = 192;
	}
	if (recompensas->num_recompensas == 2) {
		contadorRecomp->srcY = 128;
	}
	if (recompensas->num_recompensas == 1) {
		contadorRecomp->srcY = 64;
	}
	if (recompensas->num_recompensas == 0) {
		contadorRecomp->srcY = 0;
	}

	maplv1->loadMap(mapa);
};

void Game::render() {
	SDL_RenderClear(renderer);//Clear the renderer of anything

	//Here will be added all the information of the renderer.
	maplv1->drawMap(victoria);

	player1->render();
	/*enemy1->render();
	enemy3->render();*/

	vidas->render();
	contadorRecomp->render();
	SDL_RenderPresent(renderer);
};

void Game::handleEvents() {

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			this->save();
			break;

		case SDLK_RIGHT://Press the keyboard right arrow.
			if (player1->getXPos() < 704 && colision->comprobarMuroderecha(player1->getXPos(), player1->getYPos(), mapa) == false) {
				player1->addXPos();
				player1->setRightToMain();//Change of thexture.
				player1->addYsrc();//Move across the sprite sheet
				player1->posR++;
				recompensas->comprobarRecompensa(player1->getXPos(), player1->getYPos(), coordenadas_recompensa, mapa, recompensas);
				if (recompensas->num_recompensas == 0) {
					victoria = true;
				}
				if (recompensas->comprobarPuerta(player1->getXPos(), player1->getYPos(), victoria) == true) {
					victoria = false;
					recompensas->num_recompensas = 5;
					Game::isRunning = false;
					Game::cerrado = false;
				}
				//SDL_Delay(7);
			}
			break;

		case SDLK_LEFT://Press the keyboard left arrow.
			if (player1->getXPos() > 0 && colision->comprobarMuroizquierda(player1->getXPos(), player1->getYPos(), mapa) == false) {
				player1->subXPos();
				player1->setLeftToMain();//Change of texture.
				player1->addYsrc();//Move across the sprite sheet
				player1->posL++;
				recompensas->comprobarRecompensa(player1->getXPos(), player1->getYPos(), coordenadas_recompensa, mapa, recompensas);
				if (recompensas->num_recompensas == 0) {
					victoria = true;
				}
				if (recompensas->comprobarPuerta(player1->getXPos(), player1->getYPos(), victoria) == true) {
					victoria = false;
					recompensas->num_recompensas = 5;
					Game::isRunning = false;
					Game::cerrado = false;
				}
				//SDL_Delay(7);
			}
			break;

		case SDLK_UP://Press the keyboard up arrow.
			if (player1->getYPos() > 0 && colision->comprobarMuroarriba(player1->getXPos(), player1->getYPos(), mapa) == false) {
				player1->subYPos();
				player1->setUpToMain();
				player1->addYsrc();//Move across the sprite sheet.
				player1->posU++;
				recompensas->comprobarRecompensa(player1->getXPos(), player1->getYPos(), coordenadas_recompensa, mapa, recompensas);
				if (recompensas->num_recompensas == 0) {
					victoria = true;
				}
				if (recompensas->comprobarPuerta(player1->getXPos(), player1->getYPos(), victoria) == true) {
					victoria = false;
					recompensas->num_recompensas = 5;
					Game::isRunning = false;
					Game::cerrado = false;
				}
				//SDL_Delay(7);

			}
			break;

		case SDLK_DOWN://Press the keyboard down arrow.
			if (player1->getYPos() < 704 && colision->comprobarMuroabajo(player1->getXPos(), player1->getYPos(), mapa) == false) {
				player1->addYPos();
				player1->setDownToMain();
				player1->addYsrc();//Move across the sprite sheet.
				player1->posD++;
				recompensas->comprobarRecompensa(player1->getXPos(), player1->getYPos(), coordenadas_recompensa, mapa, recompensas);
				if (recompensas->num_recompensas == 0) {
					victoria = true;
				}
				if (recompensas->comprobarPuerta(player1->getXPos(), player1->getYPos(), victoria) == true && victoria == true) {
					victoria = false;
					recompensas->num_recompensas = 5;
					Game::isRunning = false;
					Game::cerrado = false;
				}
				//SDL_Delay(7);
			}
			break;

		default:
			break;
		}

	default:
		break;
	}
};

void Game::clean() {//Clean the memory from every information created by the program.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
};




//Function used to save all the information of the object in a binary file
void Game::save() {
	
	if (this->getGameSlot() == 1) {
		ofstream file("archives/s1/Player.bin", ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.write((char*)&player1->xpos, sizeof(int));
			file.write((char*)&player1->ypos, sizeof(int));
			file.close();
		}

		ofstream file2("archives/s1/Enemy1.bin", ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.write((char*)&enemy1->xpos, sizeof(int));
			file2.write((char*)&enemy1->ypos, sizeof(int));
			file2.close();
		}

		ofstream file3("archives/s1/Enemy3.bin", ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.write((char*)&enemy3->xpos, sizeof(int));
			file3.write((char*)&enemy3->ypos, sizeof(int));
			file3.close();
		}

		ofstream file4("archives/s1/Prizes.bin", ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.write((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.write((char*)&mapa, sizeof(int[23][23]));
			file4.write((char*)&rec, sizeof(int));
			file4.write((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else if (this->getGameSlot() == 2) {
		ofstream file("archives/s2/Player.bin", ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.write((char*)&player1->xpos, sizeof(int));
			file.write((char*)&player1->ypos, sizeof(int));
			file.close();
		}

		ofstream file2("archives/s2/Enemy1.bin", ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.write((char*)&enemy1->xpos, sizeof(int));
			file2.write((char*)&enemy1->ypos, sizeof(int));
			file2.close();
		}

		ofstream file3("archives/s2/Enemy3.bin", ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.write((char*)&enemy3->xpos, sizeof(int));
			file3.write((char*)&enemy3->ypos, sizeof(int));
			file3.close();
		}

		ofstream file4("archives/s2/Prizes.bin", ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.write((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.write((char*)&mapa, sizeof(int[23][23]));
			file4.write((char*)&rec, sizeof(int));
			file4.write((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else if (this->getGameSlot() == 3) {
		ofstream file("archives/s3/Player.bin", ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.write((char*)&player1->xpos, sizeof(int));
			file.write((char*)&player1->ypos, sizeof(int));
			file.close();
		}

		ofstream file2("archives/s3/Enemy1.bin", ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.write((char*)&enemy1->xpos, sizeof(int));
			file2.write((char*)&enemy1->ypos, sizeof(int));
			file2.close();
		}

		ofstream file3("archives/s3/Enemy3.bin", ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.write((char*)&enemy3->xpos, sizeof(int));
			file3.write((char*)&enemy3->ypos, sizeof(int));
			file3.close();
		}

		ofstream file4("archives/s3/Prizes.bin", ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.write((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.write((char*)&mapa, sizeof(int[23][23]));
			file4.write((char*)&rec, sizeof(int));
			file4.write((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else {
		ofstream file("archives/s4/Player.bin", ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.write((char*)&player1->xpos, sizeof(int));
			file.write((char*)&player1->ypos, sizeof(int));
			file.close();
		}

		ofstream file2("archives/s4/Enemy1.bin", ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.write((char*)&enemy1->xpos, sizeof(int));
			file2.write((char*)&enemy1->ypos, sizeof(int));
			file2.close();
		}

		ofstream file3("archives/s4/Enemy3.bin", ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.write((char*)&enemy3->xpos, sizeof(int));
			file3.write((char*)&enemy3->ypos, sizeof(int));
			file3.close();
		}

		ofstream file4("archives/s4/Prizes.bin", ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.write((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.write((char*)&mapa, sizeof(int[23][23]));
			file4.write((char*)&rec, sizeof(int));
			file4.write((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}
}

//Function used to load all the information of the object in a binary file
void Game::loadPlayer() {
	
	if (this->getGameSlot() == 1) {
		ifstream file("archives/s1/Player.bin", ios::in || ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.seekg(0);
			int x = 0;
			int y = 0;

			file.read((char*)&x, sizeof(int));
			file.read((char*)&y, sizeof(int));
			file.close();

			player1->xpos = x;
			player1->ypos = y;
			player1->initGrafo(grafo);
		}
	}

	else if (this->getGameSlot() == 2) {
		ifstream file("archives/s2/Player.bin", ios::in || ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.seekg(0);
			int x = 0;
			int y = 0;

			file.read((char*)&x, sizeof(int));
			file.read((char*)&y, sizeof(int));
			file.close();

			player1->xpos = x;
			player1->ypos = y;
			player1->initGrafo(grafo);
		}
	}

	else if (this->getGameSlot() == 3) {
		ifstream file("archives/s3/Player.bin", ios::in || ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.seekg(0);
			int x = 0;
			int y = 0;

			file.read((char*)&x, sizeof(int));
			file.read((char*)&y, sizeof(int));
			file.close();

			player1->xpos = x;
			player1->ypos = y;
			player1->initGrafo(grafo);
		}
	}

	else {
		ifstream file("archives/s4/Player.bin", ios::in || ios::binary);
		if (!file.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file.seekg(0);
			int x = 0;
			int y = 0;

			file.read((char*)&x, sizeof(int));
			file.read((char*)&y, sizeof(int));
			file.close();

			player1->xpos = x;
			player1->ypos = y;
			player1->initGrafo(grafo);
		}
	}
}

void Game::loadEnemy1() {
	
	if (this->getGameSlot() == 1) {
		ifstream file2("archives/s1/Enemy1.bin", ios::in || ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.seekg(0);
			int x = 0;
			int y = 0;
			file2.read((char*)&x, sizeof(int));
			file2.read((char*)&y, sizeof(int));
			file2.close();

			enemy1->initGrafo(grafo);
			enemy1->xpos = x;
			enemy1->ypos = y;
		}
	}

	else if (this->getGameSlot() == 2) {
		ifstream file2("archives/s2/Enemy1.bin", ios::in || ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.seekg(0);
			int x = 0;
			int y = 0;
			file2.read((char*)&x, sizeof(int));
			file2.read((char*)&y, sizeof(int));
			file2.close();

			enemy1->initGrafo(grafo);
			enemy1->xpos = x;
			enemy1->ypos = y;
		}
	}

	else if (this->getGameSlot() == 3) {
		ifstream file2("archives/s3/Enemy1.bin", ios::in || ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.seekg(0);
			int x = 0;
			int y = 0;
			file2.read((char*)&x, sizeof(int));
			file2.read((char*)&y, sizeof(int));
			file2.close();

			enemy1->initGrafo(grafo);
			enemy1->xpos = x;
			enemy1->ypos = y;
		}
	}

	else {
		ifstream file2("archives/s4/Enemy1.bin", ios::in || ios::binary);
		if (!file2.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file2.seekg(0);
			int x = 0;
			int y = 0;
			file2.read((char*)&x, sizeof(int));
			file2.read((char*)&y, sizeof(int));
			file2.close();

			enemy1->initGrafo(grafo);
			enemy1->xpos = x;
			enemy1->ypos = y;
		}
	}
}

void Game::loadEnemy3() {
	
	if (this->getGameSlot() == 1) {
		ifstream file3("archives/s1/Enemy3.bin", ios::in || ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.seekg(0);
			int x = 0;
			int y = 0;
			file3.read((char*)&x, sizeof(int));
			file3.read((char*)&y, sizeof(int));
			file3.close();

			enemy3->xpos = x;
			enemy3->ypos = y;
			enemy3->initGrafo(grafo);
		}
	}

	else if (this->getGameSlot() == 2) {
		ifstream file3("archives/s2/Enemy3.bin", ios::in || ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.seekg(0);
			int x = 0;
			int y = 0;
			file3.read((char*)&x, sizeof(int));
			file3.read((char*)&y, sizeof(int));
			file3.close();

			enemy3->xpos = x;
			enemy3->ypos = y;
			enemy3->initGrafo(grafo);
		}
	}

	else if (this->getGameSlot() == 3) {
		ifstream file3("archives/s3/Enemy3.bin", ios::in || ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.seekg(0);
			int x = 0;
			int y = 0;
			file3.read((char*)&x, sizeof(int));
			file3.read((char*)&y, sizeof(int));
			file3.close();

			enemy3->xpos = x;
			enemy3->ypos = y;
			enemy3->initGrafo(grafo);
		}
	}

	else {
		ifstream file3("archives/s4/Enemy3.bin", ios::in || ios::binary);
		if (!file3.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file3.seekg(0);
			int x = 0;
			int y = 0;
			file3.read((char*)&x, sizeof(int));
			file3.read((char*)&y, sizeof(int));
			file3.close();

			enemy3->xpos = x;
			enemy3->ypos = y;
			enemy3->initGrafo(grafo);
		}
	}
}

void Game::loadPrizes() {
	if (this->getGameSlot() == 1) {
		ifstream file4("archives/s1/Prizes.bin", ios::in || ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.seekg(0);
			file4.read((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.read((char*)*mapa, sizeof(int[23][23]));
			file4.read((char*)&rec, sizeof(int));
			file4.read((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else if (this->getGameSlot() == 2) {
		ifstream file4("archives/s2/Prizes.bin", ios::in || ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.seekg(0);
			file4.read((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.read((char*)*mapa, sizeof(int[23][23]));
			file4.read((char*)&rec, sizeof(int));
			file4.read((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else if (this->getGameSlot() == 3) {
		ifstream file4("archives/s3/Prizes.bin", ios::in || ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.seekg(0);
			file4.read((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.read((char*)*mapa, sizeof(int[23][23]));
			file4.read((char*)&rec, sizeof(int));
			file4.read((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}

	else {
		ifstream file4("archives/s4/Prizes.bin", ios::in || ios::binary);
		if (!file4.is_open()) {
			cout << "There is an error. The file cannot be opened" << endl;
			return;
		}
		else {
			file4.seekg(0);
			file4.read((char*)&coordenadas_recompensa, sizeof(int[5][2]));
			file4.read((char*)*mapa, sizeof(int[23][23]));
			file4.read((char*)&rec, sizeof(int));
			file4.read((char*)&recompensas->num_recompensas, sizeof(int));
			file4.close();
		}
	}
}


//SETTERS AND GETTERS
void Game::setLoaded(bool bolean) {
	this->loaded = bolean;
}

void Game::setLevel(int lev) {
	this->level = lev;
}

void Game::setPlayer(int player) {
	this->player = player;
}

void Game::setGameSlot(int GL) {
	this->gameSlot = GL;
}

int Game::getGameSlot() {
	return this->gameSlot;
}