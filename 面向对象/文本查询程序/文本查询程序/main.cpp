#include "TextQuery.h"
int main()
{
	
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
