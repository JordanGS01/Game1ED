#pragma once
#ifndef VICTORIA_H
#define VICTORIA_H

#include "Game.h"

class Victoria {
public:
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    static SDL_Renderer* render;
    void dibujar(time_t tiempo);
    void clean();

    bool running() { return isRunning; };
    SDL_Rect titulo, aviso, puntuacion;

private:
    SDL_Window* ventana;
    bool isRunning = true;
};

#endif