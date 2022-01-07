#pragma once
#ifndef DATE_H_INCLOUD
#define DATE_H_INCLOUD
#endif // !DATE_H_INCLOUD
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
class date
{
	friend std::ostream& operator<<(std::ostream&, const date&);
public:
	date() = default;
	date(std::string&);
	unsigned y() const { return year; }
	unsigned m() const { return month; }
	unsigned d() const { return day; }
private:
	unsigned year;
	unsigned month;
	unsigned day;
};
const std::string month_name[] = { "January","February","March",
	"April","May","June","July","August","September","October",
	"November","December" };
const std::string month_abbr[] = { "Jan","Feb","Mar","Apr","May",
	"Jun","Jul","Aug","Sept","Oct","Nov","Dec" };
const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

