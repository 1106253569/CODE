#pragma once
#ifndef QUERY_BASE
#define QUERY_BASE
#include "TextQuery.h"
#include "Query.h"
class Query_base 
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base()=default;
private:
    virtual QueryResult eval(const TextQuery&)const = 0;
    virtual std::string rep()const = 0;

};
#endif // !QUERY_BASE

class Word_query:
    public Query_base
{
	friend class Query;
	Word_query(const std::string &s):query_word(s){}
	QueryResult eval(const TextQuery& t) const 
					{ return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word;
};

class Not_query:
	public Query_base
{
	friend Query operator~(const Query&);
public:
	Not_query(const Query &q):query(q){}
private:
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&)const;
	Query query;
};


