#include <iostream>
#include <math.h>

std::string intToRoman(int num)
{
    std::string New;
    int n = num, len = 0;
    while (n != 0)
    {
        n = n / 10;
        ++len;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        int x = num / pow(10, i);
        int y = x % 5;
        if (x == 0)
            continue;
        if (i == 3)
        {
            for (int j = 0; j < y; j++)
                New = New + 'M';
            num -= x * pow(10, i);
            continue;
        }
        else if (i == 2)
        {
            if (y == 4)
            {
                New = New + 'C';
                if (x >= 5)
                    New = New + 'M';
                else
                    New = New + 'D';
                num -= x * pow(10, i);
                continue;
            }
            else
            {
                if (x >= 5)
                    New = New + 'D';
                for (int j = 0; j < y; j++)
                    New = New + 'C';
                num -= x * pow(10, i);
                continue;
            }
        }
        else if (i == 1)
        {
            if (y == 4)
            {
                New = New + 'X';
                if (x >= 5)
                    New = New + 'C';
                else
                    New = New + 'L';
                num -= x * pow(10, i);
                continue;
            }
            else
            {
                if (x >= 5)
                    New = New + 'L';
                for (int j = 0; j < y; j++)
                    New = New + 'X';
                num -= x * pow(10, i);
                continue;
            }
        }
        else if (i == 0)
        {
            if (y == 4)
            {
                New = New + 'I';
                if (x >= 5)
                    New = New + 'X';
                else
                    New = New + 'V';
                num -= x * pow(10, i);
                break;
            }
            else
            {
                if (x >= 5)
                    New = New + 'V';
                for (int j = 0; j < y; j++)
                    New = New + 'I';
                num -= x * pow(10, i);
                break;
            }
        }
    }
    return New;
}

int main()
{
    int n = 0;
    std::cout << "please enter number:";
    std::cin >> n;
    std::cout << intToRoman(n);
}