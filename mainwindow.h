#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_Play_clicked();

    void on_Sendtheanswer_clicked();

    void on_Slove_clicked();

    void on_Slove_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
