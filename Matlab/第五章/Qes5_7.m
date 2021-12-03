clear;f
xa=-1:0.1:1;
ya=0:0.1:2;
[x,y]=meshgrid(xa,ya);
z=x.*exp(x.^2+y.^2);
[zx,zy]=gradient(z,xa,ya);
f=sqrt(1+zx.^2+zy.^2);
s=0;
for i=2:length(xa)
for j=2:length(ya)
s=s+(xa(i)-xa(i-1))*(ya(j)-ya(j-1))*(f(i,j)+f(i-1,j)+f(i,j-1)+f(i-1,j-1))/4; 
end
end
s
