#include "options.h"
#include "ui_options.h"
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/foster_logo.png");
    ui->logo->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

Options::~Options()
{
    delete ui;
}

void Options::on_online_support_clicked()
{
    QUrl git_Url("https://github.com/Jivansha/Foster-Algorithm-Visualiser");
    QDesktopServices::openUrl(git_Url);
}

void Options::on_aboutus_clicked()
{
    QString about_text;
    about_text="Foster Version : 1.0.1\n";
    about_text+="Date : 15th June, 2019\n";
    about_text+="Based On : Qt Creator 4.9.0-beta2\n";
    about_text+="Copyright (c) 2019 Jivansha";
    about_text+="\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\t";
    about_text+="\nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY\t,";
    about_text+="\nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.";

    QMessageBox::about(this,"About Foster",about_text);
}

void Options::on_license_clicked()
{
    QString license_text;
    license_text="License\n";

    license_text+="Copyright (c) 2019 Jivansha\n";

    license_text+="Permission is hereby granted, free of charge, to any person obtaining a copy\n";
    license_text+="of this software and associated documentation files (the Software), to deal\n";
    license_text+="in the Software without restriction, including without limitation the rights\n";
    license_text+="to use, copy, modify, merge, publish, distribute, sublicense,\n";
    license_text+=" and to permit persons to whom the Software is\n";
    license_text+="furnished to do so, subject to the following conditions:\n\n";

    license_text+="The above copyright notice and this permission notice shall be included in all\n";
    license_text+="copies or substantial portions of the Software.\n";

    license_text+="THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n";
    license_text+="IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n";
    license_text+="FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n";
    license_text+="AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n";
    license_text+="LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n";
    license_text+="OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n";
    license_text+="SOFTWARE.";

    QMessageBox::about(this,"About Foster",license_text);
}

void Options::on_app_updates_clicked()
{
    QUrl git_Url("https://github.com/Jivansha/Foster-Algorithm-Visualiser/releases");
    QDesktopServices::openUrl(git_Url);
}

void Options::on_cancel_clicked()
{
    this->close();
}
