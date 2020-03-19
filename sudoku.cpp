#include "sudoku.h"

sudoku::sudoku()
{}

    bool sudoku::SolveSudoku (int grid[N][N]) {
        int row, col;

        // If there is no unassigned location, we are done
        if (!FindZeroLocation(grid, row, col))
            return true; // success!

        // consider digits 1 to 9
        for (int num = 1; num <= 9; num++) {
            // if looks promising
            if (isSafe(grid, row, col, num)) {
                // make tentative assignment
                grid[row][col] = num;

                // return, if success, yay!
                if (SolveSudoku(grid))
                    return true;

                // failure, unmake & try again
                grid[row][col] = UNASSIGNED;
            }
        }
        return false; // this triggers backtracking
    }

    /* Searches the grid to find an entry that is still unassigned. If
    found, the reference parameters row, col will be set the location
    that is unassigned, and true is returned. If no unassigned entries
    remain, false is returned. */
    bool sudoku::FindZeroLocation(int grid[N][N], int &row, int &col) {
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (grid[row][col] == UNASSIGNED)
                    return true;
        return false;
    }

    /* Returns a boolean which indicates whether any assigned entry
    in the specified row matches the given number. */
    bool sudoku::UsedInRow(int grid[N][N], int row, int num) {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }

    /* Returns a boolean which indicates whether any assigned entry
    in the specified column matches the given number. */
    bool sudoku::UsedInCol(int grid[N][N], int col, int num) {
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }

    /* Returns a boolean which indicates whether any assigned entry
    within the specified 3x3 box matches the given number. */
    bool sudoku::UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row+boxStartRow][col+boxStartCol] == num)
                    return true;
        return false;
    }

    /* Returns a boolean which indicates whether it will be legal to assign
    num to the given row,col location. */
    bool sudoku::isSafe(int grid[N][N], int row, int col, int num) {
        /* Check if 'num' is not already placed in current row,
            current column and current 3x3 box */
        return !UsedInRow(grid, row, num) &&
               !UsedInCol(grid, col, num) &&
               !UsedInBox(grid, row - row%3 , col - col%3, num);
    }

    /* A utility function to print grid */
    void sudoku::printGrid(int grid[N][N]) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++)
                cout<<grid[row][col]<<" ";
            cout<<endl;
        }
    }
    //make 1~9 num to make row and col change in 1~3 4~6 7~9
    void sudoku::indexgenerater(int index[N]) {
        srand(time(NULL));
        int counter[9]= {0,0,0,0,0,0,0,0,0};
//1~3
        for(int i=0; i<3; ++i) {
            int a=rand()%3;
            ++counter[a];
            while(index[i]==0) {
                if(counter[a]==1) {
                    index[i]=a+1;
                } else {
                    a=rand()%3;
                    ++counter[a];
                }
            }
        }
//4~6
        for(int i=3; i<6; ++i) {
            int	a=rand()%3+3;
            ++counter[a];
            while(index[i]==0) {
                if(counter[a]==1) {
                    index[i]=a+1;
                } else {
                    a=rand()%3+3;
                    ++counter[a];
                }
            }
        }
//7~9
        for(int i=6; i<9; ++i) {
            int	a=rand()%3+6;
            ++counter[a];
            while(index[i]==0) {
                if(counter[a]==1) {
                    index[i]=a+1;
                } else {
                    a=rand()%3+6;
                    ++counter[a];
                }
            }
        }

    }
//use the index above to change the grid
    void sudoku::randomgrid(int index[N],int grid[N][N],int grid2[N][N]) {
        for(int r=0; r<9; ++r) {
            for(int c=0; c<9; ++c) {
                grid2[r][c]=grid[r][index[c]-1];
            }
        }
        indexgenerater(index);
        for(int c=0; c<9; ++c) {
            for(int r=0; r<9; ++r) {
                grid2[r][c]=grid[index[r]-1][c];
            }
        }
    }

