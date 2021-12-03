fun=@(x)x.*sin(1./x);
fplot(fun,[-0.1,0.1]);
grid on;
[x,f,h]=fsolve(fun,0.05)