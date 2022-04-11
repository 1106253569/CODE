#include "My_file.h"

Folder::~Folder()
{
	remove_from_Msgs();
}

Folder& Folder::operator=(const Folder&f)
{
	remove_from_Msgs();
	msgs = f.msgs;
	add_to_Messages(f);
	// TODO: 在此处插入 return 语句
	return *this;
}

inline void Folder::add_to_Messages(const Folder& f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);
}

void Folder::remove_from_Msgs()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}