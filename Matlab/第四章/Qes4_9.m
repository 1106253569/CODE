clear;
fun=@Qes4_9fun;
xi=-2:0.5:1;
yi=-7:1;
[x,y]=meshgrid(xi,yi);
z=fun(x,y);
surf(x,y,z);
grid on;