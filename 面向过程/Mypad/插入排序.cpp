#include <iostream>
int main()
{
    int a[1000],step=10;
    double clockPerMillis=double(CLOCK_PER_SEC)/1000;
    std::cout<;"The worst-case time,in milliseconds,are\n";
    std::cout<<"n \t Time"<<"\n";
    for(int n=0;n<=1000;n+=step)
    {
        for(int i=0;i<n;i++)
            a[i]=n-i;
        clock_t startTime=clock();
        insertionSort(a,n);
        double elapsedMillis=(clock()-startTime)/clockPerMillis;
        std::cout<<n<<'\t'<<elapsedMillis<<"\n";
        if(n==100)
            step=100;
    }
    return 0;
}