#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(myfunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    qDebug()<<"update..";
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("E:/programs/Qt programs/practice_learnIT_girl/Qfile_demo/myfile.txt");
    if(!file.open(QFile :: WriteOnly | QFile:: Text)){
        QMessageBox::information(this,"title","file not open");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{

    QFile file("E:/programs/Qt programs/practice_learnIT_girl/Qfile_demo/myfile.txt");
    if(!file.open(QFile :: ReadOnly | QFile:: Text)){
        QMessageBox::information(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filter="All files(*.*);; text file(*.txt);; XML file(*.xml)";

    QString file_name = QFileDialog::getOpenFileName(this,"Open a file","E://",filter);
    QMessageBox::information(this,"title",file_name);
}
