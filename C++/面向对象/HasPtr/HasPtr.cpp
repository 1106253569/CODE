#include "HasPtr.h"

HasPtr HasPtr::operator=(const HasPtr&rhs)
{
	++* rhs.use;
	if (-- * use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr::~HasPtr()
{
	if (-- * use == 0)
	{
		delete ps;
		delete use;
	}
}

inline void swap(HasPtr& lhs, HasPtr&rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
