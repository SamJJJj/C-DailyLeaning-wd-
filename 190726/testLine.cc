#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
void printLine()
{
    cout << __LINE__ << endl;
}

int main(int argc, char **argv)
{
    string s;
    cout << s << endl;
    printLine();
    printLine();
    return 0;
}