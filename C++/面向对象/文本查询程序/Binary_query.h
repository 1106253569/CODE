#pragma once
#include "Query_base.h"
class Binary_query :
    public Query_base
{
protected:
	Binary_query(const Query&l,const Query&r,std::string s):
		lhs(l),rhs(r),opSym(s){}
	std::string rep()const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

class Or_query:
	public Binary_query
{
	friend Query operator|(const Query&, const Query&);
public:
	Or_query(const Query& left, const Query& right) :
		Binary_query(left, right,"|") {}
private:
	QueryResult eval(const TextQuery&) const;
};

class And_query:
	public Binary_query
{
	friend Query operator&(const Query&, const Query&);
public:
	And_query(const Query&left,const Query &right):
		Binary_query(left,right,"&") {}
private:
	QueryResult eval(const TextQuery&) const;
};


