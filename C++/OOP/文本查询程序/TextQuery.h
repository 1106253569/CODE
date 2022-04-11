#pragma once
#ifndef TEXT_QUERY
#define TEXT_QUERY
#include <iostream>
#include <vector>
#include <istream>
#include <map>
#include <set>
#include <string>
#include <sstream> 
#include <fstream> 
#include <memory>
class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult()=default;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):
		sought(s),lines(p),file(f){}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>>file;
};

class TextQuery
{
public:
	TextQuery() = default;
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	~TextQuery();
	QueryResult query(const std::string&) const;	
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
};
#endif // !TEXT_QUERY