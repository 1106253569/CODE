#include "Sales_data.h"
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cerr << "��������롢����ļ���" << "\n";
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "�޷��������ļ�" << "\n";
		return -1;
	}
	ofstream out(argv[2]);
	if (!out)
	{
		cerr << "�޷�������ļ�" << "\n";
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
			{
				print(out, total) << "\n";
				total = trans;
			}
		}
		print(out, total) << "\n";
	}
	else
	{
		cerr << "û������" << "\n";
	}
	return 0;
}