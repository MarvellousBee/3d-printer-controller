#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_stop_button_clicked();

    void on_left_button_clicked();

    void on_right_button_clicked();

    void on_backward_button_clicked();

    void on_forward_button_clicked();

    void on_up_button_clicked();

    void on_down_button_clicked();

    void on_send_button_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *gcode_input;
};
#endif // MAINWINDOW_H
