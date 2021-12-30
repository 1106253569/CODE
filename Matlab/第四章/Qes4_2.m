clear;
fun2=@(x)x.*log(sqrt(x.^2-1)+x)-sqrt(x.^2-1)-x./2;
fsolve(fun2,0)
