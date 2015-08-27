#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <cstring>
#include <vector>
#include "pregunta.h"
#include "partida.h"
#include "usuario.h"

using namespace std;
class Tablero
{
public:
	Tablero(SDL_Surface*);
	~Tablero();
private:

	void InicializaPosiciones();
	void Win();
	bool Ganador();
	void Juego();
	void Seleccion(int);
	void RecargarTexto(int,int);
	void RecargarPregunta();
	void RecargarTablero();
	void Avanza(int);
	int RCorrecto(int,int);
	void CapturarUsuarios();
	void RecargarUsuarios(string,string);
	SDL_Surface* Pantalla;
	SDL_Surface* Fondo;
	SDL_Surface* P1;
	SDL_Surface* P2;
	SDL_Surface* PI;
	SDL_Surface* Tab;

	Mix_Chunk* Correcto;
	Mix_Chunk* Incorrecto;
	Mix_Music* Tema;
	
	TTF_Font* Fuente;

	int posP1;
	int posP2;
	int posPI;
	string Pre;
	string R1;
	string R2;
	string R3;
	vector<pair<int,int> > XY;
	bool salir;

	vector<Pregunta> preguntas;
	vector<Partida> partidas;
	vector<Usuario> usuarios;
	
	Pregunta pregunta;
	Partida partida;
	Usuario Usu1;
	Usuario Usu2;
};

#endif