#include "second_dialog.h"
#include "ui_second_dialog.h"

Second_dialog::Second_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Second_dialog)
{
    ui->setupUi(this);
}

Second_dialog::~Second_dialog()
{
    delete ui;
}
