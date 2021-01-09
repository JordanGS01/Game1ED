#include "MMap.h"
#include "Textures.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
//Matrix that we use to paint the map
int lvl1[23][23] = {
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};


//The constructor recives the directions if the local disc in where the floor and walss
//png are located.
Map::Map(const char* wallDir, const char* floorDir) {
    wall = Texture::LoadTexture(wallDir);
    floor = Texture::LoadTexture(floorDir);


    loadMap(lvl1);

    src.x = src.y = 0;//Location in the source image.
    src.h = src.w = 32;//Dimention of the image.

    dest.w = dest.h = 32;//Dimentions of the destination position.
    dest.x = dest.y = 32;//Destination of the image on the pixels map.
}

//To charge the matrix values.
void Map::loadMap(int arr[23][23]) {
    for (int row = 0; row < 23; row++) {
        for (int column = 0; column < 23; column++) {
            map[row][column] = arr[row][column];
        }
    }
}

//Draws the map on screen.
//The matrix values tell us what to draw in each space.
void Map::drawMap(bool victoria) {
    int typeObj = 0;//This variable helps to know what image use to draw the laberint.
     
    SDL_Texture* mino = Texture::LoadTexture("sprites/minotauro.png");
    SDL_Texture* recompensa = Texture::LoadTexture("sprites/oro.png");
    SDL_Texture* puerta = Texture::LoadTexture("sprites/puerta.png");

    for (int row = 0; row < 23; row++) {
        for (int column = 0; column < 23; column++) {

            typeObj = map[row][column];
            dest.x = column * 32;
            dest.y = row * 32;


            switch (typeObj)
            {                
            case 1:
                Texture::draw(floor, src, dest);
                Texture::draw(wall, src, dest);
                break;
            case 0:
                Texture::draw(floor, src, dest);
                break;
            case 2:
                Texture::draw(floor, src, dest);
                Texture::draw(recompensa, src, dest);
                break;
            case 3:
                Texture::draw(floor, src, dest);
                Texture::draw(mino, src, dest);
                break;
            case 5:
                if (victoria == false) {
                    Texture::draw(wall, src, dest);
                    Texture::draw(puerta, src, dest);
                }
                else {

                    Texture::draw(wall, src, dest);
                    src.x = 32;
                    Texture::draw(puerta, src, dest);
                    src.x = 0;
                }
                break;
            default:
                break;
            }
        }
    }
}
