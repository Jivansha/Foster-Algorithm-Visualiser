#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;
    foreach(QFileInfo var,dir.drives()){
        ui->comboBox->addItem(var.absoluteFilePath());
    }

    QDir dir2("E:/programs/Qt programs/practice_learnIT_girl/Qdir_demo");
    foreach(QFileInfo var,dir2.entryInfoList()){
        if(var.isDir())
        ui->listWidget->addItem("Dir :" + var.absoluteFilePath());
        if(var.isFile())
             ui->listWidget->addItem("File :" + var.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir3("E:/programs/Qt programs/practice_learnIT_girl/Qdir_demo/yyy");
    if(dir3.exists()){
        QMessageBox::information(this,"title","exits");
    }
    else {
        dir3.mkpath("E:/programs/Qt programs/practice_learnIT_girl/Qdir_demo/yyy");
    }
}
