#include <iostream>
#define Max_size 255
struct Sq_string
{
    char ch[Max_size+1];
    int length;
}; 

int Index_BF(Sq_string S,Sq_string T,int pos)
{
    int i = pos;
    int j = 1;
    while (i<=S.length&&j<=T.length)
    {
        if(S.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
        if(j>=T.length)
            return i - T.length;
            else
                return 0;
    }
}

void Get_next(Sq_string T,int next[])
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i<T.length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j; 
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(Sq_string S,Sq_string T,int pos)
{
    int i = pos;
    int j = 1;
    int next[Max_size];
    while(i<S.length&&j<T.length)
    {
        if(j==0||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[i];
    }
    if(j>T.length)
        return i - T.length;
        else
            return 0;
}