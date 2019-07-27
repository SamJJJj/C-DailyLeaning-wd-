#include <string.h>
#include <iostream>

using std::cout;
using std::endl;


class Computer
{
public:
    Computer(const char *brand, float price)//构造函数
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand, brand);
        cout << "Computer(const char *brand, float price)" << endl;
    }

    Computer(const Computer & pc)       //拷贝构造函数
    {
        cout << "Computer(const Computer & pc)" << endl;
        _brand = new char[strlen(pc._brand) + 1]();
        strcpy(_brand, pc._brand);
        _price = pc._price;
    }

    void print()
    {
        cout << "brand: " << _brand << endl
             << "price: " << _price << endl;
    }

    Computer & operator=(const Computer & rhs)
    {
        if(this != &rhs)
        {
            delete [] _brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand, rhs._brand);
            _price = rhs._price;
        }
        return *this;
    }

    ~Computer()//析构函数
    {
        delete [] _brand;
        _brand = NULL;
        cout << "~Computer" << endl;
    }

private:
    char * _brand;
    float _price;
};

int main(void)
{
    Computer pc("swift", 7888);
    pc.print();
    return 0;
}