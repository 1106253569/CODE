#pragma once
#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <stdexcept>
class StrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob() ;
	StrBlob(std::initializer_list<std::string>);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	StrBlobPtr(const StrBlob&a,size_t sz=0):wptr(a.data),curr(sz){ }
	std::string& deref()const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
};

inline bool neq(const StrBlobPtr& , const StrBlobPtr& );
#endif // ! MY_STRBLOB_H