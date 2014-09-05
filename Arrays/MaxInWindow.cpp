/**
*   Print maximum numbers in given window
*
**/

#include <iostream>
#include <deque>
#include "ArrayUtils.h"

using namespace std;

void printMaxInWindow(vector<int> &V, int k)
{
    deque<int> Q;
    
    for (int i = 0; i < k; i++) {
        while (!Q.empty() && V[Q.back()] < V[i])
            Q.pop_back();
        Q.push_back(i);
    }
    
    for (int i = k; i < V.size(); i++) {
        cout<<V[Q.front()]<<" ";
    
        while (!Q.empty() && V[Q.back()] < V[i])
            Q.pop_back();
        
        if (!Q.empty() && k - Q.front() > i)
            Q.pop_front();

        Q.push_back(i);
    }
    
    cout<<V[Q.front()]<<" ";
}


int main()
{

    int numbers[] = {1,3,-1,-3,5,3,6,7};
    vector<int> A(numbers, numbers + sizeof(numbers) / sizeof(int));
    
    printMaxInWindow(A, 3);
    return 0;
}
