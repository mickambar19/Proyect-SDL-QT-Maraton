#include "menu.h"
#include "ui_menu.h"
#include "funciones.h"
#include <QTableWidgetItem>
#include <QMessageBox>
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    preguntas = cargar_Archivo();
    Recargar();
    win = new winPreRes();
    win->Ligar(&preguntas);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_B_Regresar_clicked()
{
    guardar_Archivo(preguntas);
    this->close();
}

void Menu::Recargar()
{
    Pregunta pregunta;
    for(int i= 0; i < ui->Tabla_Preguntas->rowCount();)
    {
        delete ui->Tabla_Preguntas->item(i,0);
        delete ui->Tabla_Preguntas->item(i,1);
        delete ui->Tabla_Preguntas->item(i,2);
        delete ui->Tabla_Preguntas->item(i,3);

        ui->Tabla_Preguntas->removeRow(i);
    }

    for(unsigned int i= 0;i < preguntas.size();i++)
    {
        pregunta = preguntas[i];
        QTableWidgetItem* a = new QTableWidgetItem();
        QTableWidgetItem* b = new QTableWidgetItem();
        QTableWidgetItem* c = new QTableWidgetItem();
        QTableWidgetItem* d = new QTableWidgetItem();
        a->setText(QString::fromStdString(pregunta.getCod()));
        b->setText(QString::fromStdString(pregunta.getNombre()));
        c->setText(QString::fromStdString(pregunta.getPuntos()));
        d->setText(QString::fromStdString(pregunta.getCategoria()));
        a->setFlags(a->flags() ^ Qt::ItemIsEditable);
        b->setFlags(b->flags() ^ Qt::ItemIsEditable);
        c->setFlags(c->flags() ^ Qt::ItemIsEditable);
        d->setFlags(d->flags() ^ Qt::ItemIsEditable);
        a->setTextAlignment(Qt::AlignHCenter);
        b->setTextAlignment(Qt::AlignHCenter);
        c->setTextAlignment(Qt::AlignHCenter);
        d->setTextAlignment(Qt::AlignHCenter);
        ui->Tabla_Preguntas->insertRow(i);
        ui->Tabla_Preguntas->setItem(i,0,a);
        ui->Tabla_Preguntas->setItem(i,1,b);
        ui->Tabla_Preguntas->setItem(i,2,c);
        ui->Tabla_Preguntas->setItem(i,3,d);
    }
}

void Menu::on_Tabla_Preguntas_cellClicked(int row, int column)
{
    (void)column;
    ui->Tabla_Preguntas->item(row,0)->setSelected(true);
    ui->Tabla_Preguntas->item(row,1)->setSelected(true);
    ui->Tabla_Preguntas->item(row,2)->setSelected(true);
    ui->Tabla_Preguntas->item(row,3)->setSelected(true);
}

void Menu::on_B_Agregar_clicked()
{
    win->Mostrar(-1);
}

void Menu::on_B_Recargar_clicked()
{
    Recargar();
}

void Menu::on_B_Modificar_clicked()
{
    int i = 0;
    for(;i < ui->Tabla_Preguntas->rowCount();i++)
    {
        if(ui->Tabla_Preguntas->item(i,0)->isSelected()) break;
    }
    if(i == ui->Tabla_Preguntas->rowCount())
    {
        QMessageBox::warning(this,"Error","Selecciona una pregunta");
        return;
    }
    win->Mostrar(i);
}

void Menu::on_B_Eliminar_clicked()
{
    int i = 0;
    for(;i < ui->Tabla_Preguntas->rowCount();i++)
    {
        if(ui->Tabla_Preguntas->item(i,0)->isSelected()) break;
    }
    if(i == ui->Tabla_Preguntas->rowCount())
    {
        QMessageBox::warning(this,"Error","Selecciona una pregunta");
        return;
    }
    preguntas.erase(preguntas.begin() + i);
    Recargar();
}
