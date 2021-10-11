#include <iostream>
int main() 
{
    int T,num,gw,sw,bw,qw;
    scanf("%d", &num);
    gw = (num % 10 + 5) % 10;
    num /= 10;
    sw = (num % 10 + 5) % 10;
    num /= 10;
    bw = (num % 10 + 5) % 10;
    num /= 10;
    qw = (num % 10 + 5) % 10;
    num /= 10;
    printf("%d%d%d%d\n", gw, sw, bw, qw);
    return 0;
}