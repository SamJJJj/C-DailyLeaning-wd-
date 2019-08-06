#include "TextQuery.h"
#include <ctype.h>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::string;

void TextQuery::readFile(const char * fileName)
{
    int lineNo = 1;
    string line;
    ifstream ifs;
    ifs.open(fileName);
    while(std::getline(ifs, line))
    {
        _lines.push_back(line);
        for(auto & c: line)
        {
            if(c >= 'A' && c <= 'Z')
            {
                c += 32;
            }
            if(!isalpha(c) && c != '\'')
            {
                c = ' ';
            }
        }
        istringstream iss(line);
        string word;
        iss >> word;
        while (!iss.eof())
        {
            auto search = _dict.find(word);
            if (search != _dict.end())
            {
                ++_dict[word];
            }
            else
            {
                _dict.insert({word, 1});
            }
            _word2Line[word].insert(lineNo);
            iss >> word;
        }
        ++lineNo;
    }
    ifs.close();
}

void TextQuery::query(const string & word)
{
    auto search = _dict.find(word);
    if(search != _dict.end())
    {
        cout << word << " occurs " << _dict[word] << " times." << endl;
        for (auto it = _word2Line[word].begin(); it != _word2Line[word].end(); ++it)
        {
            cout << "(line " << *it << ")"
                 << _lines[*it - 1] << endl;
        }
    }
    else
    {
        cout << "this text don't have word: " << word << endl;
    }
}
