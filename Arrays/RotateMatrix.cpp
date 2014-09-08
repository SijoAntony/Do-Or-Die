/**
*
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

template<class T, size_t rows, size_t cols>

void rotateMatrix(T (&A)[rows][cols]) {
    int n = rows;
    
    for(int i=0; i<n/2; i++) {
	   for(int j=0; j<(n+1)/2; j++) {
		   int temp = A[i][j];
		   A[i][j] = A[n-1-j][i];
		   A[n-1-j][i] = A[n-1-i][n-1-j];
		   A[n-1-i][n-1-j] = A[j][n-1-i];
		   A[j][n-1-i] = temp;
	   }
	}  
}

int main()
{
    int matrix[][5] = {
                        {1, 2, 3, 4 , 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}
                      };
                
    printMatrix(matrix);
    rotateMatrix(matrix); cout<<"-----"<<endl;
    printMatrix(matrix);
    return 0;
}
