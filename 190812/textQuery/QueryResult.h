#pragma once
#include <iostream>
#include <memory>
#include <set>
#include <vector>

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    using lineNo = std::vector<std::string>::size_type;
    typedef std::set<lineNo>::const_iterator line_it;
    QueryResult(std::string s,
                std::shared_ptr<std::set<lineNo>> p,
                std::shared_ptr<std::vector<std::string>> f)
    : _sought(s)
    , _lines(p)
    , _file(f)
    {}

    line_it begin() const { return _lines->begin(); }
	line_it end() const   { return _lines->end(); }
    std::shared_ptr<std::vector<std::string> > getFile() { return _file; }

private:
    std::string _sought;
    std::shared_ptr<std::set<lineNo>> _lines;
    std::shared_ptr<std::vector<std::string>> _file;
};