#include "mainwindow.h"
#include "databaseinterface.h"

#include <QFile>
#include <QTableView>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DataBase::dataBaseOpen();

    proxyModel.setSourceModel( &myModel );

    ui->tableView->setModel( &proxyModel );
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    QFile styleFile( "./style.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style(styleFile.readAll());
    setStyleSheet(style);

    resize(1200,700);
}

MainWindow::~MainWindow()
{
    delete ui;
}


