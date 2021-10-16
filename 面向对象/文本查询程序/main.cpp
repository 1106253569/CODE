#include "TextQuery.h"
int main()
{
	void runQueries(std::ifstream & infile);
	std::ostream& print(std::ostream & os, const QueryResult & qr);
	std::ifstream in("sum.txt");
	runQueries(in);
	in.close();
	return 0;
}

