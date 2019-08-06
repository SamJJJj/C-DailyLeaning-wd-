#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::istringstream;
using std::unordered_map;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::stringstream;
class Dictionary
{
public:
    Dictionary()
        : _dict()
    {
    }

    void dictRead(const string &fileName)
    {
        ifstream ifs(fileName);
        string line, word;
        while(std::getline(ifs, line))
        {
            istringstream iss(line);
            iss >> word;
            while(!iss.eof())
            {
                if(isalpha(word[0]))
                {
                    auto search = _dict.find(word);
                    if(search != _dict.end())
                    {
                       ++_dict[word];
                    }
                    else
                    {
                        _dict.insert({word, 1});
                    }
                }
                iss >> word;
            }
        }
        ifs.close();
    }

    void dictStore(const string &fileName)
    {
        ofstream ofs(fileName + "_unordered_map_dict");
        for(auto e : _dict)
        {
            ofs << e.first << "---"
                << e.second << endl;
        }
        ofs.close();
    }

private:
    unordered_map<string, int> _dict;
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