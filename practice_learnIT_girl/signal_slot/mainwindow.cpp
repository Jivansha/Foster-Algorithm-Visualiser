#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //type of message boxes
    // QMessageBox :: about(this, "My title","My message");
    // QMessageBox :: aboutQt(this, "My title");
    // QMessageBox :: critical(this, "My title","My message","Another message");
    // QMessageBox :: information(this, "My title","My message");
   // QMessageBox :: question(this, "My title","My message");
   // QMessageBox :: warning(this, "My title","My message");
    QMessageBox:: StandardButton reply = QMessageBox :: question(this, "My title","My message",
                           QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }
    else{
        qDebug()<<"No is clicked";
    }

}

