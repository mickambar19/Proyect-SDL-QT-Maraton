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
