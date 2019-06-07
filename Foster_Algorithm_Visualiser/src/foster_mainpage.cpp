#include "foster_mainpage.h"
#include "ui_foster_mainpage.h"
#include "sort_window.h"
#include "search_window.h"

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
    sortwindow.setModal(true);
    sortwindow.exec();
}

void Foster_MainPage::on_search_tab_clicked()
{
    search_window searchwindow;
    searchwindow.setModal(true);
    searchwindow.exec();
}

void Foster_MainPage::on_options_tab_clicked()
{
    Options optionwindow;
    optionwindow.setModal(true);
    optionwindow.exec();
}

void Foster_MainPage::on_close_tab_clicked()
{
    QApplication::exit();
}
