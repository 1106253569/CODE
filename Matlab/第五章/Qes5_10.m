clear;
fun=@(x)x.^2*sin(x.^2-x-2);
d=Qes5_10fun(fun,1.4,0.1,1e-3)