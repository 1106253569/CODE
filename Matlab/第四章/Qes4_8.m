clear;
fun1=@(x)x.^2*sin(x.^2-x-2);
fun2=@(y)3.*y.^5-20.*y^3+10;
fun3=@(z)abs(z.^3-z.^2-z-2);
fplot(fun1,[-2,2]);
grid on;
hold on;
fplot(fun2,[-3,3]);
hold on;
fplot(fun3,[0,3]);
