clear;
t=0:0.01:2*pi;
x=sin(t);
y=cos(t);
z=2-2.*y./3;
grid on;
plot3(x,y,z)