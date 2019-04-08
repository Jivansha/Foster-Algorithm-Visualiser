#include "foster_mainpage.h"
#include "ui_foster_mainpage.h"
#include "sort_window.h"

Foster_MainPage::Foster_MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Foster_MainPage)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/foster_logo.png");
    ui->logo_image->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}

Foster_MainPage::~Foster_MainPage()
{
    delete ui;
}

void Foster_MainPage::on_sorting_tab_clicked()
{
    sort_window sortwindow;
    sortwindow.setModal(true);      //modal approach- can't access main window
    sortwindow.exec();
}

void Foster_MainPage::on_close_tab_clicked()
{
    QApplication::exit();
}
