#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objeto.h"

#include <QMainWindow>
#include <QSet>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_criarObjetosPushButton_clicked();

    void on_destruirObjetosPushButton_clicked();

    void on_esvaziarListaPushButton_clicked();

    void on_criarObjetosSmartPointer_clicked();

    void on_destruirObjetosSmartPointer_clicked();

    void on_esvaziarListaSmartPointer_clicked();

private:
    Ui::MainWindow *ui;

    QList<Objeto*> m_objetos;
    QList<std::shared_ptr<Objeto>> m_objetosSharedPtr;
};
#endif // MAINWINDOW_H
