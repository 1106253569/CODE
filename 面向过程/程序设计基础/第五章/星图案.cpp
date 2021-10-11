#include <iostream>
#include <string>
using namespace std;
int main()
{
    string string1 = "*****";
    char str[] = "*****";
    int i,x;
    cout << "please enter i:";
    cin >> i;
    cout << "用string方法输出：" << endl;
    for ( x = 0; x < i;x++)
    {
        for (int y = 0; y < x;y++)
            cout << " ";
        cout << string1 << endl;
    }
    cout << "用字符数组方法输出："<<endl;
    for ( x = 0; x < i;x++)
    {
        for (int y = 0; y < x;y++)
            cout << " ";
        cout << str << endl;
    }
    return 0;
}