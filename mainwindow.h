#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "custommodel.h"

#include <QSortFilterProxyModel>

namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private  :
    Ui::MainWindow *ui;

    CustomModel myModel;
    QSortFilterProxyModel proxyModel;
};

#endif // MAINWINDOW_H
