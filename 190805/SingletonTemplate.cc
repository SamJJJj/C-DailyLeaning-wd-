#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Singleton
{
public:
    template <typename... Args>
    static T * getInstance(Args... args)
    {
        if(nullptr == _pInstance)
        {
            ::atexit(destroy);
            _pInstance = new T(args...);
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
    }

private:
    Singleton();
    ~Singleton();
    static T *_pInstance;
};

class Point
{
public:
    Point(int x = 0, int y = 0)
    : _ix(x)
    , _iy(y)
    {}

    void display() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

class Computer
{
public:
    Computer(const char * brand, int price)
    :_price(price)
    ,_brand(new char[strlen(brand) + 1]())
    {
        strcpy(_brand, brand);
    }

    ~Computer()
    {
        if(_brand)
            delete[] _brand;
    }

    void display() const
    {
        cout << "brand:" << _brand << endl
             << "price:" << _price << endl;
    }

private:
    int _price;
    char *_brand;
};

// Singleton<Point> *Singleton<Point>::_pInstance = nullptr;
template <class T>
T *Singleton<T>::_pInstance = nullptr;

int main(int argc, char **argv)
{
    Point *p1 = Singleton<Point>::getInstance(1, 2);
    Point *p2 = Singleton<Point>::getInstance(3, 4);
    p2->display();
    Computer *p3 = Singleton<Computer>::getInstance("lenove", 8888);
    Computer *p4 = Singleton<Computer>::getInstance("xiaomi", 6666);
    p4->display();
    return 0;
}