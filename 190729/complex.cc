#include <iostream>

using std::cout;
using std::endl;

class Complex 
{
public:
    Complex(int real = 0, int image = 0)
    : _real(real)
    , _image(image)
    {}

    void dispaly() const
    {
        cout << _real << " + "
             << _image << "i" 
             << endl;
    }

    friend Complex operator+(const Complex &, const Complex &);
private:
    double _real;
    double _image;
};

Complex operator+ (const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs._real + rhs._real, lhs._image + rhs._image);
}

int main(int argc, char **argv)
{
    Complex c1(1, 2), c2(2, 3);
    Complex c3 = c1 + c2;
    c3.dispaly();

    return 0;
}