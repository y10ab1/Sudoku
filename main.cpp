#include "mainwindow.h"
#include <QApplication>
#include "sudoku.h"
#include <QTableWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
