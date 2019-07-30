#include "line.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl{
    class Point{
    public:
        Point(int ix, int iy)
        : _ix(ix)
        , _iy(iy)
        {
            cout << "Point(int, int)" << endl;
        }

        ~Point()
        {
            cout << "~Point()" << endl;
        }

        void printPoint() const
        {
            cout << "(" << _ix
                 << "," << _iy
                 << ")";
        }

    private:
        int _ix;
        int _iy;
    };
public:
    LineImpl(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "LineImpl(int, int, int, int)" << endl;
    }

    ~LineImpl()
    {
        cout << "~LineImpl()" << endl;
    }

    void printLine() const
    {
        _pt1.printPoint();
        cout << "--->" ;
        _pt2.printPoint();
        cout << endl;
    }

private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
    cout << "Line(int, int, int, int)" << endl;
}

Line::~Line()
{
    if(_pimpl)
        delete _pimpl;
    cout << "~Line()" << endl;
}

void Line::printLine() const
{
    _pimpl->printLine();
}