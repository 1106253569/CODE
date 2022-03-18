#include "TextQuery.h"
int main()
{
	void runQueries(std::ifstream & infile);
	std::ostream& print(std::ostream & os, const QueryResult & qr);
	std::string a = "D:\\CODE\\Document\\sun.txt";
	std::ifstream in(a);
	runQueries(in);
	in.close();
	return 0;
}

