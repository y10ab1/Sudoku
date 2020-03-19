#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "QDebug"
#include "QTableWidget"
#include "QTableWidgetItem"
using namespace std;
#define UNASSIGNED 0
#define N 9


class sudoku
{
public:
    sudoku();

    bool SolveSudoku(int grid[N][N]);


    bool FindZeroLocation(int grid[N][N], int &row, int &col);


    bool UsedInRow(int grid[N][N], int row, int num);

    bool UsedInCol(int grid[N][N], int col, int num);

    bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);

    bool isSafe(int grid[N][N], int row, int col, int num);

    void printGrid(int grid[N][N]);

    void indexgenerater(int index[N]);

    void randomgrid(int index[N],int grid[N][N],int grid2[N][N]);



};

#endif // SUDOKU_H
