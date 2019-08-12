#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
class QueryResult;
class TextQuery
{
public:
    using lineNo = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> _file;
    std::map<std::string,
             std::shared_ptr<std::set<lineNo>>>
        wm;
};