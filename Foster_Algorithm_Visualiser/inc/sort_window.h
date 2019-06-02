#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>


namespace Ui {
class sort_window;
}

class sort_window : public QDialog
{
    Q_OBJECT

public:
    explicit sort_window(QWidget *parent = nullptr);
    void drawBars(int *ar,int no,int _N,int a,int b);
    void bubble_sort();
    void selection_sort();
    void insertion_sort();
    int speed_animation();
    void delay(int t);
    ~sort_window();

private slots:
    void on_pushButton_cancel_sort_clicked();

    void on_enter_cip_clicked();

    void on_enter_seql_clicked();

    void on_play_tab_clicked();

private:
    Ui::sort_window *ui;
    QGraphicsScene *scene;
    int input[110];
    int N,max;
    QVector<QGraphicsRectItem* > rect;
    QColor color1 = {255,210,228,255};
    QColor color2 = {255,170,0,255};
    QColor color3 = {102,232,224,255};

};

#endif // SORT_WINDOW_H
