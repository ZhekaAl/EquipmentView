#include "mainwindow.h"
#include "databaseinterface.h"

#include <QFile>
#include <QTableView>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DataBase::dataBaseOpen(QApplication::applicationDirPath()+ "/equipment.sqlite");
    proxyModel.setSourceModel(&myModel);
    setupTableView(*ui->tableView);
    setStyle();
    resize(1250,700);
}


void MainWindow::setupTableView(QTableView &tableView)
{
   tableView.setModel(&proxyModel);
   tableView.setSortingEnabled(true);
   tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   tableView.horizontalHeader()->setHighlightSections(false);
   tableView.setEditTriggers(QAbstractItemView::NoEditTriggers);
   tableView.setSelectionBehavior(QAbstractItemView::SelectRows);
}

 void MainWindow::setStyle()
 {
     QFile styleFile( QApplication::applicationDirPath()+"/style.qss" );
     styleFile.open( QFile::ReadOnly );
     QString style(styleFile.readAll());
     setStyleSheet(style);
 }

MainWindow::~MainWindow()
{
    delete ui;
}


