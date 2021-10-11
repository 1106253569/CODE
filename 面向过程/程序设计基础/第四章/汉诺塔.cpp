#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    void han(int n, char one, char two, char three);
    int m;
    cout << "please enter number:";
    cin >> m;
    han(m, 'A', 'B', 'C');
    return 0;
}

void han(int n,char one,char two,char three)
{
    void change(char x, char y);
    if(n==1)
        change(one, three);
        else
            {
                han(n - 1, one, three, two);
                change(one, three);
                han(n - 1, two, one, three);
            }
}

void change(char x,char y)
{
    cout << x << "to" << y << endl;
}