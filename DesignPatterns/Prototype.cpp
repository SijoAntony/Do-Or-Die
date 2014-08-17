#include <iostream>
#include <map>

using namespace std;

class Color {
public:
    enum Type {Red, Blue, Green};    
  
    Color(int red, int blue, int green) 
        : m_red(red)
        , m_blue(blue)
        , m_green(green) {
    }
        
    Color(const Color& c) {
        if (this != &c) {
            this->m_red = c.m_red;
            this->m_blue = c.m_blue;
            this->m_green = c.m_green;
        }        
    }
    
    void show() {
        cout<<"RGB("<<m_red<<", "<<m_green<<", "<<m_blue<<")"<<endl;
    }
    
    void setRed(int r){ 
        m_red = r;
    }

    void setGreen(int g){ 
        m_green = g;
    }
    void setBlue(int b){ 
        m_blue = b;
    }
    
    virtual Color *clone() = 0;

protected:
    Color() {
    }
    
private:
    int m_red, m_blue, m_green;  
};

class Red : public Color {
public:
    Color *clone() {
        return new Red();
    }

    Red() : Color(255, 0, 0) {
    }
};

class Green : public Color {
public:
    Color *clone() {
        return new Green();
    }

    Green() : Color(0, 255, 0) {
    }
};

class Blue : public Color {
public:
    Color *clone() {
        return new Blue();
    }

    Blue() : Color(0, 0, 255) {
    }
};


class ColorManager {
public:
    
    ColorManager () {
        ColorManager::addProtoType(Color::Red, new Red());
        ColorManager::addProtoType(Color::Blue, new Blue());
        ColorManager::addProtoType(Color::Green, new Green());
    }
    
    Color* getColor(Color::Type type) {
        return m_colors[type]->clone();
    }
    
    void addProtoType(Color::Type type, Color* c) {
        m_colors[type] = c;
    }    
    
private:
    map<Color::Type, Color*> m_colors;
};
    
int main()
{
    ColorManager colorManager;
    
    Color *color = colorManager.getColor(Color::Red);
    color->setBlue(122);
    
    color->show();
    
    return 0;    
}
