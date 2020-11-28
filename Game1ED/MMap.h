#pragma once
#ifndef MMAP_H
#define MMAP_H
#include "Game.h"

class Map {

public:
	Map(const char* wallDir, const char* floorDir);


	void loadMap(int arr[23][23]);
	void drawMap(bool victoria);

private:
	SDL_Rect src, dest;

	SDL_Texture* wall;
	SDL_Texture* floor;

	int map[23][23];
};

#endif