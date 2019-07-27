#include <iostream>

using std::cout;
using std::endl;

int mul(int x, int y = 1)
{
    return x * y;
}

int mul(int x, int y, int z)
{
    return x * y * z;
}

int main(int argc, char **argv)
{
    int a = 2, b = 3, c = 4;
    cout << "a = " << mul(a) << endl;
    cout << "a * b = " << mul(a, b) << endl;
    cout << "a * b * c = " << mul(a, b, c) << endl;
    return 0;
}