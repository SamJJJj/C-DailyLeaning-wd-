#include "TextQuery.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string word;
    cout << "input a word to query:" << endl;
    cin >> word;
    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.query(word);
    return 0;
}