#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
#include <string>
using namespace std;

class Partida
{
private:
    string cod;
    string fecha;
public:
    Partida();
    string getCod() const;
    void setCod(string value);
    string getFecha() const;
    void setFecha(string value);
};

#endif // PARTIDA_H
