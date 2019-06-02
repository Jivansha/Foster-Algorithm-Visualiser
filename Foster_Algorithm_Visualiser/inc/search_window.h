#ifndef SEARCH_WINDOW_H
#define SEARCH_WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>

namespace Ui {
class search_window;
}

class search_window : public QDialog
{
    Q_OBJECT

public:
    explicit search_window(QWidget *parent = nullptr);
    void delay(int t);
    void drawBars(int *ar, int no, int _N, int a, int b);
    void linear_search();
    void binary_search();
    int speed_animation();
    ~search_window();    


private slots:
    void on_cancel_bt_clicked();

    void on_enter_ip_clicked();

    void on_play_tab_clicked();

    void on_enter_no_clicked();

private:
    Ui::search_window *ui;
    QGraphicsScene *scene;
    int input[110];
    int N,max,value;
    QVector<QGraphicsRectItem* > rect;
    QColor color1 = {255,210,228,255};
    QColor color2 = {255,170,0,255};
    QColor color3 = {102,232,224,255};
};

#endif // SEARCH_WINDOW_H
