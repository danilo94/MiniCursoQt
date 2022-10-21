#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 100000, this);
    ui->numeroObjetosAlocacaoSimples->setValidator(validator);
    ui->numeroObjetosSmartPointer->setValidator(validator);
    //ObjetoDaora *objetoDaora4 = (ObjetoDaora *)malloc(sizeof(ObjetoDaora)*100000);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_criarObjetosPushButton_clicked()
{
    int objetos = ui->numeroObjetosAlocacaoSimples->text().toInt();

    for (int i=0; i<=objetos; i++){
        m_objetos.append(new Objeto(m_objetos.size()));
    }
}


void MainWindow::on_destruirObjetosPushButton_clicked()
{
    for (int i=0; i<m_objetos.size(); i++){
        Objeto *objeto = m_objetos.at(i);
        delete objeto;
    }
}


void MainWindow::on_esvaziarListaPushButton_clicked()
{
    m_objetos.clear();
}




void MainWindow::on_criarObjetosSmartPointer_clicked()
{

}


void MainWindow::on_destruirObjetosSmartPointer_clicked()
{

}


void MainWindow::on_esvaziarListaSmartPointer_clicked()
{

}

