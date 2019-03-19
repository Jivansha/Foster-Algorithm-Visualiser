#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::information(this,"title","Yes");
    }
    else {
        QMessageBox::information(this,"title","No");
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this,"title","Yes");
    }
    else {
        QMessageBox::information(this,"title","No");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->radioButton->isChecked()){
        QMessageBox::information(this,"Title","Tom");
    }
    else {
        QMessageBox::information(this,"Title","Jerry");
    }
}
