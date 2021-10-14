#include <iostream>
#include <vector>
#include <string>

void replace_string(std::string &s,const std::string&OldVal,const std::string &Newval)
{
    auto l = OldVal.size();
    if(!l)
        return ;
    auto iter = s.begin();
    while (iter <s.end())
    {
        auto iter1 = iter;
        auto iter2 = OldVal.begin();
        while (iter2!=OldVal.end()&&*iter1==*iter2)
        {
            iter1++;
            iter2++;
        }
        if(iter2==OldVal.end())
        {
            iter = s.erase(iter, iter1);
            if(Newval.size())
            {
                iter2 = Newval.end();
                do{
                    iter2--;
                    iter = s.insert(iter, *iter2);
                } while (iter2 > Newval.begin());                
            }
            iter += Newval.size();
        }
        else
            iter++;
    }
}
void replace_string1(std::string &s,const std::string&OldVal,const std::string &Newval)
{
    int p = 0;
    while ((p=s.find(OldVal,p))!=std::string::npos)
    {
        s.replace(p, OldVal.size(), Newval);
        p += Newval.size();
    }
}

int main()
{
    std::string s = "the thru tho!";
    replace_string(s, "thru", "through");
    std::cout << s << "\n";
    replace_string(s, "tho", "though");
    std::cout << s << "\n";
    replace_string(s, "through", "");
    std::cout << s << "\n";
    return 0;
}