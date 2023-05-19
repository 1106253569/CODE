#include <iostream>
using namespace std;
int main()
{
    char v[50];
    int i, a = 0, b = 0, c = 0, d = 0;
    cout << "please enter word or number:";
    cin >> v;
    char *f = v;
    for (i = 0; *(f + i) != '\0'; i++)
    {
        if (48 <= (int)*(f + 1) && (int)*(f + i) <= 57)
            a += 1;
        else if (65 <= (int)*(f + i) && (int)*(f + i) <= 90)
            b += 1;
        else if (97 <= (int)*(f + i) && (int)*(f + i) <= 122)
            c += 1;
    }
    d = i - a - b - c;
    cout << "数字个数为: " << a << endl;
    cout << "大写个数为：" << b << endl;
    cout << "小写个数为：" << c << endl;
    cout << "符号个数为：" << d << endl;
    return 0;
}
