#pragma once
#include<iostream>
#include<map>
#include<set>
#include<vector>

class TextQuery
{
public:
    void readFile(const char *fileName);
    void query(const std::string & word);
private:
    std::map<std::string, std::set<int>> _word2Line;
    std::map<std::string, int> _dict;
    std::vector<std::string> _lines;
};