#pragma once
#ifndef TEXTURES_H
#define TEXTURES_H

#include "Game.h"

class Texture {
	public:
		static SDL_Texture* LoadTexture(const char* file);
		static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif