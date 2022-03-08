#ifndef NON_GUI_H
#define NON_GUI_H
#include <string>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
namespace IP
{
    //Since it's just one function and a vraiable, i kept everything in the header.
    std::string ip{"0.0.0.0"};
    void set_ip()
    {
        QFile file(":put_your_local_ip_here.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "ERROR", "Could not read IP from the text file");
            throw 1;
        }
        QTextStream in(&file);
        QString buffer {in.readAll()};//
        buffer.chop(2);
        ip = buffer.toStdString() + '/';
    }

}

#endif // NON_GUI_H
