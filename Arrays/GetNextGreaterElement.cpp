/**
* Given an array find the next greater element in array for each element without 
* changing the original order of the elements. If no element found return -1
*
* For example, suppose the given array is 1, 2, 4, 5, 3.
*
* The resultant array would be 2, 4, 5, -1, -1
*
**/

#include <iostream>
#include <stack>

#include "ArrayUtils.h"

using namespace std;

class Solution {
public:
    void getNextGreaterElements(int A[], int size, int *result) {
        stack<int> numberStack;
        for (int i = 0; i < size; i++) {
            while (!numberStack.empty() && A[numberStack.top()] < A[i]) {
                result[numberStack.top()] = A[i];
                numberStack.pop();
            }
            numberStack.push(i);
        }
        
        while (!numberStack.empty()) {
            result[numberStack.top()] = -1;
            numberStack.pop();
        }
    }
};

int main()
{
    int A[] = {1, 2, 4, 5, 3};
    int size = sizeof(A) / sizeof (int);
    int *B = new int[size]; 
    
    Solution sl;
    sl.getNextGreaterElements(A, size, B);
    
    cout<<"\nArray: "; printArray(A, size);
    cout<<"\nMaxs: "; printArray(B, size);
    
    delete [] B;
    return 0;  
}
