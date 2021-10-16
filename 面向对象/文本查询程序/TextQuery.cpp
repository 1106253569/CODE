#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is,text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line>>word)
		{
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string&sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << "\n";
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	std::string make_plural(size_t ctr, const std::string & word, const std::string & ending);
	os << qr.sought << "occurs" << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << "\n";
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << "\n";
	return os;
}
std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

