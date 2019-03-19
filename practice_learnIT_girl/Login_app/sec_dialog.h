#ifndef SEC_DIALOG_H
#define SEC_DIALOG_H

#include <QDialog>

namespace Ui {
class sec_Dialog;
}

class sec_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sec_Dialog(QWidget *parent = nullptr);
    ~sec_Dialog();

private:
    Ui::sec_Dialog *ui;
};

#endif // SEC_DIALOG_H
