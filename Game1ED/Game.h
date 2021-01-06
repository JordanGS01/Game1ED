#pragma once
#ifndef Game_h
#define Game_h

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

class Game {

public:

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int nivel,int personaje,int matriz[23][23]);//Initialice the game object
	void update();//Update the changes that the game is having during process
	void render();//Renderer of the game
	void clean();//For clean the memory
	void handleEvents();// To hand the events ocuring during the game
	bool running() { return isRunning; };//To know if the game is running or not
	void save();
	void loadPlayer();
	void loadEnemy1();
	void loadEnemy3();
	void loadPrizes();

	void setLoaded(bool bolean);
	void setLevel(int lev);
	void setPlayer(int player);
	void setGameSlot(int GL);

	int getGameSlot();


	static SDL_Renderer* renderer;
	static SDL_Event event;

	bool cerrado = true;
private:

	int level, player, gameSlot;
	bool loaded;

	bool isRunning;
	SDL_Window* window;

};

#endif
