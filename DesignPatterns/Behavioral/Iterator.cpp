#include <iostream>

using namespace std;


class List {
public:
    explicit List(int size)
     : m_size(size)
     , m_data(new int[size]) {
        
    }
    
    void set(int A[], int size) {
        for (int i = 0; i < size && i < m_size; i++)
            m_data[i] = A[i];
    }
    
    ~List() {
        delete m_data; 
    }    
    
    class Iterator {
    public:
        Iterator(List* list, int index) 
            : m_list(list)
              , m_current(index) {
        }
        
        Iterator(const Iterator& other) {
            if (this != &other) {
                this->m_current = other.m_current;
            }
        }
        
        bool operator !=(Iterator &it) {
            return this->m_current < it.m_current;
        }
        
        Iterator& operator++() {
            this->m_current++;
            return *this;
            
        }
        Iterator operator++(int dummy) {
            Iterator temp = *this;
            this->m_current++;
            return temp;
        }
        
        int operator*() {
            return m_list->m_data[m_current];
        }
        
    private:
        List *m_list;
        int m_current;
    };
    

    Iterator begin() {
        return Iterator(this, 0);
    }
    
    Iterator end() {
        return Iterator(this, 5);
    }
    
    int size() { return m_size; }
    
private:
    int m_size;
    int *m_data;
};

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    List list(5);
    list.set(A, 5);
    
    List::Iterator eit = list.end();

    for (List::Iterator it = list.begin(); it != eit; ++it)
        cout<<*it;    
    return 0;
}
