#include <iostream>
#define Chunk_size 80
using date = std::string;
struct Chunk
{
    date ch;
    Chunk *next;
}; 
struct List_string
{
    Chunk *head;
    Chunk *tail;
    int curlen;  //当前长度
};


