#include "SoundManager.h"

//Function used to charge sound effects with ".wav" extention.
//The function revices the path of the "sound.wav"
//Return the Mix_Chunk element initialize
Mix_Chunk* SoundManager::chargeWAV(const char* direccion) {
	Mix_Chunk* auxWAV = Mix_LoadWAV(direccion);

	if (auxWAV != nullptr) {//If the element was initialize correctly
		return auxWAV;
	}
}

//Function used to charge sound effects with ".mp3" extention.
//The function revices the path of the "music.mp3"
//Return the Mix_Music* element initialize
Mix_Music* SoundManager::chargeMP3(const char* direccion) {
	Mix_Music* auxMusic = Mix_LoadMUS(direccion);

	if (auxMusic != nullptr) {
		return auxMusic;
	}
}

//Call this function to play a sound effect
//It recives the sound effect you want to play
//(It has to be Mix_Chunk* class object)
void SoundManager::playChunk(Mix_Chunk* chunk) {
	Mix_PlayChannel(-1,chunk,0);
}

//Call this function to play music
//It recives the music you want to play
//(It has to be Mix_Music* class object)
void SoundManager::playMusic(Mix_Music* music) {
	Mix_PlayMusic(music,-1);
}

//In case that the music is already initialize.
//The objetive is to used it for a "pause music" button
void SoundManager::pauseButton() {
	if (Mix_PausedMusic()) {
		Mix_ResumeMusic();
	}
	else {
		Mix_PauseMusic();
	}
}