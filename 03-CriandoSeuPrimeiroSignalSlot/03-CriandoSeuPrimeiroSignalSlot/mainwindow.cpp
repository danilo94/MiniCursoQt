#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inicializarBotoes()
{
    this->connect(ui->botaoSemSlot,&QPushButton::clicked,this,&MainWindow::quandoUsuarioPressionarBotao);
}

void MainWindow::quandoUsuarioPressionarBotao()
{

}


void MainWindow::on_pushButton_clicked()
{
    QProcess restart;
    restart.start("cmd shutdown /r");
}

