clear;
x=-2:0.02:2;
y=sqrt(9-(9*x.^2)./4);
plot(x,y);
hold on;
plot(x,-y);
axis on;
hold off;