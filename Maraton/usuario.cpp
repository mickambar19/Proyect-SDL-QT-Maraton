#include "usuario.h"

Usuario::Usuario()
{
}
string Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(string value)
{
    nombre = value;
}

string Usuario::getCod() const
{
    return cod;
}

void Usuario::setCod(string value)
{
    cod = value;
}

/*quiza se ocupen*/
bool operator<(const Usuario &a,const Usuario &b)
{
    return (a.getCod()<b.getCod());
}
bool operator>(const Usuario &a,const Usuario &b)
{
    return (a.getCod()>b.getCod());
}
bool operator==(const Usuario &a,const Usuario &b)
{
    return (a.getCod()==b.getCod());
}
bool operator!=(const Usuario &a,const Usuario &b)
{
    return (a.getCod()!=b.getCod());
}
bool operator<=(const Usuario &a,const Usuario &b)
{
    return (a.getCod()<=b.getCod());
}
bool operator>=(const Usuario &a,const Usuario &b)
{
    return (a.getCod()>=b.getCod());
}

ostream& operator<<(ostream& os,Usuario &a){
    os<<"-----------------\n";
    os<<"Codigo    :"<<a.getCod()<<endl;
    os<<"Nombre    :"<<a.getNombre()<<endl;
    os<<"-----------------\n\n";
    return os;
}

