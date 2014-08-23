/**
*   Sort an array having 0, 1, 2 in unsorted order.
*   
*   For Example :
*       Input  A[] = {2, 0, 1, 1, 2, 0, 2, 2, 0, 1, 1, 2, 1, 0, 2}
*       Output A[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2}     
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

void sort(int A[], int size)
{
    int low = 0;
    int high = size - 1;
    int index = 0;
    
    while(index <= high) {
        if (A[index] == 0)
            swap(A[low++], A[index++]);
        else if (A[index] == 2)
            swap(A[high--], A[index]);
        else
            index++;
    }
}

int main()
{
    int A[] = {2, 0, 1, 1, 2, 0, 2, 2, 0, 1, 1, 2, 1, 0, 2};
    int size = sizeof(A) / sizeof(int);

    printArray(A, size);
    sort(A, size);
    printArray(A, size);
    

    return 0;
}
