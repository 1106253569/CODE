#include "Sales_data.h"
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cerr << "请输入文件名"
			<< "\n";
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "无法输入文件"
			<< "\n";
		return -1;
	}
	Sales_data total;
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
				print(cout, total) << "\n";
			total = trans;
		}
	}
	else
	{
		cerr << "没有数据"
			<< "\n";
	}
	return 0;
}

