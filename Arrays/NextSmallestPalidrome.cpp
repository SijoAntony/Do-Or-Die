/**
*
*
**/

#include <iostream>
#include "ArrayUtils.h"

using namespace std;

void nextPalidrome(vector<int> &digits, int l, int r)
{
    if (l < 0) {
        digits[0] = 1;
        digits.push_back(1);
        return;
    }
    
    if (digits[l] < 9) {
        int current = digits[l];
        digits[l] = digits[r] = current + 1;
        return;
    }
    
    digits[l] = digits[r] = 0;
    nextPalidrome(digits, l - 1, r + 1);
}

void createPalindrome(vector<int> &digits, int l, int r)
{
    for (int i = l, j = r; i < j; i++, j--)
        digits[j] = digits[i];
}

int main()
{
    int A[] = {5, 4};
    vector<int> num(A, A + sizeof(A) / sizeof(int));
    int size = num.size();
    
    createPalindrome(num, 0, size - 1);
    
    if (size % 2)
        nextPalidrome(num, size / 2, size / 2);
    else
        nextPalidrome(num, size / 2 - 1, size / 2);
        
    printArray(num);
    return 0;
}
