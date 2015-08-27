#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <vector>
#include "partida.h"
#include "detalle_partida.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    void CargarPartidas();
    void CargarDetalles(int);
    ~Menu();

private slots:
    void on_Tabla_Partida_cellClicked(int row, int column);

    void on_Regresar_Maraton_clicked();

private:
    Ui::Menu *ui;
    vector<Partida> partidas;
};

#endif // MENU_H
