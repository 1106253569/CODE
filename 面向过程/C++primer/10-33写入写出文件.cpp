#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
int main()
{
    std::ofstream examine(std::string file_name);
    std::string argc[] = {"C:\\Users\\solitary cloud\\Documents\\practise\\sun.txt",
                   "C:\\Users\\solitary cloud\\Documents\\practise\\out_file1.txt", 
                   "C:\\Users\\solitary cloud\\Documents\\practise\\out_file2.txt"};
    int argv = 4;
    if(argv!=4)
    {
        std::cout << "用法：execise.exe in_file"
                     "out_file1 out_file2"
                  << "\n";
        return -1;
    }
    std::ifstream in(argc[0]);
    if(!in)
    {
        throw "opening is fail!";
        exit(-1);
    }
    std::ofstream out1, out2;
    out1 = examine(argc[1]);
    out2 = examine(argc[2]);
    std::istream_iterator<std::string> in_iter(in);
    std::istream_iterator<std::string> eof;
    std::ostream_iterator<std::string> out_iter1(out1," ");
    std::ostream_iterator<std::string> out_iter2(out2," ");
    while(in_iter!=eof)
    {
        if((*in_iter).size()<=5)
            *out_iter1++ = *in_iter;
            else
                *out_iter2++ = *in_iter;
            *in_iter++;
    }
    return 0;
}

std::ofstream examine( std::string file_name)
{
    std::ofstream out(file_name);
    if(!out)
    {
        throw "opening is fail!";
        exit(-1);
    }
    return out;
}