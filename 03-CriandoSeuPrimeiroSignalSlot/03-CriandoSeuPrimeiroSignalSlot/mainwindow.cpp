#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(ui->botaoSemSlot,&QPushButton::clicked,this,&MainWindow::quandoUsuarioPressionarBotao);
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
    m_vezesPressionado++;
    QMessageBox msgBox;
    msgBox.setText(QString("Olá, Você clicou no botão %1 vezes").arg(m_vezesPressionado));
    msgBox.exec();
}


void MainWindow::on_pushButton_clicked()
{
    m_vezesPressionado++;
    QMessageBox msgBox;
    msgBox.setText(QString("Olá, Você clicou no botão %1 vezes").arg(m_vezesPressionado));
    msgBox.exec();
}


void MainWindow::on_pushButton_2_clicked()
{

}

