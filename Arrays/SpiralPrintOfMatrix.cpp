/**
*   Given a matrix (2D array) of m x n elements (m rows, n columns), 
*   write a function that prints the elements in the array in a spiral manner.
*
*   For example
*
*   Consider the matrix below
*       
*       1  2  3  4
*       5  6  7  8
*       9 10 11 12       
*
*   Output : 1 2 3 4 8 12 11 10 9 5 6 7
*    
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;
template<class T, int rows, int cols>
void spiralPrintMatrix(T (&A)[rows][cols], int x, int y, int row, int col) {
    //print first row
    int i = 0;
    
    //Empty matrix
    if (row - x <= 0 || col - y <= 0)
        return;
    
    //Single row matrix    
    if (row - x  == 1) {
        for (i = y; i < col; i++)
            cout<<A[x][i]<<" ";
        return;
    }
    
    //Single column matrix
    if (col - y == 1) {
        for (i = x; i < row; i++)
            cout<<A[i][y]<<" ";
        return;
    }
    
    //Print outer layer of the matrix
    //top
    for (i = y; i < col; i++)
        cout<<A[x][i]<<" ";
    //right
    for (i = x + 1; i < row; i++)
        cout<<A[i][col - 1]<<" ";
    //bottom
    for (i = col - 2; i > y; i--)
        cout<<A[row-1][i]<<" ";
    //left
    for (i = row - 1; i > x; i--)
        cout<<A[i][y]<<" ";
    
    //now print the inner matrix
    spiralPrintMatrix(A, x + 1, y + 1, row-1, col-1);
}

int main()
{
    int matrix[][5] = {
                        { 1,  2,  3, 16, 17},
                        { 4,  5,  6, 18, 19},
                        { 7,  8,  9, 20, 21},
                        {10, 11, 12, 22, 23},
                        {13, 14, 15, 24, 25}
                      };
                
    printMatrix(matrix);
    spiralPrintMatrix(matrix, 0, 0, 5, 5);
    return 0;       
}
