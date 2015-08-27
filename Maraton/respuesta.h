#ifndef RESPUESTA_H
#define RESPUESTA_H
#include <iostream>
#include <string>
using namespace std;
class Respuesta
{
private:
    string cod;
    string descripcion;
    string codPregunta;
    string correcta;
public:
    Respuesta();
    string getCod() const;
    void setCod(string value);
    string getDescripcion() const;
    void setDescripcion(string value);
    string getCodPregunta() const;
    void setCodPregunta(string value);
    string getCorrecta() const;
    void setCorrecta(string value);
};

#endif // RESPUESTA_H
