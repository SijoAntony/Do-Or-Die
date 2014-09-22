#include <map>

using namespace std;

const int POOL_SIZE = 32;

//Interface for memory manager
class MemoryManager {
public:
    virtual void *alloc(size_t size) = 0;
    virtual void dealloc(void *pointer) = 0;    
};

//Object pool based allocator which is also singleton
class ObjectPoolAllocator : public MemoryManager {
public:
    struct MemoryBlock {
        MemoryBlock *next;
    };
    
    ObjectPoolAllocator() {
        head = NULL;
    }
    
    ~ObjectPoolAllocator() {
        cleanup();
    }    

    void *alloc(size_t size) {  // virtual
        if (!head)
            expand(size);
        MemoryBlock *block = head;
        head = head->next;
        return block;
    }
    
    void dealloc(void *pointer) {  // virtual
        MemoryBlock *block = reinterpret_cast<MemoryBlock*>(pointer);
        block->next = head;
        head = block;
    }
    
    static MemoryManager *instance() {
        if (!m_instance)
            m_instance = new ObjectPoolAllocator();
        return m_instance;
    }

    
private:
    void expand(size_t alloSize) {
        size_t size = max(alloSize, sizeof(MemoryBlock));
        head = reinterpret_cast<MemoryBlock*>(new char[size]);
        MemoryBlock *newBlock = head;
    
        for (int i = 0; i < POOL_SIZE; i++) {
            newBlock->next = reinterpret_cast<MemoryBlock*>(new char[size]);
            newBlock = newBlock->next;
        }
        newBlock->next = NULL;
    }

    void cleanup() {
        while(head) {
            MemoryBlock *block = head;
            head = head->next;
            delete [] block; //allocated as char array!
        }
    }
    
private:
    MemoryBlock *head;
    static MemoryManager *m_instance;
};

MemoryManager* ObjectPoolAllocator::m_instance = NULL;

