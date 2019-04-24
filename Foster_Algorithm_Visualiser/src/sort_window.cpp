#include "sort_window.h"
#include "ui_sort_window.h"
#include <QMessageBox>
#include <QTime>


sort_window::sort_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort_window)
{
    ui->setupUi(this);
    ui->comboBox_selectalgo->addItem("Select Sort");
    ui->comboBox_selectalgo->addItem("Bubble Sort");
    ui->comboBox_selectalgo->addItem("Quick Sort");

    ui->comboBox_selectipop->addItem("Select Input");
    ui->comboBox_selectipop->addItem("Custom Input");
    ui->comboBox_selectipop->addItem("Random Input");
    ui->lineEdit_seqlength->setValidator( new QIntValidator(0,50, this));
    ui->lineEdit_customip->setClearButtonEnabled(true);
    ui->lineEdit_seqlength->setClearButtonEnabled(true);
    ui->lineEdit_customip->setMaxLength(100);

}

sort_window::~sort_window()
{
    delete ui;
}


void sort_window::on_pushButton_cancel_sort_clicked()
{
    this->close();
}


void sort_window::on_comboBox_selectalgo_currentTextChanged(const QString &arg1)
{

    if(arg1 == "Bubble Sort"){
        QMessageBox :: information(this, "sort", arg1);     //do something
    }
    if(arg1 == "Quick Sort"){
        QMessageBox :: information(this, "sort", arg1);     //do something
    }

}


void sort_window::on_enter_cip_clicked()
{
    if(ui->comboBox_selectipop->currentText() == "Custom Input"){
        QString inputstr = ui->lineEdit_customip->text();
        QStringList customip = inputstr.split(" ",QString::SkipEmptyParts);
        int custom_input[60];
        int N=0;
        int max=0;
            foreach(QString num, customip){
                custom_input[N]=num.toInt();
                if(custom_input[N]>max){
                    max=custom_input[N];
                }
                N++;
            }
            drawBars(custom_input,N,max);
    }
}

void sort_window::on_enter_seql_clicked()
{
    if(ui->comboBox_selectipop->currentText() == "Random Input"){
        QString inputN = ui->lineEdit_seqlength->text();
        int N=inputN.toInt();
        int random_input[50];
        int max=0;
        QString rand_ip;
            for(int i=0;i<N;i++){
                  random_input[i]=qrand()%100;
                  if(random_input[i]>max){
                      max=random_input[i];
                  }
                  rand_ip.append(QString::number(random_input[i]));
                  rand_ip.append(" ");
            }
            ui->lineEdit_customip->setText(rand_ip);
        drawBars(random_input,N,max);
     }
}

void sort_window :: drawBars(int *ar,int m,int N){
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QPen bpen("black");

    QPainterPath path;

    for(int i=0;i<m;i++){

            if(i==0)
                rect = scene->addRect(QRect(10+(300*i/m)+(i*20/m),N-ar[i],300/m,ar[i]),bpen,color1);
            else if(i%2==0)
                rect = scene->addRect(QRect(10+(300*i/m)+(i*20/m),N-ar[i],300/m,ar[i]),bpen,color1);
            else if(i%2!=0)
                rect = scene->addRect(QRect(10+(300*i/m)+(i*20/m),N-ar[i],300/m,ar[i]),bpen,color2);

            path.addText(10+(300*i/m)+(i*20/m),N-10-ar[i], QFont("Arial", 200/m) ,QString::number(ar[i]));
            scene->addPath(path, QPen(QBrush("white"), 1), QBrush("white"));

    }
}