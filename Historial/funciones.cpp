#include "funciones.h"

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
    cout << "a";
    if(!Leer.good())
        return vpartidas;
    cout << "a";
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
