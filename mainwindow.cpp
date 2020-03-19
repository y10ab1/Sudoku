#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudoku.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int a=0;a<9;++a){
    ui->tableWidget->setColumnWidth(a,40);
    ui->tableWidget->setRowHeight(a,40);}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Play_clicked()
{
   int grid[N][N] = {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        };
     int grid2[N][N];

    sudoku sudoku;
    int index[N]= {0,0,0,0,0,0,0,0,0};
//clean all the item
    for(int a=0;a<9;++a){
        for(int b=0;b<9;++b){
            QString tmp=" ";
            ui->tableWidget->setItem(a, b,new QTableWidgetItem(tmp));
        }
    }
    //clean result message
    ui->tableWidget_2->setItem(0, 0,new QTableWidgetItem(" "));
   //random grid
    sudoku.indexgenerater(index);
    sudoku.randomgrid(index,grid,grid2);
   //set question in  the items
    for(int a=0;a<9;++a){
        for(int b=0;b<9;++b){
            QString tmp=QString::number(grid2[a][b]);
            if(tmp!=QString::number(0))
    ui->tableWidget->setItem(a, b,new QTableWidgetItem(tmp));
        }}


}

void MainWindow::on_Sendtheanswer_clicked()
{   sudoku sudoku;

    int answer[N][N]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
//read what you filled
        QString tmp;
        for(int a=0;a<9;++a){
            for(int b=0;b<9;++b){
tmp=ui->tableWidget->item(a, b)->text();
if(tmp==" "){ui->tableWidget_2->setItem(0, 0,new QTableWidgetItem("You Fool!"));
    return;}
answer[a][b]=tmp.toInt();
            }
        }






        if (sudoku.SolveSudoku(answer) == true){
            for(int a=0;a<9;++a){
                for(int b=0;b<9;++b){
                    tmp=QString::number(answer[a][b]);

            ui->tableWidget->setItem(a, b,new QTableWidgetItem(tmp));
                }}
            ui->tableWidget_2->setItem(0, 0,new QTableWidgetItem("Correct!"));
        }else{ui->tableWidget_2->setItem(0, 0,new QTableWidgetItem("You Fool!"));}
            ;
}

void MainWindow::on_Slove_clicked()
{
    sudoku sudoku;

        int answer[N][N]={
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}};

            QString tmp;
            for(int a=0;a<9;++a){
                for(int b=0;b<9;++b){

    tmp=ui->tableWidget->item(a, b)->text();
    answer[a][b]=tmp.toInt();
                }
            }
            if (sudoku.SolveSudoku(answer) == true){
                for(int a=0;a<9;++a){
                    for(int b=0;b<9;++b){
                        tmp=QString::number(answer[a][b]);

                ui->tableWidget->setItem(a, b,new QTableWidgetItem(tmp));
                    }}

            }
                ;

}

//clean button
void MainWindow::on_Slove_2_clicked()
{
    for(int a=0;a<9;++a){
        for(int b=0;b<9;++b){
            QString tmp=" ";
            ui->tableWidget->setItem(a, b,new QTableWidgetItem(tmp));
        }
    }   
    ui->tableWidget_2->setItem(0, 0,new QTableWidgetItem(" "));
}
