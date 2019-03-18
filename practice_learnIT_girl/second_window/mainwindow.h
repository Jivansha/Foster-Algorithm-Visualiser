#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "second_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Second_dialog *second;
};

#endif // MAINWINDOW_H
