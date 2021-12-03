clear;
t=0:0.01:1.5;
x=log(cos(t));
y=cos(t)-t.*cos(t);
dydx=gradient(y,x)
[x_1,id]=min(abs(x-(-1)));
dydx(id)