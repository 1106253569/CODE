#include "date.h"
int main(std::string x)
{
	std::ostream& operator<<(std::ostream & out, const date & d);
	std::cout << "please enter string or 'q' to quit: ";
	while (std::cin>>x)
	{
		date d1(x);
		operator<<(std::cout, d1);
		std::cout << "please enter string or 'q' to quit: ";
	}
	return 0;
}
