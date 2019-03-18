#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include "second_dialog.h"   //for modal approach, cut and paste in mainwindow.h for

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

void MainWindow::on_pushButton_clicked()
{
   // Second_dialog second;
   // second.setModal(true);      //modal approach- can't access main window
   // second.exec();
    hide();     //hide main window
    second = new Second_dialog(this);     //modal less apporach
    second->show();

}
