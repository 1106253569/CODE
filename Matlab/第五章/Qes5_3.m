clear;
xa=-1:0.1:1;
ya=0:0.1:2;
[x,y]=meshgrid(xa,ya);
z=x.*exp(-x.^2-y.^3);
[px,py]=gridient(z,xa,ya);
