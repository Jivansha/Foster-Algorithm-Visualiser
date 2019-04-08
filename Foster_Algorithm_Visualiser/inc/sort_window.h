#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H

#include <QDialog>
#include <QList>


namespace Ui {
class sort_window;
}

class sort_window : public QDialog
{
    Q_OBJECT

public:
    explicit sort_window(QWidget *parent = nullptr);
    ~sort_window();

private slots:
    void on_pushButton_cancel_sort_clicked();

    void on_comboBox_selectalgo_currentTextChanged(const QString &arg1);

    void on_enter_cip_clicked();

    void on_enter_seql_clicked();


private:
    Ui::sort_window *ui;
    QList<int> input_array;

};

#endif // SORT_WINDOW_H