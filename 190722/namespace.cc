#include <iostream>

using std::cout;
using std::endl;

int number = 1;
namespace wd
{
int number=10;
int dispaly(int number)
{
    cout << "number = " << number << endl;
    cout << "wd::number = " << wd::number << endl;
    cout << "全局 number = " << ::number << endl;
}
}

int main(int argc, char **argv)
{
    int number = 20;
    wd::dispaly(number);
    return 0;
}