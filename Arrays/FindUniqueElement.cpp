/**
*   Find the element that appears once
*   Given an array where every element occurs three times, except one element which occurs only once. 
*   Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
*
*   Examples:
*
*   Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
*   Output: 2
*
**/

#include <iostream>
#include <bitset>

using namespace std;

int findUnique(int A[], int size)
{
    int ones = 0, twos = 0;
    int notThrees = 0;
    
    for (int i = 0; i < size; i++) {
        twos = twos | (ones & A[i]);
        ones = ones ^ A[i];
        notThrees = ~(twos & ones);
        ones = ones & notThrees;
        twos = twos & notThrees;
    }
    
    return ones;
}

int main()
{
    int A[] = {3, 3, 1, 3, 2, 2, 2};
    
    cout<<"Unique Element is "<<findUnique(A, sizeof(A) / sizeof(int));
    return 0;
}
