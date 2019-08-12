#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter a word to look for, or q to quit" << endl;
        string s;
        if(!(cin >> s) || s == "q")
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open("china_daily.txt");
    runQueries(ifs);
    ifs.close();
    return 0;
}