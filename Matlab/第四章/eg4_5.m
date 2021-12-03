clear;
x=-1.6:0.01:-1;
y=x.*sin(x.^2-x-1);
[m,k]=min(y)