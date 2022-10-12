#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderHidden(true);
    ui->treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    CustomItem *item;
    if(ui->treeWidget->selectedItems().size()==1){
        item = new CustomItem(ui->treeWidget->selectedItems().first(), QStringList(QString("Objeto: %1").arg(m_items.size())),0);
    }
    else{
        item = new CustomItem(nullptr, QStringList(QString("Objeto: %1").arg(m_items.size())),0);
    }
    m_items.append(item);
    ui->treeWidget->insertTopLevelItem(0,item);
    ui->treeWidget->expandAll();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->treeWidget->selectedItems().size()==1){
        ui->treeWidget->removeItemWidget(ui->treeWidget->selectedItems().first(),0);
        delete ui->treeWidget->selectedItems().first();
    }
}

