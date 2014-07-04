/**
*
*   Calling Ctor and Dtor of a class explicitly.
*
**/

#include <iostream>

using namespace std;
 
class Test {
public:
    Test()  { cout << "Constructor is executed\n"; }
    Test(const Test& t)  { cout << "Copy Constructor is executed\n"; }    
    ~Test() { cout << "Destructor is executed\n";  }
    friend void fun(Test t);
};

void fun(Test t)
{
    Test();
    t.~Test();
}

int main()
{
    Test();     //Calls temporary Ctor-Dtor
    Test t;     //Calls t Ctor
    fun(t);     //Calls t.CopyCtor, temporary Ctor-Dtor, t.Dtor, t.Dtor
    return 0;   //t.Dtor
}
