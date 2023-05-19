#include <iostream>
using namespace std;

void qipao(double array[], int n)
{
    double temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    double a[8];
    cout << "enter the originl array:" << endl;
    for (int i = 0; i < 8; i++)
        cin >> a[i];
    cout << "the sorted array:" << endl;
    qipao(a, 8);
    for (int i = 0; i < 8; i++)
        cout << a[i] << ' ';
}