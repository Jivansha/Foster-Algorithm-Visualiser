#ifndef SECOND_DIALOG_H
#define SECOND_DIALOG_H

#include <QDialog>

namespace Ui {
class Second_dialog;
}

class Second_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Second_dialog(QWidget *parent = nullptr);
    ~Second_dialog();

private:
    Ui::Second_dialog *ui;
};

#endif // SECOND_DIALOG_H
