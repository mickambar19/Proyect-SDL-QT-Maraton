#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>
#include <string>
using namespace std;
class Categoria
{
private:
    string cod;
    string nombre;
public:
    Categoria();
    string getCod() const;
    void setCod(string value);
    string getNombre() const;
    void setNombre(string value);
};

#endif // CATEGORIA_H
