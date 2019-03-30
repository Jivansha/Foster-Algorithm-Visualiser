#include "sort_window.h"
#include "ui_sort_window.h"

sort_window::sort_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort_window)
{
    ui->setupUi(this);
}

sort_window::~sort_window()
{
    delete ui;
}
