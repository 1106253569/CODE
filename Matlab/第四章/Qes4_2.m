clear;
fun2=@(x)x.*ln(sqrt(x.^2-1)+x)-sqrt(x.^2-1)-x./2;
[x,f,h]=fsolve(fun2,0)
