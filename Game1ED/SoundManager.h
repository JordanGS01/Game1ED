#pragma once
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Game.h"
//This class is the one who manage all the game sound effects.
class SoundManager {
	public:
		static Mix_Music* chargeMP3(const char* direccion);
		static Mix_Chunk* chargeWAV(const char* direccion);
		static void playMusic(Mix_Music* music);
		static void playChunk(Mix_Chunk* chunk);
		static void pauseButton();
};


#endif
