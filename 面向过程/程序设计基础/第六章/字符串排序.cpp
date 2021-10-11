#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string *b[10];
    void sort(string * word1, string * word2);
    cout << "please enter word:"<<endl;
    for (int i = 0; i < 10;i++)
        cin >> *b[i];
    cout << "原序列为：" << endl;
    for (int i = 0; i < 10;i++)
        cout << *b[i] << endl;
    for (int i = 0; i < 9;i++)
        for (int j = i; j < 9;j++)
            sort(b[j], b[j + 1]);
    cout << "新序列为：" << endl;
    for (int i = 0; i < 10;i++)
        cout << *b[i] << endl;
    return 0;
}

void sort(string * word1, string * word2)
{
    if(* word1<* word2)
    {
        string temp = *word1;
        *word1 = *word2;
        *word2 = temp;
    }

}