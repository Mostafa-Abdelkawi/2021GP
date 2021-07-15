#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QMessageBox>
#include <QCoreApplication>
#include <QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setGeometry(825, 200, 450, 200);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl::fromLocalFile("/home/engkhalid7/Desktop/Project_files/packages/Dashboard/Dashboard.qml"));
    ui->label_15->setVisible(false);
    ui->label_25->setVisible(false);
    ui->progressBar->setVisible(false);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
     a1 =::chdir(path.c_str());
    //a = create_client_socket(5000,ip);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_10_clicked()
{
    Get_Swc(path, dirs_inside_parent, files_inside_parent, swc_names, versions);

    for(size_t i=0; i<dirs_inside_parent.size(); i++)
    {
        updates.push_back(std::make_pair(swc_names[i],versions[i]));
    }

    a = create_client_socket(5000,ip);
    send_vector_pair(a,updates);
    package_name_update=recv_string(a);
    package_size_update=recv_string(a);
    size_=stoi(package_size_update);

    if(package_name_update.empty()!= true)
    {
       package_name_update_zip=package_name_update+".zip";
       ui->pushButton_9->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
       ui->pushButton_21->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
       ui->pushButton_28->setIcon(QIcon(":/rec/img/output-onlinepngtools.png"));
       ui->label_15->setText("1");
    }
    else
    {

    }

}

void MainWindow::on_pushButton_9_clicked()
{
    QString flag =ui->label_15->text();
    std::string name_="Name:  "+package_name_update;
    QString Name_=QString::fromStdString(name_);
    std::string size_="Package Size:  "+package_size_update+" bytes";
    QString Size_=QString::fromStdString(size_);

    if(flag=="1")
    {
      ui->label_11->setText("New Software Available.");
      ui->label_12->setText(Name_);
      ui->pushButton_21->setIcon(QIcon(":/rec/img/3C3C5844-4430-48CD-BBE7-F5D8D5062211.png"));
      ui->label_13->setVisible(true);
      ui->label_13->setText(Size_);
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
    for( int i = 0; i <50; ++i ) {
       ui->progressBar->setValue(i);
       QThread::msleep(50);
    }
   int b=recv_files(a, package_name_update_zip, download_path);
   for( int i = 50; i <101; ++i ) {
      ui->progressBar->setValue(i);
      QThread::msleep(50);
   }
    printf("[+]Data written in the file successfully.\n");


    ui->label_11->setText("Phase 2/3:Verfiy");
    ui->label_14->setText("Verifying......");
    for( int i = 0; i <50; ++i ) {
       ui->progressBar->setValue(i);
       QThread::msleep(50);
    }

    aes_decrypt(package_name_update_zip);
    integrity_check(package_name_update_zip);

    for( int i = 50; i <101; ++i ) {
       ui->progressBar->setValue(i);
       QThread::msleep(50);
    }


    close_socket(a);

    int a_1;
    QMessageBox::StandardButton reply;

    reply=QMessageBox::question(this,"Update Is Ready To Be Install.","Do You Want Install Now?",QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        b = create_client_socket(5002,ip);


        ui->label_11->setText("Phase 3/3:Install");
        ui->label_14->setText("Installing......");
        for( int i = 0; i <25; ++i ) {
           ui->progressBar->setValue(i);
           QThread::msleep(50);
        }


        Send_operation(TransferStart,b);
        TransferIdType ID;
        a_1=Send_element<unsigned long long>(size_, b);
        a_1=Recieve_element<TransferIdType>(ID, b);


        for( int i = 25; i <50; ++i ) {
           ui->progressBar->setValue(i);
           QThread::msleep(50);
        }

        Send_operation(TransferData,b);
        std::string package_transfer;
        package_transfer=download_path+"/"+package_name_update_zip;
        ByteVectorType re = packedfile(&package_transfer[0]);
        unsigned long long size=re.size();
        unsigned long long blockCounter=0;

       int num_blocks=re.size()/fixed_size_;
       std::cout<<num_blocks<<std::endl;
       a_1=Send_element<TransferIdType>(ID, b);


       for( int i = 50; i <75; ++i ) {
          ui->progressBar->setValue(i);
          QThread::msleep(50);
       }



        for(int k =0 ; k<=num_blocks ; k++)
        {
            ByteVectorType pre;
            if( size>fixed_size_)
            {
                for (int i = 0; i < fixed_size_; i++)
                {
                    pre.push_back(re[i+blockCounter*fixed_size_]);
                }
                blockCounter++;
               a_1=Send_element<unsigned long long>(blockCounter, b);


               Send_Data(pre,fixed_size_, b);
               size-=fixed_size_;
            }
            else
            {
                for (auto i = 0; i < size; i++)
                {
                    pre.push_back(re[i+blockCounter*fixed_size_]);
                }
                blockCounter++;
                a_1=Send_element<unsigned long long>(blockCounter, b);
               Send_Data(pre,size, b);
            }
        }

        for( int i = 75; i <101; ++i ) {
           ui->progressBar->setValue(i);
           QThread::msleep(50);
        }

       /* msg="ProcessSwPackage";
        Send_operation(ProcessSwPackage,b);
        //send_string(b,msg);
        std::cout<<"ok_ProcessSwPackage"<<std::endl;
        a_1=Send_element<TransferIdType>(ID, b);*/

        close_socket(b);
        //QApplication::quit();
    }



    QMessageBox::information(this,"Update","The Update Is Compeleted.");

    QDateTime s = QDateTime::currentDateTime();
    QString a_=s.toString("dd-MM-yyyy");
    QString b_=s.toString("hh:mm:ss");
    ui->textEdit->insertPlainText(b_);
    ui->textEdit->insertPlainText(" :: ");
    ui->textEdit->insertPlainText(a_);
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
