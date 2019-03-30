#include "foster_mainpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Foster_MainPage w;
    w.show();

    return a.exec();
}
