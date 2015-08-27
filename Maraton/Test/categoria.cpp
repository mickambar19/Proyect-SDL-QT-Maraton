#include "categoria.h"

Categoria::Categoria()
{
}
string Categoria::getNombre() const
{
    return nombre;
}

void Categoria::setNombre(string value)
{
    nombre = value;
}

string Categoria::getCod() const
{
    return cod;
}

void Categoria::setCod(string value)
{
    cod = value;
}
/*quiza se ocupen*/
bool operator<(const Categoria &a,const Categoria &b)
{
    return (a.getCod()<b.getCod());
}
bool operator>(const Categoria &a,const Categoria &b)
{
    return (a.getCod()>b.getCod());
}
bool operator==(const Categoria &a,const Categoria &b)
{
    return (a.getCod()==b.getCod());
}
bool operator!=(const Categoria &a,const Categoria &b)
{
    return (a.getCod()!=b.getCod());
}
bool operator<=(const Categoria &a,const Categoria &b)
{
    return (a.getCod()<=b.getCod());
}
bool operator>=(const Categoria &a,const Categoria &b)
{
    return (a.getCod()>=b.getCod());
}

ostream& operator<<(ostream& os,Categoria &a){
    os<<"-----------------\n";
    os<<"Codigo    :"<<a.getCod()<<endl;
    os<<"Nombre    :"<<a.getNombre()<<endl;
    os<<"-----------------\n\n";
    return os;
}

