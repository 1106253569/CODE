#include "StrBlob.h"
int main()
{
	const StrBlob b = { "hello","world","!" };
	for (auto it = b.begin(); neq(it, b.end()); it.incr())
		std::cout << it.deref() << "\n";
	return 0;
}