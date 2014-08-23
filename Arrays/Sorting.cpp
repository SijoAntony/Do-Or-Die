#include <iostream>
#include "ArrayUtils.h"

using namespace std;

//Insertion Sort
void insertionSort(int A[], int size)
{
    for(int i = 1, j; i < size; i++) {
        int elem = A[i];

        for (j = i; j > 0 && A[j - 1] > elem; j--)
            A[j] = A[j - 1];
 
        A[j] = elem;
    }
}

//Selection Sort
void selectionSort(int A[], int size)
{
    for (int i = 0, j; i < size - 1; i++) {
        int min = i;
        
        for (j = i + 1; j < size; j++)
            if (A[j] < A[min])
                min = j;
                
        if (min != i)
            swap(A[min], A[i]);
    }
}


//Heap sort
void heapify(int A[], int size, int index)
{
    int i = index;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && A[left] > A[i])
        i = left;
    if (right < size && A[right] > A[i])
        i = right;
       
    if (i != index) {
        swap(A[i], A[index]);
        heapify(A, size, i);
    }  
}

void buildHeap(int A[], int size)
{
    for (int i = size / 2 - 1; i >=0; i--)
        heapify(A, size, i);
}

void heapSort(int A[], int size)
{
    buildHeap(A, size);
    for (int i = size - 1; i >=0; i--) {
        swap(A[i], A[0]);
        heapify(A, i, 0);
    }
}

//Merge Sort
void merge(int A[], int low, int mid, int high)
{
    int *buffer = new int[high - low + 1];
    int index = 0;
    int i, j;
    for (i = low, j = mid + 1; i <= mid && j <= high;)
        if (A[i] < A[j])
            buffer[index++] = A[i++];
        else
            buffer[index++] = A[j++];
    
    while(i <= mid)
        buffer[index++] = A[i++];

    while(j <= mid)
        buffer[index++] = A[j++];
    
    i = 0;
    
    while (i < index) {
        A[low + i] = buffer[i]; 
        i++;
    }
    delete buffer;
}

void mergeSort(int A[], int low, int high)
{
    if (high <= low)
        return;
        
    int mid  = low + (high - low) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    
    merge(A, low, mid, high);
}

void mergeSort(int A[], int size)
{
    mergeSort(A, 0, size - 1);
}

//Quick sort
int partition(int A[], int low, int high)
{
    int pivote = low;
    int i = low + 1, j = high; 

    while (i <= j) {
        while (A[pivote] >= A[i] && i <= j) i++;
        while (A[pivote] < A[j]) j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[pivote], A[j]);
    return j;
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return;

    int index = partition(A, low, high);
    quickSort(A, low, index - 1);
    quickSort(A, index + 1, high);
}

void quickSort(int A[], int size)
{
    quickSort(A, 0, size - 1);
}


int main()
{
    int A[] = {99, 2, 5, 100, -20, 33};
    int size = sizeof(A) / sizeof(int);

    printArray(A, size);
    quickSort(A, size);
    printArray(A, size);
    
    return 0;
}
