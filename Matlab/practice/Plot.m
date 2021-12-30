clear;
t=0:0.1:pi;
x=2.*t;
y=t.*sin(t).*sin(t);
plot(x,y)
grid on
hold on
x=linspace(0,2*pi,100);
plot(x,sin(x),'k:',x,2*sin(x),'b--',x,3*sin(x),'rp')

