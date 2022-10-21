#include "mainwindow.h"
#include "operacaointensivaworker.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::rodarOperacaoIntensivaEmOutraThread);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rodarOperacaoIntensivaEmOutraThread()
{
    OperacaoIntensivaWorker *worker = new OperacaoIntensivaWorker();
    QThread *thread = new QThread();

    int iteracoes = ui->lineEdit->text().toInt();

    worker->definirNumeroIteracoes(iteracoes);
    worker->moveToThread(thread);
    connect(thread, &QThread::finished,worker,&QObject::deleteLater);
    connect(thread, &QThread::finished,thread,&QThread::deleteLater);
    connect(worker, &OperacaoIntensivaWorker::resultadoThread,this,&MainWindow::receberResultadoThread);
    connect(thread, &QThread::started, worker, &OperacaoIntensivaWorker::executarTarefaPesada);
    thread->start();
}

void MainWindow::receberResultadoThread(QString valor)
{
    ui->textEdit->append(valor);
}

void MainWindow::initValidator()
{
    QValidator *validator = new QIntValidator(1000, 30000, this);
    ui->lineEdit->setValidator(validator);
}
