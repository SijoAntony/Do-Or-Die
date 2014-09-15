/**
*   Push all the zero's of a given array to the start of the array. In place only. 
*   For Example 1,2,0,4,0,0,8 becomes 0,0,0,1,2,4,8
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;
//Moves zeros to start, but other numbers loose ordering
//So its not inplace
void moveZerosToStart(int A[], int size) {
    for(int i = 0, j = size - 1; i < j;) {
        if (A[i] == 0) i++;
        else if (A[j] != 0) j--;
        else {
            swap(A[i], A[j]);
            i++, j--;
        }
    }
}

//Its inplace algorithm
void moveZerosToStartEx(int A[], int size) {
    int pos = size - 1;
   
    for (int i = size - 1; i >= 0; i--) {
        if (A[i])
            A[pos--] = A[i];
    }
    
    for (int i = pos; i >= 0; i--)
        A[i] = 0;
}

int main()
{
    int A[] = {0, 0, 1, 2, 0, 4, 0, 0, 8, 9};
    int size =  sizeof(A) / sizeof(int);
    
    cout<<"Before ";printArray(A, size);
    moveZerosToStartEx(A, size);
    cout<<"After ";printArray(A, size);
    return 0;
}
