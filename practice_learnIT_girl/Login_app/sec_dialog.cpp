#include "sec_dialog.h"
#include "ui_sec_dialog.h"

sec_Dialog::sec_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sec_Dialog)
{
    ui->setupUi(this);
}

sec_Dialog::~sec_Dialog()
{
    delete ui;
}
