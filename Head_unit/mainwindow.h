#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include "socket.h"
#include "Get_SWC.h"
#include "decrypt.h"
#include "integrity_check.h"
#include "Packing_Unpacking.h"

#define fixed_size_ 1000
typedef unsigned long long TransferIdType;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string package_name_update{};
    std::string package_size_update{};
    std::string package_name_update_zip{};
    std::vector<std::string> dirs_inside_parent{};
    std::vector<std::string> files_inside_parent{};
    std::vector<std::string> swc_names{};
    std::vector<std::pair<std::string,std::string>> updates {};
    std::vector <std::string> versions{};
    unsigned long long size_;
    int a1;
    int a;
    int b;


    std::string path = "/home/engkhalid7/Desktop/Project_files/SW_Clusters";
    std::string download_path = "/home/engkhalid7/Desktop/Project/Download";
    std::string ip="127.0.0.1";


private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_39_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
