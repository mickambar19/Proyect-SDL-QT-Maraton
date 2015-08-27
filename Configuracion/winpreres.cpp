#include "winpreres.h"
#include "ui_winpreres.h"
#include <QCheckBox>
#include <QMessageBox>

winPreRes::winPreRes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winPreRes)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
}

void winPreRes::Ligar(vector<Pregunta> *pas)
{
    preguntas = pas;
}

void winPreRes::Mostrar(int value)
{
    Estado = value;
    if(Estado == -1)
    {
        ui->B_Capturar->setText("Capturar");
        for(int i = 0; i < 3;i++)
        {
            QTableWidgetItem* a = new QTableWidgetItem();
            QTableWidgetItem* b = new QTableWidgetItem();
            QCheckBox* c = new QCheckBox();
            ui->tableWidget->setItem(i,0,a);
            ui->tableWidget->setItem(i,1,b);
            ui->tableWidget->setCellWidget(i,2,c);
            check.push_back(c);
        }
    }
    else
    {
        Pregunta pregunta = preguntas->at(Estado);
        ui->B_Capturar->setText("Modificar");
        for(int i = 0; i < 6;i++)
        {
            ui->comboBox->setCurrentIndex(i);
            if(pregunta.getCategoria() == ui->comboBox->currentText().toStdString()) break;
        }
        ui->L_cod->setText(QString::fromStdString(pregunta.getCod()));
        ui->L_nom->setText(QString::fromStdString(pregunta.getNombre()));
        ui->L_pun->setText(QString::fromStdString(pregunta.getPuntos()));
        for(int i = 0; i < 3;i++)
        {
            QTableWidgetItem* a = new QTableWidgetItem();
            QTableWidgetItem* b = new QTableWidgetItem();
            QCheckBox* c = new QCheckBox();
            a->setText(QString::fromStdString(pregunta.respuestas[i].getCod()));
            b->setText(QString::fromStdString(pregunta.respuestas[i].getDescripcion()));
            if(pregunta.respuestas[i].getCorrecta() == "0") c->setChecked(false);
            else c->setChecked(true);
            ui->tableWidget->setItem(i,0,a);
            ui->tableWidget->setItem(i,1,b);
            ui->tableWidget->setCellWidget(i,2,c);
            check.push_back(c);
        }
    }
    this->show();
}

void winPreRes::Limpiar()
{
    for(int i = 0; i < 3; i++)
    {
        delete ui->tableWidget->item(i,0);
        delete ui->tableWidget->item(i,1);
        //delete ui->tableWidget->cellWidget(i,2);
    }
    ui->L_cod->setText("");
    ui->L_nom->setText("");
    ui->L_pun->setText("");
    check.clear();
}

winPreRes::~winPreRes()
{
    delete ui;
}

void winPreRes::on_B_Capturar_clicked()
{
    if(ui->L_cod->text() == "")
    {
        QMessageBox::warning(this,"Error","Ingresa Codigo");
        return;
    }
    if(ui->L_nom->text() == "")
    {
        QMessageBox::warning(this,"Error","Ingresa Nombre");
        return;
    }
    if(ui->L_pun->text() == "")
    {
        QMessageBox::warning(this,"Error","Ingresa Puntación");
        return;
    }
    for(int i = 0; i < preguntas->size();i++)
    {
        Pregunta pregunta = preguntas->at(i);
        if(i == Estado) continue;
        if(pregunta.getCod() == ui->L_cod->text().toStdString())
        {
            QMessageBox::warning(this,"Error","Código repetido");
            return;
        }
    }
    for(int i = 0; i < preguntas->size();i++)
    {
        Pregunta pregunta = preguntas->at(i);
        if(i == Estado) continue;
        for(int j = 0; j < pregunta.respuestas.size();j++)
        {
            Respuesta respuesta = pregunta.respuestas.at(j);
            for(int k = 0; k < 3;k++)
            {
                if(respuesta.getCod() == ui->tableWidget->item(k,0)->text().toStdString())
                {
                    QMessageBox::warning(this,"Error","Código de respuesta repetido");
                    return;
                }
            }
        }
    }
    Pregunta pregunta;

    pregunta.setCategoria(ui->comboBox->currentText().toStdString());
    pregunta.setCod(ui->L_cod->text().toStdString());
    pregunta.setNombre(ui->L_nom->text().toStdString());
    pregunta.setPuntos(ui->L_pun->text().toStdString());

    for(int i = 0; i < 3; i++)
    {
        Respuesta respuesta;
        respuesta.setCod(ui->tableWidget->item(i,0)->text().toStdString());
        respuesta.setDescripcion(ui->tableWidget->item(i,1)->text().toStdString());
        respuesta.setCodPregunta(pregunta.getCod());
        if(check[i]->isChecked()) respuesta.setCorrecta("1");
        else respuesta.setCorrecta("0");
        pregunta.respuestas.push_back(respuesta);
    }
    if(Estado == -1)
    {
        preguntas->push_back(pregunta);
    }
    else
    {
        preguntas->at(Estado) = pregunta;
    }
    Limpiar();
    this->close();
}

void winPreRes::on_B_Salir_clicked()
{
    Limpiar();
    this->close();
}
