#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QElapsedTimer>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initValidator();
    this->connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::operacaoIntensiva);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initValidator()
{
    QValidator *validator = new QIntValidator(1000, 30000, this);
    ui->lineEdit->setValidator(validator);

}

void MainWindow::operacaoIntensiva()
{
    QElapsedTimer timer;
    timer.start();

    int numeroIteracoes = ui->lineEdit->text().toInt();
    int result=0;
    for (int i=0; i<= numeroIteracoes; i++){
        for (int j=0; j <= numeroIteracoes; j++){
            for (int k=0; k<=numeroIteracoes; k++){
                result += i + j + k;
            }
        }
    }
    QString resultado = QString("Operação Finalizada, tempo gasto: %1 segundos").arg(timer.elapsed()/1000);
    ui->textEdit->append(resultado);
}

