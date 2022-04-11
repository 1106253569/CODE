#pragma once
#ifndef Has_Ptr
#define Has_Ptr
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr() = default;
	//接受一个（可选的）string参数
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0),use(new std::size_t(1)) {};
	HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i), use(p.use) { ++* use; }
	HasPtr operator=(const HasPtr&);
	~HasPtr();
private:
	std::string* ps;
	int i;
	std::size_t* use;
};
#endif // !Has_Ptr



