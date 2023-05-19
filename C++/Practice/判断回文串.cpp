#include <iostream>
using namespace std;
int main()
{
    char words[100],real_words[100],j=0;
    int fac(char *f);
    std::cin >> words;
    for (int i = 0; words[i] != NULL;i++)
    {
        if(0<words[i]&&words[i]<9||'a'<words[i]&&words[i]<'z'||'A'<words[i]&&words[i]<'Z')
            {
                real_words[j] = words[i];
                j += 1;
            }
    }
    int n = fac(real_words),v=0;
    for (int i = 0; i < n / 2;i++)
    {
        if(real_words[i]!=real_words[n-1-i])
            v += 1;
    }
    if(v)
        std::cout << "false";
        else
            std::cout << "turn";
    return 0;
}

int fac(char *f)
{
    int a = 0;
    while (*(f+a)!='\0')
    {
        a += 1;
    }
     return (a);
}