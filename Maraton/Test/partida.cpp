#include "partida.h"

Partida::Partida()
{
}

string Partida::getCod() const
{
    return cod;
}

void Partida::setCod(string value)
{
    cod = value;
}

string Partida::getFecha() const
{
    return fecha;
}

void Partida::setFecha(string value)
{
    fecha = value;
}
/*quiza se ocupen*/
bool operator<(const Partida &a,const Partida &b)
{
    return (a.getCod()<b.getCod());
}
bool operator>(const Partida &a,const Partida &b)
{
    return (a.getCod()>b.getCod());
}
bool operator==(const Partida &a,const Partida &b)
{
    return (a.getCod()==b.getCod());
}
bool operator!=(const Partida &a,const Partida &b)
{
    return (a.getCod()!=b.getCod());
}
bool operator<=(const Partida &a,const Partida &b)
{
    return (a.getCod()<=b.getCod());
}
bool operator>=(const Partida &a,const Partida &b)
{
    return (a.getCod()>=b.getCod());
}

ostream& operator<<(ostream& os,Partida &a){
    os<<"-----------------\n";
    os<<"Codigo    :"<<a.getCod()<<endl;
    os<<"Fecha    :"<<a.getFecha()<<endl;
    os<<"-----------------\n\n";
    return os;
}
