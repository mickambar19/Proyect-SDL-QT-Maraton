#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
#include <string>
#include <vector>
#include "detalle_partida.h"
using namespace std;

class Partida
{
private:
    string cod;
    string fecha;
public:
	vector<Detalle_Partida> detalles;
    Partida();
    string getCod() const;
    void setCod(string value);
    string getFecha() const;
    void setFecha(string value);
};

#endif // PARTIDA_H
