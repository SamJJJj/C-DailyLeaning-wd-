#include <iostream>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

bool checkParenthese(string str)
{
    if(str.empty())
    {
        return false;
    }
    stack<char> s;
    for(auto & c : str)
    {
        if(c == '(')
            s.push(')');
        else if(c == '[')
            s.push(']');
        else if (c == '{')
            s.push('}');
        else if(s.empty() || s.top() != c)
            return false;
        else
            s.pop();
    }
    return s.empty();
}

int main(int argc, char **argv)
{
    string input;
    input = "";
    cout << checkParenthese(input) << endl;
    return 0;
}