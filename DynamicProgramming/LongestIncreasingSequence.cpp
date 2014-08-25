#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSequence(int A[], int size)
{
    if (size == 1)
        return 1;
    
    vector<int> lis(size, 1);
    int maxlen = 1;
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        maxlen = max(maxlen, lis[i]);
    }
    
    return maxlen;
}

int ceilIndex(vector<int>& v, int low, int high, int key)
{
    while(high - low > 1) {
        int mid = low + (high - low) / 2;
        (v[mid] >= key ? high : low) = mid;        
    }
    return high;
}

int longestIncreasingSequenceEx(int A[], int size)
{
    vector<int> lis(size, 0);
    int maxlen = 1;
    lis[0] = A[0];

    for (int i = 1; i < size; i++) {
        if (A[i] < lis[0])
            lis[0] = A[i];
        else if (A[i] > lis[maxlen - 1])
            lis[maxlen++] = A[i];
        else {
            lis[ceilIndex(lis, 0, maxlen - 1, A[i])] = A[i];
        }
    }
    for (int i =0; i < maxlen; i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    return maxlen;
}

int main()
{
    int A[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout<<"Length of longest increasing sequence: "<<longestIncreasingSequenceEx(A, sizeof(A) / sizeof(int))<<endl;
    return 0;    
}
