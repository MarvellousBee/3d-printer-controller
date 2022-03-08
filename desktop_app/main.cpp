#include "mainwindow.h"
#include "requests.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    crl request{};

    w.show();
    return a.exec();
}
