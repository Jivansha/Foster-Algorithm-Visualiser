#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H

#include <QDialog>

namespace Ui {
class sort_window;
}

class sort_window : public QDialog
{
    Q_OBJECT

public:
    explicit sort_window(QWidget *parent = nullptr);
    ~sort_window();

private:
    Ui::sort_window *ui;
};

#endif // SORT_WINDOW_H
