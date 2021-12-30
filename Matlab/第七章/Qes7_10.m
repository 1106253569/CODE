syms x y;f=(x-y)^3*sin(x+2*y);
Ix=simple(int(f,y,-x,x))