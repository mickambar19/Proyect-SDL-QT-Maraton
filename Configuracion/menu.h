#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "pregunta.h"
#include "respuesta.h"
#include "winpreres.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
    void Recargar();

private slots:
    void on_B_Regresar_clicked();

    void on_Tabla_Preguntas_cellClicked(int row, int column);

    void on_B_Agregar_clicked();

    void on_B_Recargar_clicked();

    void on_B_Modificar_clicked();

    void on_B_Eliminar_clicked();

private:
    Ui::Menu *ui;
    vector<Pregunta> preguntas;
    winPreRes* win;
};

#endif // MENU_H
