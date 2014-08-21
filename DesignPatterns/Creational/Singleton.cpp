#include <iostream>
#include <mutex> //works only in C++11

using namespace std;

class Printer {
public:
    static Printer* getInstance() {
        if (!m_instance) {
            //Handle thread safetly
            m_locker.lock();
            if (!m_instance)
                m_instance = new Printer();
            m_locker.unlock();
        }
        
        return m_instance;
    }
    
    static void destroy() {
        delete m_instance;    
    }
    
    void printToConsole(string data) {
        cout<<data<<endl;
    }
    
    void printToFile(string data) {
    }

private:
    Printer() {
    }

    Printer(const Printer& other) {
        //avoid self assignment
        if (this != &other) {
        }    
    }
    static mutex m_locker;
    static Printer* m_instance;
};

Printer* Printer::m_instance = NULL;


int main()
{
    Printer* printer = Printer::getInstance(); // Since new Printer(); fails
    printer->printToConsole("Hello there!");
    return 0;    
}
