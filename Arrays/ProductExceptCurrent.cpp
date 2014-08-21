#include <iostream>

using namespace std;

int printProd(int A[], int n, int prevProd, int index)
{
    int revProd = 1;
    if (index < n) {
        revProd = printProd(A, n, prevProd * A[index], index + 1);
        cout<<prevProd * revProd<<" ";
        revProd *= A[index];
    }
    return revProd;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    printProd(A, 5, 1, 0);
    return 0;
}
