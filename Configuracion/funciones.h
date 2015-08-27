#ifndef N_H
#define N_H
#include <fstream>
#include <vector>
#include "pregunta.h"

using namespace std;

void guardar_Archivo(vector<Pregunta> vPreguntas);
vector<Pregunta> cargar_Archivo();

#endif // N_H
