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
    QTreeWidgetItem *selectedItem = nullptr;
    QString objectName = QString("Objeto: %1").arg(m_items.size()) ;
    if(ui->treeWidget->selectedItems().size()==1){
        selectedItem = ui->treeWidget->selectedItems().first();
    }


    if (!ui->nomeObjeto->text().isEmpty()){
        objectName = ui->nomeObjeto->text();
    }


    item = new CustomItem(selectedItem, QStringList(objectName),0);
    item->setIcon(0,QIcon(":icones/icones/check.png"));


    m_items.append(item);
    ui->treeWidget->insertTopLevelItem(0,item);
    ui->treeWidget->expandAll();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->treeWidget->selectedItems().size()==1){
        ui->treeWidget->removeItemWidget(ui->treeWidget->selectedItems().first(),0);
        delete ui->treeWidget->selectedItems().takeFirst();
    }
}

