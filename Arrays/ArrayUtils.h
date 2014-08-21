#include <iostream>
#include <vector>

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

template<class T, size_t rows, size_t cols>
vector<vector<T> > arrayToVector(T (&A)[rows][cols])
{
    vector<vector<T> > matrix;
        
    for (int i; i < rows; i++) {
        vector<type> row;
        for (int j =0; j < cols; j++)
            row.push_back(A[i][j]);
        matrix.push_back(row);
    }    
    return matrix;
}
template<class T>
void printMatrix(const vector<vector<T>>& matrix) {
    if (matrix.empty())
        return;
        
    int rows = matrix.size();
    int cols = matrix.begin()->size();
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }
}
