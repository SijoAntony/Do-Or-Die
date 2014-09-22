#include <iostream>

using namespace std;

template<class Type, int capacity, int nStacks>
class Stack{
public:
    struct Item {
        Type data;
        int link;
    };
    
    explicit Stack() {
        //initialize link pointers for each item
        int i;
        for (i = 0; i < capacity - 1; i++)
            data[i].link = i + 1;
        //update the last link to terminator
        data[i].link = -1;
        
        for (i =0; i < nStacks; i++)
            stackPtrs[i] = -1;
        
        nextAvail = 0;    
    }
    ~Stack() {
    }
    
    void push(int stack, const Type& item) {
        //check if stack is valid
        valid(stack);

        //stack full!            
        if (full())
            throw string("Stack is full");
        
        Item &sItem = data[nextAvail];
        sItem.data = item;
        int next = sItem.link;
        sItem.link = stackPtrs[stack - 1];
        stackPtrs[stack - 1] = nextAvail;
        nextAvail =  next;
    }
    
    void pop(int stack) {
         //check if stack is valid
        valid(stack);
        
        //check if empty
        empty(stack);
        
        Item &sItem = data[stackPtrs[stack - 1]];
        Type item = sItem.data;
        int prev = sItem.link;
        sItem.link = nextAvail;
        nextAvail = stackPtrs[stack - 1];
        stackPtrs[stack - 1] = prev;
    }
    
    Type top(int stack) {
         //check if stack is valid
        valid(stack);
        
        //check if empty
        empty(stack);
        
        return data[stackPtrs[stack - 1]].data;
    }
    
    void print(int stack) {
        //check if stack is valid
        valid(stack);
            
        for (int i = stackPtrs[stack - 1]; i >= 0; i = data[i].link)
            cout<<data[i].data<<" ";
        cout<<endl;
    }
private:
    void valid(int stack) { 
        if (stack <= 0 || stack > nStacks) 
            throw string("Invalid stack pointer");
    }

    bool full() { return nextAvail < 0; }
    
    void empty(int stack) {
        if (stackPtrs[stack] < 0)
            throw  string("Stack is empty!");
    }

private:
    Item data[capacity];
    int stackPtrs[nStacks];   
    int nextAvail; 
};
int main()
{
    Stack<int, 10, 3> s;
    s.push(1, 5);
    s.push(2, 5);
    s.push(1, 6);
    s.push(2, 6);
    s.push(1, 7);
    s.push(1, 8);
    s.push(3, 8);
    s.push(3, 9);
    s.push(3, 10);
    s.push(3, 11);
    s.pop(1);
    s.pop(1);
    s.push(2, 13);
    s.push(3, 14);
    s.pop(2);
    s.pop(2);
    s.push(1, 12);
    s.push(1, 13);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    s.pop(2);
    s.push(3, 15);
    s.push(3, 16);
    s.print(1);
    s.print(2);
    s.print(3);
    return 0;    
}