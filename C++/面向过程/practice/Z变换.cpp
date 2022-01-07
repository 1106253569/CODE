#include <iostream>
int main()
{
    std::string convert(std::string s, int numRows);
    std::string a;
    int n;
    std::cin >> a >> n;
    std::cout << convert(a, n);
    return 0;
}
std::string convert(std::string s, int numRows) 
{
    int length = s.length();
    if(numRows==1)
        return s;
    if(numRows>=length)
        return s;
    int segment = 0, i = 1;
    int k = numRows - 1;
    char a[numRows][1000];
    for (int n = 0; n < numRows; n++)
        for(int m=0;m<1000;m++)
        {
            a[n][m]={'\0'};
        }
    std::string New;
    while (i <= length)
    {
        int j = (i - 1) % (2 * k);
        segment = i / (2 * k);
        if (j < k)
        {
            a[j][segment * k] = s[i - 1];
            ++i;
        }
        else
            for(int L=0;L<k;L++)
            {
                a[j-L][segment*k+L]=s[i-1];
                ++i;
            }   
    }
    for(i=0;i<numRows;i++)
        for(int j=0;j<1000;j++)
        {
            if(isalpha(a[i][j]))
            New+=a[i][j];
        }
    return New;
}