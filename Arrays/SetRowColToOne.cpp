/**
*   Given a M x N matrix consisting of only 0's and 1's. 
*   Wherever you find 1, make all the elements of that row and column as 1.
*
*   For example:
*
*   Consider Matrix   
*         0, 0, 0, 0
*         0, 0, 1, 0
*         0, 0, 0, 0
*         1, 0, 0, 0
*         
*   Output:
*         1, 0, 1, 0
*         1, 1, 1, 1
*         1, 0, 1, 0
*         1, 1, 1, 1
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

template<size_t m, size_t n>
void setMatrixRowCol(int (&A)[m][n]) 
{
    int *rows = new int[m];
    int *cols = new int[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            if (A[i][j]) {
                rows[i]  = 1;
                cols[j] = 1;
            }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows[i] || cols[j])
                A[i][j] = 1; 
        }
    }
    
    delete []rows;
    delete []cols;
                
}

int main()
{
    int matrix[][4] = {
                        {0, 0, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0},
                        {1, 0, 0, 0},
                      };
                
    printMatrix(matrix);
    setMatrixRowCol(matrix);
    cout<<"Modified Matrix:"<<endl;
    printMatrix(matrix);
    return 0;
}
