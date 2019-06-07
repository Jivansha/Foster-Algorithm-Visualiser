#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:
    void on_online_support_clicked();

    void on_aboutus_clicked();

    void on_license_clicked();

    void on_pushButton_clicked();

    void on_app_updates_clicked();

    void on_cancel_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
