#pragma once
#ifndef CARGAR_H
#define CARGAR_H
#include "Game.h"

class Cargar
{
public:
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    static SDL_Renderer* render;
    static SDL_Event evento;
    void dibujar(const char* texto);

    bool running() { return isRunning; };
    void eventos();
    void clean();
    int respuesta = -1;
    bool cerrado = true;
    SDL_Rect aviso, slots;
private:
    bool isRunning;
    SDL_Window* ventana;
};

#endif