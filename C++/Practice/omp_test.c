#include <math.h>
#include "omp.h"
#include <stdio.h>
int main()
{
    int a, b, c, tid;
    omp_set_num_threads(4);
    a = -1;
    b = -2;
    c = -3;
    tid = omp_get_thread_num();
    printf("a=%d,b=%d,c=%d,id=%d\n", a, b, c, tid);
    printf("before parallel\n");
    printf("during parallel\n");
#pragma omp parallel private(a, b, tid) shared(c)
    {
        int d = -4;
        tid = omp_get_thread_num();
        printf("a=%d,b=%d,c=%d,d=%d,id=%d\n", a, b, c, d, tid);
        b = 10 + tid;
        c = c + int(pow(10, tid));
        d = d + int(pow(10, tid));
        printf("a=%d,b=%d,c=%d,d=%d,id=%d changed\n", a, b, c, d, tid);
    }
    tid = omp_get_thread_num();
    printf("after parallel\n");
    printf("a=%d,b=%d,c=%d,id=%d\n", a, b, c, tid);
    return 0;
}