/**
*
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

template <int rows, int cols>
void findMaxMatrix(int (&A)[rows][cols])
{
    int max = 0, maxr = 0, maxc = 0;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (A[i][j])
                A[i][j] += min(min(A[i-1][j], A[i][j-1]), A[i-1][j-1]);
            if (A[i][j] > max) {
                max = A[i][j];
                maxr = i, maxc = j;
            }
        }
    }
    
    cout<<"Max Rect : ("<<max - maxr + 1<<", "<<max - maxc + 1<<", "<<maxr<<", "<<maxc<<")"<<endl;
}
int main()
{
    int matrix[][5] = {
                        {0, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1},
                        {1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1},
                      };

    printMatrix(matrix);
    findMaxMatrix(matrix);
    printMatrix(matrix);
    return 0;
}
