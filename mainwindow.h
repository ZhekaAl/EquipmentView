#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>

#include "ui_mainwindow.h"
#include "custommodel.h"

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
    void setupTableView(QTableView& tableView);
    void setStyle();
    CustomModel myModel;
    QSortFilterProxyModel proxyModel;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
