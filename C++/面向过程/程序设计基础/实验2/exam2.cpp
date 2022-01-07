#include <stdio.h>
#include <string.h>
#include <math.h>
double main(double num)
{
    double x;
    int a,b,c;
    a=(int)num;
    x=num-a;
    char numf[12];
    sprintf (numf ,"%.9g",x);
    b=strlen(numf);
    c=pow(10,(b-2));
    b=x*c;
    if(b==0)
    {
        printf ("%d",a);
        return 0;
    }
    else if(b==(c-1))
    {
        printf("%d %d %d",a,b,c);
        return 0;
    }
    for(int i=b;i>1;i--){
        if(b%i==0&&c%i==0){
            b=b/i;
            c=c/i;

            printf ("%d %d %d",a,b,c);
            return 0;
        }
    }
    printf("%d,%d,%d", a, b, c);
    return 0;
}