/**
*
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

template<class T, size_t rows, size_t cols>
void rotateMatrix(T (&A)[rows][cols]) {

}

int main()
{
    int matrix[][3] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                      };
                
    printMatrix(matrix);
    rotateMatrix(matrix);
    return 0;
}
