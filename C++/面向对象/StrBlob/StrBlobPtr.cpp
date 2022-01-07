#include "StrBlob.h"
inline std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

inline std::string& StrBlobPtr::deref()const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string&);
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string&) ;
	--curr;
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}

bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

inline bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	bool eq(const StrBlobPtr & lhs, const StrBlobPtr & rhs);
	return !eq(lhs, rhs);
}