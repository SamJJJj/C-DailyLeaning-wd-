#include <iostream>

using std::cout;
using std::endl;

class Circle{
public:
    Circle()
    : _r(0)
    {
        cout << "Circle()" << endl;
    }

    Circle(double r)
    : _r(r)
    {
        cout << "Circle(double)" << endl;
    }

    double getArea()
    {
        return 3.14 * _r * _r;
    }

    double getPerimeter()
    {
        return 2 * _r * 3.14;
    }

    void show()
    {
        cout << "radius = " << _r << endl
             << "area = " << getArea() << endl
             << "perimeter = " << getPerimeter() << endl;
    }

private:
    double _r;
};

class Cylinder
: public Circle
{
public:
    Cylinder(double r, double h)
    : Circle(r)
    , _h(h)
    {
        cout << "Cylinder(double, double)" << endl;
    }

    double getVolume()
    {
        return _h * getArea();
    }

    void showVolume()
    {
        cout << "Volume = " << getVolume() <<endl;
    }

private:
    double _h;
};

int main(int argc, char **argv)
{
    Cylinder c(2, 2);
    c.show();
    c.showVolume();
    return 0;
}