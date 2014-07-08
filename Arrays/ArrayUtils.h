#include <iostream>

void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        std::cout<<A[i] << " ";
}

//Awesome way to print 2D arrays using templates
template<class T, size_t rows, size_t cols>
void printMatrix(T (&A)[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout<<A[i][j]<<" ";
        std::cout<<std::endl;
    }
}

