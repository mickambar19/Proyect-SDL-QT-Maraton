#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Menu.h"
#include "Tablero.h"
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define FONT "Rakoon_PersonalUse.ttf"
#define OPFONT "The Chicken love Story.ttf"

//Turquoise Hexagon Sun
using namespace std;

Menu::Menu()
{

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cerr << "Fallo inicio" << endl << SDL_GetError() << endl;
		exit(1);
	}

	Pantalla = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if( Pantalla == NULL )
	{
		cerr << "Falló video" << endl << SDL_GetError() << endl;
	}

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,1024) == -1)
	{
		cerr << "Falló audio" << endl << Mix_GetError() << endl;
	}
	if( TTF_Init() != 0 )
	{
		cerr << "Falló inicio de font" << endl << SDL_GetError() << endl;
	}

	Fuente = TTF_OpenFont(FONT,94);
	OFuente = TTF_OpenFont(OPFONT,52);

	if (Fuente == NULL)
	{
		cerr << "Falló la carga de font" << endl << SDL_GetError() << endl;
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	if (OFuente == NULL)
	{
		cerr << "Falló la carga de font" << endl << SDL_GetError() << endl;
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}

	Fondo = IMG_Load("FondoMenu.png");
	
	if (Fondo == NULL)
	{
		cerr << "Falló la carga de fondo" << endl << SDL_GetError() << endl;
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}

	Tema = Mix_LoadMUS("Tema.wav");

	if (Tema == NULL)
	{
		cerr << "Falló la carga de música" << endl << Mix_GetError();
		Mix_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	close = false;
	Principal();
}

void Menu::Principal()
{
	int opc = 0;
	SDL_Event event;
	SDL_Color TiCol = {4,68,100};
	Titulo.x = 140;
	Titulo.y = 45;

	SDL_Surface* texto = TTF_RenderUTF8_Blended(Fuente,"Maratón",TiCol);
	SDL_BlitSurface(Fondo,NULL,Pantalla,NULL);
	SDL_BlitSurface(texto,NULL,Pantalla,&Titulo);
	Opciones(event,opc);
	Mix_PlayMusic(Tema,0);
	SDL_Flip(Pantalla);
	//SDL_EnableKeyRepeat(200,100);
	while(1)
	{
		if(close)
		{
			Mix_PauseMusic();
			if(opc == 2) system("./Historial");
			else system("./Configuracion");
			Mix_ResumeMusic();
			close = false;
		}
		if (SDL_PollEvent(&event))
		{
	         // Check for the quit message
			if (event.type == SDL_QUIT)
	        {
	            // Quit the program
	            break;
	        }

	        if(event.type == SDL_KEYDOWN)
	        {	
	        	SDL_FillRect(Pantalla, NULL, 0x000000);
				SDL_BlitSurface(Fondo,NULL,Pantalla,NULL);
				SDL_BlitSurface(texto,NULL,Pantalla,&Titulo);
	        	Opciones(event,opc);
	        	SDL_Flip(Pantalla);
	        }
		}
	}

}

void Menu::Opciones(SDL_Event event,int& opc){

	SDL_Rect Opc1;
	SDL_Rect Opc2;
	SDL_Rect Opc3;
	SDL_Surface* texto;
	SDL_Color SiSel = {255,85,0};
	SDL_Color NoSel = {0,255,230};
	SDL_Color TiCol = {4,68,100};

	texto = TTF_RenderUTF8_Blended(OFuente,"Iniciar",SiSel);
	Opc1.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	texto = TTF_RenderUTF8_Blended(OFuente,"Historial",NoSel);
	Opc2.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	texto = TTF_RenderUTF8_Blended(OFuente,"Configuracion",NoSel);
	Opc3.x = (SCREEN_WIDTH/2) - (texto->w / 2);
	
	Opc1.y = 270;
	//Opc2.x = 245;
	Opc2.y = 320;
	//Opc3.x = 245;
	Opc3.y = 370;

	if(opc == 0){
		texto = TTF_RenderUTF8_Blended(OFuente,"Iniciar",SiSel);
		SDL_BlitSurface(texto,NULL,Pantalla,&Opc1);
		texto = TTF_RenderUTF8_Blended(OFuente,"Historial",NoSel);
		SDL_BlitSurface(texto,NULL,Pantalla,&Opc2);
		texto = TTF_RenderUTF8_Blended(OFuente,"Configuracion",NoSel);
		SDL_BlitSurface(texto,NULL,Pantalla,&Opc3);
		opc++;
		return;
	}

	switch(event.key.keysym.sym){

		case SDLK_UP:
			if(opc == 1)
				opc = 3;
			else
				opc--;
			break;

		case SDLK_DOWN:
			if(opc == 3)
				opc = 1;
			else
				opc++;
			break;

		case SDLK_RETURN:
		case SDLK_SPACE:
			if(opc == 1)
			{
				//Mix_HaltMusic();
				Tablero tablero(Pantalla);
				Mix_PlayMusic(Tema,-1);
				texto = TTF_RenderUTF8_Blended(Fuente,"Maratón",TiCol);
				SDL_FillRect(Pantalla, NULL, 0x000000);
				SDL_BlitSurface(Fondo,NULL,Pantalla,NULL);
				SDL_BlitSurface(texto,NULL,Pantalla,&Titulo);
			}
			else
			{
				close = true;
			}
			break;


	}

	switch(opc){

		case 1:
			texto = TTF_RenderUTF8_Blended(OFuente,"Iniciar",SiSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc1);
			texto = TTF_RenderUTF8_Blended(OFuente,"Historial",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc2);
			texto = TTF_RenderUTF8_Blended(OFuente,"Configuracion",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc3);
			break;

		case 2:
			texto = TTF_RenderUTF8_Blended(OFuente,"Iniciar",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc1);
			texto = TTF_RenderUTF8_Blended(OFuente,"Historial",SiSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc2);
			texto = TTF_RenderUTF8_Blended(OFuente,"Configuracion",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc3);
			break;

		case 3:
			texto = TTF_RenderUTF8_Blended(OFuente,"Iniciar",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc1);
			texto = TTF_RenderUTF8_Blended(OFuente,"Historial",NoSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc2);
			texto = TTF_RenderUTF8_Blended(OFuente,"Configuracion",SiSel);
			SDL_BlitSurface(texto,NULL,Pantalla,&Opc3);
			break;
	}
}

Menu::~Menu()
{
	SDL_FreeSurface(Pantalla);
	SDL_FreeSurface(Fondo);

	Mix_FreeMusic(Tema);

	TTF_CloseFont(Fuente);
	TTF_CloseFont(OFuente);

	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}