#include "foster_mainpage.h"
#include "sort_window.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Foster_MainPage w;
    w.show();
    qsrand(QDateTime::currentDateTime().toTime_t());

    return a.exec();
}