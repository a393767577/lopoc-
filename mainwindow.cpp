#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.open();
    model=new QSqlRelationalTableModel(this);
    ui->tableView->setModel(model);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model->setTable("ddd");
    model->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

   model->insertRow( model->rowCount());
}

void MainWindow::on_pushButton_2_clicked()
{
    model->submitAll();
}

void MainWindow::on_pushButton_3_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());
        model->submitAll();
}
