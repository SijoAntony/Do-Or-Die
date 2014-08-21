#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle() {
public:
    Circle(int x, int y, int radius)
        : m_x(x)
        , m_y(y)
        , m_radius(radius){
        
    }

    void draw() {
        cout<<"Circle( "<<m_x<<", "<<m_y<<")"<<endl;
    }
    
private:
    int m_x, m_y, m_radius;    
}

class ShapeImpl {
public:
    virtual void draw() = 0;
};

class GDIDraw

int main()
{
    return 0;
}