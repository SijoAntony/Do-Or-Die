/**
*
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

int getIndex(int A[], int low, int high) 
{    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || A[mid - 1] == 0) && A[mid] == 1)
            return mid;
        
        else if (A[mid - 1] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1;
}

template<int rows, int cols>
int getRowWithMaxOnes(int (&A)[rows][cols])
{
    int rowIndex = -1;
    int c = getIndex(A[0], 0, cols - 1);

    if (c == -1)
        c = cols - 1;
    else
        rowIndex = 0;
        
    for (int r = 1; r < rows; r++) {
        while (c >= 0 && A[r][c] == 1) {
            c--;
            rowIndex = r;    
        }    
    }
    return rowIndex;
}

int main()
{
    int matrix[][5] = {
                        {0, 0, 0, 0, 1},
                        {0, 0, 1, 1, 1},
                        {0, 0, 0, 1, 1},
                        {0, 1, 1, 1, 1},
                        {0, 0, 1, 1, 1}                       
                      };
                
    printMatrix(matrix);
    cout<<"\nRow with Max 1s: "<<getRowWithMaxOnes<5, 5>(matrix) + 1;
    return 0;
}
