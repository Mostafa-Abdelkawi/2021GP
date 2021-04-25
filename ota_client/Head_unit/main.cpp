#include "mainwindow.h"
#include <QProcess>
#include <QApplication>
//#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



//    QString program = "E:/Khalid VIP files/GP/Dashboard/dashboard";
//   QStringList arguments;
//    arguments << "-style" << "fusion";

//    QProcess myProcess ;
//    myProcess.start(program);

//    QDeclarativeView *qmlView = new QDeclarativeView;
//    qmlView->setSource(QUrl::fromLocalFile("E:/Khalid VIP files/GP/Dashboard/dashboard.qml"));
//    qmlView->view();

//    QWidget *widget = myExistingWidget();
//    QVBoxLayout *layout = new QVBoxLayout(widget);
//    layout->addWidget(qmlView);

    return a.exec();

}
