#include "Query.h"

Query operator~(const Query& operand)
{
	return std::shared_ptr<Query_base>(new Not_query(operand));
}

Query operator|(const Query&lhs,const Query&rhs)
{
	return std::shared_ptr<Query_base>(new Or_query(lhs, rhs));
}

Query operator&(const Query&lhs, const Query&rhs)
{
	return std::shared_ptr<Query_base>(new And_query(lhs, rhs));
}

std::ostream& operator<<(std::ostream&os,const Query &query)
{
	return os << query.rep();
}

