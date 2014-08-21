#include <iostream>
#include <vector>

using namespace std;

int minNumOfQoins(int W[], int n, int weight) {
    vector<int> minWeight(weight + 1, INT_MAX);
    minWeight[0] = 0;
    
    for (int i = 1; i <= weight; i++) {
        for (int j = 0; j < n; j++) {
            if (W[j] <= i)
                minWeight[i] = min(minWeight[i], minWeight[i - W[j]] + 1);
        }
    }
    return minWeight[weight];
}

int main()
{
    int W[] = {1, 3, 5};
    int S = 11;
    cout<<"Min no of Qoins : "<<minNumOfQoins(W, 3, S)<<endl;
    return 0;    
}
