#ifndef DETALLE_PARTIDA_H
#define DETALLE_PARTIDA_H
#include <iostream>
#include <string>
using namespace std;
class Detalle_Partida
{
private:
    string partida;
    string codUsuario;
    string codPregunta;
    string codRespuesta;
    string puntosdeResp;//puntos de respuesta
public:
    Detalle_Partida();
    string getPartida() const;
    void setPartida(string value);
    string getCodUsuario() const;
    void setCodUsuario(string value);
    string getCodPregunta() const;
    void setCodPregunta(string value);
    string getCodRespuesta() const;
    void setCodRespuesta(string value);
    string getPuntosdeResp() const;
    void setPuntosdeResp(string value);
};

#endif // DETALLE_PARTIDA_H
