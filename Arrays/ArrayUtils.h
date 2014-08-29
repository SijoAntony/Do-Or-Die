#include <iostream>
#include <vector>

using namespace std;

void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<A[i] << " ";
    cout<<endl;
}

template<class T>
void printArray(const vector<T>& A)
{
    for(int i = 0; i < A.size(); i++)
        cout<<A[i] << " ";
    cout<<endl;
}

//Awesome way to print 2D arrays using templates
template<class T, size_t rows, size_t cols>
void printMatrix(T (&A)[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

template<class T, size_t rows, size_t cols>
vector<vector<T> > arrayToVector(T (&A)[rows][cols])
{
    vector<vector<T> > matrix;
        
    for (int i; i < rows; i++) {
        vector<T> row;
        for (int j =0; j < cols; j++)
            row.push_back(A[i][j]);
        matrix.push_back(row);
    }    
    return matrix;
}

template<class T>
void printMatrix(const vector<vector<T> >& matrix) {
    if (matrix.empty())
        return;
        
    int rows = matrix.size();
    for(int i = 0; i < rows; i++) {
        int cols = matrix[i].size();
        for (int j = 0; j < cols; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

