#include "StrBlob.h"
int main()
{
	std::string argv[] = { "C:\\Users\\solitary cloud\\Documents\\practise\\sun.txt" };
	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		std::cout << b2.size() << "\n";
	}
	std::cout << b1.size() << "\n";
	std::cout << b1.front() << " " << b1.back() << "\n";
	const StrBlob b3 = b1;
	std::cout << b3.front() << " " << b3.back() << "\n";
	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
		std::cout << it.deref() << "\n";
	return 0;
}