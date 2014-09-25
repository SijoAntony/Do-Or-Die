#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T, int numQueues, int size>
class Queue {
public:
    struct Item {
        T value;
        int next;
    };
    struct QueuePtr {
        int front;
        int rear;
    };
    
    Queue() {
        for (int i = 0; i < size - 1; i++)
            items[i].next = i + 1;
        items[size - 1].next = -1;
        
        for (int i = 0; i < numQueues; i++) {
            queuePtrs[i].front = -1;
            queuePtrs[i].rear = -1;
        }
        nextAvail = 0;
    }
    
    void enqueue(int queue, T data) {
        validate(queue);
        full();
            
        Item& item = items[nextAvail];
        item.value = data;
        int next = item.next;
        
        items[queuePtrs[queue - 1].rear].next = nextAvail;
        queuePtrs[queue - 1].rear = nextAvail;
        
        if (queuePtrs[queue - 1].front == -1)
            queuePtrs[queue - 1].front = queuePtrs[queue - 1].rear;
            
        nextAvail =  next;
    }
    
    T dequeue(int queue) {
        validate(queue);
        empty(queue);

        int current = queuePtrs[queue - 1].front;
        Item& item = items[current];

        if (queuePtrs[queue - 1].front == queuePtrs[queue - 1].rear)
            queuePtrs[queue - 1].front = queuePtrs[queue - 1].rear = -1;
        else
            queuePtrs[queue - 1].front = item.next;
        item.next = nextAvail;
        nextAvail = current;
        return item.value;
    }
    
    void print(int queue) {
        validate(queue);
        cout<<"Queue "<<queue<<": ";
        for (int i = queuePtrs[queue - 1].front; i >= 0; i = items[i].next) {
            cout<<items[i].value<<" ";
            if (i == queuePtrs[queue - 1].rear)
                break;
        }
        
        cout<<endl;
    }

private:
    void validate(int queue) {
        if (queue < 0 && queue > numQueues)
            throw string("Invalid queue");
    }
    
    bool full() {
        if (nextAvail == -1)
            throw string("Queue is full");
        return false;    
    }
    
    bool empty(int queue) {
        if (queuePtrs[queue - 1].front == -1)
            throw string("Queue is empty");
        return false;
    }

private:
    Item items[size];
    QueuePtr queuePtrs[numQueues];
    int nextAvail;
};

int main()
{
    Queue<int, 3, 10> q;
    
     // Let us put some items in queue number 3
    q.enqueue(3, 15);
    q.enqueue(3, 45);
 
    // Let us put some items in queue number 2
    q.enqueue(2, 17);
    q.enqueue(2, 49);
    q.enqueue(2, 39);
 
    // Let us put some items in queue number 1
    q.enqueue(1, 11);
    q.enqueue(1, 9);
    q.enqueue(1, 7);

    q.print(1);    
    q.print(2);
    q.print(3);
    return 0;    
}