/**
*
*
**/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A[] = {1, 2, 4, 5, 7, 11, 10, 9, 15, 14, 18, 19, 16};
    vector<int> N(A, A + sizeof(A) / sizeof(int));
    int n = 20, i;
    int k = n - N.size();

    for (i = n - k; i < n; i++)
        N.push_back(N[0]);
    
    for (i = 0; i < n - k; i++) {
        while(N[N[i]] != N[i])
            swap(N[i], N[N[i]]);
    }    

    for (i = 0; i < n; i++) {
        if (N[i] != i)
            cout<<i<<" ";
    }
    
    cout<<endl;    
    
    return 0;
}
