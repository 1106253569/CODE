#include "Binary_query.h"

QueryResult Or_query::eval(const TextQuery&text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult And_query::eval(const TextQuery&text) const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}