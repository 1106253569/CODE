clear;
K=3.06;
p=5;
fun=@(x)K*x*sqrt(1+x)*sqrt(p)-(1-x)*sqrt(10.52+x);
x=fzero(fun,0);
x