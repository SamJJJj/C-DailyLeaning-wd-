#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

typedef struct item
{
    item(const string & word = "", int cnt = 1)
    :_word(word)
    , _cnt(cnt)
    {}

    string _word;
    int _cnt;
} Item_t;

class Dictionary
{
public:
    Dictionary()
    :_items()
    {
        _items.reserve(10000);
    }
    void dictRead(const string & fileName)
    {
        Item_t item;
        ifstream ifs;
        size_t idx;
        ifs.open(fileName);
        string line, word;
        while(std::getline(ifs, line))
        {
            istringstream iss(line);
            iss >> word;
            while (!iss.eof())
            {
                if(isalpha(word[0]))
                {
                    for (idx = 0; idx != _items.size(); ++idx)
                    {
                        if(_items[idx]._word == word)
                        {
                            ++_items[idx]._cnt;
                            break;
                        }
                    }
                    if(idx == _items.size())
                    {
                        item._word = word;
                        _items.push_back(item);
                    }
                }
                iss >> word;
            }
        }
        ifs.close();
    }

    void dictStore(const string & fileName)
    {
        ofstream ofs;
        ofs.open(fileName + "_dict");
        for(auto & e : _items)
        {
            ofs << e._word << "---"
                << e._cnt << endl;
        }
        ofs.close();
    }

private:
    vector<Item_t> _items;
};

int main(int argc, char **argv)
{
    string fileName;
    cout << "Please input a file's absolute path:" << endl;
    Dictionary dict;
    cin >> fileName;
    cout << fileName << endl;
    dict.dictRead(fileName);
    cout << "read over" << endl;
    dict.dictStore(fileName);

    return 0;
}