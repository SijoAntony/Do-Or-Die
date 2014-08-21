#include <iostream>

using namespace std;

class Rectangle {
public:
    virtual void draw() = 0;

};

class LegacyRectangle {
public:
    LegacyRectangle(int x1, int y1, int x2, int y2) 
        : m_x1(x1)
        , m_x2(x2)
        , m_y1(y1)
        , m_y2(y2){
        
    }
    
    void legacyDraw() {
        cout<<"LegacyRectangle("<<m_x1<<","<<m_y1<<","<<m_x2<<","<<m_y2<<")"<<endl;
    }
    
private:
    int m_x1, m_x2, m_y1, m_y2;
};

class RectangleAdapter: public Rectangle, public LegacyRectangle {
public:
    RectangleAdapter(int x, int y, int width, int height)
        : LegacyRectangle(x, y, x + width, y + width) {
    }
    
    virtual void draw() {
        legacyDraw();
    }
};


int main()
{
    Rectangle *rect = new RectangleAdapter(10, 10, 200, 200);
    rect->draw();
    return 0;
}
