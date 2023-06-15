### OpenMP主要指令

| 指令       | 描述                                                                                                                                   |
| ---------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| parallel   | 放在一个代码段之前，表示这段代码将分配给多个线程并行执行                                                                               |
| for        | 放在for循环前，将循环分配给多个线程并行执行，但必须保证每次循环之间没有相关性                                                          |
| sections   | 放在被并行执行的代码段之前                                                                                                             |
| critical   | 用在一段代码之前，表明临界区中的代码只能由一个线程执行，其他线程则被阻塞在临界区开始位置                                               |
| single     | 用在一段只能被单个线程执行的代码段之前，表示后面的代码段将仅被一个线程执行                                                             |
| flush      | 标识一个同步点，确保所有执行的线程看到一致的存储视图，即执行的各个线程看到的共享变量是一致的                                           |
| barrier    | 标识一个栅障用于并行区内线程组中所有线程的同步。先到达的线程在此阻塞，等到其他的线程，直到所有线程都执行到栅障时才能继续往下执行       |
| atomic     | 指定特定的一块内存区域被自动更新                                                                                                       |
| master     | 指定一段代码块仅有主线程执行                                                                                                           |
| ordered    | 指定并行区域内的循环按次序执行。保证任何时刻只能有一个线程执行被ordered所限制的部分，它只能出现在for或者parallel for语句的动态范围内。 |
| task       | 生成一个任务结构                                                                                                                       |
| taskwait   | 等待子任务的完成                                                                                                                       |
| taskgroup  | 等待子任务和所有子孙任务的完成                                                                                                         |
| taskloop   | 对循环迭代进行分割并捆绑到多个任务中                                                                                                   |
| simd       | 对循环进行向量化操作                                                                                                                   |
| target     | 在目标设备上运行target结构内代码块                                                                                                     |
| teams      | 表示紧随其后的循环会分配给多个线程组                                                                                                   |
| distribute | 将循环以隐式任务形式分配给线程组群执行                                                                                                 |

注意：

（1）除了指令flush，critical，master，ordered，atomic没有相应的子句外，其他的指令都有一组适合它的子句。

（2）指定for、sections、single、master和barrier、task等必须绑定在指令parallel定义的并行区中。如果这些指令不在并行区内执行，则是无效指令。

（3）指令ordered必须和do指令绑定。

（4）指令atomic使atomic指令下第一个语句在所有线程中都能互斥的进行读写数据操作。但是指令atomic只能保护一句代码。

（5）指令critical使critical指令下第一个语句在所有线程中都能互斥的进行读写数据操作。但是指令critical只能保护一句代码。

（6）除指令parallel外，一个指令不能与其他指令绑定使用。

以下时不允许绑定使用的指令：

（1）指定for、sections和single可以绑定在同一个parallel结构中，但他们不允许互相嵌套，也不能将他们嵌套到隐式任务、critical结构、atomic结构、ordered结构和master结构中。

（2）指令parallel、flush、critical、atomic和隐式任务不允许出现在atomic结构中。

（3）指令critical不允许互相嵌套。

（4）指令barrier不允许出现在并行构造（for、sections和single）、critical结构、atomic结构、ordered结构、master结构和隐式任务中。

（5）指令master不允许出现在并行构造（for、sections和single）、critical结构、atomic结构和隐式任务中。

（6）指令ordered不允许出现在critical结构、atomic结构和隐式任务中。

### 主要子句

| 子句          | 描述                                                                                                                 |
| ------------- | -------------------------------------------------------------------------------------------------------------------- |
| private       | 表示变量列表中列出的变量对于每个线程来说均是私有变量，即每个线程都拥有自己的私有变量副本                             |
| shared        | 表示变量列表中列出的变量被线程组中所有线程所共享，即所有的线程都能对这些变量进行读写操作                             |
| default       | 表示并行区中所有变量是私有还是共享未定义，缺省情况下变量是共享变量                                                   |
| firstprivate  | 表示每个线程都有自己的变量副本，并且私有变量在进入并行区时需要继承主线程中同名原始变量作为自己的初始值。             |
| lastprivate   | 表示退出并行区后，执行最后一次迭代或最后一个section的线程中一个或多个私有变量的值复制给主线程中同名原始变量。        |
| reduction     | 指定一个或多个变量为私有变量，并在并行结束后对线程组中的相应变量执行指定的规约变量，并将结果返回给主线程的同名变量。 |
| threadprivate | 表示一个全局变量在并行区内变量每个线程的私有变量                                                                     |
| copyin        | 将主线程中threadprivate定义的全局变量的私有副本复制给同一并行区内其他线程的同名变量的私有副本                        |
| copyprivate   | 将线程中局部变量的私有副本复制给同一并行区内其他线程的同名变量的私有副本，一般与single指令联合使用                   |
| nowait        | 表示并发线程忽略指令中暗含的栅障                                                                                     |
| schedule      | 指定for循环的任务分配调度类型                                                                                        |
| ordered       | 表示for循环内的指定代码段要按照穿行循环的迭代次序进行执行                                                            |
| num_threads   | 指定线程的个数                                                                                                       |
| if            | 条件判断                                                                                                             |
| map           | 指定主机与目标设备之间数据传输的方向                                                                                 |
| device        | 给出设备编号，指定并行计算设备                                                                                       |

### 指令与子句的配套使用

| 子句         | parallel | for | sections | single | parallel for | parallel sections | task | simd | target |
| ------------ | -------- | --- | -------- | ------ | ------------ | ----------------- | ---- | ---- | ------ |
| if           | *        |     |          |        | *            | *                 | *    |      | *      |
| private      | *        | *   | *        | *      | *            | *                 | *    | *    | *      |
| shared       | *        |     |          |        | *            | *                 | *    |      |        |
| default      | *        |     |          |        | *            | *                 | *    |      |        |
| firstprivate | *        | *   | *        | *      | *            | *                 | *    |      | *      |
| lastprivate  |          | *   | *        |        | *            | *                 |      | *    |        |
| reduction    | *        | *   | *        |        | *            | *                 |      | *    |        |
| copyin       | *        |     |          |        | *            | *                 |      |      |        |
| copyprivate  |          |     |          | *      |              |                   |      |      |        |
| schedule     |          | *   |          |        | *            |                   |      |      |        |
| ordered      |          | *   |          |        | *            |                   |      |      |        |
| nowait       |          | *   | *        | *      |              |                   |      |      |        |
| num_threads  | *        |     |          |        | *            | *                 |      |      |        |
| collapse     |          | *   |          |        | *            |                   |      | *    |        |

### 常用库函数

除了编译制导外，OpenMP还提供了一组库函数。这些库函数可分为三种：运行时环境函数、锁函数和时间函数。下面列出几个常用的OpenMP库函数。

（1）omp_set_num_threads: 设置后续并行区中并行执行的线程数量。

（2）omp_get_num_procs: 返回计算系统的处理器数量。

（3）omp_get_num_threads: 确定当前并行区内活动线程数量。如果在并行区域外调用，该函数返回值为1.

（4）omp_get_thread_num: 返回当前的线程号。线程号的值在0到线程总数减1之间。

（5）omp_get_max_threads: 返回当前的并行区域内可用的最大线程数量。

（6）omp_set_dynamic: 启用或关闭线程数量的动态改变

（7）omp_get_dynamic: 判断是否支持动态改变线程数量

（8）omp_get_wtime：返回值是一个双精度实数，单位为秒。此数代表相对于某个任意参考时刻而言已经经历的时间。

（9）omp_init_lock: 初始化一个简单锁

（10）omp_set_lock：给一个简单锁上锁

（11）omp_unset_lock: 给一个简单锁解锁，必须与omp_set_lock函数配对使用

（12）omp_destroy_lock：关闭一个锁并释放内存，必须与omp_init_lock函数配对使用

### 数据环境

#### private子句、shared子句、default子句

private(变量列表)

对出现在变量列表中的变量，子句private将其定义为私有变量后，将在并行区域的开始处为线程组的每个线程产生一个该变量的私有副本。需要注意，子句private声明的私有变量的初始值在并行区域的入口处是未定义的（分编译器），它不会继承并行区域外同名原始变量的值。

```c
#include<stdio.h>
#include<math.h>
#include<omp.h>
int main()
{
    int a,b,c,tid;
    omp_set_num_threads(4);
    a=-1;
    b=-2;
    c=-3;
    tid=omp_get_thread_num();
    printf("a=%d,b=%d,c=%d,id=%d\n",a,b,c,tid);
    printf("before parallel\n");
    printf("during parallel\n");
    #pragma omp parallel private(a,b,tid) shared(c)
    {
        int d=-4;
        tid=omp_get_thread_num();
        printf("a=%d,b=%d,c=%d,d=%d,id=%d\n",a,b,c,d,tid);
        b=10+tid;
        c=c+int(pow(10,tid));
        d=d+int(pow(10,tid));
        printf("a=%d,b=%d,c=%d,d=%d,id=%d changed\n",a,b,c,d,tid);
    }
    tid=omp_get_thread_num();
    printf("after parallel\n");
    printf("a=%d,b=%d,c=%d,id=%d\n",a,b,c,tid);
    return 0;
}
```

需要强调几点：

（1）在并行区域内对各线程的私有变量是否初始化取决于所使用的编译器。换言之，部分编译器并不对各线程的私有变量进行初始化操作；而部分编译器对各线程的私有变量进行初始化仅是意味着将这些变量取零值，而与串行区同名原始变量的值无关。

（2）对于共享变量，多个子线程均指向同一内存地址。这样，各子线程均能改变共享变量的值。实际上，无论程序是在串行区内执行，还是在并行区内执行，共享变量在内存空间的位置一直保持不变。

（3）并行区内各线程私有变量副本的地址和串行区同名原始变量的地址各不相同。因此，他们的值可以不一致而且通常互相不可见。

#### 子句firstprivate和子句lastprivate

firstprivate(变量列表)

对于变量列表中的变量，子句firstprivate将其变量定义为私有变量；并在进入并行区域时，此子句会将每个线程的私有变量副本的值初始化为进入并行区前串行区同名原始变量的值。

在并行区内，当完成对子线程私有变量的计算后，有时需要将它的值传递给并行区外同名的原始变量。OpenMP提供了子句lastprivate来实现此功能。

lastprivate(变量列表)

由于在并行区内有多个线程并行执行，那么将哪个线程的最终结果复制并传递给并行区外同名的原始变量是一个关键问题。OpenMP指出：如果是for循环，则在退出并行区后会将执行最后一次迭代的子线程的私有变量的值带出并行区并赋给并行区外同名的原始变量。如果是sections指令，则将执行最后一个section子句的子线程的私有变量的值赋给并行区外同名的原始变量。

注意：子句private不能和子句firstprivate混用于同一个变量，firstprivate和lastprivate可以对同一变量使用。

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    int tid,i,j,a[4],b[4];
    omp_set_num_threads(3);
    for(i=0;i<4;i++)
    {
        a[i]=-10;
        b[i]=-10;
    }
    tid=omp_get_thread_num();
    for(i=0;i<4;i++)
        printf("a[%d]=%d ",i,a[i]);
    printf("thread %d\n",tid);
    for(i=0;i<4;i++)
        printf("b[%d]=%d ",i,b[i]);
    printf("thread %d\n",tid);
    printf("before parallel");
    printf("during parallel");
    #pragma omp parallel for private(i,j,tid) firstprivate(a,b) lastprivate(b)
    for(i=0;i<4;i++)
    {
        tid=omp_get_thread_num();
        printf("a[%d]=%d b[%d]=%d thread %d\n",i,a[i],i,b[i],tid);
        a[i]=(i+1)*3+tid;
        b[i]=(i+1)*7+tid;
        printf("a[%d]=%d b[%d]=%d thread %d changed\n",i,a[i],i,b[i],tid);
    }
    tid=omp_get_thread_num();
    printf("after parallel");
        for(i=0;i<4;i++)
        printf("a[%d]=%d ",i,a[i]);
    printf("thread %d\n",tid);
    for(i=0;i<4;i++)
        printf("b[%d]=%d ",i,b[i]);
    printf("thread %d\n",tid);
    return 0;
}
```

#### 指令threadprivate

#pragma omp threadprivate(变量列表)

变量列表中的变量须为全局变量。threadprivate将全局变量定义为私有全局变量，即各个线程拥有自己私有的全局变量。需要指出的是：子句private将局部变量指定为私有变量后，此变量退出并行区域后会失效；指令threadprivate将全局变量定义为私有变量后，此变量可以在前后多个并行区之间保持连续性。

| 项目                                         | 子句private                                                      | 指令threadprivate                                                                                                             |
| -------------------------------------------- | ---------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| 数据类型                                     | 局部变量                                                         | 全局变量                                                                                                                      |
| 作用范围                                     | 并行区                                                           | 整个程序                                                                                                                      |
| 声明位置                                     | 在区域或者工作共享组的开头                                       | 在全局文件作用域的程序声明里                                                                                                  |
| 关联性                                       | 并行区内的各子线程私有变量的副本与并行区域外同名原始变量没有关联 | 并行区域内子线程0的全局变量的副本继承了并行区外同名原始变量的值，而其他子线程的全局变量的副本则与并行区外同名原始变量没有关联 |
| 持久性                                       | 否                                                               | 是                                                                                                                            |
| 进入并行区域，继承串行区同名原始变量的值     | 子句firstprivate                                                 | 子句copyin                                                                                                                    |
| 退出并行区域，赋值给并行区外同名原始变量的值 | 子句lastprivate                                                  | 并行区内子线程0所拥有的全局变量的副本                                                                                         |
| 线程间自由变量的通信                         | 子句copyprivate                                                  | 子句copyprivate                                                                                                               |

注意：

（1）在第一次进入并行区的时候，除非在parallel指令后指定了copyin子句，否则指令threadprivate定义的私有变量的初值是未定义的。

（2）在使用指令threadprivate的时候，各个并行块的线程数量须保持不变，因此只有关闭动态线程的属性，才能保证结果正确。

（3）指令threadprivate作用的区域大于子句private作用的区域。由指令threadprivate指定的全局变量并不是针对某一个并行区，而是作用域整个程序，所以，其拷贝的副本变量也是全局的，记载不同的并行区之间的同一个线程也是共享的。

（4）变量必须首先声明为全局变量，然后才能用指令threadprivate将其指定为全局私有变量。

```c
#include<stdio.h>
#include<omp.h>
int x,y;
#pragma omp threadprivate(x)
int main()
{
    int tid,a;
    omp_set_num_threads(4);
    tid=omp_get_thread_num();
    a=-1;
    x=-1;
    y=-1;
    printf("first serial region\n");
    printf("a=%d,x=%d,y=%d,id=%d\n",a,x,y,tid);
    printf("first parallel region");
    #pragma omp parallel private(a,tid)
    {
       tid=omp_get_thread_num();
       printf("a=%d,x=%d,y=%d,id=%d\n",a,x,y,tid);
       a=a+tid+10;
       x=x+tid+10;
       y=y+tid+10;
       printf("a=%d,x=%d,y=%d,id=%d changed\n",a,x,y,tid);
    }
    tid=omp_get_thread_num();
    printf("second serial region\n");
    printf("a=%d,x=%d,y=%d,id=%d\n",a,x,y,tid);
    a=a+tid+10;
    x=x+tid+10;
    y=y+tid+10;
    printf("a=%d,x=%d,y=%d,id=%d changed\n",a,x,y,tid);
    printf("second parallel region\n");
    #pragma omp parallel private(tid)
    {
       tid=omp_get_thread_num();
       printf("a=%d,x=%d,y=%d,id=%d\n",a,x,y,tid);
       a=a+tid+10;
       x=x+tid+10;
       y=y+tid+10;
       printf("a=%d,x=%d,y=%d,id=%d changed\n",a,x,y,tid);
    }
    printf("third serial region\n");
    printf("a=%d,x=%d,y=%d,id=%d\n",a,x,y,tid);
    return 0;
}
```

#### 子句copyin和子句copyprivate

与子句threadprivate对应的是子句copyin和子句copyprivate。子句copyin是将主线程中threadprivate声明的全局变量的私有副本复制给并行区内各个线程的相应全局变量的私有副本。这样，线程组中各个线程各自拥有的全局变量的私有副本具有相同的值。

copyin(变量列表)

子句copyprivate是将线程私有变量的副本从一个线程广播到本并行区的其他线程的同名变量。

```c
#include<stdio.h>
#include<omp.h>
int x;
#pragma omp threadprivate(x)
int main()
{
    int tid,a;
    omp_set_num_threads(4);
    tid=omp_get_thread_num();
    a=-1;
    x=-2;
    printf("first serial region\n");
    printf("a=%d,x=%d,id=%d\n",a,x,tid);
    printf("first parallel region\n");
    #pragma omp parallel firstprivate(a) private(tid) copyin(x)
    {
        tid=omp_get_thread_num();
        printf("a=%d,x=%d,id=%d\n",a,x,tid);
        a=a+tid+10;
        x=x+tid+100;
        printf("a=%d,x=%d,id=%d changed\n",a,x,tid);
    }
    tid=omp_get_thread_num();
    printf("second serial region\n");
    printf("a=%d,x=%d,id=%d\n",a,x,tid);
    a=a+tid+10;
    x=x+tid+100;
    printf("a=%d,x=%d,id=%d changed\n",a,x,tid);
    printf("second parallel region\n");
    #pragma omp parallel firstprivate(a) private(tid)
    {
        tid=omp_get_thread_num();
        printf("second parallel:a=%d,x=%d,id=%d\n",a,x,tid);
        #pragma omp single copyprivate(x,a)
        {
            printf("second parallel region single block\n");
            tid=omp_get_thread_num();
            printf("a=%d,x=%d,id=%d\n",a,x,tid);
            a=a+tid+10;
            x=x+tid+100;
            printf("a=%d,x=%d,id=%d changed\n",a,x,tid);  
        }
        printf("second parallel region after single block\n");
        tid=omp_get_thread_num();
        printf("a=%d,x=%d,id=%d\n",a,x,tid);
    }
    printf("third serial region\n");
    printf("a=%d,x=%d,id=%d\n",a,x,tid);
    return 0;
}
```

### 并行控制

静态模式: omp_set_num_threads, num_threads, OMP_NUM_THREADS

动态模式：默认模式，omp_set_dynamic

嵌套模式：omp_set_nested

条件模式：if

#### 默认模式

所谓默认模式，就是在程序中对并行计算的线程数量不做显式声明。此方式的优越性在于程序的扩展性能好。当硬件升级到更多核时，在不修改程序的情况下，程序创建的线程数量随系统处理器核数的变化而变化。但是也会带来问题：

（1）如果并行程序的结果依赖于线程的数量，则会出错。

（2）在大多数情况下，为了提高设备利用率，大部分服务器都是公用的。如果多个用户一起使用，采用默认模式就会抢占资源，影响其他用户的使用。

（3）如果计算负载小，线程过多有时会造成实际计算耗时的延长。

#### 动态模式

在动态模式中，并行区域中的线程数时动态确定的，各并行区域可以具有不同的线程数。

线程数的动态调整是通过调用环境库函数omp_set_dynamic来实现的。如果参数为真，表明启用了可用线程数的动态调整，此时omp_set_num_threads()只能设定一个上限，实际参加运行的线程数不会超过所设置的线程数目。如果设为假，表明禁用可用线程数的动态调整，那么函数omp_set_num_threads()设置的线程数目几位实际参加的线程数。

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    int nthreads_set,nthreads,tid;
    nthreads_set=3;
    omp_set_dynamic(1);
    omp_set_num_threads(nthreads_set);
    printf("set_number_threads=%d\n",nthreads_set);
    printf("dynamic region(1 or 0):%d\n",omp_get_dunamic());
    #pragma omp parallel private(tid,nthreads)
    {
        nthreads=omp_get_num_threads();
        tid=omp_get_thread_num();
        printf("number of threads=%d ",nthreads);
        printf("tid=%d\n",tid);
    }
    return 0;
}
```

#### 嵌套模式

函数omp_set_nested()的作用是启用或禁用嵌套并行操作。此调用只影响调用线程所遇到的同一级或内部嵌套级别的后续并行区。如设为真，表示启用嵌套并行操作，能在嵌套并行区配置额外的线程；如设为假，表示禁用嵌套并行操作，那么嵌套并行区域内代码将被目前的线程串行执行。

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    omp_set_nested(1);
    omp_set_dynamic(0);
    printf("nested region:%d\n",omp_get_nested());
    #pragma omp parallel num_threads(2)
    {
        if(omp_get_thread_num()==0) omp_set_num_threads(4);
        else omp_set_num_threads(3);
        #pragma omp master
        printf("outer zone:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads());
        #pragma omp parallel
        {
            #pragma omp master
           printf("inner zone:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
           printf("inner: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads());         
        }   
    }
    return 0;
}
```

OpenMP的嵌套并行是指在并行区中可以遇到另一个并行区域。常用嵌套并行方式有两种：先使用粗粒度并行的tasks或parallel sections，然后使用parallel for在任务task或子区域section内获取进一步的并行性。

```c
#include<stdio.h>
#include<omp.h>
#define m 5
#define n 4
int main()
{
    int array1[m],array2[n];
    omp_set_dynamic(0);
    #pragma omp parallel sections shared(array1,array2) num_threads(3)
    {
        #pragma omp section
        {
        printf("outer section 1:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads()); 
            #pragma omp parallel for shared(array1) num_threads(3)
            for(int i=0;i<m;i++)
            {
                array1[i]=i;
                printf("innerzone:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads());
            }
        }
        #pragma omp section
        {
        printf("outer section 1:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads()); 
            #pragma omp parallel for shared(array2) num_threads(2)
            for(int i=0;i<n;i++)
            {
                array1[i]=i;
                printf("innerzone:active_level=%d,team_size=%d\n",omp_get_active_level(),
               omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID=%d, thread_in_team=%d\n",omp_get_thread_num()
               omp_get_num_threads());
            }
        }
    }
    return 0;
}
```

#### 条件并行语句

具体而言，如果子句if的条件能够得到满足，就采用并行方式来运行并行区的代码；如果子句if的条件不能得到满足，就采用串行方式来运行并行区的代码。

if(标量逻辑表达式)

```c
#include<stdio.h>
#include<omp.h>
void printnumthreads(int n)
{
    int nthreads;
    #pragma omp parallel private(nthreads) if(n>10) num_threads(4)
    {
        nthreads=omp_get_num_threads();
        printf("number of threads=%d,n=%d\n",nthreads,n);
    }
    return
}
int main()
{
    printnumthreads(2);
    printnumthreads(20);
    return 0;
}
```

### 并行构造

#### 指令sections

除了循环结构可以进行并行之外，分段并行（sections）是另一种有效的并行执行方法。具体而言，当并行执行一个程序时，通常实在同一个时间段内将一个计算任务划分为若干个子任务然后利用多个线程完成。

指令sections的语法如下：

```c
#pragma omp sections [子句...]
private firstprivate lastprivate reduction nowait
{
    #pragma omp section
    结构块
    #pragma omp section
    结构块   
}
```

注意：

（1）由于指令sections在大多数情况下与一个独立的parallel指令一起使用，OpenMP提供了一个复合指令#pragma omp parallels sections.

（2）一个程序中可以定义多个sections结构。

（3）section内部不允许出现能够到达section之外的跳转语句，也不允许有外部的跳转语句达到section内部。

（4）如果子句nowait没有使用，在指令sections结束时有一个隐含的栅障。

#### 指令single

在并行区里，有时候希望部分程序代码以串行方式执行。在未使用nowait子句情况下，只有一个线程去执行并行区内的部分程序代码，而其他的线程则跳过这段程序代码。由于在single后面会有一个隐含的栅障，因此在此线程执行期间其他线程处于空闲状态；所有线程只有在single指令结束处隐含的栅障处同步后才能继续开始执行。

```c
#pragma omp single [子句]
private firstprivate copyprivate nowait
{
    结构块
}
```

注意：

（1）一个single结构只能由一个线程来执行，但并不一定是主线程来执行。

（2）结构single内部不允许出现能够到达single之外的跳转语句，也不允许由外部的跳转语句到达single内部。

### 线程同步

#### 指令barrier

#pragma omp barrier

指令barrier要求并行区内所有线程在此处同步等待其他线程，然后恢复并行执行barrier后面的语句。

OpenMP的许多指令自身都带有隐含的栅障。下列OpenMP结构结束处存在隐含的栅障barrier：

（1）#pragma omp parallel

（2）#pragma omp for

（3）#pragma omp sections

（4）#pragma omp critical

（5）#pragma omp single

#### 指令nowait

每个指令parallel for都带有一个同步的栅障。通常可以在#pragma omp for, #pragma omp sections, #pragma omp single后采用nowait去除这些共享结构结束处隐含的栅障。

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    int m=4;
    int tid, nthreads, i;
    omp_set_num_threads(3);
    #pragma omp parallel private(tid,nthreads)
    {
        #pragma omp for
        for(i=1;i<=m;i++)
        {
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
            printf("first for loop: %d,id=%d\n",nthreads,tid);
        }
         #pragma omp for nowait
        for(i=1;i<=m;i++)
        {
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
            printf("second for loop: %d,id=%d\n",nthreads,tid);
        }  
                #pragma omp for 
        for(i=1;i<=m;i++)
        {
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
            printf("third for loop: %d,id=%d\n",nthreads,tid);
        }
    }
    return 0;
}要求
```

#### 指令master

语法：

```
#pragma omp master
{
   结构块
}
```

指令master要求主线程区执行并行区域内的部分程序代码，而其他的线程则越过这段程序代码直接向下执行。此条指令没有隐式栅障。

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    int nthreads,tid;
    omp_set_num_threads();
    #pragma omp parallel private(tid,nthreads)
    {
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
        printf("before master: %d,id=%d\n",nthreads,tid);
        #pragma omp master
        {
             tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
        printf("master region: %d,id=%d\n",nthreads,tid);         
        }
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
        printf("after master: %d,id=%d\n",nthreads,tid);      
    }
    return 0;
}
```

#### 指令ordered

指令ordered要求循环for区域内的代码块必须按照循环迭代的次序来执行。这是因为在 执行循环的过程中，部分工作是可以并行执行的，然而特定部分工作则需要等待前面的工作完成以后才能够正确执行。

语法：

```
#pragma omp for ordered [子句]
for循环区
{
      #pragma omp ordered
      代码块
}
```

指令ordered在使用过程中需满足：

（1）指令ordered一般与指令for或指令parallel for联合使用。

（2）在任意时刻，只允许一个线程执行ordered结构。

（3）不允许跳出跳入。

（4）一个for循环内部只能出现一次ordered指令

```c
#include<stdio.h>
#include<omp.h>
int main()
{
    int i,tid,nthreads;
    int a[10];
    omp_set_num_threads(3);
    printf("nthreads id i a[]\n");
    #pragma omp parallel private(i,tid,nthreads) shared(n)
    {
        #pragma omp for
        for(i=0;i<10;i++)
        {
            a[i]=i+1;
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
            printf("%d %d %d %d\n",nthreads,tid,i,a[i]);
        }
        #pragma omp for ordered
        for(i=0;i<10;i++)
        {
            a[i]=a[i-1]-1;
            tid=omp_get_thread_num();
            nthreads=omp_get_num_threads();
            printf("%d %d %d %d\n",nthreads,tid,i,a[i]);
        }      
    }
    return 0;
}
```

### 运行环境

#### OpenMP时间函数

OpenMP提供的时间函数由两个omp_get_wtime和omp_get_wtick。这两个函数的返回值均是一个双精度实数。如果要得到系统时间，建议使用函数omp_get_wtime，函数返回值的单位是秒。

| 时间函数               | 描述                                                                                      |
| ---------------------- | ----------------------------------------------------------------------------------------- |
| double omp_get_wtime() | 返回值是一个双精度实数，单位为秒。此数值是相对于某个参考时刻而言已经经理的时间。          |
| double omp_get_wtime() | 返回值是一个双精度实数，单位为秒。此数值等于两虚的时钟计时 周期之间的秒数，即计时器的精度 |

```c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#define m 10000
int main()
{
    int i,j;
    double start_time, end_time, used_time,tick,x;
    omp_set_num_threads(2);
    printf("start_time=%e seconds.\n",start_time);
    x=0;
    for(i=1;i<m+1;i++)
    {
        #pragma omp parallel for private(j) lastprivate(x)
        for(j=1;j<m+1;j++)
        {
            x=x+log(pow(2.7,(pow(sin(pow(1.1,1.1)),1.1)+1.0))+1.0);
        }
    }
    end_time=omp_get_wtime();
    printf("end_time=%e seconds.\n",end_time);
    used_time=end_time-start_time;
    printf("used_time=%e seconds.\n",used_time);
    printf("x=%e\n",x);
    tick=omp_get_wtick();
    printf("tick=%e seconds.\n",tick);
    return 0;
}
```
