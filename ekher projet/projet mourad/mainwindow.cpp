#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mourad.h"
#include"melek.h"
#include"fred.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    if((ui->lineEdit->text()=="mourad") && (ui->lineEdit_2->text()=="mourad"))
    {
        mourad m;
        m.show();
        m.exec();

    }
    else if((ui->lineEdit->text()=="melek") && (ui->lineEdit_2->text()=="melek"))
    {
        melek m;
        m.show();
        m.exec();

    }
    else if((ui->lineEdit->text()=="fred") && (ui->lineEdit_2->text()=="fred"))
    {
        fred m;
        m.show();
        m.exec();

    }

}
