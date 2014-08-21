#include <iostream>
#include <vector>


using namespace std;

int maxSubsequenceSum(int A[], int size) 
{
    int maxSum = A[0];
    int curMax = A[0];

    for (int i = 1; i < size; i++) {
        curMax = max(curMax + A[i], A[i]);
        if (maxSum < curMax)
            maxSum = curMax;
    }
    
    return maxSum;
}

int main()
{
    int A[] = {-15, 29, -36, 3, -22, 11, 19, -5};
    cout<<maxSubsequenceSum(A, sizeof(A) / sizeof(int));
    return 0;
}
