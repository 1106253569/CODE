A=[13 -56 78;25 63 -235;78 25 563;1 0 -1];

A

max(A)

max(A,[],1)%是求每一列的最大值，返回一个行矩阵(后两个参数可以省略)

max(A,[],2)%是求每一行的最大值，返回一个列矩阵

max(max(A),[],2)

mean(A)

mean(A,2)

mean(mean(A),2)

median(A)

mean(A,1)

mean(A,2)

median(mean(A))



