#include "date.h"

date::date(std::string&ds)
{
	int get_month(std::string & ds, int& end_of_month);
	int get_day(std::string & ds, int month, int& p);
	int get_year(std::string & ds, int& p);
	int p;
	size_t q;
	if ((p = ds.find_first_of("0123456789")) == std::string::npos)
		throw std::invalid_argument("û�����֣��Ƿ�����");
	if (p > 0)
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("�Ƿ������");
		p++;
		year = get_year(ds, p);
	}
	else
	{
		month = stoi(ds, &q);
		p = q;
		if (month < 1 || month>12)
			throw std::invalid_argument("���ǺϷ��·���");
		if (ds[p++] != '/')
			throw std::invalid_argument("�Ƿ������");
		day = get_day(ds, month,p);
		if(ds[p++]!='/')
			throw std::invalid_argument("�Ƿ������");
		year = get_year(ds, p);
	}
}

std::ostream& operator<<(std::ostream&out, const date&d)
{
	out << d.y() << "��" << d.m() << "��" << d.d() << "��" << "\n";
	return out;
}

int get_month(std::string& ds, int& end_of_month)
{
	int i(0), j(0);
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < month_abbr[i].size(); j++)
		{
			if (ds[j] != month_abbr[i][j])
				break;
		}
		if (j == month_abbr[j].size())
			break;
	}
	if (i == 12)
		throw std::invalid_argument("���ǺϷ��·���");
	if (ds[j] == ' ')
	{
		end_of_month = j + 1;
		return i + 1;
	}
	throw std::invalid_argument("���ǺϷ��·���");
}
int get_day(std::string& ds, int month, int& p)
{
	size_t q;
	int day = stoi(ds.substr(p), &q);
	if (day<1 || day>days[month])
		throw std::invalid_argument("���ǺϷ�����ֵ");
	p += q;
	return day;
}
int get_year(std::string& ds, int& p)
{
	size_t q;
	int year = stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("�Ƿ���β����");
	return year;
}
