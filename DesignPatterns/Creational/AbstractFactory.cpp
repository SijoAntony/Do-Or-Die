#include <iostream>

using namespace std;

class Button {
public:
    virtual void draw() = 0;    
};

class WinButton : public Button {
public:
    void draw() {cout<<"Win - Button"<<endl;}    
};

class LinuxButton : public Button  {
public:
    void draw() {cout<<"Lin - Button"<<endl;}    
    
};

class AbstractFactory {
public:
    enum OSType { Win = 0, Linux };
    virtual Button* createButton() = 0;
};

class WinFactory : public AbstractFactory {
public:
    Button* createButton() { return new WinButton() ; }
};

class LinuxFactory : public AbstractFactory {
public:
    Button* createButton() { return new LinuxButton() ; }
};

class ControlFactory {
public:
    AbstractFactory* createFactory(AbstractFactory::OSType type) {
        switch(type) {
        case AbstractFactory::Win:
            return new WinFactory();
             
        case AbstractFactory::Linux:
            return new LinuxFactory();
        }
    }
};

int main()
{
    ControlFactory cf;
    AbstractFactory *f = cf.createFactory(AbstractFactory::Win);
    Button* btn = f->createButton();
    btn->draw();    
    return 0;    
}
