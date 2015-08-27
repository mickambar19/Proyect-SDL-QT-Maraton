#include "funciones.h"
void guardar_Archivo(vector<Pregunta> vPreguntas)
{
    Pregunta pregunta;
    Respuesta respuesta;
    ofstream escribir("Pregunta.txt",ios::app);
    for(unsigned int i=0;i<vPreguntas.size();i++ )
    {
        pregunta=vPreguntas.at(i);
        escribir<<pregunta.getCod()<<"|"<<pregunta.getNombre()<<"|"<<pregunta.getPuntos()<<"|"<<pregunta.getCategoria()<<"!";
        for(unsigned int j=0;j<pregunta.respuestas.size();j++)
        {
            unsigned int b=1;

            respuesta=pregunta.respuestas.at(j);
            escribir<<respuesta.getCod()<<"|"<<respuesta.getDescripcion()<<"|"<<respuesta.getCorrecta()<<"|"<<respuesta.getCodPregunta();
            if((pregunta.respuestas.size()-b)==j)
            {
                escribir<<"#";
            }else
            {
                escribir<<"*";
            }
        }
    }
    escribir.close();
}

vector<Pregunta> cargar_Archivo(){
    Pregunta pregunta;
    Respuesta respuesta;
    vector<Pregunta> miVector;
    char aux;
    string cadena;
    ofstream caliz("Aux.txt",ios::app);

    ifstream leer("Pregunta.txt");
    if(!leer.good()){
        //no existe el archivo
    }else
    {
        while(!leer.eof())
        {
            pregunta.respuestas.clear();
            cadena="";
            do{
                leer.read((char *)&aux,sizeof(char));
                if(aux!='|'&& aux!='#')
                {
                    cadena+=aux;if(leer.eof()) break;
                }
            }while(aux!='|'&& aux!='#');
            pregunta.setCod(cadena);
            cadena="";
            do{
                leer.read((char *)&aux,sizeof(char));
                if(aux!='|'&& aux!='#')
                {
                    cadena+=aux;if(leer.eof()) break;
                }
            }while(aux!='|'&& aux!='#');
            pregunta.setNombre(cadena);
           cadena="";
            do{
                leer.read((char *)&aux,sizeof(char));
                if(aux!='|'&& aux!='#')
                {
                    cadena+=aux;if(leer.eof()) break;
                }
            }while(aux!='|'&& aux!='#');
            pregunta.setPuntos(cadena);
            cadena="";
            do{
                leer.read((char *)&aux,sizeof(char));
                if(aux!='!'&& aux!='#')
                {
                    cadena+=aux;if(leer.eof()) break;
                }
            }while(aux!='!'&& aux!='#');
            pregunta.setCategoria(cadena);
            if(leer.eof())break;
            caliz<<pregunta.getCod()<<"|"<<pregunta.getNombre()<<"|"<<pregunta.getPuntos()<<"|"<<pregunta.getCategoria()<<"!";
            //Aqui se empiezan a leer las respuestas
            while(aux!='#')
            {
                cadena="";
                if(leer.eof())break;
                do{
                    leer.read((char *)&aux,sizeof(char));
                    if(aux!='|')
                    {
                        cadena+=aux;if(leer.eof()) break;
                    }
                }while(aux!='|');
                respuesta.setCod(cadena);
                cadena="";
                do{
                    leer.read((char *)&aux,sizeof(char));
                    if(aux!='|')
                    {
                        cadena+=aux;if(leer.eof()) break;
                    }
                }while(aux!='|');
                respuesta.setDescripcion(cadena);
                cadena="";
                do{
                    leer.read((char *)&aux,sizeof(char));
                    if(aux!='|')
                    {
                        cadena+=aux;if(leer.eof()) break;
                    }
                }while(aux!='|');
                respuesta.setCorrecta(cadena);
                cadena="";
                do{

                    leer.read((char *)&aux,sizeof(char));
                    if(aux!='*'&& aux!='#')
                    {
                         cadena+=aux;if(leer.eof()) break;
                    }
                }while(aux!='*' && aux!='#');
                respuesta.setCodPregunta(cadena);
                pregunta.respuestas.push_back(respuesta);
                caliz<<respuesta.getCod()<<"|"<<respuesta.getDescripcion()<<"|"<<respuesta.getCorrecta()<<"|"<<respuesta.getCodPregunta()<<"#";
              }

            if(leer.eof())break;
            miVector.push_back(pregunta);
        }
    }
    leer.close();
    return miVector;
 }

void guardar_Partidas(vector<Partida> vpartidas)
{
    Partida partida;
    Detalle_Partida detalle;
    ofstream Escribir("Partidas.txt");
    for (int i = 0; i < vpartidas.size(); i++)
    {
        partida = vpartidas[i];
        Escribir << partida.getCod() << '|' << partida.getFecha() << '|';
        for (int j = 0; j < partida.detalles.size(); j++)
        {
            detalle = partida.detalles[j];
            Escribir << detalle.getPartida() << '|' << detalle.getCodUsuario() << '|';
            Escribir << detalle.getCodPregunta() << '|' << detalle.getCodRespuesta() << '|';
            Escribir << detalle.getPuntosdeResp() << '|';
        }
        Escribir << '&' << '|';
    }

    Escribir.close();
}

vector<Partida> cargar_Partidas()
{
    vector<Partida> vpartidas;
    Partida partida;
    Detalle_Partida detalle;
    string aux;
    ifstream Leer("Partidas.txt");
    if(!Leer.good())
        return vpartidas;

    while(!Leer.eof())
    {
        partida.detalles.clear();
        getline(Leer,aux,'|');
        if(Leer.eof())
            break;
        partida.setCod(aux);
        getline(Leer,aux,'|');
        partida.setFecha(aux);
        while(1)
        {
            getline(Leer,aux,'|');
            if(aux == "&")
                break;
            detalle.setPartida(aux);
            getline(Leer,aux,'|');
            detalle.setCodUsuario(aux);
            getline(Leer,aux,'|');
            detalle.setCodPregunta(aux);
            getline(Leer,aux,'|');
            detalle.setCodRespuesta(aux);
            getline(Leer,aux,'|');
            detalle.setPuntosdeResp(aux);
            partida.detalles.push_back(detalle);
        }
        vpartidas.push_back(partida);
    }

    return vpartidas;
}

void guardar_Usuarios(vector<Usuario> usuarios)
{
    Usuario usuario;
    ofstream Escribir("Usuarios.txt");

    for (int i = 0; i < usuarios.size(); i++)
    {
        usuario = usuarios[i];
        Escribir << usuario.getCod() << '|' << usuario.getNombre() << '|';
    }
    Escribir.close();
}

vector<Usuario> cargar_Usuarios()
{
    vector<Usuario> usuarios;
    Usuario usuario;
    string aux;
    ifstream Leer("Usuarios.txt");
    if(!Leer.good())
        return usuarios;

    while(!Leer.eof())
    {
        getline(Leer,aux,'|');
        if(Leer.eof()) break;
        usuario.setCod(aux);
        getline(Leer,aux,'|');
        usuario.setNombre(aux);
        usuarios.push_back(usuario);
    }
    return usuarios;
}