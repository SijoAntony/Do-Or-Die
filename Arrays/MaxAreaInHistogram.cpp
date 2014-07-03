/**
* Find the largest rectangular area possible in a given histogram where the largest rectangle can be 
* made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
*
* For example, consider the histogram with 7 bars of heights {6, 2, 5, 4, 5, 2, 6}. 
* The largest possible rectangle possible is 12.
*
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaxArea(int A[], int size) {
        stack<int> numberStack;
        int maxArea = 0, i;
        
        for (i = 0; i < size;) {
            if (numberStack.empty() || A[numberStack.top()] <= A[i])
                numberStack.push(i++);
            else {
                int top = numberStack.top();
                numberStack.pop();
                int area = A[top] * (numberStack.empty() ? i : i - numberStack.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        
        while (!numberStack.empty()) {
            int top = numberStack.top();
            numberStack.pop();
            int area = A[top] * (numberStack.empty() ? i : i - numberStack.top() - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }       
};

int main()
{
    //Histogram bar heights
    int A[] = {2, 1, 5, 6, 2, 4};
    int size = sizeof(A) / sizeof (int);
    
    Solution sl;
    cout<<"Max Are of Histogram: "<<sl.getMaxArea(A, size)<<endl;
    
    return 0;
}
