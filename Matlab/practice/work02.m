clear;
title("202011010002 谢霖辉");
grid on;
hold on;

aplha=0:pi/100:2*pi;
r=2;
x(1,:)=r*cos(aplha);
x(2,:)=r*sin(aplha);
plot(x(1,:),x(2,:),'-');
axis equal
A=[2,0;0,2];
xx=A*x;
plot(xx(1,:),xx(2,:),'g')

A=[0.5,0;0,0.5];
xx=A*x;
plot(xx(1,:),xx(2,:),'g')

A=[1.5,0;0,0.5];
xx=A*x;
plot(xx(1,:),xx(2,:),'g')

theta=pi/4;
A=[cos(theta),-sin(theta);sin(theta),cos(theta)];
xx=A*xx;
plot(xx(1,:),xx(2,:),'m')

xx=xx+3;
hold on
plot(xx(1,:),xx(2,:),'c')

aplha=0:pi/100:2*pi;
r=2;
x(1,:)=r*cos(aplha);
x(2,:)=r*sin(aplha);
plot(x(1,:),x(2,:),'-');
axis equal
A=[2,0;0,2];
xx=A*x;
hold on
plot(xx(1,:),xx(2,:),'g')

A=[0.5,0;0,0.5];
xx=A*x;
hold on
plot(xx(1,:),xx(2,:),'g')
A=[1.5,0;0,0.5];
xx=A*x;
plot(xx(1,:),xx(2,:),'g')

theta=pi/4;
A=[cos(theta),-sin(theta);sin(theta),cos(theta)];
xx=A*xx;
plot(xx(1,:),xx(2,:),'m')

xx=xx+3;
hold on
plot(xx(1,:),xx(2,:),'c')
