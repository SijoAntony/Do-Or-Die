#include <iomanip>
#include "Heap.h"

class NumberStream {
public:
    NumberStream() : N(0) {
    }
    
    void insert(int number) {
        if (N % 2 == 0) {
            maxHeap.push(number);
            
            if (!minHeap.empty() && maxHeap.top() < minHeap.top()) {
                int toMin = maxHeap.pop();
                int toMax = minHeap.pop();
                
                maxHeap.push(toMax);
                minHeap.push(toMin);    
            }
             
        } else {
            maxHeap.push(number);
            int toMin = maxHeap.pop();
            minHeap.push(toMin);
        }

        N += 1;            
    }
    
    double getMedian() {
        if (N % 2)
            return maxHeap.top();
        return (maxHeap.top() * 1.0 + minHeap.top()) / 2;
    }

private:
    MaxHeap maxHeap;
    MinHeap minHeap;
    int N;
};

int main()
{
    int A[] = {3,5,4,6,2,1,0,7,9,8};
    int size = sizeof(A) / sizeof(int);
    NumberStream numStream;
    
    for (int i = 0; i < size; i++) {
        numStream.insert(A[i]);
        cout<<"-->"<<fixed << setprecision( 2 ) <<numStream.getMedian()<<endl;    
    }
    
    return 0;    
}
