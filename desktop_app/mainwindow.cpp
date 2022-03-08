#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requests.h"
#include "non_gui.h"
#include <regex>

crl request;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   IP::set_ip();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_stop_button_clicked()
{
    request.get(IP::ip+"stop");
}


void MainWindow::on_left_button_clicked()
{
    request.get(IP::ip+"button_down/left");
}


void MainWindow::on_right_button_clicked()
{
    request.get(IP::ip+"button_down/right");
}


void MainWindow::on_backward_button_clicked()
{
    request.get(IP::ip+"button_down/backward");
}


void MainWindow::on_forward_button_clicked()
{
    request.get(IP::ip+"button_down/forward");
}


void MainWindow::on_up_button_clicked()
{
    request.get(IP::ip+"button_down/up");
}


void MainWindow::on_down_button_clicked()
{
    request.get(IP::ip+"button_down/down");
}


void MainWindow::on_send_button_clicked()
{
    QString searchString{ui->gcode_input->text()};
    std::string str{searchString.toStdString()};
    str = std::regex_replace(str, std::regex(" "), "\%");
    request.get(IP::ip+"custom/"+str);
}

