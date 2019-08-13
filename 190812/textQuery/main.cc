#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"
#include <iostream>
#include <fstream>

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    string sought1, sought2;
    cin >> sought1;
    cin >> sought2;
    Query andq = Query(sought1) & Query(sought2);
    cout << "\nExecuting query for: " << andq << endl;
    QueryResult results = andq.eval(tq);
    print(cout, results);
    results = Query(sought1).eval(tq);
    cout << "\nExecuted query: " << Query(sought1) << endl;
    // report matches
    print(cout, results);

    results = Query(sought2).eval(tq);
    cout << "\nExecuted query: " << Query(sought2) << endl;
    // report matches
    print(cout, results);
}

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open("china_daily.txt");
    runQueries(ifs);
    ifs.close();
    return 0;
}