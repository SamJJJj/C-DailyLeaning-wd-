#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int x = 0, int y = 0)
    : _xPos(x)
    , _yPos(y)
    , _xRef(x)
    {}

    void print()
    {
        cout << "(" << _xPos
             << "," << _yPos
             << ")" << endl;
    }

private:
    const int _xPos;
    const int _yPos;
    static int length;
    int &_xRef;
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {}

private:
    Point _pt1;
    Point _pt2;
};

int Point::length = 0;

int main(int argc, char **argv)
{
    return 0;
}