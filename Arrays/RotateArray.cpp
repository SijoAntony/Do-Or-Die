/**
*   Rotate a one-dimensional array of n elements to the right by k steps. 
*
*   For Example, with n=7 and k=3, the array {1, 2, 3, 4, 5, 6, 7} is rotated to {5, 6, 7, 1, 2, 3, 4}
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

void rotateArray(int A[], int size, int k)
{
    k = k % size;
    
    if (k <= 0)
        return;
        
    int *buffer = new int[size - k];
    int i = 0, j = 0;
    
    //copy k positions to be moved
    for (i = 0; i < size - k; i++)
        buffer[i] = A[i];

    for (i = 0, j = size - k; j < size;i++, j++)
        A[i] = A[j];

    for (i = k, j = 0; i < size; i++, j++)
        A[i] = buffer[j]; 
}


int main()
{
    int array[]= {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(array) / sizeof(int);
    printArray(array, size);
    rotateArray(array, size, 4);
    cout<<endl;
    printArray(array, size);
    return 0;
}

