#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix("E:/photoshop/empirical techno logo2");
    QPixmap pix(":/image/img/empirical techno logo3.jpg");
    int w=ui->picture->width();
    int h =ui->picture->height();
    //ui->picture->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    ui->picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ui->statusBar->addPermanentWidget(ui->label_3,2);
    //ui->statusBar->addPermanentWidget(ui->progressBar,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_button_clicked()
{
    QString username = ui->Username->text();
    QString password =ui->Password->text();

    if(username == "test" && password == "test"){
        QMessageBox:: information(this,"My Account","Username and Passwords match!");
        second = new sec_Dialog(this);
        second->show();

       // ui->statusBar->showMessage("Username and password match!");
    }
    else{
        QMessageBox:: warning(this,"My Account","Username and Passwords don't match!");

        // for showing the message on the status bar
       //ui->statusBar->showMessage("Username and password don't match!",5000);
    }
}
