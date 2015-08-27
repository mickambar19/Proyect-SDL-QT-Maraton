#ifndef N_H
#define N_H
#include <fstream>
#include <vector>
#include "partida.h"

using namespace std;

void guardar_Partidas(vector<Partida> partidas);
vector<Partida> cargar_Partidas();

#endif // N_H
