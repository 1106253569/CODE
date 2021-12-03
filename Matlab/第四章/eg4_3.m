clear;
fun=@(x)x.*sin(x.^2-x-1);
fplot(fun,[-2,-0.1]);
grid on;
fzero(fun,[-2,-1.2])
fzero(fun,[-1.2,-0.1])
fzero(fun,-1.6)
fzero(fun,[-1.2,-0.1])
fzero(fun,-1.6)
fzero(fun,-0.6)
