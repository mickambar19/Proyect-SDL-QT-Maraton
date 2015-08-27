#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Tablero.h"
#include "funciones.h"
#include "pregunta.h"
#include "respuesta.h"
#include "partida.h"
#include "detalle_partida.h"

#define Par pair<int,int>
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define FONT "Pixel.ttf"
#define S_R 5
#define CORRECTO 1
#define INCORRECTO 0

using namespace std;

Tablero::Tablero(SDL_Surface* p)
{
	InicializaPosiciones();
	Pantalla = p;
	Fondo = IMG_Load("FondoTablero.png");
	if (Fondo == NULL)
	{
		cerr << "Error al cargar imagen" << endl << SDL_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	Tab = IMG_Load("Tablero.png");
	if (Tab == NULL)
	{
		cerr << "Error al cargar imagen" << endl << SDL_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	PI = IMG_Load("Ignorancia.png");
	if (PI == NULL)
	{
		cerr << "Error al cargar imagen" << endl << SDL_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	P1 = IMG_Load("Jugador_1.png");
	if (P1 == NULL)
	{
		cerr << "Error al cargar imagen" << endl << SDL_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	P2 = IMG_Load("Jugador_2.png");
	if (P2 == NULL)
	{
		cerr << "Error al cargar imagen" << endl << SDL_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	Fuente = TTF_OpenFont(FONT,22);
	if (Fuente == NULL)
	{
		cerr << "Falló la carga de font" << endl << SDL_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
	}
	Correcto = Mix_LoadWAV("Correcto.wav");
	Incorrecto = Mix_LoadWAV("Incorrecto.wav");
	Tema = Mix_LoadMUS("Tema_Fondo.wav");
	preguntas =  cargar_Archivo();
	partidas = cargar_Partidas();
	usuarios = cargar_Usuarios();

	partida.setCod(to_string((partidas.size()+1)+4000));
	time_t Tiempo;
	time(&Tiempo);
	partida.setFecha(ctime(&Tiempo));

	posP1 = 0;
	posP2 = 0;
	posPI = 0;

	Usu1.setCod(to_string((usuarios.size()+1)+5000));
	Usu2.setCod(to_string((usuarios.size()+2)+5000));

	CapturarUsuarios();
	srand(time(NULL));
	salir = false;
	Juego();
}

Tablero::~Tablero()
{
	SDL_FreeSurface(P1);
	SDL_FreeSurface(P2);
	SDL_FreeSurface(PI);
	SDL_FreeSurface(Tab);
	SDL_FreeSurface(Fondo);

	Mix_FreeChunk(Correcto);
	Mix_FreeChunk(Incorrecto);
	Mix_FreeMusic(Tema);
	TTF_CloseFont(Fuente);

	if(!salir)
	{
		usuarios.push_back(Usu1);
		usuarios.push_back(Usu2);
		partidas.push_back(partida);
		cout << partidas.size() << endl;

		guardar_Partidas(partidas);
		guardar_Usuarios(usuarios);
	}
}

void Tablero::InicializaPosiciones()
{
	XY.push_back(Par(56,20));
	XY.push_back(Par(132,20));
	XY.push_back(Par(208,20));
	XY.push_back(Par(284,20));
	XY.push_back(Par(360,20));
	XY.push_back(Par(436,20));
	XY.push_back(Par(511,20));
	XY.push_back(Par(512,90));
	XY.push_back(Par(512,161));
	XY.push_back(Par(512,231));
	XY.push_back(Par(437,231));
	XY.push_back(Par(361,231));
	XY.push_back(Par(361,161));
	XY.push_back(Par(286,161));
	XY.push_back(Par(210,161));
	XY.push_back(Par(210,231));
	XY.push_back(Par(134,231));
	XY.push_back(Par(58,231));
}

void Tablero::CapturarUsuarios()
{
	string str1;
	string str2;
	SDL_Event event;
	bool flag = false;
	while(1)
	{
		SDL_WaitEvent(&event);
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					str1+='a'; break;
				case SDLK_b:
					str1+='b'; break;
				case SDLK_c:
					str1+='c'; break;
				case SDLK_d:
					str1+='d'; break;			
				case SDLK_e:
					str1+='e'; break;
				case SDLK_f:
					str1+='f'; break;
				case SDLK_g:
					str1+='g'; break;
				case SDLK_h:
					str1+='h'; break;
				case SDLK_i:
					str1+='i'; break;
				case SDLK_j:
					str1+='j'; break;
				case SDLK_k:
					str1+='k'; break;
				case SDLK_l:
					str1+='l'; break;
				case SDLK_m:
					str1+='m'; break;
				case SDLK_n:
					str1+='n'; break;
				case SDLK_o:
					str1+='o'; break;
				case SDLK_p:
					str1+='p'; break;
				case SDLK_q:
					str1+='q'; break;
				case SDLK_r:
					str1+='r'; break;
				case SDLK_s:
					str1+='s'; break;
				case SDLK_t:
					str1+='t'; break;
				case SDLK_u:
					str1+='u'; break;
				case SDLK_v:
					str1+='v'; break;
				case SDLK_w:
					str1+='w'; break;
				case SDLK_x:
					str1+='x'; break;
				case SDLK_y:
					str1+='y'; break;
				case SDLK_z:
					str1+='z'; break;
				case SDLK_SPACE:
					str1+=' '; break;
				case SDLK_BACKSPACE:
					if(!str1.empty()) str1.erase(str1.size()-1,1);
					break;
				case SDLK_RETURN:
					flag = true; break;
			}
		}
		if(event.type == SDL_QUIT)
			SDL_Quit();
		if(flag && !str1.empty()) break;
		flag = false;
		RecargarUsuarios(str1,str2);
	}

	flag = false;

	while(1)
	{
		SDL_WaitEvent(&event);
		if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					str2+='a'; break;
				case SDLK_b:
					str2+='b'; break;
				case SDLK_c:
					str2+='c'; break;
				case SDLK_d:
					str2+='d'; break;			
				case SDLK_e:
					str2+='e'; break;
				case SDLK_f:
					str2+='f'; break;
				case SDLK_g:
					str2+='g'; break;
				case SDLK_h:
					str2+='h'; break;
				case SDLK_i:
					str2+='i'; break;
				case SDLK_j:
					str2+='j'; break;
				case SDLK_k:
					str2+='k'; break;
				case SDLK_l:
					str2+='l'; break;
				case SDLK_m:
					str2+='m'; break;
				case SDLK_n:
					str2+='n'; break;
				case SDLK_o:
					str2+='o'; break;
				case SDLK_p:
					str2+='p'; break;
				case SDLK_q:
					str2+='q'; break;
				case SDLK_r:
					str2+='r'; break;
				case SDLK_s:
					str2+='s'; break;
				case SDLK_t:
					str2+='t'; break;
				case SDLK_u:
					str2+='u'; break;
				case SDLK_v:
					str2+='v'; break;
				case SDLK_w:
					str2+='w'; break;
				case SDLK_x:
					str2+='x'; break;
				case SDLK_y:
					str2+='y'; break;
				case SDLK_z:
					str2+='z'; break;
				case SDLK_SPACE:
					str2+=' '; break;
				case SDLK_BACKSPACE:
					if(!str2.empty()) str2.erase(str2.size()-1,1);
					break;
				case SDLK_RETURN:
					flag = true; break;
			}
		}
		if(event.type == SDL_QUIT)
			SDL_Quit();
		if(flag && !str2.empty()) break;
		flag = false;
		RecargarUsuarios(str1,str2);
	}

	Usu1.setNombre(str1);
	Usu2.setNombre(str2);
	Mix_HaltMusic();
}

void Tablero::RecargarUsuarios(string str1,string str2)
{
	SDL_Rect rect;
	SDL_Surface* texto;
	SDL_Color C1 = {57,100,73};
	SDL_Color C2 = {88,138,158};
	SDL_Color TiCol = {0,0,0};

	SDL_BlitSurface(Fondo,NULL,Pantalla,NULL);

	texto = TTF_RenderUTF8_Blended(Fuente,"Nombre de jugador 1:",TiCol);
	rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	rect.y = (SCREEN_HEIGHT/2) - 100;
	SDL_BlitSurface(texto,NULL,Pantalla,&rect);

	if(!str1.empty())
	{
		texto = TTF_RenderUTF8_Blended(Fuente,str1.c_str(),C1);
		rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
		rect.y = (SCREEN_HEIGHT/2) - 60;
		SDL_BlitSurface(texto,NULL,Pantalla,&rect);
	}

	texto = TTF_RenderUTF8_Blended(Fuente,"Nombre de jugador 2:",TiCol);
	rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	rect.y = (SCREEN_HEIGHT/2) + 60;
	SDL_BlitSurface(texto,NULL,Pantalla,&rect);

	if(!str2.empty())
	{
		texto = TTF_RenderUTF8_Blended(Fuente,str2.c_str(),C2);
		rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
		rect.y = (SCREEN_HEIGHT/2) + 100;
		SDL_BlitSurface(texto,NULL,Pantalla,&rect);
	}

	SDL_Flip(Pantalla);
}

void Tablero::Juego()
{
	SDL_Event event;
	int Jugador = 1;
	Mix_PlayMusic(Tema,-1);
	cout << "ay";
	while(!Ganador())
	{
		RecargarTablero();
		RecargarPregunta();
		Seleccion(Jugador);
		if(Jugador == 1) Jugador = 2;
		else Jugador = 1;
		if(salir) break;
	}
	if(!salir)
	{
		RecargarTablero();
		Win();
		SDL_Flip(Pantalla);
		while(1)
		{
			if(SDL_PollEvent(&event))
			{
				if(event.type == SDL_KEYDOWN)
					break;
			}
		}
	}
}

void Tablero::Seleccion(int p)
{
	int Jugador = p;
	int cont = 0;
	int opc = 0;
	int correcto = S_R;
	SDL_Event event;
	RecargarTexto(opc,Jugador);
	SDL_Flip(Pantalla);
	while(1)
	{
		RecargarTablero();
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:
						if(opc == 0) opc = 2;
						else opc--;
						break;

					case SDLK_DOWN:
						if(opc == 2) opc = 0;
						else opc++;
						break;

					case SDLK_SPACE:
						correcto = RCorrecto(opc,Jugador);
						break;

					case SDLK_BACKSPACE:
						event.type = SDL_QUIT;
						break;
				}
			}
			if(event.type == SDL_QUIT)
			{
				salir = true;
				break;
			}
		}
		if(correcto != S_R)
		{
			if(correcto == CORRECTO)
				break;
			else
			{
				if(cont == 1)
				{
					cont++;
					break;
				}
				cont++;
				if(Jugador == 1) Jugador = 2;
				else Jugador = 1;
				correcto = S_R;
			}
		}
		RecargarTexto(opc,Jugador);
		SDL_Flip(Pantalla);
	}
	if(cont == 2)
		Avanza(cont+1);
	else
		Avanza(Jugador);
}

void Tablero::RecargarTexto(int opc,int j)
{
	SDL_Rect Re1;
	SDL_Rect Re2;
	SDL_Rect Re3;
	SDL_Rect rect;
	SDL_Surface* texto;
	SDL_Color Nel = {115,115,115};
	SDL_Color Sel = {192,192,192};
	SDL_Color C1 = {57,100,73};
	SDL_Color C2 = {88,138,158};
	SDL_Color TiCol = {0,0,0};
	texto = TTF_RenderUTF8_Blended(Fuente,Pre.c_str(),TiCol);
	rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	rect.y = 320;
	SDL_BlitSurface(texto,NULL,Pantalla,&rect);
	if(j == 1) texto = TTF_RenderUTF8_Blended(Fuente,Usu1.getNombre().c_str(),C1);
	else texto = TTF_RenderUTF8_Blended(Fuente,Usu2.getNombre().c_str(),C2);
	rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	rect.y = 102;
	SDL_BlitSurface(texto ,NULL,Pantalla,&rect);
	texto = TTF_RenderUTF8_Blended(Fuente,R1.c_str(),Sel);
	Re1.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	Re1.y = 360;
	texto = TTF_RenderUTF8_Blended(Fuente,R2.c_str(),Sel);
	Re2.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	Re2.y = 390;
	texto = TTF_RenderUTF8_Blended(Fuente,R3.c_str(),Sel);
	Re3.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	Re3.y = 420;

	switch (opc)
	{
		case 0:
			texto = TTF_RenderUTF8_Blended(Fuente,R1.c_str(),Sel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re1);
			texto = TTF_RenderUTF8_Blended(Fuente,R2.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re2);
			texto = TTF_RenderUTF8_Blended(Fuente,R3.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re3);
			break;
		case 1:
			texto = TTF_RenderUTF8_Blended(Fuente,R1.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re1);
			texto = TTF_RenderUTF8_Blended(Fuente,R2.c_str(),Sel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re2);
			texto = TTF_RenderUTF8_Blended(Fuente,R3.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re3);
			break;
		case 2:
			texto = TTF_RenderUTF8_Blended(Fuente,R1.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re1);
			texto = TTF_RenderUTF8_Blended(Fuente,R2.c_str(),Nel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re2);
			texto = TTF_RenderUTF8_Blended(Fuente,R3.c_str(),Sel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Re3);
			break;
	}
}

void Tablero::RecargarPregunta()
{
	if(preguntas.size() == 0) preguntas = cargar_Archivo();
	int posicion = rand() % preguntas.size();
	cout << posicion;
	cout << preguntas[posicion].getNombre() << endl;

	pregunta = preguntas[posicion];
	preguntas.erase(preguntas.begin() + posicion);

	Pre = pregunta.getNombre();
	R1 = pregunta.respuestas[0].getDescripcion();
	R2 = pregunta.respuestas[1].getDescripcion();
	R3 = pregunta.respuestas[2].getDescripcion();
}

bool Tablero::Ganador()
{
	if(posP1 == 17)
		return true;
	if(posP2 == 17)
		return true;
	if(posPI == 17)
		return true;
	return false;
}

void Tablero::Avanza(int p)
{
	switch(p)
	{
		case 1:
			for (int i = 0; i < atoi(pregunta.getPuntos().c_str()); ++i)
				posP1++;
			break;

		case 2:
			for (int i = 0; i < atoi(pregunta.getPuntos().c_str()); ++i)
				posP2++;
			break;

		case 3:
			posPI++;
			break;
	}
}

void Tablero::RecargarTablero()
{
	SDL_Rect rect;
	SDL_BlitSurface(Fondo,NULL,Pantalla,NULL);
	SDL_BlitSurface(Tab,NULL,Pantalla,NULL);
	if(posP1 <= 17)
	{
		rect.x = XY[posP1].first;
		rect.y = XY[posP1].second;
	}
	else
	{
		rect.x = XY[17].first;
		rect.y = XY[17].second;
	}
	SDL_BlitSurface(P1,NULL,Pantalla,&rect);
	if(posP2 <= 17)
	{
		rect.x = XY[posP2].first+15;
		rect.y = XY[posP2].second+10;
	}
	else
	{
		rect.x = XY[17].first+15;
		rect.y = XY[17].second+10;
	}
	SDL_BlitSurface(P2,NULL,Pantalla,&rect);
	if(posPI <= 17)
	{
		rect.x = XY[posPI].first+30;
		rect.y = XY[posPI].second+20;
	}
	else
	{
		rect.x = XY[17].first+30;
		rect.y = XY[17].second+20;
	}
	SDL_BlitSurface(PI,NULL,Pantalla,&rect);
}

int Tablero::RCorrecto(int opc,int j)
{
	Detalle_Partida det;
	det.setPartida(partida.getCod());
	if(j == 1) det.setCodUsuario(Usu1.getCod());
	else det.setCodUsuario(Usu2.getCod());
	det.setCodPregunta(pregunta.getCod());
	det.setCodRespuesta(pregunta.respuestas[opc].getCod());
	if(pregunta.respuestas[opc].getCorrecta() == "1")
	{
		Mix_PlayChannel(-1,Correcto,0);
		det.setPuntosdeResp(pregunta.getPuntos());
		partida.detalles.push_back(det);
		return CORRECTO;
	}

	else 
	{
		Mix_PlayChannel(-1,Incorrecto,0);
		det.setPuntosdeResp("0");
		partida.detalles.push_back(det);
		return INCORRECTO;
	}
}

void Tablero::Win()
{
	SDL_Rect rect;
	Detalle_Partida det;
	det.setPartida(partida.getCod());
	string aux = "El ganador es ";
	SDL_Surface* texto;
	SDL_Color C1 = {57,100,73};
	SDL_Color C2 = {88,138,158};
	SDL_Color TiCol = {0,0,0};
	cout << posP1 << " " << posP2 << endl;
	if(posP1 == 17) 
	{
		det.setCodUsuario(Usu1.getNombre());
		det.setPuntosdeResp(to_string(posP1));
		aux+= Usu1.getNombre();
		texto = TTF_RenderUTF8_Blended(Fuente,aux.c_str(),C1);
	}
	else if(posP2 == 17)
	{
		det.setCodUsuario(Usu1.getNombre());
		det.setPuntosdeResp(to_string(posP2));
		aux += Usu2.getNombre();
		texto = TTF_RenderUTF8_Blended(Fuente,aux.c_str(),C2);
	}
	else
	{
		det.setCodUsuario("Ignorancia");
		det.setPuntosdeResp(to_string(posPI));
		aux+= "La ignorancia";
		texto = TTF_RenderUTF8_Blended(Fuente,aux.c_str(),TiCol);
	}
	partida.detalles.push_back(det);
	rect.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	rect.y = 320;
	SDL_BlitSurface(texto,NULL,Pantalla,&rect);
}