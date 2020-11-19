#pragma once
#ifndef Game_h
#define Game_h

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

class Game {

public:

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);//Initialice the game object
	void update();//Update the changes that the game is having during process
	void render();//Renderer of the game
	void clean();//For clean the memory
	void handleEvents();// To hand the events ocuring during the game

	bool running() { return isRunning; };//To know if the game is running or not
	 
	static SDL_Renderer* renderer;
	static SDL_Event event;
private:
	bool isRunning;
	SDL_Window* window;

};

#endif

