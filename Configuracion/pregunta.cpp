#include "pregunta.h"
Pregunta::Pregunta()
{
}
string Pregunta::getCategoria() const
{
    return categoria;
}

void Pregunta::setCategoria(string value)
{
    categoria = value;
}

string Pregunta::getPuntos() const
{
    return puntos;
}

void Pregunta::setPuntos(string value)
{
    puntos = value;
}

string Pregunta::getNombre() const
{
    return nombre;
}

void Pregunta::setNombre(string value)
{
    nombre = value;
}

string Pregunta::getCod() const
{
    return cod;
}

void Pregunta::setCod(string value)
{
    cod = value;
}

/*quiza se ocupen*/
bool operator<(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()<b.getCod());
}
bool operator>(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()>b.getCod());
}
bool operator==(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()==b.getCod());
}
bool operator!=(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()!=b.getCod());
}
bool operator<=(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()<=b.getCod());
}
bool operator>=(const Pregunta &a,const Pregunta &b)
{
    return (a.getCod()>=b.getCod());
}

ostream& operator<<(ostream& os,Pregunta &a){
    os<<"-----------------\n";
    os<<"Codigo    :"<<a.getCod()<<endl;
    os<<"Nombre    :"<<a.getNombre()<<endl;
    os<<"Puntos   :"<<a.getPuntos()<<endl;
    os<<"Categoria    :"<<a.getCategoria()<<endl;
    os<<"-----------------\n\n";
    return os;
}
