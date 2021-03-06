#include "Query.h"
#include "QueryResult.h"
#include <algorithm>
using namespace std;

ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

QueryResult OrQuery::eval(const TextQuery & text) const
{
    auto right = _rhs.eval(text), left = _lhs.eval(text);
    auto retLines = make_shared<set<lineNo>>(left.begin(), left.end());
    retLines->insert(right.begin(), right.end());
    return QueryResult(rep(), retLines, left.getFile());
}

QueryResult AndQuery::eval(const TextQuery & text) const
{
    auto right = _rhs.eval(text), left = _lhs.eval(text);
    auto retLines = make_shared<set<lineNo>>();
    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*retLines, retLines->begin()));
    return QueryResult(rep(), retLines, left.getFile());
}

QueryResult NotQuery::eval(const TextQuery & text) const
{
    auto result = _query.eval(text);
    shared_ptr<set<lineNo> > ret_lines(new set<lineNo>);

	QueryResult::line_it beg = result.begin(), end = result.end();

	vector<string>::size_type sz = result.getFile()->size();
    for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n) 
			ret_lines->insert(n);  
		else if (beg != end) 
			++beg; 
	}
	return QueryResult(rep(), ret_lines, result.getFile());
}