#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include <iostream>

class MainMenu {
public:
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    static SDL_Renderer* render2;
    static SDL_Event evento;
    int respuesta;
    void dibujar();
    void dibujarPuntuaciones(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5);
    void eventos();
    void clean();
    void setRunning(bool running) { isRunning = running; };
    bool running() { return isRunning; };
    bool cerrado = true;
    bool scores = false;
    SDL_Rect titulo, aviso, partidaNueva, cargar, puntuacion, salir;
private:
    SDL_Window* ventana;
    bool isRunning;
};

#endif