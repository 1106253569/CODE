#include <iostream> 
#include <string>
using namespace std;
int main()
{
    string words;
    while (getline(cin,words))
    {
        cout << words << endl;
    }
    for (auto &n:words)
        if (n != NULL)
            n = 'x';
    cout << words;
    return 0;
}
