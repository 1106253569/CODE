#include "date.h"

date::date(std::string&ds)
{
	int get_month(std::string & ds, int& end_of_month);
	int get_day(std::string & ds, int month, int& p);
	int get_year(std::string & ds, int& p);
	int p;
	size_t q;
	if ((p = ds.find_first_of("0123456789")) == std::string::npos)
		throw std::invalid_argument("没有数字，非法日期");
	if (p > 0)
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("非法间隔符");
		p++;
		year = get_year(ds, p);
	}
	else
	{
		month = stoi(ds, &q);
		p = q;
		if (month < 1 || month>12)
			throw std::invalid_argument("不是合法月份名");
		if (ds[p++] != '/')
			throw std::invalid_argument("非法间隔符");
		day = get_day(ds, month,p);
		if(ds[p++]!='/')
			throw std::invalid_argument("非法间隔符");
		year = get_year(ds, p);
	}
}

std::ostream& operator<<(std::ostream&out, const date&d)
{
	out << d.y() << "年" << d.m() << "月" << d.d() << "日" << "\n";
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
		throw std::invalid_argument("不是合法月份名");
	if (ds[j] == ' ')
	{
		end_of_month = j + 1;
		return i + 1;
	}
	throw std::invalid_argument("不是合法月份名");
}
int get_day(std::string& ds, int month, int& p)
{
	size_t q;
	int day = stoi(ds.substr(p), &q);
	if (day<1 || day>days[month])
		throw std::invalid_argument("不是合法日期值");
	p += q;
	return day;
}
int get_year(std::string& ds, int& p)
{
	size_t q;
	int year = stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("非法结尾内容");
	return year;
}
