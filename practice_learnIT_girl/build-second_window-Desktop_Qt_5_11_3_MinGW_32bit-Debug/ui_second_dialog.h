/********************************************************************************
** Form generated from reading UI file 'second_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_DIALOG_H
#define UI_SECOND_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Second_dialog
{
public:

    void setupUi(QDialog *Second_dialog)
    {
        if (Second_dialog->objectName().isEmpty())
            Second_dialog->setObjectName(QStringLiteral("Second_dialog"));
        Second_dialog->resize(400, 300);

        retranslateUi(Second_dialog);

        QMetaObject::connectSlotsByName(Second_dialog);
    } // setupUi

    void retranslateUi(QDialog *Second_dialog)
    {
        Second_dialog->setWindowTitle(QApplication::translate("Second_dialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Second_dialog: public Ui_Second_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_DIALOG_H
