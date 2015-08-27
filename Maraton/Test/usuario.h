#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
using namespace std;
class Usuario
{
private:
    string cod;
    string nombre;
public:
    Usuario();
    string getCod() const;
    void setCod(string value);
    string getNombre() const;
    void setNombre(string value);
};

#endif // USUARIO_H
