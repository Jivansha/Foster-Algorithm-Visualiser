#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>


namespace Ui {
class sort_window;
}

class sort_window : public QDialog
{
    Q_OBJECT

public:
    explicit sort_window(QWidget *parent = nullptr);
    void drawBars(int *ar,int m,int N);
    ~sort_window();


private slots:
    void on_pushButton_cancel_sort_clicked();

    void on_comboBox_selectalgo_currentTextChanged(const QString &arg1);

    void on_enter_cip_clicked();

    void on_enter_seql_clicked();


private:
    Ui::sort_window *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    QColor color1 = {255,210,228,255};
    QColor color2 = {255,170,0,255};

};

#endif // SORT_WINDOW_H
