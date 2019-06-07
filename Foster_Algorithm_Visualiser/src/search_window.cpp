#include "search_window.h"
#include "ui_search_window.h"

search_window::search_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_window)
{
    ui->setupUi(this);
    ui->algo_comboBox->addItem("Select Algo");
    ui->algo_comboBox->addItem("Linear Search");
    ui->algo_comboBox->addItem("Binary Search");
    ui->input_lineEdit->setClearButtonEnabled(true);
    ui->input_lineEdit->setMaxLength(100);
    ui->speed_comboBox->addItem("1X");
    ui->speed_comboBox->addItem("0.5X");
    ui->speed_comboBox->addItem("1.5X");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

search_window::~search_window()
{
    delete ui;
}

void search_window::on_cancel_bt_clicked()
{
    this->close();
}


void search_window::on_enter_ip_clicked()
{
    QString inputstr = ui->input_lineEdit->text();
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
        ui->size_lineEdit->setText(QString::number(N));
        drawBars(input,N,max,-1,-1,-1);
}


void search_window :: drawBars(int *ar,int no,int _N,int a,int b,int c){
    scene->clear();
    QPen bpen("black");
    QBrush brush("white");
    QPainterPath path;

    for(int i=0;i<no;i++){

            if(i==a)
                brush.setColor(color3);
            else if(i==b || i==c)
                brush.setColor(color1);
            else
                brush.setColor(color2);

            QGraphicsRectItem *rect = new QGraphicsRectItem(10+(300*i/no)+(i*20/no),_N-ar[i],300/no,ar[i]);
            rect->setBrush(brush);
            scene->addItem(rect);

            path.addText(10+(300*i/no)+(i*20/no),_N-10-ar[i], QFont("Arial", 200/no) ,QString::number(ar[i]));
            scene->addPath(path, QPen(QBrush("white"), 1), QBrush("white"));
    }
    delay(speed_animation());
}

int search_window::speed_animation(){
    QString speed =  ui->speed_comboBox->currentText();
    if(speed == "0.5X")
        return (5);
    else if(speed == "1X")
        return (3);
    else if(speed == "1.5X")
        return (1);
}

void search_window::delay(int t)
{
    QTime dieTime= QTime::currentTime().addSecs(t);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void search_window::on_play_tab_clicked()
{
    if(ui->algo_comboBox->currentText()=="Linear Search"){
        linear_search();
    }
    if(ui->algo_comboBox->currentText()=="Binary Search"){
            binary_search();
    }
}

void search_window::on_enter_no_clicked(){
    value= ui->no_lineEdit->text().toInt();
}

void search_window::linear_search(){
    int c=0;
    int flag=0;
    QString info="";
    value = ui->no_lineEdit->text().toInt();
    for(int i=0;i<N;i++){
        info = "Complexity - O(N)\nComparing elements at index : ";
        info += QString::number(i);
        info +=" , and number to be searched : ";
        info += QString::number(value);
        ui->info_edit->setPlainText(info);
        if(input[i] == value){
            flag=1;
            info += ". Element found at index ";
            info += QString::number(i);
            ui->info_edit->setPlainText(info);
            info = "";
            drawBars(input,N,max,-1,i,-1);
            break;
        }
        else{
            info += ". Element not found at index ";
            info += QString::number(i);
        }

       ui->info_edit->setPlainText(info);
       info = "";
       c++;
       ui->lcdNumber->display(c);
       drawBars(input,N,max,i,-1,-1);
    }
    if(flag!=1){
        info ="Element not found in array.";
        ui->info_edit->setPlainText(info);
    }
}

void search_window::binary_search(){
    int c=0;
    int flag=0;
    QString info="";
    value = ui->no_lineEdit->text().toInt();
    info = "Complexity - O(log(N))\nSorting array";
    ui->info_edit->setPlainText(info);
    drawBars(input,N,max,-1,-1,-1);
    std::sort(input, input + (N-1));
    int l=0;
    int r=N;
    drawBars(input,N,max,-1,l,r-1);
    while (l <= r) {
            int m = l + (r - l) / 2;
            info = "Complexity - O(log(N))\nComparing elements at index : ";
            info += QString::number(m);
            info +=" , and number to be searched : ";
            info += QString::number(value);
            ui->info_edit->setPlainText(info);
            drawBars(input,N,max,m,l,r);
            c++;
            ui->lcdNumber->display(c);
            if (input[m] == value){
                info = "Complexity - O(log(N))\nNumber to be searched present at index : ";
                info += QString::number(m);
                flag =1;
                ui->info_edit->setPlainText(info);
                drawBars(input,N,max,m,-1,-1);
                break;
            }

            if (input[m] < value){
                info = "Complexity - O(log(N))\nNumber to be searched GREATER than element at index : ";
                info += QString::number(m);
                info += "\nShifting to the RIGHT Half.";
                l = m + 1;
                info += "\nFirst index of Block :";
                info += QString::number(l);
                info += "\nLast index of Block :";
                info += QString::number(r);
                ui->info_edit->setPlainText(info);

            }

            else{
                info = "Complexity - O(log(N))\nNumber to be searched LESS than element at index : ";
                info += QString::number(m);
                info += "\nShifting to the LEFT Half.";
                r = m - 1;
                info += "\nFirst index of Block :";
                info += QString::number(l);
                info += "\nLast index of Block :";
                info += QString::number(r);
                ui->info_edit->setPlainText(info);
            }
        }
    if(flag!=1){
        info ="Element not found in array.";
        ui->info_edit->setPlainText(info);
    }
}
