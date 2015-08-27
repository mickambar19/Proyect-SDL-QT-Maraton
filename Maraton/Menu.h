#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

class Menu
{
public:
	Menu();
	~Menu();
	void Principal();
	void Opciones(SDL_Event event, int& opc);

private:

	SDL_Surface *Pantalla;
	SDL_Surface *Fondo;
	SDL_Rect rctFondo;
	int opc;
	TTF_Font *Fuente;
	TTF_Font *OFuente;
	SDL_Rect Titulo;
	Mix_Music *Tema;
	bool close;
};

#endif