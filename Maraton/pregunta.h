#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <iostream>
#include <string>
#include <vector>
#include "respuesta.h"
using namespace std;
class Pregunta
{
private:
    string cod;
    string nombre;
    string puntos;
    string categoria;
public:
    Pregunta();
    vector<Respuesta> respuestas;
    string getCod() const;
    void setCod(string value);
    string getNombre() const;
    void setNombre(string value);
    string getPuntos() const;
    void setPuntos(string value);
    string getCategoria() const;
    void setCategoria(string value);
};

#endif // PREGUNTA_H
