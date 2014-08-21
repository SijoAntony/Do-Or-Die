#include <iostream>
#include <map>

using namespace std;

class Control {
public:
    enum Type {Button = 0, Text, Label};
    virtual void draw() = 0;
};

class Button : public Control {
public:
    void draw() { cout<<"Button"<<endl;}
    static Control* create() {return new Button();}
    
};

class Text : public Control {
public:
    void draw() { cout<<"Text"<<endl;}
    static Control* create() {return new Text();}    
};

class Label : public Control {
public:
    void draw() { cout<<"Label"<<endl;}
    static Control* create() {return new Label();}
    
};

class ControlFactory {
public:
    typedef Control* (*Instantiator)();
    ControlFactory() {
        _register(Control::Button, Button::create);    
        _register(Control::Text, Text::create);    
        _register(Control::Label, Label::create);    
    }    
    
    Control* create(Control::Type type) {
        return controls[type]();
    }
    
    void _register(Control::Type type, Instantiator intor) {
        controls[type] = intor;
    }
private:
    map<Control::Type, Instantiator> controls;
};


int main()
{
    ControlFactory cf;
    Control* btn = cf.create(Control::Button);
    Control* txt = cf.create(Control::Text);    
    Control* lbl = cf.create(Control::Label);
    
    btn->draw();
    txt->draw();
    lbl->draw();
            
    return 0;
}
