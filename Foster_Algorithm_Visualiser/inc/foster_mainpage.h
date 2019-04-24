#ifndef FOSTER_MAINPAGE_H
#define FOSTER_MAINPAGE_H

#include <QMainWindow>
#include "sort_window.h"

namespace Ui {
class Foster_MainPage;
}

class Foster_MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Foster_MainPage(QWidget *parent = nullptr);
    ~Foster_MainPage();

private slots:
    void on_sorting_tab_clicked();

    void on_close_tab_clicked();

private:
    Ui::Foster_MainPage *ui;
    sort_window *sortwindow;
};

#endif // FOSTER_MAINPAGE_H