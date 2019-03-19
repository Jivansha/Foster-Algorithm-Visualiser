#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/icons/images/57c516a4e2650e5fb7a7e6c726cebea2.jpg"),"Mat");
    ui->comboBox->addItem(QIcon(":/icons/images/8f6e81a39703447cd7e50a16b703bcc0.jpg"),"Rat");
    ui->comboBox->addItem(QIcon(":/images/images/589efbefcd646acf7682cefcf1562a46.jpg"),"cat");

    for(int i=0;i<5;i++){
        ui->comboBox->addItem(QString::number(i)+"name");
    }
    ui->comboBox->insertItem(3,QIcon(":/icons/images/8f6e81a39703447cd7e50a16b703bcc0.jpg"),"Text");
    ui->listWidget->addItem("July1");
    ui->listWidget->addItem("July2");
    ui->listWidget->addItem("July3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this,"title","NEw");
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"tilte",ui->comboBox->currentText());
}
