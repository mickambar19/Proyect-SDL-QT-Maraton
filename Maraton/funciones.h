#ifndef N_H
#define N_H
#include <fstream>
#include <vector>
#include "pregunta.h"
#include "partida.h"
#include "usuario.h"

using namespace std;
void guardar_Archivo(vector<Pregunta> vPreguntas);
vector<Pregunta> cargar_Archivo();

void guardar_Partidas(vector<Partida> partidas);
vector<Partida> cargar_Partidas();

void guardar_Usuarios(vector<Usuario> usuarios);
vector<Usuario> cargar_Usuarios();
#endif // N_H
