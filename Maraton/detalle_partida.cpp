#include "detalle_partida.h"


string Detalle_Partida::getPartida() const
{
    return partida;
}

void Detalle_Partida::setPartida(string value)
{
    partida = value;
}

string Detalle_Partida::getCodUsuario() const
{
    return codUsuario;
}

void Detalle_Partida::setCodUsuario(string value)
{
    codUsuario = value;
}

string Detalle_Partida::getCodPregunta() const
{
    return codPregunta;
}

void Detalle_Partida::setCodPregunta(string value)
{
    codPregunta = value;
}

string Detalle_Partida::getCodRespuesta() const
{
    return codRespuesta;
}

void Detalle_Partida::setCodRespuesta(string value)
{
    codRespuesta = value;
}

string Detalle_Partida::getPuntosdeResp() const
{
    return puntosdeResp;
}

void Detalle_Partida::setPuntosdeResp(string value)
{
    puntosdeResp = value;
}
Detalle_Partida::Detalle_Partida()
{
}
/*quiza se ocupen*/
bool operator<(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()<b.getPartida());
}
bool operator>(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()>b.getPartida());
}
bool operator==(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()==b.getPartida());
}
bool operator!=(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()!=b.getPartida());
}
bool operator<=(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()<=b.getPartida());
}
bool operator>=(const Detalle_Partida &a,const Detalle_Partida &b)
{
    return (a.getPartida()>=b.getPartida());
}

ostream& operator<<(ostream& os,Detalle_Partida &a){
    os<<"-----------------\n";
    os<<"Partidaigo    :"<<a.getPartida()<<endl;
    os<<"Codigo Usuario   :"<<a.getCodUsuario()<<endl;
    os<<"Codigo Pregunta   :"<<a.getCodPregunta()<<endl;
    os<<"Codigo Respuesta   :"<<a.getCodRespuesta()<<endl;
    os<<"Puntos Respuesta  :"<<a.getPuntosdeResp()<<endl;
    os<<"-----------------\n\n";
    return os;
}
