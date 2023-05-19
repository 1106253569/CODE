#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout,std::cin;
int main()
{
    void elimDups(std::vector<std::string> & word);
    char a[] = "C:\\Users\\solitary cloud\\Downloads\\hamlet.txt";
    std::ifstream in(a);
    if(!in)
    {
        cout << "Opening file is fail"
             << "\n";
        exit(1);
    }
    std::vector<std::string> words;
    std::string word;
    while(in>>word)
        words.push_back(word);
    elimDups(words);
    return 0;
}

inline void output_words(std::vector<std::string> &word)
{
    for (auto iter = word.begin(); iter != word.end();iter++)
    {
        cout << *iter << " ";
    }
    cout << "\n";
}
void elimDups(std::vector<std::string> &word)
{
    void output_words(std::vector<std::string> & word);
    output_words(word);
    std::sort(word.begin(), word.end());
    output_words(word);
    auto end_unique = unique(word.begin(), word.end(),
                             [](const std::string &s1, const std::string &s2)->bool
                             { return s1.size() < s2.size(); });
    output_words(word);
    word.erase(end_unique, word.end());
    output_words(word);
}
