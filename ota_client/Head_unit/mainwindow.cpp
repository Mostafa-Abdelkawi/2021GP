#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QMessageBox>
#include <QCoreApplication>
#include <QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_15->setVisible(false);
    ui->label_25->setVisible(false);
    ui->progressBar->setVisible(false);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->pushButton_9->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
    ui->pushButton_21->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
    ui->pushButton_28->setIcon(QIcon(":/rec/img/output-onlinepngtools.png"));
    ui->label_15->setText("1");
}

void MainWindow::on_pushButton_9_clicked()
{
    QString flag =ui->label_15->text();
    if(flag=="1")
    {
      ui->label_11->setText("New Software Available.");
      ui->label_12->setText("name:");
      ui->pushButton_21->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
      ui->label_13->setVisible(true);
      ui->pushButton->setVisible(true);
      ui->pushButton_23->setVisible(true);
      ui->label_14->setVisible(true);
//      ui->label_15->setText("0");
    }
    else
    {
        ui->pushButton_21->setIcon(QIcon(":/rec/img/gMJRp2s.png"));
        ui->label_13->setVisible(false);
        ui->label_12->setVisible(true);
        ui->pushButton->setVisible(false);
        ui->pushButton_23->setVisible(false);
        ui->label_12->setText("No Data Available.");
        ui->label_14->setVisible(false);
        ui->label_11->setText("The Software Is Up To Date.");
    }
    ui->stackedWidget->setCurrentIndex(1);
    ui->progressBar->setVisible(false);
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_11->setText("Phase 1/3:Download");
    ui->label_12->setVisible(false);
    ui->label_13->setVisible(false);
    ui->label_14->setText("Downolading......");
    ui->progressBar->setVisible(true);

    ui->pushButton->setVisible(false);
    ui->pushButton_23->setVisible(false);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    for( int i = 0; i <101; ++i ) {
       ui->progressBar->setValue(i);
       QThread::msleep(50);
    }




    QMessageBox::information(this,"Update","The Update Is Compeleted.");

    QDateTime s = QDateTime::currentDateTime();
    QString a=s.toString("dd-MM-yyyy");
    QString b=s.toString("hh:mm:ss");
    ui->textEdit->insertPlainText(b);
    ui->textEdit->insertPlainText(" :: ");
    ui->textEdit->insertPlainText(a);
    ui->textEdit->insertPlainText(" Update Name.\n");

    ui->pushButton_28->setIcon(QIcon(":/rec/img/output-onlinepngtools (4).png"));
    ui->pushButton_9->setIcon(QIcon(":/rec/img/gMJRp2s.png"));
    ui->label_15->setText("0");
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_16_clicked()
{
    QQuickView *view = new QQuickView;
    view->setSource(QUrl::fromLocalFile("home/root/2021GP/ota_client/Dashboard/Dashboard.qml"));
    view->show();
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_17_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_25->setText("1");
}

void MainWindow::on_pushButton_36_clicked()
{
    QString flag_1 =ui->label_25->text();
    if(flag_1=="1")
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(flag_1=="0")
    {
      ui->stackedWidget->setCurrentIndex(1);
    }

}

void MainWindow::on_pushButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_35_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_25->setText("0");

    QString flag_2 =ui->label_15->text();
    if(flag_2=="1")
    {
      ui->pushButton_28->setIcon(QIcon(":/rec/img/output-onlinepngtools.png"));
      ui->label_11->setText("New Software Available.");
      ui->label_12->setText("name:");
      ui->label_13->setVisible(true);
      ui->pushButton->setVisible(true);
      ui->pushButton_23->setVisible(true);
      ui->label_14->setVisible(true);
    }
    else
    {
        ui->pushButton_28->setIcon(QIcon(":/rec/img/output-onlinepngtools (4).png"));
        ui->label_13->setVisible(false);
        ui->label_12->setVisible(true);
        ui->pushButton->setVisible(false);
        ui->pushButton_23->setVisible(false);
        ui->label_12->setText("No Data Available.");
        ui->label_14->setVisible(false);
        ui->label_11->setText("The Software Is Up To Date.");
    }
}



void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    QString flag_3 =ui->label_15->text();
    if(flag_3=="1")
    {
      ui->label_11->setText("New Software Available.");
      ui->label_12->setText("name:");
      ui->label_13->setVisible(true);
      ui->pushButton->setVisible(true);
      ui->pushButton_23->setVisible(true);
      ui->label_14->setVisible(true);
    }
    else
    {
        ui->label_13->setVisible(false);
        ui->label_12->setVisible(true);
        ui->pushButton->setVisible(false);
        ui->pushButton_23->setVisible(false);
        ui->label_12->setText("No Data Available.");
        ui->label_14->setVisible(false);
        ui->label_11->setText("The Software Is Up To Date.");
    }

}


void MainWindow::on_pushButton_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_39_clicked()
{
     QApplication::quit();
}
