#include <iostream>

using namespace std;

int maxVal(int A[], int size)
{
    int maxTotal = 0;
    int maxCurrent = A[0];
    
    for (int i = 1; i < size; i++) {
        maxCurrent = max(A[i], maxCurrent + A[i]);
        maxTotal = max(maxTotal, maxCurrent);
    }
    return maxTotal;
}

int main()
{
    int A[] = {-5, 0, -4, 1, 4, 3, -2, -1, 2, -3};
    int size = sizeof(A) / sizeof(int);
    
    cout<<"Max value of contiguous subsequence :"<<maxVal(A, size)<<endl;
    
    return 0;
}
