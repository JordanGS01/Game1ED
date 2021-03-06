#pragma once
#ifndef TEXTURES_H
#define TEXTURES_H

#include "Game.h"

class Texture {
public:
    static SDL_Texture* LoadTexture(const char* file);
    static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
    static SDL_Texture* LoadText(const char* texto, SDL_Color color, SDL_Renderer* render);
    static void draw_interfaz(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
    static void draw_text(SDL_Texture* texture, SDL_Rect dest, SDL_Renderer* render);
    static SDL_Texture* LoadTexture_inter(const char* texture);
};

#endif