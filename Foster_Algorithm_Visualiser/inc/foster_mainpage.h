#ifndef FOSTER_MAINPAGE_H
#define FOSTER_MAINPAGE_H

#include <QMainWindow>
#include "sort_window.h"
#include "search_window.h"
#include "options.h"

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

    void on_search_tab_clicked();

    void on_options_tab_clicked();

private:
    Ui::Foster_MainPage *ui;
    sort_window *sortwindow;
    search_window *searchwindow;
    Options *optionwindow;
};

#endif // FOSTER_MAINPAGE_H
