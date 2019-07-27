#include <iostream>
#define MUL(x, y) x * y

using std::cout;
using std::endl;

inline int multiply(int x, int y)
{
    return x * y;
}

int main(int argc, char **argv)
{
    int a = 2, b = 3;
    cout << "a * b = " << multiply(a, b) << endl;
    cout << "(a + b) * b = " << multiply(a + b, b) << endl; //若是define 就不是15
    cout << "(a + b) * b = " << MUL(a + b, b) << endl;      //11
}