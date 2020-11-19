#include "Game.h"
#include "Textures.h"
#include "GameObj.h"
#include "MMap.h"
#include "mapsMatrix.h"
#include "Player.h"

#include <iostream>
//_____________________________________
//Game objects
Player* player1;

Map* maplv1;//Map of the first level


SDL_Event Game::event;//To handle the game events.
SDL_Renderer* Game::renderer = nullptr;

//Recives the title of the game, x and y possition in screen of the window, width and height if the window.
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//If SDL isn't initialized
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}
	else {//If there's some problem, we didn't initialize anything.
		isRunning = false;
	}
	
	player1 = new Player("sprites/rightMovement.png","sprites/leftMovement.png","sprites/upMovement.png","sprites/downMovement.png", 32, 32);
	maplv1 = new Map("sprites/new-wall-lv1.png", "sprites/floor_lv1.png");

	//PROOF-------------------------------------------
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4048);
	player1->deadSound = Mix_LoadWAV("sounds/death.wav");
	player1->apearSound = Mix_LoadWAV("sounds/beggining.wav");

	Mix_PlayChannel(-1, player1->apearSound, 0);
};

//
void Game::update() {

	player1->update();
	maplv1->loadMap(mlvl1);
};


void Game::render() {
	SDL_RenderClear(renderer);//Clear the renderer of anything

	//Here will be added all the information of the renderer.
	
	maplv1->drawMap();

	player1->render();
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
		case SDLK_RIGHT://Press the keyboard right arrow.
			if (player1->getXPos() < 704) {
				player1->addXPos();
				player1->setRightToMain();//Change of thexture.
				player1->addYsrc();//Move across the sprite sheet
				SDL_Delay(30);
			}
			break;

		case SDLK_LEFT://Press the keyboard left arrow.
			if (player1->getXPos() > 0) {
				player1->subXPos();
				player1->setLeftToMain();//Change of texture.
				player1->addYsrc();//Move across the sprite sheet
				SDL_Delay(30);
			}
			break;

		case SDLK_UP://Press the keyboard up arrow.
			if (player1->getYPos() > 0) {
				player1->subYPos();
				player1->setUpToMain();
				player1->addYsrc();//Move across the sprite sheet.
				SDL_Delay(30);

			}
			break;

		case SDLK_DOWN://Press the keyboard down arrow.
			if (player1->getYPos() < 704) {
				player1->addYPos();
				player1->setDownToMain();
				player1->addYsrc();//Move across the sprite sheet.
				SDL_Delay(30);
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
	SDL_Quit();
};
