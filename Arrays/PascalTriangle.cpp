/**
*   Given numRows, generate the first numRows of Pascal's triangle.
*
*   For example, given numRows = 5,
*   Return
*
*   [
*        [1],
*       [1,1],
*      [1,2,1],
*     [1,3,3,1],
*    [1,4,6,4,1]
*   ]
*
**/

#include <iostream>
#include <vector>
#include "ArrayUtils.h"

using namespace std;


vector<vector<int> > pascalTriangle(int n) 
{
    vector<vector<int> > triangle (n);
    for (int i = 0, j; i < n; i++) {
        
        triangle[i] = vector<int>(i + 1);
        triangle[i][0] = 1;

        for (j = 1; j < i; j++)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            
        triangle[i][i] = 1;
    }

    return triangle;
}

vector<int> pascalRow(int rowIndex) 
{
    rowIndex  = rowIndex + 1;
    vector<int> row(rowIndex);

    for (int i = 0, j; i < rowIndex; i++) {
        vector<int> last = row; 
        row = vector<int>(i + 1);

        row[0] = 1;

        for (j = 1; j < i; j++)
            row[j] = last[j - 1] + last[j];
            
        row[i] = 1;
    }

    return row;
}



int main()
{
    vector<vector<int> > triangle  = pascalTriangle(7);
    printMatrix<int>(triangle);
    
    vector<int> row = pascalRow(4);
    printArray(row);
    
    return 0;
}
