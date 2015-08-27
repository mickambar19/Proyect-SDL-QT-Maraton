#include <QTableWidgetItem>
#include "menu.h"
#include "ui_menu.h"
#include "funciones.h"
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    partidas = cargar_Partidas();
    CargarPartidas();
}

void Menu::CargarPartidas()
{
    Partida partida;
    for(; 5 != partidas.size();)
    {
        partidas.erase(partidas.begin());
    }
    for(int i = 0; i < partidas.size();i++)
    {
        partida = partidas[i];
        QTableWidgetItem* a = new QTableWidgetItem;
        QTableWidgetItem* b = new QTableWidgetItem;
        a->setText(QString::fromStdString(partida.getCod()));
        b->setText(QString::fromStdString(partida.getFecha()));
        a->setFlags(a->flags() ^ Qt::ItemIsEditable);
        b->setFlags(b->flags() ^ Qt::ItemIsEditable);
        a->setTextAlignment(Qt::AlignHCenter);
        b->setTextAlignment(Qt::AlignHCenter);
        ui->Tabla_Partida->insertRow(i);
        ui->Tabla_Partida->setItem(i,0,a);
        ui->Tabla_Partida->setItem(i,1,b);
    }
}

void Menu::CargarDetalles(int i)
{
    for(int i = 0; i < ui->Tabla_Detalle->rowCount();)
    {
        delete ui->Tabla_Detalle->item(i,0);
        delete ui->Tabla_Detalle->item(i,1);
        delete ui->Tabla_Detalle->item(i,2);
        delete ui->Tabla_Detalle->item(i,3);
        delete ui->Tabla_Detalle->item(i,4);

        ui->Tabla_Detalle->removeRow(i);
    }
    Detalle_Partida detalle;
    vector<Detalle_Partida> det = partidas[i].detalles;
    for(int i = 0; i < det.size();i++)
    {
        detalle = det[i];
        QTableWidgetItem* a = new QTableWidgetItem;
        QTableWidgetItem* b = new QTableWidgetItem;
        QTableWidgetItem* c = new QTableWidgetItem;
        QTableWidgetItem* d = new QTableWidgetItem;
        QTableWidgetItem* e = new QTableWidgetItem;
        a->setText(QString::fromStdString(detalle.getPartida()));
        b->setText(QString::fromStdString(detalle.getCodUsuario()));
        c->setText(QString::fromStdString(detalle.getCodPregunta()));
        d->setText(QString::fromStdString(detalle.getCodRespuesta()));
        e->setText(QString::fromStdString(detalle.getPuntosdeResp()));
        ui->Tabla_Detalle->insertRow(i);
        ui->Tabla_Detalle->setItem(i,0,a);
        ui->Tabla_Detalle->setItem(i,1,b);
        ui->Tabla_Detalle->setItem(i,2,c);
        ui->Tabla_Detalle->setItem(i,3,d);
        ui->Tabla_Detalle->setItem(i,4,e);
    }
}

Menu::~Menu()
{
    for(int i = 0; i < ui->Tabla_Detalle->rowCount();)
    {
        delete ui->Tabla_Detalle->item(i,0);
        delete ui->Tabla_Detalle->item(i,1);
        delete ui->Tabla_Detalle->item(i,2);
        delete ui->Tabla_Detalle->item(i,3);
        delete ui->Tabla_Detalle->item(i,4);

        ui->Tabla_Detalle->removeRow(i);
    }
    for(int i = 0; i < ui->Tabla_Partida->rowCount();)
    {
        delete ui->Tabla_Partida->item(i,0);
        delete ui->Tabla_Partida->item(i,1);

        ui->Tabla_Partida->removeRow(i);
    }
    delete ui;
}

void Menu::on_Tabla_Partida_cellClicked(int row, int column)
{
    ui->Tabla_Partida->item(row,0)->setSelected(true);
    ui->Tabla_Partida->item(row,1)->setSelected(true);
    CargarDetalles(row);
}

void Menu::on_Regresar_Maraton_clicked()
{
    this->close();
}
