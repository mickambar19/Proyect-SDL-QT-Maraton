#include <iostream>
#include <vector>
#include <cstring>
#include "usuario.h"
#include "pregunta.h"
#include "respuesta.h"
#include "funciones.h"
using namespace std;

int main(int argc, char const *argv[])
{
	vector<Pregunta> Preguntas;
	Pregunta pregunta;
	Respuesta respuesta;
	string aux;

	Preguntas = cargar_Archivo();

	for (auto it = Preguntas.begin(); it != Preguntas.end(); it++)
	{
		cout << (*it).getCod() << endl;
		cout << (*it).getNombre() << endl;
		cout << (*it).getPuntos() << endl;
		cout << (*it).getCategoria() << endl;
		for (auto i = (*it).respuestas.begin(); i != (*it).respuestas.end(); i++)
		{
			cout << (*i).getCod() << endl;
			cout << (*i).getDescripcion() << endl;
			cout << (*i).getCodPregunta() << endl;
			cout << (*i).getCorrecta() << endl;
		}
	}
	/*
	getline(cin,aux);
	pregunta.setCod(aux);
	getline(cin,aux);
	pregunta.setNombre(aux);
	getline(cin,aux);
	pregunta.setPuntos(aux);
	getline(cin,aux);
	pregunta.setCategoria(aux);
	
	for (int i = 0; i < 3; i++)
	{
		getline(cin,aux);
		respuesta.setCod(aux);
		getline(cin,aux);
		respuesta.setDescripcion(aux);
		getline(cin,aux);
		respuesta.setCodPregunta(aux);
		getline(cin,aux);
		respuesta.setCorrecta(aux);
		pregunta.respuestas.push_back(respuesta);
	}
	for (int i = 0; i < 15; i++)		
		Preguntas.push_back(pregunta);

	guardar_Archivo(Preguntas);*/
	return 0;
}