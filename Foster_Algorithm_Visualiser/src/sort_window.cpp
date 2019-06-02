#include "sort_window.h"
#include "ui_sort_window.h"
#include <QTime>

sort_window::sort_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort_window)
{
    ui->setupUi(this);
    ui->comboBox_selectalgo->addItem("Select Sort");
    ui->comboBox_selectalgo->addItem("Bubble Sort");
    ui->comboBox_selectalgo->addItem("Selection Sort");
    ui->comboBox_selectalgo->addItem("Insertion Sort");
    ui->comboBox_selectipop->addItem("Select Input");
    ui->comboBox_selectipop->addItem("Custom Input");
    ui->comboBox_selectipop->addItem("Random Input");
    ui->lineEdit_seqlength->setValidator( new QIntValidator(2,50, this));
    ui->lineEdit_customip->setClearButtonEnabled(true);
    ui->lineEdit_seqlength->setClearButtonEnabled(true);
    ui->lineEdit_customip->setMaxLength(100);
    ui->speed_comboBox->addItem("1X");
    ui->speed_comboBox->addItem("0.5X");
    ui->speed_comboBox->addItem("1.5X");
    ui->speed_comboBox->addItem("2X");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

sort_window::~sort_window()
{
    delete ui;
}


void sort_window::on_pushButton_cancel_sort_clicked()
{
    this->close();
}

void sort_window::on_play_tab_clicked()
{
    if(ui->comboBox_selectalgo->currentText()=="Bubble Sort"){
        bubble_sort();
    }
    if(ui->comboBox_selectalgo->currentText()=="Selection Sort"){
        selection_sort();
    }
    if(ui->comboBox_selectalgo->currentText()=="Insertion Sort"){
        insertion_sort();
    }
}


void sort_window::on_enter_cip_clicked()
{
    if(ui->comboBox_selectipop->currentText() == "Custom Input"){
        QString inputstr = ui->lineEdit_customip->text();
        QStringList customip = inputstr.split(" ",QString::SkipEmptyParts);

        N=0;
        max=0;
            foreach(QString num, customip){
                input[N]=num.toInt();
                if(input[N]>max){
                    max=input[N];
                }
                N++;
            }
            ui->lineEdit_seqlength->setText(QString::number(N));
            drawBars(input,N,max,-1,-1);
    }
}

void sort_window::on_enter_seql_clicked()
{
    if(ui->comboBox_selectipop->currentText() == "Random Input"){
        QString inputN = ui->lineEdit_seqlength->text();
        int N=inputN.toInt();
        int max=0;
        QString rand_ip;
            for(int i=0;i<N;i++){
                  input[i]=qrand()%100;
                  if(input[i]>max){
                      max=input[i];
                  }
                  rand_ip.append(QString::number(input[i]));
                  rand_ip.append(" ");
            }
            ui->lineEdit_customip->setText(rand_ip);
        drawBars(input,N,max,-1,-1);
     }
}

void sort_window::bubble_sort(){
    int c=0;
    QString info="";
    QString inputN = ui->lineEdit_seqlength->text();

    int no=inputN.toInt();
    int m=0;

    for(int k=0;k<no;k++){
        if(input[k]>m)
            m=input[k];
    }
    for (int i=0;i<no-1;i++){
        for (int j=0;j<no-i-1;j++){
            info = "Complexity - O(N^2)";
            info += "\nComparing element at index ";
            info += QString::number(j);
            info += " and index ";
            info += QString::number(j+1);
            ui->info_text->setPlainText(info);

            drawBars(input,no,m,j,j+1);
            if (input[j] > input[j+1]){
                info = "Complexity - O(N^2)";
                info += "\nSwapping element at index ";
                info += QString::number(j);
                info += " and index ";
                info += QString::number(j+1);
                ui->info_text->setPlainText(info);
               std::swap(input[j],input[j+1]);
               drawBars(input,no,m,-1,-1);
            }
            c++;
            ui->lcdNumber_comaprision->display(c);
        }
    }
    drawBars(input,no,m,-1,-1);
}

void sort_window::selection_sort(){
    int min_idx;
    int c=0;
    QString inputN = ui->lineEdit_seqlength->text();
    QString info="";
    int no=inputN.toInt();
    int m=0;

    for(int k=0;k<no;k++){
        if(input[k]>m)
            m=input[k];
    }
        for (int i=0;i<no;i++){
            min_idx = i;
            for (int j=i+1;j<no;j++){
                info = "Complexity - O(N^2)";
                info += "\nComparing element at index ";
                info += QString::number(j);
                info += " and minimum value index ";
                info += QString::number(min_idx);
                ui->info_text->setPlainText(info);
                drawBars(input,no,m,j,min_idx);
                if (input[j] < input[min_idx]){
                    min_idx=j;
                }
                c++;
                ui->lcdNumber_comaprision->display(c);
           }
            info = "Complexity - O(N^2)";
            info += "\nSwapping element at index ";
            info += QString::number(min_idx);
            info += " and index ";
            info += QString::number(i);
            ui->info_text->setPlainText(info);
           std::swap(input[min_idx],input[i]);
           drawBars(input,no,m,-1,-1);
        }
}

void sort_window::insertion_sort(){
    int temp,j;
    int c=0;
    QString inputN = ui->lineEdit_seqlength->text();
    QString info="";
    int no=inputN.toInt();
    int m=0;

    for(int k=0;k<no;k++){
        if(input[k]>m)
            m=input[k];
    }
    for(int i=1;i<=no-1;i++){
            temp=input[i];
            j=i-1;

            while((temp<input[j]) && (j>=0)){
                info = "Complexity - O(N^2)";
                info += "\nComparing element at index ";
                info += QString::number(i);
                info += " and index ";
                info += QString::number(j);
                ui->info_text->setPlainText(info);
                delay(speed_animation());
                input[j+1]=input[j];
                j=j-1;
                info = "Complexity - O(N^2)\nShifting element at index ";
                info += QString::number(j+1);
                ui->info_text->setPlainText(info);
                c++;
                ui->lcdNumber_comaprision->display(c);
                delay(speed_animation());
            }
            input[j+1]=temp;
            drawBars(input,no,m,i,j+1);
     }
    drawBars(input,no,m,-1,-1);
}

int sort_window::speed_animation(){
    QString speed =  ui->speed_comboBox->currentText();
    if(speed == "0.5X")
        return (7);
    else if(speed == "1X")
        return (5);
    else if(speed == "1.5X")
        return (3);
    else if(speed == "2X")
        return (1);
}

void sort_window :: drawBars(int *ar,int no,int _N,int a,int b){
    scene->clear();
    QPen bpen("black");
    QBrush brush("white");
    QPainterPath path;

    for(int i=0;i<no;i++){

            if(i==a || i==b)
                brush.setColor(color3);
            else if(i==0)
                brush.setColor(color1);
            else if(i%2==0)
                brush.setColor(color1);
            else if(i%2!=0)
                brush.setColor(color2);

            QGraphicsRectItem *rect = new QGraphicsRectItem(10+(300*i/no)+(i*20/no),_N-ar[i],300/no,ar[i]);
            rect->setBrush(brush);
            scene->addItem(rect);

            path.addText(10+(300*i/no)+(i*20/no),_N-10-ar[i], QFont("Arial", 200/no) ,QString::number(ar[i]));
            scene->addPath(path, QPen(QBrush("white"), 1), QBrush("white"));

    }
    delay(speed_animation());

}

void sort_window::delay(int t)
{
    QTime die_time= QTime::currentTime().addSecs(t);
    while (QTime::currentTime() < die_time)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
