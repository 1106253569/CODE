#include <math.h>
#include <iostream>
#include <omp.h>

int main()
{
    int a, b, c, tid;
    omp_set_num_threads(4);
    a = -1;
    b = -2;
    c = -3;
    tid = omp_get_thread_num();
    printf("i=0,a=%d,b=%d,c=%d,id=%d\n", a, b, c, tid);
    printf("before parallel\n");
    printf("during parallel\n");
#pragma omp parallel private(a, b, tid) shared(c)
    {
        int d = -4;
        tid = omp_get_thread_num();
        printf("i=1,a=%d,b=%d,c=%d,d=%d,id=%d\n", a, b, c, d, tid);
        b = 10 + tid;
        c = (int)(c + pow(10, tid));
        d = (int)(d + pow(10, tid));
        printf("i=2,a=%d,b=%d,c=%d,d=%d,id=%d changed\n", a, b, c, d, tid);
    }
    tid = omp_get_thread_num();
    printf("after parallel\n");
    printf("i=3,a=%d,b=%d,c=%d,id=%d\n", a, b, c, tid);
    return 0;
}