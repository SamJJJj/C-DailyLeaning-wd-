#include <iostream>

using std::cout;
using std::endl;


int num[5] = {1, 2, 3, 4, 5};

void swap(int &x, int &y)
{
    int temp = y;
    y = x;
    x = temp;
}

int & getNum(int idx)
{
    return num[idx];
}

int main(int argc, char **argv)
{
    int a = 2, b = 3, idx = 0;
    cout << "before swap" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "after swap" << endl;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "num[0] = " << getNum(0) << endl;
    getNum(0) = 10;
    cout << "num[0] = " << num[0] << endl;
}