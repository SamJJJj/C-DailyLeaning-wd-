#pragma once
#include "TextQuery.h"
#include "QueryResult.h"

class QueryBase
{
    friend class Query;
protected:
    using lineNo = TextQuery::lineNo;
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
    friend std::ostream &operator<<(std::ostream &os, const Query &query);

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const { return _q->eval(t); }
    std::string rep() const { return _q->rep(); }   
private:
    Query(std::shared_ptr<QueryBase> query)
    : _q(query)
    {}
    std::shared_ptr<QueryBase> _q;
};

class WordQuery
: public QueryBase
{
    friend class Query;
    WordQuery(const std::string &s)
    : _queryWord(s)
    {}
    QueryResult eval(const TextQuery &t) const
    {
        return t.query(_queryWord);
    }
    std::string rep() const { return _queryWord; }
    std::string _queryWord;
};

inline
Query::Query(const std::string &s): _q(new WordQuery(s)){ }

class NotQuery
:public QueryBase
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q)
    : _query(q)
    {}
    std::string rep() const { return "~(" + _query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const;
    Query _query;
};

inline
Query operator~(const Query &operand)
{
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

class BinaryQuery
: public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
    : _lhs(l)
    , _rhs(r)
    , _opSym(s)
    {}
    std::string rep() const { return "(" + _lhs.rep() + " " + _opSym + " " + _rhs.rep() + ")"; }
    Query _lhs, _rhs;
    std::string _opSym;
};

class AndQuery
: public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query & left, const Query & right)
    : BinaryQuery(left, right, "&")
    {}
    QueryResult eval(const TextQuery &) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery
: public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query & left, const Query & right)
    : BinaryQuery(left, right, "|")
    {}
    QueryResult eval(const TextQuery &) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}