#include <iostream>
#include <string>

using namespace std;

class Wrapper {
public:
    class Child {
    public:
        Child(string _name)
            : name(_name) {
        }
        string getName() {
            return name;
        }
    private:
        string name;
    };
    
    Wrapper(string name) 
        : kid (name) {
    }
    string name() {
        return kid.getName();    
    }
private:
    Child kid;
};


int main()
{
    Wrapper wrapper("John");
    cout<<wrapper.name()<<endl;
    return 0;    
}
