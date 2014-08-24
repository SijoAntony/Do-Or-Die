#include <iostream>

using namespace std;

int numTrees(int n) {
    if (n <= 1)
        return 1;

    int trees = 0, left = 0, right = 0;

    for (int i = 1; i <= n; i++) {
        left = numTrees(i - 1);
        right = numTrees(n - i);
        trees += left * right;
    }

    return trees;
}

int main()
{
    cout<<"Num of trees "<<numTrees(4)<<endl;
    return 0;
}
