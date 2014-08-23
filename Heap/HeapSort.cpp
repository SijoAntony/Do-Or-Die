#include <iostream>

using namespace std;

void maxHeapify(int A[], int size, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int i = index;
    
    if (left < size && A[left] > A[i])
        i = left;
    if (right < size && A[right] > A[i])
        i = right;
        
    if (i != index) {
        swap(A[i], A[index]);
        maxHeapify(A, size, i);
    }
    
}

void buildHeap(int A[], int size)
{
    for (int i = size/ 2 - 1; i >= 0; i--)
        maxHeapify(A, size, i);
}


void heapSort(int A[], int size) 
{
    if (!A || size <=0 )
        return;
    
    buildHeap(A, size);
    
    for (int i = size - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        maxHeapify(A, i, 0);
    }
}

void print(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main()
{
    int A[] = {99, 60, 23, 55, 71, 9, 20, 43, 86};
    int size = sizeof(A) / sizeof(int);
    
    print(A, size);
    heapSort(A, size);
    print(A, size);
    
    return 0;
}
