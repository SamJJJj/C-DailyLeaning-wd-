#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <string>
#include <fstream>

using std::ifstream;
using std::istringstream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

TextQuery::TextQuery(ifstream & is)
:_file(new vector<string>)
{
    string text;
    while(std::getline(is, text))
    {
        _file->push_back(text);
        int n = _file->size() - 1;
        istringstream iss(text);
        string word;
        while(iss >> word)
        {
            for(auto & e : word)
            {
                if(isalpha(e) && (e >= 'A' && e <= 'Z'))
                    e += 32;
            }
            auto &lines = wm[word];
            if(!lines)
            {
                lines.reset(new set<lineNo>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<lineNo>> nodata(new set<lineNo>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
    {
        return QueryResult(sought, nodata, _file);
    }
    else
    {
        return QueryResult(sought, loc->second, _file);
    }
}