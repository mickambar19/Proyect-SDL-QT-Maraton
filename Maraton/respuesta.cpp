#include "respuesta.h"

Respuesta::Respuesta()
{
}
string Respuesta::getCorrecta() const
{
    return correcta;
}

void Respuesta::setCorrecta(string value)
{
    correcta = value;
}

string Respuesta::getCodPregunta() const
{
    return codPregunta;
}

void Respuesta::setCodPregunta(string value)
{
    codPregunta = value;
}

string Respuesta::getDescripcion() const
{
    return descripcion;
}

void Respuesta::setDescripcion(string value)
{
    descripcion = value;
}

string Respuesta::getCod() const
{
    return cod;
}

void Respuesta::setCod(string value)
{
    cod = value;
}
/*quiza se ocupen*/
bool operator<(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()<b.getCod());
}
bool operator>(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()>b.getCod());
}
bool operator==(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()==b.getCod());
}
bool operator!=(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()!=b.getCod());
}
bool operator<=(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()<=b.getCod());
}
bool operator>=(const Respuesta &a,const Respuesta &b)
{
    return (a.getCod()>=b.getCod());
}

ostream& operator<<(ostream& os,Respuesta &a){
    os<<"-----------------\n";
    os<<"Codigo    :"<<a.getCod()<<endl;
    os<<"Nombre    :"<<a.getDescripcion()<<endl;
    os<<"codigo pregunta   :"<<a.getCodPregunta()<<endl;
    os<<"correcta    :"<<a.getCorrecta()<<endl;
    os<<"-----------------\n\n";
    return os;
}


