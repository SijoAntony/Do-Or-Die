#include <iostream>
#include <ctime>

#include "ObjectPoolAllocator.h"

using namespace std;

class ComplexNumber {
public:
    explicit ComplexNumber(double r, double c)
        : m_r(r)
        , m_c(c) {
    }
    ~ComplexNumber() {
    }
 
    //overloaded operators for the class
    void *operator new(size_t size) {
        return ObjectPoolAllocator::instance()->alloc(size);
    }
    void operator delete(void *pointer) {
        return ObjectPoolAllocator::instance()->dealloc(pointer);
    }

private:
    double m_r, m_c;
};

//testing module
int main()
{
    ComplexNumber *numbers[1000];
    clock_t begin = clock();

    for (int i = 0; i < 5000; i++) {
        for (int j = 0; j < 1000; j++)
            numbers[j] = new ComplexNumber(i, j);
        
        for (int j = 0; j < 1000; j++)
            delete numbers[j];
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Time taken "<<elapsed_secs<<endl;
    return 0;
}