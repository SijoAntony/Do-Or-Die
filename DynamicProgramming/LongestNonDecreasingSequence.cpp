#include <iostream>
#include <vector>

using namespace std;

int lengthNonDecrSequence(int A[], int n) {
    vector<int> S(n, 1);
    S[0] = 1;
    int maxS = 1;
    
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) {
            S[i] = max(S[i], S[i - 1] + 1);
            maxS = max(maxS, S[i]);
        }
    }
    
    return maxS;
}

int main()
{
    int A[] = {1, 3, 4, 5, 6, 7};
    cout<<"Length of longest non decreasing sequence: "<<lengthNonDecrSequence(A, sizeof(A) / sizeof(int))<<endl;
    return 0;    
}
