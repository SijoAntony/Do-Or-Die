#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    void push(int number) {
        m_data.insert(m_data.begin(), number);
        heapify(0);
    }
    
    int pop() {
        if (empty())
            return -1;
        int number = m_data[0];
        m_data[0] = m_data[m_data.size() - 1];
        m_data.pop_back();
        heapify(0);
        return number;
    }    
    
    void print() {
        for (vector<int>::iterator it = m_data.begin(); it != m_data.end(); ++it)
            cout<<*it;
        cout<<endl;
    }
    
    bool empty() {
        if (!m_data.size())
            return true;
        return false;
    }
    
    int top() {
        if (!empty())
            return m_data.front();
        return -1;    
    }

protected:
    void heapify(int index) {
        int i = index;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int size = m_data.size();
        
        if (left < size && compare(m_data[left], m_data[index]))
            index = left;
        if (right < size && compare(m_data[right], m_data[index]))
            index = right;
            
        if (i != index) {
            swap(m_data[index], m_data[i]);
            heapify(index);
        }
    }
    
    virtual bool compare(int a, int b) = 0;
    
private:
    vector<int> m_data;
};

class MaxHeap : public Heap {
protected:
    bool compare(int a, int b) {
        return a > b;
    }
};

class MinHeap : public Heap {
protected:
    bool compare(int a, int b) {
        return a < b;
    }
};
