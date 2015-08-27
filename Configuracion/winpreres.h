#ifndef WINPRERES_H
#define WINPRERES_H

#include <QWidget>
#include <vector>
#include <QCheckBox>
#include "pregunta.h"
namespace Ui {
class winPreRes;
}

class winPreRes : public QWidget
{
    Q_OBJECT

public:
    explicit winPreRes(QWidget *parent = 0);
    ~winPreRes();
    void Ligar(vector<Pregunta>* pas);
    void Mostrar(int);
    void Limpiar();

private slots:
    void on_B_Capturar_clicked();

    void on_B_Salir_clicked();

private:
    Ui::winPreRes *ui;
    vector<Pregunta>* preguntas;
    vector<QCheckBox*> check;
    int Estado;
};

#endif // WINPRERES_H
