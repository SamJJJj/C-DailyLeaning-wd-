#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char **argv)
{
    string test = "";
    regex reg1("<.*?>");
    test = regex_replace(test, reg1, "");
    cout << test << endl;
    return 0;
}