#pragma once
#ifndef My_File
#define My_Flie
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
class Folder;
class Message
{
	friend class Folder;
	friend void swap(Message& lhs, Message& rhs);
public:
	explicit Message(const std::string &str=""):contents(str){}
	Message(const Message&);
	Message& operator=(const Message&);
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder* f) { folders.insert(f); }
	~Message();
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};
class Folder
{
public:
	Folder() = default;
	Folder(const Folder& f) :msgs(f.msgs) { add_to_Messages(f); }
	Folder& operator=(const Folder&);
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.erase(m); }
	~Folder();
private:
	std::set<Message*>msgs;
	void add_to_Messages(const Folder&);
	void remove_from_Msgs();
};
#endif // !My_File



